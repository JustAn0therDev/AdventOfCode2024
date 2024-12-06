#include "DayFour.h"
#include "FileReader.h"
#include <iostream>

static constexpr const const char* XMAS = "XMAS";
constexpr int XMAS_SIZE = 4;

void DayFour::LoadLinesFromFile()
{
	this->linesFromInputFile = FileReader::GetInputFileLines("input_day_four.txt");
}

unsigned long long DayFour::SolvePartOne()
{
	unsigned long long count = 0;

	unsigned long long currentXmasIndex = 0;

	for (size_t i = 0; i < this->linesFromInputFile.size(); i++)
	{
		for (size_t j = 0; j < this->linesFromInputFile[i].size(); j++)
		{
			if (this->linesFromInputFile[i][j] == 'X')
			{
				int right = HasXmasToTheRight(i, j);
				int left = HasXmasToTheLeft(i, j);
				int upperRight = HasXmasUpperRight(i, j);
				int upperLeft = HasXmasUpperLeft(i, j);
				int downRight = HasXmasDownRight(i, j);
				int downLeft = HasXmasDownLeft(i, j);
				int straightDown = HasXmasStraightDown(i, j);
				int straightUp = HasXmasStraightUp(i, j);

				//if (right)
				//{
				//	std::cout << "Found XMAS to the right. Indexes: " << i << ", " << j << std::endl;
				//}

				//if (left)
				//{
				//	std::cout << "Found XMAS to the left. Indexes: " << i << ", " << j << std::endl;
				//}

				//if (upperRight)
				//{
				//	std::cout << "Found XMAS upper right. Indexes: " << i << ", " << j << std::endl;
				//}

				//if (upperLeft)
				//{
				//	std::cout << "Found XMAS upper left. Indexes: " << i << ", " << j << std::endl;
				//}

				//if (downRight)
				//{
				//	std::cout << "Found XMAS down right. Indexes: " << i << ", " << j << std::endl;
				//}

				//if (downLeft)
				//{
				//	std::cout << "Found XMAS down left. Indexes: " << i << ", " << j << std::endl;
				//}

				//if (straightDown)
				//{
				//	std::cout << "Found XMAS straight down. Indexes: " << i << ", " << j << std::endl;
				//}

				//if (straightUp)
				//{
				//	std::cout << "Found XMAS straight up. Indexes: " << i << ", " << j << std::endl;
				//}

				count += right;
				count += left;
				count += upperLeft;
				count += upperRight;
				count += downLeft;
				count += downRight;
				count += straightUp;
				count += straightDown;
			}
		}
	}

	return count;
}

int DayFour::HasXmasToTheRight(int row, int column)
{
	int xmasIndex = 1;

	while (++column < this->linesFromInputFile[row].size())
	{
		if (xmasIndex == XMAS_SIZE)
		{
			break;
		}

		if (this->linesFromInputFile[row][column] == XMAS[xmasIndex])
		{
			++xmasIndex;
			continue;
		}
		else
		{
			return 0;
		}
	}

	if (xmasIndex == XMAS_SIZE)
	{
		return 1;
	}

	if (column == this->linesFromInputFile[row].size())
	{
		return 0;
	}

	return 1;
}

int DayFour::HasXmasToTheLeft(int row, int column)
{
	int xmasIndex = 1;

	while (--column > -1)
	{
		if (xmasIndex == XMAS_SIZE)
		{
			break;
		}

		if (this->linesFromInputFile[row][column] == XMAS[xmasIndex])
		{
			++xmasIndex;
			continue;
		}
		else
		{
			return 0;
		}
	}

	if (xmasIndex == XMAS_SIZE)
	{
		return 1;
	}

	if (column == -1)
	{
		return 0;
	}

	return 1;
}

int DayFour::HasXmasUpperRight(int row, int column)
{
	int xmasIndex = 1;

	while (--row > -1 && ++column < this->linesFromInputFile[row].size())
	{
		if (xmasIndex == XMAS_SIZE)
		{
			break;
		}

		if (this->linesFromInputFile[row][column] == XMAS[xmasIndex])
		{
			++xmasIndex;
			continue;
		}
		else
		{
			return 0;
		}
	}

	if (xmasIndex == XMAS_SIZE)
	{
		return 1;
	}

	if (row == -1 || column == this->linesFromInputFile[row].size())
	{
		return 0;
	}

	return 1;
}

int DayFour::HasXmasUpperLeft(int row, int column)
{
	int xmasIndex = 1;

	while (--row > -1 && --column > -1)
	{
		if (xmasIndex == XMAS_SIZE)
		{
			break;
		}

		if (this->linesFromInputFile[row][column] == XMAS[xmasIndex])
		{
			++xmasIndex;
			continue;
		}
		else
		{
			return 0;
		}
	}

	if (xmasIndex == XMAS_SIZE)
	{
		return 1;
	}

	if (column == -1 || row == -1)
	{
		return 0;
	}

	return 1;
}

int DayFour::HasXmasDownRight(int row, int column)
{
	int xmasIndex = 1;

	while (++column < this->linesFromInputFile[row].size() && ++row < this->linesFromInputFile.size())
	{
		if (xmasIndex == XMAS_SIZE)
		{
			break;
		}

		if (this->linesFromInputFile[row][column] == XMAS[xmasIndex])
		{
			++xmasIndex;
			continue;
		}
		else
		{
			return 0;
		}
	}

	if (xmasIndex == XMAS_SIZE)
	{
		return 1;
	}

	if (row == this->linesFromInputFile.size() || column == this->linesFromInputFile[row].size())
	{
		return 0;
	}

	return 1;
}

int DayFour::HasXmasDownLeft(int row, int column)
{
	int xmasIndex = 1;

	while (--column > -1 && ++row < this->linesFromInputFile.size())
	{
		if (xmasIndex == XMAS_SIZE)
		{
			break;
		}

		if (this->linesFromInputFile[row][column] == XMAS[xmasIndex])
		{
			++xmasIndex;
			continue;
		}
		else
		{
			return 0;
		}
	}

	if (xmasIndex == XMAS_SIZE)
	{
		return 1;
	}

	if (column == -1 || row == this->linesFromInputFile.size())
	{
		return 0;
	}

	return 1;
}

int DayFour::HasXmasStraightDown(int row, int column)
{
	int xmasIndex = 1;

	while (++row < this->linesFromInputFile.size())
	{
		if (xmasIndex == XMAS_SIZE)
		{
			break;
		}

		if (this->linesFromInputFile[row][column] == XMAS[xmasIndex])
		{
			++xmasIndex;
			continue;
		}
		else
		{
			return 0;
		}
	}

	if (xmasIndex == XMAS_SIZE)
	{
		return 1;
	}

	if (row == this->linesFromInputFile.size())
	{
		return 0;
	}

	return 1;
}

int DayFour::HasXmasStraightUp(int row, int column)
{
	int xmasIndex = 1;

	while (--row > -1)
	{
		if (xmasIndex == XMAS_SIZE)
		{
			break;
		}

		if (this->linesFromInputFile[row][column] == XMAS[xmasIndex])
		{
			++xmasIndex;
			continue;
		}
		else
		{
			return 0;
		}
	}

	if (xmasIndex == XMAS_SIZE)
	{
		return 1;
	}

	if (row == -1)
	{
		return 0;
	}

	return 1;
}

unsigned long long DayFour::SolvePartTwo()
{
	return 0;
}