#include "DayTwo.h"
#include <vector>
#include <string>
#include "FileReader.h"
#include "StringSplitter.h"
#include <iostream>

void DayTwo::LoadLinesFromFile()
{
	this->linesFromInputFile = FileReader::GetInputFileLines("input_day_two.txt");
}

unsigned long long DayTwo::SolvePartOne()
{
	unsigned long long safeReports = 0;

	std::vector<std::vector<int>> reports = GetReportsFromFileLines();

	for (const std::vector<int>& report : reports)
	{
		if (IsReportValid(report)) ++safeReports;
	}

	return safeReports;
}

bool DayTwo::IsReportValid(const std::vector<int>& currentReport)
{
	bool ascending = true;

	if (currentReport[0] > currentReport[1])
	{
		ascending = false;
	}

	for (size_t i = 0; i < currentReport.size() - 1; i++)
	{
		if (ascending)
		{
			if (currentReport[i] >= currentReport[i + 1])
			{
				return false;
			}

			int diff = currentReport[i + 1] - currentReport[i];

			if (diff < 1 || diff > 3)
			{
				return false;
			}
		}
		else
		{
			if (currentReport[i] <= currentReport[i + 1])
			{
				return false;
			}

			int diff = currentReport[i] - currentReport[i + 1];

			if (diff < 1 || diff > 3)
			{
				return false;
			}
		}
	}

	return true;
}

unsigned long long DayTwo::SolvePartTwo()
{
	unsigned long long safeReports = 0;

	std::vector<std::vector<int>> reports = GetReportsFromFileLines();

	for (const std::vector<int>& report : reports)
	{
		bool reportIsValid = IsReportValid(report);
		bool reportValidWithProblemDampener = IsReportValidWithProblemDampener(report);

		if (reportIsValid || reportValidWithProblemDampener)
		{
			++safeReports;
		}
	}

	return safeReports;
}

std::vector<std::vector<int>> DayTwo::GetReportsFromFileLines()
{
	std::vector<std::vector<int>> reports;

	reports.reserve(this->linesFromInputFile.size());

	for (size_t i = 0; i < this->linesFromInputFile.size(); i++)
	{
		reports.emplace_back(std::vector<int>());

		const auto& line = this->linesFromInputFile[i];

		std::vector<std::string> splitLine = StringSplitter::Split(line, " ");

		reports[i].reserve(splitLine.size());

		for (const auto& numberInStringFormat : splitLine)
		{
			reports[i].emplace_back(std::stoi(numberInStringFormat));
		}
	}

	return reports;
}

bool DayTwo::IsReportValidWithProblemDampener(const std::vector<int>& currentReport)
{
	int unsafeLevelsFound = 0;

	for (size_t i = 0; i < currentReport.size(); ++i)
	{
		std::vector<int> reportCopy = currentReport;

		reportCopy.erase(reportCopy.begin() + i);

		bool valid = true;
		bool ascending = true;

		if (reportCopy[0] > reportCopy[1])
		{
			ascending = false;
		}

		for (size_t j = 0; j < reportCopy.size() - 1; j++)
		{
			if (ascending)
			{
				if (reportCopy[j] >= reportCopy[j + 1])
				{
					valid = false;
					break;
				}

				int diff = reportCopy[j + 1] - reportCopy[j];

				if (diff < 1 || diff > 3)
				{
					valid = false;
					break;
				}
			}
			else
			{
				if (reportCopy[j] <= reportCopy[j + 1])
				{
					valid = false;
					break;
				}

				int diff = reportCopy[j] - reportCopy[j + 1];

				if (diff < 1 || diff > 3)
				{
					valid = false;
					break;
				}
			}
		}

		if (valid)
			return true;

		if (IsUnsafeAnyway(unsafeLevelsFound))
		{
			return false;
		}
	}

	return false;
}

bool DayTwo::IsUnsafeAnyway(int unsafeLevels)
{
	return unsafeLevels >= 2;
}
