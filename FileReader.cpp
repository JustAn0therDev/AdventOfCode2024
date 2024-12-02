#include "FileReader.h"
#include "assert.h"

std::vector<std::string> FileReader::GetInputFileLines(const char* fileName)
{
    std::vector<std::string> linesInFile;
    std::ifstream inputFile(fileName);

    assert(inputFile.is_open());

    for (std::string line; std::getline(inputFile, line); )
    {
        linesInFile.emplace_back(line);
    }

    return linesInFile;
}