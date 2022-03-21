#include "Operations.h"
#include "Cells.h"

/**
* @file Operations.cpp
* Файл, содержащий определение функций из файла Operations.h
* @brief Обработка взаимодействий
* @see Operations.h
* @author Спектор Евгений
*/

Cell_matrix::Cell_matrix(ptrdiff_t n_col, ptrdiff_t  n_row)
{
	if (n_row <= 0 || n_col <= 0) { throw std::logic_error("Negative size Matrix(rowCount, colCount"); }
	n_row_ = n_row;
	n_col_ = n_col;
	data_.resize(n_row * n_col, char());
	for(auto id : data_)
		id = 0;
}

char& Cell_matrix::at(std::ptrdiff_t i_row, std::ptrdiff_t i_col)
{
	if (i_row >= rowCount() || i_col >= colCount() || i_row < 0 || i_col < 0) { throw std::out_of_range("Matrix::at"); }
	return data_[i_row * colCount() + i_col];
}

char Cell_matrix::at(std::ptrdiff_t i_row, std::ptrdiff_t i_col) const
{
	if (i_row >= rowCount() || i_col >= colCount() || i_row < 0 || i_col < 0) { throw std::out_of_range("Matrix::at"); }
	return data_[i_row * colCount() + i_col];
}



Cell* Operational_combine::cellFromId(const char& id)
{
	switch (id)
	{
	case 0:
	{
		Cell_air temp;
		return &temp;
		break;
	}
	case 1:
		{
			Cell_concrete temp;
			return &temp;
			break;
		}	
	case 2:
	{
		Cell_sand temp;
		return &temp;
		break;
	}
	case 3:
	{
		Cell_water temp;
		return &temp;
		break;
	}
	case 4:
	{
		Cell_gas temp;
		return &temp;
		break;
	}
	default:
		{
			Cell_error temp;
			return &temp;
			break;
		}	
	}
}

void Operational_combine::addCells(sf::Vector2f& previousPosition, sf::Vector2f nextPosition, char id)
{
	if(previousPosition.x / tileSize_.x >= 0 && previousPosition.x / tileSize_.x < matrixSize_.x && previousPosition.y / tileSize_.y >= 0 && previousPosition.y / tileSize_.y < matrixSize_.y)
		for (auto position : getPath(previousPosition, nextPosition))
			if(position.x > 0 && position.x < tileSize_.x * matrixSize_.x && position.y > 0 && position.y < tileSize_.y * matrixSize_.y)
				if((cellMatrix_.getData())[size_t(position.x / tileSize_.x) + size_t(position.y / tileSize_.y) * matrixSize_.x] == 0 || id == 0)
					(cellMatrix_.getData())[size_t(position.x / tileSize_.x) + size_t(position.y / tileSize_.y) * matrixSize_.x] = id;
}

void Operational_combine::processCells()
{
	for (int i = matrixSize_.y - 1; i >=0; i--)
		for (size_t j = 0; j < matrixSize_.x; j++)
			if (cellMatrix_.at(i, j) != 4)
				(*cellFromId(cellMatrix_.at(i, j))).processCell(cellMatrix_.getData(), sf::Vector2u((unsigned int)j, (unsigned int)i), matrixSize_);

	for (size_t i = 0; i < matrixSize_.y; i++)
		for (size_t j = 0; j < matrixSize_.x; j++)
			if(cellMatrix_.at(i, j) == 4)
				(*cellFromId(cellMatrix_.at(i, j))).processCell(cellMatrix_.getData(), sf::Vector2u((unsigned int)j, (unsigned int)i), matrixSize_);
}

sf::Color* Operational_combine::getCellsColor()
{
	sf::Color* colors = new sf::Color[(size_t)matrixSize_.x * matrixSize_.y];

	for (size_t i = 0; i < matrixSize_.y; i++)
		for (size_t j = 0; j < matrixSize_.x; j++)
			colors[i * matrixSize_.x + j] = cellFromId(cellMatrix_.at(i, j))->getCellColor();

	return colors;
}