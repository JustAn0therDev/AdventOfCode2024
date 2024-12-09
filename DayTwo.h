#include "BaseDay.h"

#pragma once
class DayTwo : public BaseDay
{
private:
	std::vector<std::vector<int>> GetReportsFromFileLines();
	bool IsReportValid(const std::vector<int>& currentReport);
	bool IsReportValidWithProblemDampener(const std::vector<int>& report);
	bool IsUnsafeAnyway(int unsafeLevels);

public:
	void LoadLinesFromFile() override;
	unsigned long long SolvePartOne() override;
	unsigned long long SolvePartTwo() override;
};

