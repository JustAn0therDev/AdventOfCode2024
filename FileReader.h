#include <vector>
#include <string>
#include <fstream>

#pragma once
class FileReader
{
public:
	static std::vector<std::string> getInputFileLines(const char* fileName);
};

