#pragma once
#include <vector>
#include <string>
#include "BaseDay.h"
#include <regex>

class DayThree : public BaseDay
{
public:
	void LoadLinesFromFile() override;
	unsigned long long SolvePartOne() override;
	unsigned long long GetResultFromCurrentMult(std::smatch& match);
	unsigned long long SolvePartTwo() override;
};

