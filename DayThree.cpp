#include "DayThree.h"
#include "FileReader.h"
#include <cassert>
#include <regex>
#include <iostream>

static constexpr const char* DO_CONST = "do()";
static constexpr const char* DONT_CONST = "don't()";

void DayThree::LoadLinesFromFile()
{
    this->linesFromInputFile = FileReader::GetInputFileLines("input_day_three.txt");
    assert(this->linesFromInputFile.size() > 0);
}

unsigned long long DayThree::SolvePartOne()
{
    unsigned long long result = 0;
    
    const std::basic_regex<char> mulRegex = std::basic_regex<char>("mul\\(\\d{1,3},\\d{1,3}\\)");

    for (std::string& corruptMemory : this->linesFromInputFile)
    {
        std::smatch match;

        std::string::const_iterator searchStart(corruptMemory.cbegin());
        
        while (std::regex_search(searchStart, corruptMemory.cend(), match, mulRegex))
        {
            result += GetResultFromCurrentMult(match);
            searchStart = match.suffix().first;
        }
    }

    return result;
}

unsigned long long DayThree::GetResultFromCurrentMult(std::smatch& match)
{
    const std::string foundMult = match[0];

    const std::basic_regex<char> numberRegex = std::basic_regex<char>("\\d{1,3}");

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

    return static_cast<unsigned long long>(firstNumber * secondNumber);
}

unsigned long long DayThree::SolvePartTwo()
{
    unsigned long long result = 0;
    bool isMulEnabled = true;

    const std::basic_regex<char> mulDontAndDoRegex = std::basic_regex<char>("mul\\(\\d{1,3},\\d{1,3}\\)|don't\\(\\)|do\\(\\)");

    for (std::string& corruptMemory : this->linesFromInputFile)
    {
        std::smatch match;

        std::string::const_iterator searchStart(corruptMemory.cbegin());

        while (std::regex_search(searchStart, corruptMemory.cend(), match, mulDontAndDoRegex))
        {
            const bool matchesDont = match[0] == DONT_CONST;
            const bool matchesDo = match[0] == DO_CONST;

            if (matchesDont)
            {
                isMulEnabled = false;
            }
            else if (matchesDo)
            {
                isMulEnabled = true;
            }
            else if (isMulEnabled && !matchesDont && !matchesDo)
            {
                result += GetResultFromCurrentMult(match);
            }

            searchStart = match.suffix().first;
        }
    }

    return result;
}
