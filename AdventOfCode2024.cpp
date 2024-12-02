#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include "DayOne.h"

int main()
{
	DayOne dayOne;
	dayOne.LoadLinesFromFile();
	std::cout << dayOne.SolvePartOne() << std::endl;
	std::cout << dayOne.SolvePartTwo() << std::endl;
}