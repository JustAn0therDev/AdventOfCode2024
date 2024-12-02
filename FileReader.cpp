#include "FileReader.h"

std::vector<std::string> FileReader::getInputFileLines(const char* fileName)
{
    std::vector<std::string> linesInFile;
    std::ifstream inputFile(fileName);

    for (std::string line; std::getline(inputFile, line); )
    {
        linesInFile.emplace_back(line);
    }

    return linesInFile;
}