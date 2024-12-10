#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include "BaseDay.h"
#include "DayFive.h"

int main()
{
	DayFive day = DayFive();
	day.LoadLinesFromFile();
	//std::cout << day.SolvePartOne() << std::endl;
	std::cout << day.SolvePartTwo() << std::endl;
}