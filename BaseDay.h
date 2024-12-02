#pragma once
#include <vector>
#include <string>

class BaseDay
{
protected:
	std::vector<std::string> linesFromInputFile;

public:
	virtual void LoadLinesFromFile() {};
	virtual unsigned long long SolvePartOne() { return 0; };
	virtual unsigned long long SolvePartTwo() { return 0; };
};

