#include "Visuals.h"

/**
* @file Visuals.cpp
* Файл, содержащий определение функций из файла Visuals.h
* @brief Вывод изображения
* @see Visuals.h
* @author Спектор Евгений
*/

Visual_tiles::Visual_tiles(const sf::Vector2u& tileSize, const sf::Vector2u& gridSize)
    : gridSize_(gridSize)
{
    this->m_vertices.setPrimitiveType(sf::Quads);
    this->m_vertices.resize((size_t)gridSize.x * gridSize.y * 4);

    for (size_t i = 0; i < gridSize.x; ++i)
        for (size_t j = 0; j < gridSize.y; ++j)
        {
            sf::Vertex* quad = &this->m_vertices[(i + j * gridSize.x) * 4];

            quad[0].position = sf::Vector2f((float)(i * tileSize.x), (float)(j * tileSize.y));
            quad[1].position = sf::Vector2f((float)((i + 1) * tileSize.x), (float)(j * tileSize.y));
            quad[2].position = sf::Vector2f((float)((i + 1) * tileSize.x), (float)((j + 1) * tileSize.y));
            quad[3].position = sf::Vector2f((float)(i * tileSize.x), (float)((j + 1) * tileSize.y));

            quad[0].color = sf::Color::Black;
            quad[1].color = sf::Color::Black;
            quad[2].color = sf::Color::Black;
            quad[3].color = sf::Color::Black;
        }
}

void Visual_tiles::update(sf::Color* tiles)
{
    for (size_t i = 0; i < gridSize_.x; ++i)
        for (size_t j = 0; j < gridSize_.y; ++j)
        {
            size_t tileNumber = i + j * this->gridSize_.x;
            sf::Vertex* quad = &this->m_vertices[(size_t)tileNumber * 4];

            quad[0].color = tiles[tileNumber];
            quad[1].color = tiles[tileNumber];
            quad[2].color = tiles[tileNumber];
            quad[3].color = tiles[tileNumber];
        }
}

void Visual_tiles::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(this->m_vertices, states);
}



Visual_menu::Visual_menu(Visual_button* buttons, sf::RenderWindow* window) 
    : buttons_(buttons), window_(window) 
{
    for(int i = 0; i < 9; i++)
        buttons_[i].changeVisibility();
}

char Visual_menu::checkButtons()
{
    char menuNumber;
    if (isMainMenu_)
    {
        if (!info_)
        {
            menuNumber = 1;
            for(int i = 0; i < 11; i++)
            {
                if(buttons_[i].visibility())
                    buttons_[i].changeVisibility();
            }
            for (int i = 0; i < 4; i++)
            {
                if (!buttons_[i].visibility())
                    buttons_[i].changeVisibility();
            }
            if (buttons_[1].checkButton(window_))
            {
                isMainMenu_ = false;
                menuNumber = 4;
            }
            if (buttons_[2].checkButton(window_))
            {
                info_ = true;
                menuNumber = 2;
            }
            if (buttons_[3].checkButton(window_))
                window_->close();
        }
        else
        {
            menuNumber = 2;
            for (int i = 0; i < 11; i++)
            {
                if (buttons_[i].visibility())
                    buttons_[i].changeVisibility();
            }
            for (int i = 4; i < 7; i++)
            {
                if (!buttons_[i].visibility())
                    buttons_[i].changeVisibility();
            }
            if (buttons_[6].checkButton(window_))
            {
                info_ = false;
                menuNumber = 1;
            }
        }
    }
    else
    {
        menuNumber = 3;
        for (int i = 0; i < 11; i++)
        {
            if (buttons_[i].visibility())
                buttons_[i].changeVisibility();
        }
        for (int i = 7; i < 11; i++)
        {
            if (!buttons_[i].visibility())
                buttons_[i].changeVisibility();
        }
        if (buttons_[8].checkButton(window_))
        {
            menuNumber = 4;
        }
        if (buttons_[9].checkButton(window_))
        {
            isMainMenu_ = true;
            menuNumber = 1;
        }
        if (buttons_[10].checkButton(window_))
            window_->close();
    }
    return menuNumber;
}

void Visual_menu::drawMenu()
{
    for (int i = 0; i < 11; i++)
        if(buttons_[i].visibility())
            (*window_).draw(*buttons_[i].getButton());
}



Visual_combine::Visual_combine(const sf::Vector2u& tileSize, const sf::Vector2u& gridSize, std::string Name, Visual_button* buttons)
    : window_(sf::VideoMode(gridSize.x * tileSize.x, gridSize.y * tileSize.y), Name, sf::Style::Close), tiles_(tileSize, gridSize), input(&window_), menu_(buttons, &window_)
{
    window_.setVerticalSyncEnabled(true);
    window_.setFramerateLimit(120);
    window_.setKeyRepeatEnabled(false);
    sf::Mouse::setPosition(sf::Vector2i(0, 0), window_);
}

void Visual_combine::changeCursor(std::string cursorFile)
{
    sf::Image cursorImage;
    if (!cursorImage.loadFromFile(cursorFile))
        cursorImage.loadFromFile("../" + cursorFile);
    sf::Cursor cursor;
    cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), { cursorImage.getSize().x / 2, cursorImage.getSize().y / 2 });
    window_.setMouseCursor(cursor);
}

void Visual_combine::displayVisuals()
{
    window_.clear();
    if(inESCMenu_)
        window_.draw(tiles_);
    if (inMenue())
    {
        menu_.drawMenu();
        switch (menu_.checkButtons())
        {
        case 1:
            inMainMenu_ = true;
            inSideMenu_ = false;
            inESCMenu_ = false;
            break;
        case 2:
            inMainMenu_ = false;
            inSideMenu_ = true;
            inESCMenu_ = false;
            break;
        case 3:
            inMainMenu_ = false;
            inSideMenu_ = false;
            inESCMenu_ = true;
            break;
        case 4:
            inMainMenu_ = false;
            inSideMenu_ = false;
            inESCMenu_ = false;
            break;
        }
    }
    else
        window_.draw(tiles_);
    window_.display();
}

char Visual_combine::events(char element)
{
    sf::Event event;
    while(window_.pollEvent(event))
        switch(event.type)
        {
        case sf::Event::Closed:
            window_.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                if (inMainMenu_) { window_.close(); }
                else if (inSideMenu_) { menu_.MainMenu(); }
                else { inESCMenu_ = (inESCMenu_)?(false):(true); }
            break;
        case sf::Event::MouseWheelScrolled:
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                element += (int)event.mouseWheelScroll.delta;
                element = (element < 1) ? (1) : (element);
                element = (element > 4) ? (4) : (element);
            }
            break;
        }
    return element;
}



Visual_button::Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, std::string fileActive, const sf::Color& colorInactive, const sf::Color& colorActive)
    : position_(position), size_(size), colorInactive_(colorInactive), colorActive_(colorActive), texture_(true), color_(true)
{
    if(!textureInactive_.loadFromFile(fileInactive))
        textureInactive_.loadFromFile("../" + fileInactive);
    if (!textureActive_.loadFromFile(fileActive))
        textureActive_.loadFromFile("../" + fileActive);
    textureInactive_.setSmooth(true);
    textureActive_.setSmooth(true);
    button_ = sf::Sprite(textureInactive_);
    button_.setColor(colorInactive_);
    button_.setPosition(sf::Vector2f::Vector2(position_));
}

Visual_button::Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const sf::Color& colorInactive, const sf::Color& colorActive)
    : position_(position), size_(size), colorInactive_(colorInactive), colorActive_(colorActive),  texture_(false), color_(true)
{
    if (!textureInactive_.loadFromFile(fileInactive))
        textureInactive_.loadFromFile("../" + fileInactive);
    textureInactive_.setSmooth(true);
    button_ = sf::Sprite(textureInactive_);
    button_.setColor(colorInactive_);
    button_.setPosition(sf::Vector2f::Vector2(position_));
}

Visual_button::Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const std::string fileActive, const sf::Color& colorInactive)
    :position_(position), size_(size), colorInactive_(colorInactive), texture_(true), color_(false)
{
    if (!textureInactive_.loadFromFile(fileInactive))
        textureInactive_.loadFromFile("../" + fileInactive);
    if (!textureActive_.loadFromFile(fileActive))
        textureActive_.loadFromFile("../" + fileActive);
    textureInactive_.setSmooth(true);
    textureActive_.setSmooth(true);
    button_ = sf::Sprite(textureInactive_);
    button_.setColor(colorInactive_);
    button_.setPosition(sf::Vector2f::Vector2(position_));
}

Visual_button::Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const sf::Color& colorInactive)
    : position_(position), size_(size), colorInactive_(colorInactive), texture_(false), color_(false)
{
    if (!textureInactive_.loadFromFile(fileInactive))
        textureInactive_.loadFromFile("../" + fileInactive);
    textureInactive_.setSmooth(true);
    button_ = sf::Sprite(textureInactive_);
    button_.setColor(colorInactive_);
    button_.setPosition(sf::Vector2f::Vector2(position_));
}

bool Visual_button::checkButton(sf::RenderWindow* window)
{
    if (visible_)
    {
        if (texture_ && active_)
            button_.setTexture(textureInactive_);
        if (color_ && active_)
            button_.setColor(colorInactive_);
        active_ = false;
        if (sf::IntRect(sf::Vector2i::Vector2(position_), sf::Vector2i::Vector2(size_)).contains(sf::Mouse::getPosition(*window)))
        { 
            if(texture_ && !active_)
                button_.setTexture(textureActive_);
            if(color_ && !active_)
                button_.setColor(colorActive_);
            active_ = true;

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(sf::milliseconds(100));
                return true;
            }   
        }
    }
    return false;
}