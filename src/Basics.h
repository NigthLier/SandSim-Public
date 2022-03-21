#pragma once
#include <SFML/Graphics.hpp>

/**
* @file Basics.h
* ����, ���������� ���������� �������, ���������� �� ������� �������������� ������
* @brief ������� ������ ������
* @see Basics.cpp
* @author ������� �������
*/

/**
 * getPath() - �������, �������������� ������ ���� ����� ����� �������
 * @param previousPosition - ������ �����
 * @param nextPosition - ������ �����
 * @return ����� �����
 * @brief ���� ����� �������
 */
std::vector<sf::Vector2f> getPath(const sf::Vector2f& previousPosition, const sf::Vector2f& nextPosition);

/**
 * Cell - ������� ����� ������, ������������ � �������� ������ ��� ��������� ������� ������\n
 * ������ ���������: �����������
 * @brief ������� ������
 */
class Cell
{
public:
	Cell() = default;
/**
 * Cell::getCellId() - �������, ������������ ID ������
 * @return ID ������ ������
 * @brief ID ������
*/
	char& getCellId() { return id_; };
/**
 * Cell::getCellColor() - �������, ������������ ���� ������
 * @return ���� ������ ������
 * @brief ���� ������
*/
	sf::Color& getCellColor() { return color_; };
/**
 * Cell::processCell() - �������, ������������ ��������� ������� ������, ��� ����������
 * @param cells - ������� ������
 * @param position - ���������� ������
 * @param matrixSize - ������ �������
 * @brief ��������� ������
*/
	virtual void processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize) {};
protected:
	char id_ = 0;
	sf::Color color_ = sf::Color::Black;
 };

/**
 * Loose_cell - ����� ������ ������������ � �������� ������ ��� ������, ������������ ������� ��������\n
 * ������ ���������: ������ ����� ���� ������������ ����, ��������� ��������� ������� ������� �������
 * @brief ������� ������
 */
class Loose_cell : public Cell
{
public:
	Loose_cell() = default;
/**
 * Loose_cell::processCell() - �������, ���������������� ��������� ��� ������� ������� �������
 * @param cells - ������� ������
 * @param position - ���������� ������
 * @param matrixSize - ������ �������
 * @brief ��������� ������� �������
*/
	virtual void processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize) override;
};

/**
 * Liquid_cell - ����� ������ ������������ � �������� ������ ��� ������, ������������ ������ ��������\n
 * ������ ���������: ������ ����� ���� ������������ ���� � � �������, ��������� ��������� ���������
 * @brief ������ ������
 */
class Liquid_cell : public Cell
{
public:
	Liquid_cell() = default;
/**
 * Liquid_cell::processCell() - �������, ���������������� ��������� ��� ������ �������
 * @param cells - ������� ������
 * @param position - ���������� ������
 * @param matrixSize - ������ �������
 * @brief ��������� ���������
*/
	virtual void processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize) override;
};

/**
 * Gas_cell - ����� ������ ������������ � �������� ������ ��� ������, ������������ ������������ ��������\n
 * ������ ���������: ������ ����� ���� ������������ ����� � � �������, ��������� ��������� �����
 * @brief ������������ ������
 */
class Gas_cell : public Cell
{
public:
	Gas_cell() = default;
/**
 * Gas_cell::processCell() - �������, ���������������� ��������� ��� ������������ �������
 * @param cells - ������� ������
 * @param position - ���������� ������
 * @param matrixSize - ������ �������
 * @brief ��������� �����
*/
	virtual void processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize) override;
};