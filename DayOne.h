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
	virtual void LoadLinesFromFile();
	virtual unsigned long long SolvePartOne();
	virtual unsigned long long SolvePartTwo();
};

