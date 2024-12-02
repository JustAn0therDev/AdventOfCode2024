#include "DayOne.h"
#include "FileReader.h"
#include <cassert>
#include <algorithm>

void DayOne::LoadLinesFromFile()
{
	this->linesFromInputFile = FileReader::GetInputFileLines("input_day_one.txt");
    assert(this->linesFromInputFile.size() > 0);
}

unsigned long long DayOne::SolvePartOne()
{
    std::vector<int> leftList;
    std::vector<int> rightList;

    leftList.reserve(this->linesFromInputFile.size());
    rightList.reserve(this->linesFromInputFile.size());

    LoadLeftAndRightLists(leftList, rightList);

    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    unsigned long long result = 0;

    for (int i = 0; i < leftList.size(); i++)
    {
        result += static_cast<unsigned long long>(std::abs(leftList[i] - rightList[i]));
    }

    return result;
}

unsigned long long DayOne::SolvePartTwo()
{
    std::vector<int> leftList;
    std::vector<int> rightList;

    leftList.reserve(this->linesFromInputFile.size());
    rightList.reserve(this->linesFromInputFile.size());

    this->LoadLeftAndRightLists(leftList, rightList);

    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    unsigned long long result = 0;

    for (int i = 0; i < leftList.size(); i++)
    {
        int numberOfTimesItAppearedInTheList = 0;

        // NOTES: This is unoptimized at best.
        // We could asside from having them sorted, use a hashmap
        // or a list of structs (with number and seen times) to check
        // whether that single number has already been checked.
        // It would save us some work per iteration each time it goes to check for the next one.
        for (int j = 0; j < rightList.size(); j++)
        {
            if (leftList[i] < rightList[j])
                break;

            if (leftList[i] == rightList[j])
                numberOfTimesItAppearedInTheList++;
        }

        result += static_cast<unsigned long long>(leftList[i] * numberOfTimesItAppearedInTheList);
    }

    return result;
}

void DayOne::LoadLeftAndRightLists(std::vector<int>& leftList, std::vector<int>& rightList)
{
    for (std::string line : this->linesFromInputFile)
    {
        char* lineContent = (char*)calloc(line.size() + 1, 1);

        assert(lineContent != 0);

        memcpy(lineContent, line.c_str(), line.size());
        char* token = strtok(lineContent, "   ");

        leftList.emplace_back(std::stoi(token));

        token = strtok(0, "   ");

        rightList.emplace_back(std::stoi(token));

        free(lineContent);
    }
}