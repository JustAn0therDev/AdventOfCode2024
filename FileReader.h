#include <vector>
#include <string>
#include <fstream>

#pragma once
class FileReader
{
public:
	static std::vector<std::string> GetInputFileLines(const char* fileName);
};

