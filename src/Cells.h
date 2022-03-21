#pragma once

#include "Basics.h"

/**
* @file Cells.h
* ‘айл содержащий объ€влени€ классов, отвечающих за описание типов клеток
* @brief “ипы клеток
* @see Cells.cpp
* @author —пектор ≈вгений
*/

/**
 * Cell_error - класс клеток использеумый дл€ нахождени€ ошибок в ходе Cell::processCell()\n
 * ÷вет: зелЄный, id: -1
 * @brief  летка ошибки
 */
class Cell_error : public Cell
{
public:
	Cell_error() { id_ = -1, color_ = sf::Color::Cyan; };
};

/**
 * Cell_air - класс клеток использеумый в качестве заполнител€ пустого пространства\n
 * ÷вет: черный, id: 0
 * @brief  летка воздуха
 */
class Cell_air : public Cell
{
public:
	Cell_air() { id_ = 0, color_ = sf::Color::Black; };
};

/**
 * Cell_error - класс клеток использеумый в качестве неподвижных стен\n
 * ÷вет: серый, id: 1
 * @brief  летка бетона
 */
class Cell_concrete : public Cell
{
public:
	Cell_concrete() { id_ = 1, color_ = sf::Color::Color(200, 200, 200, 255); };
};

/**
 * Cell_error - класс клеток использеумый в качестве демонстрационного сыпучего иатериала\n
 * ÷вет: жЄлтый, id: 2
 * @brief  летка песка
 */
class Cell_sand : public Loose_cell
{
public:
	Cell_sand() { id_ = 2, color_ = sf::Color::Color(217, 185, 43, 255); };
};

/**
 * Cell_error - класс клеток использеумый в качестве демонстрационного жидкого иатериала\n
 * ÷вет: синий, id: 3
 * @brief  летка воды
 */
class Cell_water : public Liquid_cell
{
public:
	Cell_water() { id_ = 3, color_ = sf::Color::Color(6, 99, 199, 255); };
};

/**
 * Cell_error - класс клеток использеумый в качестве демонстрационного летучего иатериала\n
 * ÷вет: фиолетовый, id: 4
 * @brief  летка газа
 */
class Cell_gas : public Gas_cell
{
public:
	Cell_gas() { id_ = 4, color_ = sf::Color::Color(119, 27, 194, 255); };
};