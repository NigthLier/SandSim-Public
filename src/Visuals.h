#pragma once

#include <SFML/Graphics.hpp>

/**
* @file Visuals.h
* ����, ���������� ���������� �������, ���������� �� ������������ ����������
* @brief ����� �����������
* @see Visuals.cpp
* @author ������� �������
*/

/**
 * Visual_tiles - ����� ������������ ��� �������� � ��������� ������ ������
 * @brief ������ ������
 */
class Visual_tiles : public sf::Drawable, public sf::Transformable
{
public:
/**
 * Visual_tiles::Visual_tiles(const sf::Vector2u&, const sf::Vector2u&) - ����������� ��������� ������������ ����� ������
 * @param tileSize - ������ �����
 * @param gridSize - ������ ������
 * @brief ����������� �����������
*/
    Visual_tiles(const sf::Vector2u& tileSize, const sf::Vector2u& gridSize);
/**
 * Visual_tiles::update() - �����, ����������� ����� ������ ������
 * @param tiles - ���������� ������ ������
 * @brief ���������� ������
*/
    void update(sf::Color* tiles);
private:
    sf::Vector2u gridSize_;
    sf::VertexArray m_vertices;
/**
 * Visual_tiles::draw() - �����, �������������� ������ ������, �������� ���������������� ������ sf::Drawable::draw()
 * @param target - ���� ���������
 * @param states - ������ ���������
 * @brief ��������� ������
 * @see <https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php>
*/
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

/**
 * Visual_input - ����� ������������ ��� ����������� ��������� ����
 * @brief ���� �����
 */
class Visual_input
{
public:
/**
 * Visual_input::Visual_input(sf::RenderWindow*) - ����������� ��������� ������������ ������ �����
 * @param window - ���� �����
 * @brief ����������� �����������
*/
    Visual_input(sf::RenderWindow* window) : window_(window) {};
/**
 * Visual_input::getNext() - �����, ������������ ������� ��������� ����
 * @return ������� �����
 * @brief �������� ������� �����
*/
    sf::Vector2f getNext() { return (*window_).mapPixelToCoords(sf::Mouse::getPosition(*window_)); };
/**
 * Visual_input::getPrevious() - �����, ������������ ���������� ��������� ����
 * @return  ���������� �����
 * @brief �������� ���������� �����
*/
    sf::Vector2f& getPrevious() { return previous_; };
/**
 * Visual_input::setPrevious() - �����, ������������ ��������������� ������� ��������� ���� ��� ����������
 * @brief ��������� ���������� �����
*/
    void setPrevious() { previous_ = (*window_).mapPixelToCoords(sf::Mouse::getPosition(*window_)); };
private:
    sf::RenderWindow* window_;
    sf::Vector2f previous_ = { 0 , 0 };
    sf::Vector2f next_ = { 0 , 0 };
};

/**
 * Visual_button - ����� ������������ ��� �������� � ��������� ������
 * @brief ������
 */
class Visual_button
{
public:
/**
 * Visual_button::Visual_button(const sf::Vector2u&, const sf::Vector2u&, const std::string, const std::string, const sf::Color&, const sf::Color&) - ����������� ��������� ������������ ������
 * @param position - ������� ������
 * @param size - ������ ������
 * @param fileInactive - ������� ��������
 * @param fileActive - �������� ��� ���������
 * @param colorInactive - ������� ����
 * @param colorActive - ���� ��� ���������
 * @brief ����������� �����������
*/
    Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const std::string fileActive, const sf::Color& colorInactive, const sf::Color& colorActive);
/**
 * Visual_button::Visual_button(const sf::Vector2u&, const sf::Vector2u&, const std::string, const std::string, const sf::Color&) - ����������� ��������� ������������ ������
 * @param position - ������� ������
 * @param size - ������ ������
 * @param fileInactive - ������� ��������
 * @param fileActive - �������� ��� ���������
 * @param colorInactive - ������� ����
 * @brief ����������� �����������
*/
    Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const sf::Color& colorInactive, const sf::Color& colorActive);
/**
 * Visual_button::Visual_button(const sf::Vector2u&, const sf::Vector2u&, const std::string, const sf::Color&, const sf::Color&) - ����������� ��������� ������������ ������
 * @param position - ������� ������
 * @param size - ������ ������
 * @param fileInactive - ������� ��������
 * @param colorInactive - ������� ����
 * @param colorActive - ���� ��� ���������
 * @brief ����������� �����������
*/
    Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const std::string fileActive, const sf::Color& colorInactive);
/**
 * Visual_button::Visual_button(const sf::Vector2u&, const sf::Vector2u&, const std::string, const sf::Color&) - ����������� ��������� ������������ ������
 * @param position - ������� ������
 * @param size - ������ ������
 * @param fileInactive - ������� ��������
 * @param colorInactive - ������� ����
 * @brief ����������� �����������
*/
    Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const sf::Color& colorInactive);
/**
 * Visual_input::checkButton() - �����, ����������� ���������� ������
 * @param window - ���� ���������
 * @return ��������� ������
 * @brief ��������� ������
*/
    bool checkButton(sf::RenderWindow* window);
/**
 * Visual_input::getButton() - �����, ������������ ������ ������
 * @return ������ ������
 * @brief ������ ������
*/
    sf::Sprite* getButton() { return  &button_; };
/**
 * Visual_input::changeVisibility() - �����, ������������� ��������� ������
 * @brief ��������� ���������
*/
    void changeVisibility() { visible_ = (visible_)?(false):(true); };
/**
 * Visual_input::visibility() - �����, ������������ ��������� ������
 * @return ��������� ������
 * @brief ���������
*/
    bool visibility() { return visible_; };
private:
    sf::Sprite button_;
    sf::Vector2u position_;
    sf::Vector2u size_;
    sf::Texture textureInactive_;
    sf::Texture textureActive_;
    sf::Color colorInactive_;
    sf::Color colorActive_;
    bool texture_;
    bool color_;
    bool active_ = false;
    bool visible_ = true;
};

/**
 * Visual_menu - ����� ������������ ��� �������� � ��������� ����
 * @brief ����
 */
class Visual_menu
{
public:
/**
 * Visual_menu::Visual_menu(Visual_button*, sf::RenderWindow*) - ����������� ��������� ������������ ����
 * @param buttons - ������ ������
 * @param window - ���� ���������
 * @brief ����������� �����������
*/
    Visual_menu(Visual_button* buttons, sf::RenderWindow* window);
/**
 * Visual_menu::checkButtons() - �����, ����������� ������ � ������������ ��������� ����
 * @return ��������� ����
 * @brief ��������� ������
*/
    char checkButtons();
/**
 * Visual_menu::drawMenu() - �����, �������������� ����
 * @brief ���������� ����
*/
    void drawMenu();
/**
 * Visual_menu::MainMenu() - �����, �������� � ������� ����
 * @brief ������� �� �������
*/
    void MainMenu() { isMainMenu_ = true; info_ = false; };
private:
    sf::RenderWindow* window_;
    Visual_button* buttons_;
    bool isMainMenu_ = true;
    bool info_ = false;
};

/**
 * Visual_combine - ����� ����������� �������� ������������� �������� ��� ���������� ����������
 * @brief ���������� �������
 */
class Visual_combine
{
public:
/**
 * Visual_combine::Visual_combine(const sf::Vector2u&, const sf::Vector2u&, std::string, Visual_button*) - ����������� ��������� ������������ ���������� �������
 * @param tileSize - ������ �����
 * @param gridSize - ������ ������
 * @param Name - ��� ����
 * @param buttons - ������ ������
 * @brief ����������� �����������
*/
    Visual_combine(const sf::Vector2u& tileSize, const sf::Vector2u& gridSize, std::string Name, Visual_button* buttons);
/**
 * Visual_combine::changeCursor() - �����, ���������� ����������� �������
 * @brief �������� ������
*/
    void changeCursor(std::string cursorFile);
/**
 * Visual_combine::displayVisuals() - �����, �������������� ������� � ����
 * @brief ��������� ����
*/
    void displayVisuals();
/**
 * Visual_combine::events() - �����, ����������� ������� �������� � ������� �������� ������� ����
 * @param ������ �������
 * @return ����� �������
 * @brief �������� �����
*/
    char events(char element);
/**
 * Visual_combine::update() - �����, ����������� ����������� ������� Visual_tiles
 * @brief �������� �����
*/
    void update(sf::Color* tiles) { if(!inMenue()) tiles_.update(tiles); };
/**
 * Visual_combine::getwindow() - �����, ������������ ���� ���������
 * @return ���� ���������
 * @brief �������� ����
*/
    sf::RenderWindow* getwindow() { return &window_; };
/**
 * Visual_combine::getPreviousPosition() - �����, ������������ ���������� ��������� ���� ������� Visual_input
 * @return ���������� �����
 * @brief �������� ���������� �����
*/
    sf::Vector2f& getPreviousPosition() { return input.getPrevious(); };
/**
 * Visual_combine::getNextPosition() - �����, ������������ ������� ��������� ���� ������� Visual_input
 * @return ������� �����
 * @brief �������� ��������� �����
*/
    sf::Vector2f getNextPosition() { return input.getNext(); };
/**
 * Visual_combine::setPreviousPosition() - �����, ��������������� ���������� ������� ������� Visual_input
 * @brief ��������� ���������� �����
*/
    void setPreviousPosition() { return input.setPrevious(); };
/**
 * Visual_combine::openedWindow() - �����, ����������� ��, ��� ���� �������
 * @return ������� �� ����
 * @brief ��������� ����
*/
    bool openedWindow() { return window_.isOpen(); };
/**
 * Visual_combine::focusedWindow() - �����, ����������� ��, ��� ���� ��������� � ������
 * @return ��������� �� ���� � ������
 * @brief ��������� �����
*/
    bool focusedWindow() { return window_.sf::Window::hasFocus(); };
/**
 * Visual_combine::inMenue() - �����, ����������� ���������� � ����
 * @return �������� �� ����� ����
 * @brief ���������� � ����
*/
    bool inMenue() { return inMainMenu_ || inSideMenu_ || inESCMenu_; };
private:
    sf::RenderWindow window_;
    Visual_tiles tiles_;
    Visual_menu menu_;
    Visual_input input;
    bool inMainMenu_ = true;
    bool inSideMenu_ = false;
    bool inESCMenu_ = false;
};
