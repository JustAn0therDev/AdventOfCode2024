#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include "DayFour.h"
#include "BaseDay.h"

int main()
{
	DayFour day = DayFour();
	day.LoadLinesFromFile();
	std::cout << day.SolvePartOne() << std::endl;
	//std::cout << day.SolvePartTwo() << std::endl;
}