#include <string>
#include <vector>
#include "BaseDay.h"

#pragma once
class DayOne : public BaseDay
{
private:
	std::vector<std::string> linesFromInputFile;
	void LoadLeftAndRightLists(std::vector<int>& leftList, std::vector<int>& rightList);

public:
	void LoadLinesFromFile() override;
	unsigned long long SolvePartOne() override;
	unsigned long long SolvePartTwo() override;
};

