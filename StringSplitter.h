#pragma once
#include <vector>
#include <string>

class StringSplitter
{
public:
    static std::vector<std::string> Split(const std::string& constInputString, const std::string& delimiter) 
    {
        std::string inputString = constInputString;
        std::vector<std::string> tokens;
        size_t pos = 0;
        std::string token;

        while ((pos = inputString.find(delimiter)) != std::string::npos)
        {
            token = inputString.substr(0, pos);
            tokens.push_back(token);
            inputString.erase(0, pos + delimiter.length());
        }

        tokens.push_back(inputString);

        return tokens;
    }
};

