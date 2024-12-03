#include "DayThree.h"
#include "FileReader.h"
#include <cassert>
#include <regex>
#include <iostream>

void DayThree::LoadLinesFromFile()
{
    this->linesFromInputFile = FileReader::GetInputFileLines("input_day_three.txt");
    assert(this->linesFromInputFile.size() > 0);
}

unsigned long long DayThree::SolvePartOne()
{
    unsigned long long result = 0;

    int count = 0;

    for (std::string& corruptMemory : this->linesFromInputFile)
    {
        std::basic_regex<char> regex = std::basic_regex<char>("mul\\(\\d{1,3},\\d{1,3}\\)");

        std::smatch match;

        std::string::const_iterator searchStart(corruptMemory.cbegin());
        
        while (std::regex_search(searchStart, corruptMemory.cend(), match, regex))
        {
            count++;

            std::string foundMult = match[0];

            std::basic_regex<char> numberRegex = std::basic_regex<char>("\\d{1,3}");

            std::string::const_iterator foundMultIteratorBegin(foundMult.cbegin());

            std::smatch innerMatch;

            int firstNumber = 0, secondNumber = 0;

            if (std::regex_search(foundMultIteratorBegin, foundMult.cend(), innerMatch, numberRegex))
            {
                firstNumber = std::stoi(innerMatch.str());
                foundMultIteratorBegin = innerMatch.suffix().first;
            }

            if (std::regex_search(foundMultIteratorBegin, foundMult.cend(), innerMatch, numberRegex))
            {
                secondNumber = std::stoi(innerMatch.str());
            }

            result += static_cast<unsigned long long>(firstNumber * secondNumber);

            searchStart = match.suffix().first;
        }
    }

    std::cout << count << std::endl;

    return result;
}

unsigned long long DayThree::SolvePartTwo()
{
    return 0;
}
