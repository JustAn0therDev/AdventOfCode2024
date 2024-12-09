#include "DayFive.h"
#include <vector>
#include <iostream>
#include "FileReader.h"
#include "StringSplitter.h"
#include <map>
#include <string>

void DayFive::LoadLinesFromFile()
{
	this->linesFromInputFile = FileReader::GetInputFileLines("input_day_five.txt");
}

unsigned long long DayFive::SolvePartOne()
{
	unsigned long long result = 0;

	std::map<int, std::vector<int>> pageOrder;

	bool isInFirstSectionOfFile = true;

	// Separating the first part of the input
	// TODO: check if we have reached an empty line.
	for (const std::string& line : this->linesFromInputFile)
	{
		if (line.empty())
		{
			isInFirstSectionOfFile = false;
			continue;
		}

		if (isInFirstSectionOfFile)
		{
			SetPageOrderMap(line, pageOrder);
		}
		else
		{
			// Check if any of the numbers in the list of any of the maps are behind the current one

			std::vector<std::string> splitString = StringSplitter::Split(line, ",");

			bool isValidSequence = true;

			for (size_t i = 0; i < splitString.size(); i++)
			{
				if (i == 0)
					continue;

				int num = std::stoi(splitString[i]);

				for (int j = i - 1; j >= 0; j--)
				{
					int numBehind = std::stoi(splitString[j]);

					if (std::find(pageOrder[num].begin(), pageOrder[num].end(), numBehind) != pageOrder[num].end())
					{
						isValidSequence = false;
						break;
					}
				}
			}

			if (isValidSequence)
			{
				result += static_cast<unsigned long long>(std::stoi(splitString[static_cast<size_t>(floor(splitString.size() / 2))]));
			}
		}
	}

	//for (const auto& pair : pageOrder)
	//{
	//	printf("%s: %s\n", std::to_string(pair.first).c_str(), GetJoined(pair.second).c_str());
	//}

	return result;
}

void DayFive::SetPageOrderMap(const std::string& line, std::map<int, std::vector<int>>& pageOrder)
{
	std::vector<std::string> splitString = StringSplitter::Split(line, "|");

	int firstLineNumber = std::stoi(splitString[0]);
	int lastLineNumber = std::stoi(splitString[1]);

	if (pageOrder.count(firstLineNumber) > 0)
	{
		pageOrder[firstLineNumber].emplace_back(lastLineNumber);
	}
	else
	{
		pageOrder.insert(std::make_pair(firstLineNumber, std::vector<int>()));
		pageOrder[firstLineNumber].emplace_back(lastLineNumber);
	}
}

std::string DayFive::GetJoined(const std::vector<int>& collection)
{
	std::string joinedCollection;

	for (int num : collection)
	{
		joinedCollection.append(std::to_string(num));
		joinedCollection.append(" ");
	}

	return joinedCollection;
}

unsigned long long DayFive::SolvePartTwo()
{
	return 0;
}
