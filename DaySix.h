#pragma once
#include "BaseDay.h"

class DaySix : public BaseDay
{
public:
	unsigned long long SolvePartOne() override;
	unsigned long long PredictGuardsMovement(std::vector<std::string>& guardMap, int row, int column);
	unsigned long long SolvePartTwo() override;
	void LoadLinesFromFile() override;
};

