#pragma once
#include <vector>
#include <string>
#include "BaseDay.h"
#include <regex>

class DayThree : public BaseDay
{
public:
	virtual void LoadLinesFromFile();
	virtual unsigned long long SolvePartOne();
	unsigned long long GetResultFromCurrentMult(std::smatch& match);
	virtual unsigned long long SolvePartTwo();
};

