#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include "BaseDay.h"
#include "DaySix.h"

int main()
{
	DaySix day = DaySix();
	day.LoadLinesFromFile();
	std::cout << day.SolvePartOne() << std::endl;
	//std::cout << day.SolvePartTwo() << std::endl;
}