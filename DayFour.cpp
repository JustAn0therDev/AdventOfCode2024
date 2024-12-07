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

	for (size_t i = 0; i < this->linesFromInputFile.size(); i++)
	{
		for (size_t j = 0; j < this->linesFromInputFile[i].size(); j++)
		{
			if (this->linesFromInputFile[i][j] == 'X')
			{
				count += HasXmasToTheRight(i, j);
				count += HasXmasToTheLeft(i, j);
				count += HasXmasUpperRight(i, j);
				count += HasXmasUpperLeft(i, j);
				count += HasXmasDownRight(i, j);
				count += HasXmasDownLeft(i, j);
				count += HasXmasStraightDown(i, j);
				count += HasXmasStraightUp(i, j);
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
	unsigned long long count = 0;

	for (size_t i = 0; i < this->linesFromInputFile.size(); i++)
	{
		for (size_t j = 0; j < this->linesFromInputFile[i].size(); j++)
		{
			if (this->linesFromInputFile[i][j] == 'A')
			{
				char upperRightChar = CharOnUpperRight(i, j);
				char downLeftCharShouldBe = '\0';

				if (upperRightChar == 'M')
				{
					downLeftCharShouldBe = 'S';
				}
				else if (upperRightChar == 'S')
				{
					downLeftCharShouldBe = 'M';
				}
				else
				{
					continue;
				}

				char downLeftChar = CharOnDownLeft(i, j);

				if (downLeftChar != downLeftCharShouldBe)
				{
					continue;
				}

				char upperLeftChar = CharOnUpperLeft(i, j);
				char downRightCharShouldBe = '\0';

				if (upperLeftChar == 'M')
				{
					downRightCharShouldBe = 'S';
				}
				else if (upperLeftChar == 'S')
				{
					downRightCharShouldBe = 'M';
				}
				else
				{
					continue;
				}

				char downRightChar = CharOnDownRight(i, j);

				if (downRightChar != downRightCharShouldBe)
				{
					continue;
				}

				count++;
			}
		}
	}

	return count;
}

char DayFour::CharOnUpperRight(int row, int column)
{
	if (--row > -1 && ++column < this->linesFromInputFile[row].size())
	{
		return this->linesFromInputFile[row][column];
	}

	return '\0';
}

char DayFour::CharOnUpperLeft(int row, int column)
{
	if (--row > -1 && --column > -1)
	{
		return this->linesFromInputFile[row][column];
	}

	return '\0';
}

char DayFour::CharOnDownRight(int row, int column)
{
	if (++row < this->linesFromInputFile.size() && ++column < this->linesFromInputFile[row].size())
	{
		return this->linesFromInputFile[row][column];
	}

	return '\0';
}

char DayFour::CharOnDownLeft(int row, int column)
{
	if (++row < this->linesFromInputFile.size() && --column > -1)
	{
		return this->linesFromInputFile[row][column];
	}

	return '\0';
}