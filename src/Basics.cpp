#include "Basics.h"

/**
* @file Basics.cpp
* Файл, содержащий определение функций из файла Basics.h
* @brief Базовые классы клеток
* @see Basics.h
* @author Спектор Евгений
*/

std::vector<sf::Vector2f> getPath(const sf::Vector2f& previousPosition, const sf::Vector2f& nextPosition)
{
	std::vector<sf::Vector2f> path;

	if (previousPosition == nextPosition)
	{
		path.push_back(nextPosition);
		return path;
	}

	int x1 = (int)previousPosition.x, y1 = (int)previousPosition.y;
	int x2 = (int)nextPosition.x, y2 = (int)nextPosition.y;

	int deltaX = x1 - x2, modifierX = (deltaX < 0) ? (1) : (-1);
	int deltaY = y1 - y2, modifierY = (deltaY < 0) ? (1) : (-1);

	int longSideLength = abs(deltaX), shortSideLength = abs(deltaY);
	bool isXLongSide = longSideLength > shortSideLength;

	if (!isXLongSide)
		std::swap(longSideLength, shortSideLength);

	float tilt = (shortSideLength == 0 || longSideLength == 0) ? (0) : ((float)(shortSideLength + 1) / (longSideLength + 1));

	for (int i = 1, iX, iY; i <= longSideLength; i++)
	{
		iX = i;
		iY = (int)round(i * tilt);
		if (!isXLongSide)
			std::swap(iX, iY);
		path.push_back(sf::Vector2f((float)(x1 + (iX * modifierX)), (float)(y1 + (iY * modifierY))));
	}

	return path;
}


void Loose_cell::processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize)
{
	size_t pos = position.x + (size_t)position.y * matrixSize.x;
	bool f = true;

	if (position.y + 1 >= 0 && position.y + 1 < matrixSize.y && f)
	{
		if ((cells[pos + matrixSize.x] == 3 || cells[pos + matrixSize.x] == 4 || cells[pos + matrixSize.x] == 0) && f)
		{
			std::swap(cells[pos], cells[pos + matrixSize.x]);

			if (position.x + 1 >= 0 && position.x + 1 < matrixSize.x && f)
				if (cells[pos + 1] == 4 || cells[pos + 1] == 0)
				{
					std::swap(cells[pos], cells[pos + 1]);
					f = false;
				}

			if (position.x - 1 >= 0 && position.x - 1 < matrixSize.x && f)
				if (cells[pos - 1] == 4 || cells[pos - 1] == 0)
				{
					std::swap(cells[pos], cells[pos - 1]);
					f = false;
				}
			position.y++;
			f = false;
		}

		if (position.x + 1 >= 0 && position.x + 1 < matrixSize.x && f)
			if ((cells[pos + matrixSize.x + 1] == 3 || cells[pos + matrixSize.x + 1] == 4 || cells[pos + matrixSize.x + 1] == 0) && ((cells[pos + 1] == 3 || cells[pos + 1] == 4 || cells[pos + 1] == 0) || (cells[pos + 1] == 1 && cells[pos + matrixSize.x] != 1)))
			{
				std::swap(cells[pos], cells[pos + matrixSize.x + 1]);
				position.x++;
				position.y++;
				f = false;
			}

		if(position.x - 1 >= 0 && position.x - 1 < matrixSize.x && f)
			if((cells[pos + matrixSize.x - 1] == 3 || cells[pos + matrixSize.x - 1] == 4 || cells[pos + matrixSize.x - 1] == 0) && ((cells[pos - 1] == 3 || cells[pos - 1] == 4 || cells[pos - 1] == 0) || (cells[pos - 1] == 1 && cells[pos + matrixSize.x] != 1)))
			{
				std::swap(cells[pos], cells[pos + matrixSize.x - 1]);
				position.x--;
				position.y++;
				f = false;
			}
	}
}

void Liquid_cell::processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize)
{
	size_t pos = position.x + (size_t)position.y * matrixSize.x;
	bool f = true;

	if (position.y + 1 >= 0 && position.y + 1 < matrixSize.y && f)
	{
		if ((cells[pos + matrixSize.x] == 4 || cells[pos + matrixSize.x] == 0) && f)
		{
			std::swap(cells[pos], cells[pos + matrixSize.x]);

			if (position.x + 1 >= 0 && position.x + 1 < matrixSize.x && f)
				if (cells[pos + 1] == 0)
				{
					std::swap(cells[pos], cells[pos + 1]);
					f = false;
				}

			if (position.x - 1 >= 0 && position.x - 1 < matrixSize.x && f)
				if (cells[pos - 1] == 0)
				{
					std::swap(cells[pos], cells[pos - 1]);
					f = false;
				}

			position.y++;
			f = false;
		}

		if (position.x + 1 >= 0 && position.x + 1 < matrixSize.x && f)
			if ((cells[pos + matrixSize.x + 1] == 4 || cells[pos + matrixSize.x + 1] == 0) && ((cells[pos + 1] == 4 || cells[pos + 1] == 0) || (cells[pos + 1] == 1 && cells[pos + matrixSize.x] != 1)))
			{
				std::swap(cells[pos], cells[pos + matrixSize.x + 1]);
				position.x++;
				position.y++;
				f = false;
			}

		if (position.x - 1 >= 0 && position.x - 1 < matrixSize.x && f)
			if ((cells[pos + matrixSize.x - 1] == 4 || cells[pos + matrixSize.x - 1] == 0) && ((cells[pos - 1] == 4 || cells[pos - 1] == 0) || (cells[pos - 1] == 1 && cells[pos + matrixSize.x] != 1)))
			{
				position.x--;
				position.y++;
				std::swap(cells[pos], cells[pos + matrixSize.x - 1]);
				f = false;
			}
	}

	if (position.x + 1 >= 0 && position.x + 1 < matrixSize.x && f)
		if (cells[pos + 1] == 4 || cells[pos + 1] == 0)
		{
			std::swap(cells[pos], cells[pos + 1]);
			position.x++;
			f = false;
		}

	if (position.x - 1 >= 0 && position.x - 1 < matrixSize.x && f)
		if (cells[pos - 1] == 4 || cells[pos - 1] == 0)
		{
			std::swap(cells[pos], cells[pos - 1]);
			position.x--;
			f = false;
		}
}

void Gas_cell::processCell(std::vector<char>& cells, sf::Vector2u position, sf::Vector2u& matrixSize)
{
	size_t pos = position.x + (size_t)position.y * matrixSize.x;
	bool f = true;

	if (position.y - 1 >= 0 && position.y - 1 < matrixSize.y && f)
	{

		if (cells[pos - matrixSize.x] == 0 && f)
		{
			std::swap(cells[pos], cells[pos - matrixSize.x]);
			position.y--;
			f = false;
		}


		if (position.x + 1 >= 0 && position.x + 1 < matrixSize.x && f)
			if (cells[pos - matrixSize.x + 1] == 0  && ((cells[pos + 1] == 0) || (cells[pos + 1] == 1 && cells[pos - matrixSize.x] != 1)))
			{
				std::swap(cells[pos], cells[pos - matrixSize.x + 1]);
				position.x++;
				position.y--;
				f = false;
			}

		if (position.x - 1 >= 0 && position.x - 1 < matrixSize.x && f)
			if (cells[pos - matrixSize.x - 1] == 0 && ((cells[pos - 1] == 0) || (cells[pos- 1] == 1 && cells[pos - matrixSize.x] != 1)))
			{
				std::swap(cells[pos], cells[pos - matrixSize.x - 1]);
				position.x--;
				position.y--;
				f = false;
			}
	}

	if (position.x + 1 >= 0 && position.x + 1 < matrixSize.x && f)
		if (cells[pos + 1] == 0)
		{
			std::swap(cells[pos], cells[pos + 1]);
			position.x++;
			f = false;
		}

	if (position.x - 1 >= 0 && position.x - 1 < matrixSize.x && f)
		if (cells[pos - 1] == 0)
		{
			std::swap(cells[pos], cells[pos - 1]);
			position.x--;
			f = false;
		}
}