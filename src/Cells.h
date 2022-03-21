#pragma once

#include "Basics.h"

/**
* @file Cells.h
* ���� ���������� ���������� �������, ���������� �� �������� ����� ������
* @brief ���� ������
* @see Cells.cpp
* @author ������� �������
*/

/**
 * Cell_error - ����� ������ ������������ ��� ���������� ������ � ���� Cell::processCell()\n
 * ����: ������, id: -1
 * @brief ������ ������
 */
class Cell_error : public Cell
{
public:
	Cell_error() { id_ = -1, color_ = sf::Color::Cyan; };
};

/**
 * Cell_air - ����� ������ ������������ � �������� ����������� ������� ������������\n
 * ����: ������, id: 0
 * @brief ������ �������
 */
class Cell_air : public Cell
{
public:
	Cell_air() { id_ = 0, color_ = sf::Color::Black; };
};

/**
 * Cell_error - ����� ������ ������������ � �������� ����������� ����\n
 * ����: �����, id: 1
 * @brief ������ ������
 */
class Cell_concrete : public Cell
{
public:
	Cell_concrete() { id_ = 1, color_ = sf::Color::Color(200, 200, 200, 255); };
};

/**
 * Cell_error - ����� ������ ������������ � �������� ����������������� �������� ���������\n
 * ����: �����, id: 2
 * @brief ������ �����
 */
class Cell_sand : public Loose_cell
{
public:
	Cell_sand() { id_ = 2, color_ = sf::Color::Color(217, 185, 43, 255); };
};

/**
 * Cell_error - ����� ������ ������������ � �������� ����������������� ������� ���������\n
 * ����: �����, id: 3
 * @brief ������ ����
 */
class Cell_water : public Liquid_cell
{
public:
	Cell_water() { id_ = 3, color_ = sf::Color::Color(6, 99, 199, 255); };
};

/**
 * Cell_error - ����� ������ ������������ � �������� ����������������� �������� ���������\n
 * ����: ����������, id: 4
 * @brief ������ ����
 */
class Cell_gas : public Gas_cell
{
public:
	Cell_gas() { id_ = 4, color_ = sf::Color::Color(119, 27, 194, 255); };
};