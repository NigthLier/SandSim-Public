#pragma once
#include <SFML/Graphics.hpp>

/**
* @file Basics.h
* Файл, содержащий объявления классов, отвечающих за базовое взаимодействие клеток
* @brief Базовые классы клеток
* @see Basics.cpp
* @author Спектор Евгений
*/

/**
 * getPath() - функция, рассчитывающая прямой путь между двумя точками
 * @param previousPosition - первая точка
 * @param nextPosition - вторая точка
 * @return Линию точек
 * @brief Путь между точками
 */
std::vector<sf::Vector2f> getPath(const sf::Vector2f& previousPosition, const sf::Vector2f& nextPosition);

/**
 * Cell - базовый класс клеток, использеумый в качестве основы для остальных классов клеток\n
 * Особое поведение: отсутствует
 * @brief Базовая клетка
 */
class Cell
{
public:
	Cell() = default;
/**
 * Cell::getCellId() - функция, возвращающая ID клетки
 * @return ID данной клетки
 * @brief ID клеток
*/
	char& getCellId() { return id_; };
/**
 * Cell::getCellColor() - функция, возвращающая цвет клетки
 * @return Цвет данной клетки
 * @brief Цвет клеток
*/
	sf::Color& getCellColor() { return color_; };
/**
 * Cell::processCell() - функция, определяющая состояние базовых клеток, как неизменное
 * @param cells - матрица клеток
 * @param position - координаты клетки
 * @param matrixSize - размер матрицы
 * @brief Поведение клеток
*/
	virtual void processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize) {};
protected:
	char id_ = 0;
	sf::Color color_ = sf::Color::Black;
 };

/**
 * Loose_cell - класс клеток использеумый в качестве основы для клеток, симулирующих сыпучие вещества\n
 * Особое поведение: клетки этого типа перемещаются вниз, симулируя поведение твердых сыпучих веществ
 * @brief Сыпучая клетка
 */
class Loose_cell : public Cell
{
public:
	Loose_cell() = default;
/**
 * Loose_cell::processCell() - функция, переопределяющая поведение для твердых сыпучих веществ
 * @param cells - матрица клеток
 * @param position - координаты клетки
 * @param matrixSize - размер матрицы
 * @brief Поведение сыпучих веществ
*/
	virtual void processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize) override;
};

/**
 * Liquid_cell - класс клеток использеумый в качестве основы для клеток, симулирующих жидкие вещества\n
 * Особое поведение: клетки этого типа перемещаются вниз и в стороны, симулируя поведение жидкостей
 * @brief Жидкая клетка
 */
class Liquid_cell : public Cell
{
public:
	Liquid_cell() = default;
/**
 * Liquid_cell::processCell() - функция, переопределяющая поведение для жидких веществ
 * @param cells - матрица клеток
 * @param position - координаты клетки
 * @param matrixSize - размер матрицы
 * @brief Поведение жидкостей
*/
	virtual void processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize) override;
};

/**
 * Gas_cell - класс клеток использеумый в качестве основы для клеток, симулирующих газообразные вещества\n
 * Особое поведение: клетки этого типа перемещаются вверх и в стороны, симулируя поведение газов
 * @brief Газообразная клетка
 */
class Gas_cell : public Cell
{
public:
	Gas_cell() = default;
/**
 * Gas_cell::processCell() - функция, переопределяющая поведение для газообразных веществ
 * @param cells - матрица клеток
 * @param position - координаты клетки
 * @param matrixSize - размер матрицы
 * @brief Поведение газов
*/
	virtual void processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize) override;
};