#include "BaseDay.h"

#pragma once
class DayTwo : public BaseDay
{
private:
	std::vector<std::vector<int>> GetReportsFromFileLines();
	bool IsUnsafeEventWithTheProblemDampener(const std::vector<int>& report, int index);
	bool IsUnsafeAnyway(int unsafeLevels);

public:
	virtual void LoadLinesFromFile();
	virtual unsigned long long SolvePartOne();
	bool IsReportValid(const std::vector<int>& currentReport);
	bool IsReportValidWithProblemDampener(const std::vector<int>& report);
	virtual unsigned long long SolvePartTwo();
};

