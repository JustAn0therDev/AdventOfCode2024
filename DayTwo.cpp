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

	for (size_t i = 0; i < reports.size(); i++)
	{
		if (IsReportValid(reports[i])) ++safeReports;
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

	for (size_t j = 0; j < currentReport.size() - 1; j++)
	{
		if (ascending)
		{
			if (currentReport[j] >= currentReport[j + 1])
			{
				return false;
			}

			int diff = currentReport[j + 1] - currentReport[j];

			if (diff < 1 || diff > 3)
			{
				return false;
			}
		}
		else
		{
			if (currentReport[j] <= currentReport[j + 1])
			{
				return false;
			}

			int diff = currentReport[j] - currentReport[j + 1];

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

	for (size_t i = 0; i < reports.size(); i++)
	{
		bool reportIsValid = IsReportValid(reports[i]);
		bool reportValidWithProblemDampener = IsReportValidWithProblemDampener(reports[i]);

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
	}

	return false;
}
