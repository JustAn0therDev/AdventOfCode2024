#pragma once
#include "BaseDay.h"
#include <map>

class DayFive : public BaseDay
{
public:
	void LoadLinesFromFile() override;
	unsigned long long SolvePartOne() override;
	unsigned long long SolvePartTwo() override;
	void SetPageOrderMap(const std::string& line, std::map<int, std::vector<int>>& pageOrder);

private:
	std::string GetJoined(const std::vector<int>& collection);
};

