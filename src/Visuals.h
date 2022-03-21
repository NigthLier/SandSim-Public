#pragma once

#include <SFML/Graphics.hpp>

/**
* @file Visuals.h
* Файл, содержащий объявления классов, отвечающих за визуализацию приложения
* @brief Вывод изображения
* @see Visuals.cpp
* @author Спектор Евгений
*/

/**
 * Visual_tiles - класс используемый для создания и отрисовки набора тайлов
 * @brief Массив тайлов
 */
class Visual_tiles : public sf::Drawable, public sf::Transformable
{
public:
/**
 * Visual_tiles::Visual_tiles(const sf::Vector2u&, const sf::Vector2u&) - конструктор создающий определенный набор тайлов
 * @param tileSize - размер тайла
 * @param gridSize - размер набора
 * @brief Специальный конструктор
*/
    Visual_tiles(const sf::Vector2u& tileSize, const sf::Vector2u& gridSize);
/**
 * Visual_tiles::update() - метод, обновляющий цвета набора тайлов
 * @param tiles - одномерный массив цветов
 * @brief Обновление тайлов
*/
    void update(sf::Color* tiles);
private:
    sf::Vector2u gridSize_;
    sf::VertexArray m_vertices;
/**
 * Visual_tiles::draw() - метод, отрисовывающий набора тайлов, является переопределением метода sf::Drawable::draw()
 * @param target - цель отрисовки
 * @param states - статус отрисовки
 * @brief Отрисовка тайлов
 * @see <https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php>
*/
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

/**
 * Visual_input - класс используемый для определения положений мыши
 * @brief Ввод мышью
 */
class Visual_input
{
public:
/**
 * Visual_input::Visual_input(sf::RenderWindow*) - конструктор создающий определенный объект ввода
 * @param window - окно ввода
 * @brief Специальный конструктор
*/
    Visual_input(sf::RenderWindow* window) : window_(window) {};
/**
 * Visual_input::getNext() - метод, возвращающий текущее положение мыши
 * @return Текущая точка
 * @brief Получить текущую точку
*/
    sf::Vector2f getNext() { return (*window_).mapPixelToCoords(sf::Mouse::getPosition(*window_)); };
/**
 * Visual_input::getPrevious() - метод, возвращающий предыдущее положение мыши
 * @return  Предыдущая точка
 * @brief Получить предыдущую точку
*/
    sf::Vector2f& getPrevious() { return previous_; };
/**
 * Visual_input::setPrevious() - метод, возвращающий устанавлювающий текущее положение мыши как предыдущее
 * @brief Поставить предыдущую точку
*/
    void setPrevious() { previous_ = (*window_).mapPixelToCoords(sf::Mouse::getPosition(*window_)); };
private:
    sf::RenderWindow* window_;
    sf::Vector2f previous_ = { 0 , 0 };
    sf::Vector2f next_ = { 0 , 0 };
};

/**
 * Visual_button - класс используемый для создания и отрисовки кнопок
 * @brief Кнопка
 */
class Visual_button
{
public:
/**
 * Visual_button::Visual_button(const sf::Vector2u&, const sf::Vector2u&, const std::string, const std::string, const sf::Color&, const sf::Color&) - конструктор создающий определенную кнопку
 * @param position - позиция кнопки
 * @param size - размер кнопки
 * @param fileInactive - обычная текстура
 * @param fileActive - текстура при активации
 * @param colorInactive - обычный цвет
 * @param colorActive - цвет при активации
 * @brief Специальный конструктор
*/
    Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const std::string fileActive, const sf::Color& colorInactive, const sf::Color& colorActive);
/**
 * Visual_button::Visual_button(const sf::Vector2u&, const sf::Vector2u&, const std::string, const std::string, const sf::Color&) - конструктор создающий определенную кнопку
 * @param position - позиция кнопки
 * @param size - размер кнопки
 * @param fileInactive - обычная текстура
 * @param fileActive - текстура при активации
 * @param colorInactive - обычный цвет
 * @brief Специальный конструктор
*/
    Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const sf::Color& colorInactive, const sf::Color& colorActive);
/**
 * Visual_button::Visual_button(const sf::Vector2u&, const sf::Vector2u&, const std::string, const sf::Color&, const sf::Color&) - конструктор создающий определенную кнопку
 * @param position - позиция кнопки
 * @param size - размер кнопки
 * @param fileInactive - обычная текстура
 * @param colorInactive - обычный цвет
 * @param colorActive - цвет при активации
 * @brief Специальный конструктор
*/
    Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const std::string fileActive, const sf::Color& colorInactive);
/**
 * Visual_button::Visual_button(const sf::Vector2u&, const sf::Vector2u&, const std::string, const sf::Color&) - конструктор создающий определенную кнопку
 * @param position - позиция кнопки
 * @param size - размер кнопки
 * @param fileInactive - обычная текстура
 * @param colorInactive - обычный цвет
 * @brief Специальный конструктор
*/
    Visual_button(const sf::Vector2u& position, const sf::Vector2u& size, const std::string fileInactive, const sf::Color& colorInactive);
/**
 * Visual_input::checkButton() - метод, проверяющий активность кнопки
 * @param window - окно отрисовки
 * @return Состояние кнопки
 * @brief Проверить кнопку
*/
    bool checkButton(sf::RenderWindow* window);
/**
 * Visual_input::getButton() - метод, возвращающий спрайт кнопки
 * @return Спрайт кнопки
 * @brief Спрайт кнопки
*/
    sf::Sprite* getButton() { return  &button_; };
/**
 * Visual_input::changeVisibility() - метод, переключающий видимость кнопки
 * @brief Изменение видимости
*/
    void changeVisibility() { visible_ = (visible_)?(false):(true); };
/**
 * Visual_input::visibility() - метод, возвращающий видимость кнопки
 * @return Видимость кнопки
 * @brief Видимость
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
 * Visual_menu - класс используемый для создания и отрисовки меню
 * @brief Меню
 */
class Visual_menu
{
public:
/**
 * Visual_menu::Visual_menu(Visual_button*, sf::RenderWindow*) - конструктор создающий определенное меню
 * @param buttons - массив кнопок
 * @param window - окно отрисовки
 * @brief Специальный конструктор
*/
    Visual_menu(Visual_button* buttons, sf::RenderWindow* window);
/**
 * Visual_menu::checkButtons() - метод, проверяющий кнопки и возвращающий состояние меню
 * @return Состояние меню
 * @brief Проверить кнопки
*/
    char checkButtons();
/**
 * Visual_menu::drawMenu() - метод, отрисовывающий меню
 * @brief Отрисовать меню
*/
    void drawMenu();
/**
 * Visual_menu::MainMenu() - метод, перехода в гдавное меню
 * @brief Переход на главную
*/
    void MainMenu() { isMainMenu_ = true; info_ = false; };
private:
    sf::RenderWindow* window_;
    Visual_button* buttons_;
    bool isMainMenu_ = true;
    bool info_ = false;
};

/**
 * Visual_combine - класс посредством которого осуществляеся контроль над отрисовкой приложения
 * @brief Обработчик графики
 */
class Visual_combine
{
public:
/**
 * Visual_combine::Visual_combine(const sf::Vector2u&, const sf::Vector2u&, std::string, Visual_button*) - конструктор создающий определенный обработчик графики
 * @param tileSize - размер тайла
 * @param gridSize - размер набора
 * @param Name - имя окна
 * @param buttons - массив кнопок
 * @brief Специальный конструктор
*/
    Visual_combine(const sf::Vector2u& tileSize, const sf::Vector2u& gridSize, std::string Name, Visual_button* buttons);
/**
 * Visual_combine::changeCursor() - метод, изменяющий изображение курсора
 * @brief Изменить курсор
*/
    void changeCursor(std::string cursorFile);
/**
 * Visual_combine::displayVisuals() - метод, отрисовывающий графику в окне
 * @brief Отрисовка окна
*/
    void displayVisuals();
/**
 * Visual_combine::events() - метод, проверяющий события закрытия и события поворота колёсика мыши
 * @param Старый элемент
 * @return Новый элемент
 * @brief Обновить тайлы
*/
    char events(char element);
/**
 * Visual_combine::update() - метод, обновляющий изображение объекта Visual_tiles
 * @brief Обновить тайлы
*/
    void update(sf::Color* tiles) { if(!inMenue()) tiles_.update(tiles); };
/**
 * Visual_combine::getwindow() - метод, возвращающий окно отрисовки
 * @return Окно отрисовки
 * @brief Получить окно
*/
    sf::RenderWindow* getwindow() { return &window_; };
/**
 * Visual_combine::getPreviousPosition() - метод, возвращающий предыдущее положение мыши объекта Visual_input
 * @return Предыдущая точка
 * @brief Получить предыдущую точку
*/
    sf::Vector2f& getPreviousPosition() { return input.getPrevious(); };
/**
 * Visual_combine::getNextPosition() - метод, возвращающий текущее положение мыши объекта Visual_input
 * @return Текущая точка
 * @brief Получить следующую точку
*/
    sf::Vector2f getNextPosition() { return input.getNext(); };
/**
 * Visual_combine::setPreviousPosition() - метод, устанавливающий предыдущую позицию объекта Visual_input
 * @brief Поставить предыдущую точку
*/
    void setPreviousPosition() { return input.setPrevious(); };
/**
 * Visual_combine::openedWindow() - метод, проверяющий то, что окно открыто
 * @return Открыто ли окно
 * @brief Проверить окно
*/
    bool openedWindow() { return window_.isOpen(); };
/**
 * Visual_combine::focusedWindow() - метод, проверяющий то, что окно находится в фокусе
 * @return Находится ли окно в фокусе
 * @brief Проверить фокус
*/
    bool focusedWindow() { return window_.sf::Window::hasFocus(); };
/**
 * Visual_combine::inMenue() - метод, проверяющий нахождение в меню
 * @return Является ли экран меню
 * @brief Нахождение в меню
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
