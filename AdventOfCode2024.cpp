#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include "DayThree.h"
#include "BaseDay.h"

int main()
{
	DayThree day = DayThree();
	day.LoadLinesFromFile();
	//std::cout << day.SolvePartOne() << std::endl;
	std::cout << day.SolvePartTwo() << std::endl;
}