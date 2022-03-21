#pragma once

#include "Basics.h"
#include <vector>
#include <iostream>
#include <math.h>

/**
* @file Operations.h 
* Файл, содержащий объявления классов, отвечающих за обработку взаимодействия клеток между собой и окружением
* @brief Обработка взаимодействий
* @see Operations.cpp
*/

/**
 * Cell_matrix - хранилище информации о расположении клеток
 * @brief Матрица клеток
 */
class Cell_matrix
{
public:
	Cell_matrix() = default;
/**
 * Cell_matrix::Cell_matrix(const Cell_matrix&) - конструктор копирования
 * @brief Конструктор копирования
*/
	Cell_matrix(const Cell_matrix&) = default;
/**
 * Cell_matrix::Cell_matrix(const std::ptrdiff_t, const std::ptrdiff_t) - конструктор создающий матрицу с определенныым количеством строк и столбцов
 * @param row_count - количество строк
 * @param col_count - количество столбцов
 * @brief Специальный конструктор
 * @author Спектор Евгений
*/
	Cell_matrix(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count);
	~Cell_matrix() = default;
/**
 * Cell_matrix::operator=() - оператор присвивания
 * @brief Оператор присвивания
*/
	Cell_matrix& operator=(const Cell_matrix&) = default;

/**
 * Cell_matrix::rowCount() - метод, возвращающий количество строк
 * @return количество строк
 * @brief Количество строк
*/
	std::ptrdiff_t rowCount() const noexcept { return n_row_; };
/**
 * Cell_matrix::colCount() - метод, возвращающий количество столбцов
 * @return количество столбцов
 * @brief Количество столбцов
*/
	std::ptrdiff_t colCount() const noexcept { return n_col_; };

/**
 * Cell_matrix::at() - метод, возвращающий данные в конкретной ячейке матрицы
 * @param i_row - номер строки
 * @param i_col - номер столбца
 * @return Данные ячейки
 * @brief Данне в ячейке
*/
	char& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col);
/**
 * Cell_matrix::at() const - константная версия метода Cell_matrix::at(), возвращающего данные в конкретной ячейке матрицы
 * @param i_row - номер строки
 * @param i_col - номер столбца
 * @return Данные ячейки
 * @brief Данне в ячейке
*/
	char at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const;

/**
 * Cell_matrix::getData() - метод, возвращающий хранящиеся данные в виде одномерного массива
 * @return Массив данных
 * @brief Передача данных
*/
	std::vector<char>& getData() { return data_; }

private:
	std::ptrdiff_t n_row_{ 0 };
	std::ptrdiff_t n_col_{ 0 };
	std::vector<char> data_;
};


/**
 * Operational_combine - класс посредством которого осуществляеся контроль над взаимодействием клеток
 * @brief Обработчик взаимодействий
 */
class Operational_combine
{
public:
/**
 * Cell_matrix::Operational_combine(sf::Vector2u, sf::Vector2u) - конструктор создающий определенный обработчик взаимодействий
 * @param matrixSize - размер матрицы
 * @param tileSize - размер тайла
 * @brief Специальный конструктор
*/
	Operational_combine(sf::Vector2u matrixSize, sf::Vector2u tileSize) : matrixSize_(matrixSize), tileSize_(tileSize), cellMatrix_(matrixSize.x, matrixSize.y) {};
/**
 * Operational_combine::addCells() - метод, размещающий клетки опредленного ID между двумя точками в матрице, используя функцию getPath()
 * @param previousPosition - первая точка
 * @param nextPosition - вторая точка
 * @param id - ID клетки
 * @brief Добавление клеток
 * @see getPath()
*/
	void addCells(sf::Vector2f& previousPosition, sf::Vector2f nextPosition, char id);
/**
 * Operational_combine::processCells() - метод, рассчитывающий взаимодействие между клетками в матрице, используя функцию Cell::processCell()
 * @brief Симуляция взаимодействий
 * @see Cell::processCell()
*/
	void processCells();
/**
 * Operational_combine::cellFromId() - метод, возвращающий клетку с определенным ID
 * @param id - ID клетки
 * @return Клетка
 * @brief Генератор клеток
*/
	Cell* cellFromId(const char& id);
/**
 * Operational_combine::getCellsColor() - метод, возвращающий одномерный массив цветов клеток
 * @return Массив цветов
 * @brief Передача цветов
*/
	sf::Color* getCellsColor();
private:
	sf::Vector2u matrixSize_;
	sf::Vector2u tileSize_;
	Cell_matrix cellMatrix_;
};