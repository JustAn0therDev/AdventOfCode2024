#include "DaySix.h"
#include "FileReader.h"
#include <set>

typedef struct grid_location {
    int row;
    int column;

    bool operator<(const struct grid_location& grid_location) const noexcept
    {
        return this->row == grid_location.row && this->column == grid_location.column;
    }
} GridLocation;

unsigned long long DaySix::SolvePartOne()
{
    unsigned long long result = 0;

    std::vector<std::string> guardMap = this->linesFromInputFile;

    for (size_t i = 0; i < guardMap.size(); i++)
    {
        for (size_t j = 0; j < guardMap[i].size(); j++)
        {
            if (guardMap[i][j] == '^')
            {
                result = PredictGuardsMovement(guardMap, i, j);
            }
        }
    }

    return result;
}

unsigned long long DaySix::PredictGuardsMovement(std::vector<std::string>& guardMap, int row, int column)
{
    std::vector<GridLocation> seenPlaces;
    
    // I don't need to visit every place with a for...
    // I have to guide the guard until they go off the map.

    while (row < guardMap.size() && column < guardMap[0].size())
    {
        bool seen = false;
        for (const auto& place : seenPlaces) {
            if (place.row == row && place.column == column) {
                seen = true;
                break;
            }
        }
        if (!seen)
            seenPlaces.push_back({ row, column });

        if (guardMap[row][column] == '^')
        {
            if (row > 0)
            {
                int upperRow = row - 1;

                if (upperRow == -1)
                {
                    break;
                }

                if (guardMap[upperRow][column] == '#')
                {
                    guardMap[row][column] = '>';
                    continue;
                }
                else
                {
                    guardMap[row][column] = '.';
                    guardMap[upperRow][column] = '^';
                }
            }

            --row;
        }
        else if (guardMap[row][column] == '>')
        {
            if (column < guardMap[row].size())
            {
                int nextColumn = column + 1;

                if (nextColumn == guardMap[row].size())
                {
                    break;
                }

                if (guardMap[row][nextColumn] == '#')
                {
                    guardMap[row][column] = 'v';
                    continue;
                }
                else
                {
                    guardMap[row][column] = '.';
                    guardMap[row][nextColumn] = '>';
                }

                ++column;
            }
        }
        else if (guardMap[row][column] == 'v')
        {
            if (row < guardMap.size())
            {
                int downRow = row + 1;

                if (downRow == guardMap.size())
                {
                    break;
                }

                if (guardMap[downRow][column] == '#')
                {
                    guardMap[row][column] = '<';
                    continue;
                }
                else
                {
                    guardMap[row][column] = '.';
                    guardMap[downRow][column] = 'v';
                }
            }

            ++row;
        }
        else
        {
            if (column > 0)
            {
                int previousColumn = column - 1;

                if (previousColumn == -1)
                {
                    break;
                }

                if (guardMap[row][previousColumn] == '#')
                {
                    guardMap[row][column] = '^';
                    continue;
                }
                else
                {
                    guardMap[row][column] = '.';
                    guardMap[row][previousColumn] = '<';
                }
            }

            --column;
        }

        // Look "forward" (in the guard's orientation) to see if there is an obstacle.
        // If there is, make them turn right 90 degrees and make them move in that direction.
        // Every place visited has to be added to the seenPlaces vector.
    }

    return seenPlaces.size();
}

unsigned long long DaySix::SolvePartTwo()
{
    return 0;
}

void DaySix::LoadLinesFromFile()
{
    this->linesFromInputFile = FileReader::GetInputFileLines("input_day_six.txt");
}
