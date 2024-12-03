#pragma once
#include <vector>
#include <string>
#include "BaseDay.h"

class DayThree : public BaseDay
{
public:
	virtual void LoadLinesFromFile();
	virtual unsigned long long SolvePartOne();
	virtual unsigned long long SolvePartTwo();
};

