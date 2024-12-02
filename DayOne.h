#include <string>
#include <vector>

#pragma once
class DayOne
{
private:
	std::vector<std::string> linesFromInputFile;
	void LoadLeftAndRightLists(std::vector<int>& leftList, std::vector<int>& rightList);

public:
	void LoadLinesFromFile();
	unsigned long long SolvePartOne();
	unsigned long long SolvePartTwo();
};

