#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include "DayTwo.h"
#include "BaseDay.h"

int main()
{
	DayTwo day = DayTwo();
	day.LoadLinesFromFile();
	std::cout << day.SolvePartOne() << std::endl;
	std::cout << day.SolvePartTwo() << std::endl;
}