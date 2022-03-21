#pragma once

#include "Basics.h"
#include <vector>
#include <iostream>
#include <math.h>

/**
* @file Operations.h 
* ����, ���������� ���������� �������, ���������� �� ��������� �������������� ������ ����� ����� � ����������
* @brief ��������� ��������������
* @see Operations.cpp
*/

/**
 * Cell_matrix - ��������� ���������� � ������������ ������
 * @brief ������� ������
 */
class Cell_matrix
{
public:
	Cell_matrix() = default;
/**
 * Cell_matrix::Cell_matrix(const Cell_matrix&) - ����������� �����������
 * @brief ����������� �����������
*/
	Cell_matrix(const Cell_matrix&) = default;
/**
 * Cell_matrix::Cell_matrix(const std::ptrdiff_t, const std::ptrdiff_t) - ����������� ��������� ������� � ������������� ����������� ����� � ��������
 * @param row_count - ���������� �����
 * @param col_count - ���������� ��������
 * @brief ����������� �����������
 * @author ������� �������
*/
	Cell_matrix(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count);
	~Cell_matrix() = default;
/**
 * Cell_matrix::operator=() - �������� �����������
 * @brief �������� �����������
*/
	Cell_matrix& operator=(const Cell_matrix&) = default;

/**
 * Cell_matrix::rowCount() - �����, ������������ ���������� �����
 * @return ���������� �����
 * @brief ���������� �����
*/
	std::ptrdiff_t rowCount() const noexcept { return n_row_; };
/**
 * Cell_matrix::colCount() - �����, ������������ ���������� ��������
 * @return ���������� ��������
 * @brief ���������� ��������
*/
	std::ptrdiff_t colCount() const noexcept { return n_col_; };

/**
 * Cell_matrix::at() - �����, ������������ ������ � ���������� ������ �������
 * @param i_row - ����� ������
 * @param i_col - ����� �������
 * @return ������ ������
 * @brief ����� � ������
*/
	char& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col);
/**
 * Cell_matrix::at() const - ����������� ������ ������ Cell_matrix::at(), ������������� ������ � ���������� ������ �������
 * @param i_row - ����� ������
 * @param i_col - ����� �������
 * @return ������ ������
 * @brief ����� � ������
*/
	char at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const;

/**
 * Cell_matrix::getData() - �����, ������������ ���������� ������ � ���� ����������� �������
 * @return ������ ������
 * @brief �������� ������
*/
	std::vector<char>& getData() { return data_; }

private:
	std::ptrdiff_t n_row_{ 0 };
	std::ptrdiff_t n_col_{ 0 };
	std::vector<char> data_;
};


/**
 * Operational_combine - ����� ����������� �������� ������������� �������� ��� ��������������� ������
 * @brief ���������� ��������������
 */
class Operational_combine
{
public:
/**
 * Cell_matrix::Operational_combine(sf::Vector2u, sf::Vector2u) - ����������� ��������� ������������ ���������� ��������������
 * @param matrixSize - ������ �������
 * @param tileSize - ������ �����
 * @brief ����������� �����������
*/
	Operational_combine(sf::Vector2u matrixSize, sf::Vector2u tileSize) : matrixSize_(matrixSize), tileSize_(tileSize), cellMatrix_(matrixSize.x, matrixSize.y) {};
/**
 * Operational_combine::addCells() - �����, ����������� ������ ������������ ID ����� ����� ������� � �������, ��������� ������� getPath()
 * @param previousPosition - ������ �����
 * @param nextPosition - ������ �����
 * @param id - ID ������
 * @brief ���������� ������
 * @see getPath()
*/
	void addCells(sf::Vector2f& previousPosition, sf::Vector2f nextPosition, char id);
/**
 * Operational_combine::processCells() - �����, �������������� �������������� ����� �������� � �������, ��������� ������� Cell::processCell()
 * @brief ��������� ��������������
 * @see Cell::processCell()
*/
	void processCells();
/**
 * Operational_combine::cellFromId() - �����, ������������ ������ � ������������ ID
 * @param id - ID ������
 * @return ������
 * @brief ��������� ������
*/
	Cell* cellFromId(const char& id);
/**
 * Operational_combine::getCellsColor() - �����, ������������ ���������� ������ ������ ������
 * @return ������ ������
 * @brief �������� ������
*/
	sf::Color* getCellsColor();
private:
	sf::Vector2u matrixSize_;
	sf::Vector2u tileSize_;
	Cell_matrix cellMatrix_;
};