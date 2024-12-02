#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<std::string> getInputFileContent()
{
    std::vector<std::string> lines_in_file;
    std::ifstream input_file("input.txt");

    for (std::string line; std::getline(input_file, line); )
    {
        lines_in_file.emplace_back(line);
    }

    return lines_in_file;
}

int main()
{
    std::vector<std::string> linesInFile = getInputFileContent();

    std::vector<int> leftList;
    std::vector<int> rightList;

    leftList.reserve(linesInFile.size());
    leftList.reserve(linesInFile.size());

    for (std::string line : linesInFile)
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

    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    unsigned long long result = 0;
    
    // The first part requires us to get the smaller numbers from both lists and sum their differences.
    // The second part requires us to get the amount of times a number from the left list appears in the right list.

    // This mess of a code will be refactored.

    for (int i = 0; i < leftList.size(); i++)
    {
        int numberOfTimesItAppearedInTheList = 0;

        for (int j = 0; j < rightList.size(); j++)
        {
            if (leftList[i] == rightList[j])
                numberOfTimesItAppearedInTheList++;
        }

        result += static_cast<unsigned long long>(leftList[i] * numberOfTimesItAppearedInTheList);
    }

    std::cout << result << std::endl;
}