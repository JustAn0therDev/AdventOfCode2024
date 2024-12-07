#pragma once
#include "BaseDay.h"
#include <vector>
#include <string>

class DayFour : public BaseDay
{
public:
	virtual void LoadLinesFromFile();
	virtual unsigned long long SolvePartOne();
	virtual unsigned long long SolvePartTwo();
	int HasXmasToTheRight(int row, int column);
	int HasXmasToTheLeft(int row, int column);
	int HasXmasUpperRight(int row, int column);
	int HasXmasUpperLeft(int row, int column);
	int HasXmasDownRight(int row, int column);
	int HasXmasDownLeft(int row, int column);
	int HasXmasStraightDown(int row, int column);
	int HasXmasStraightUp(int row, int column);
	char CharOnUpperRight(int row, int column);
	char CharOnUpperLeft(int row, int column);
	char CharOnDownRight(int row, int column);
	char CharOnDownLeft(int row, int column);
};

