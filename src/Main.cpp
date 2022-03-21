#include "Operations.h"
#include "Visuals.h"

/**
* @mainpage Документация по исходникам проекта SandSim
* В данной документации описываются классы и функии, используемые в проекте SandSim
*/


/**
* @file Main.cpp
* Файл, содержащий создание базовых объектов обработки взаимодействий и вывода изображения, а также взаиможействие между ними
* @brief Место входа в программу
* @author Спектор Евгений
*/

/**
 * main() - функция, с которой начинается выполнение программы
 * @return Состояние выхода из программы
 * @brief Точка входа
*/
int main()
{
    const sf::Vector2u gridSize(128, 96), tileSize(8, 8);
    char element = 1;

    Visual_button* buttons = new Visual_button[11]
    {
        Visual_button({ 0, 0 }, { gridSize.x * tileSize.x, gridSize.y * tileSize.y }, std::string("images/Background.png"), sf::Color::Color(255, 255, 255, 255)),
        Visual_button({ 312, 184 }, { 400, 80 }, std::string("images/Simulation.png"), sf::Color::Red, sf::Color::Green),
        Visual_button({ 312, 344 },  { 400, 80 }, std::string("images/Info.png"), sf::Color::Red, sf::Color::Green),
        Visual_button({ 312, 504 },  { 400, 80 }, std::string("images/Exit.png"), std::string("images/ExitNot.png"), sf::Color::Red, sf::Color::Green),
        Visual_button({ 0, 0 }, { gridSize.x * tileSize.x, gridSize.y * tileSize.y }, std::string("images/BackgroundInfo.png"), sf::Color::Color(255, 255, 255, 255)),
        Visual_button({ 0, 0 }, { gridSize.x * tileSize.x, gridSize.y * tileSize.y }, std::string("images/InfoText.png"), sf::Color::Color(255, 255, 255, 255)),
        Visual_button({ 312, 608 },  { 400, 80 }, std::string("images/Back.png"), sf::Color::Red, sf::Color::Green),
        Visual_button({ 0, 0 }, { gridSize.x * tileSize.x, gridSize.y * tileSize.y }, std::string("images/FlatColor.png"), sf::Color::Color(50, 50, 50, 240)),
        Visual_button({ 312, 184 },  { 400, 80 }, std::string("images/Continue.png"), sf::Color::Red, sf::Color::Green),
        Visual_button({ 312, 344 },  { 400, 80 }, std::string("images/Menu.png"), sf::Color::Red, sf::Color::Green),
        Visual_button({ 312, 504 },  { 400, 80 }, std::string("images/Exit.png"), std::string("images/ExitNot.png"), sf::Color::Red, sf::Color::Green)
    };

    Visual_combine VC(tileSize, gridSize, "SandSim", buttons);
    Operational_combine OP(gridSize, tileSize);

    while (VC.openedWindow())
    {
        VC.changeCursor(std::string("images/Cursor.png"));
        element = VC.events(element);

        if (VC.focusedWindow())
        {
            if (!VC.inMenue())
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    OP.addCells(VC.getPreviousPosition(), VC.getNextPosition(), 0);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    OP.addCells(VC.getPreviousPosition(), VC.getNextPosition(), element);

                VC.setPreviousPosition();
                VC.update(OP.getCellsColor());
                OP.processCells();
            }
            VC.displayVisuals();
        }
    }

    return 0;
}