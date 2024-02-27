#include "OASIS.h"

#include <algorithm>
#include <functional>
#include <numeric>

#include <iostream>

OASIS::OASIS(const std::vector<std::vector<long long>>& r) : readings(r)
{
}

long long OASIS::calculateSolution(bool isPart1)
{
    for (auto& reading : readings)
    {
        auto lastDifferences =  std::vector<long long>();
        auto part2Differences = std::vector<long long>();

        while (!allZeroes(reading))
        {
            const auto readingIdx = isPart1 ? (reading.size() - 1) : 0;
            lastDifferences.push_back(reading[readingIdx]);
            calculateDifferences(reading);
        }

        if (!isPart1)
        {
            calculatePart2Differences(lastDifferences, part2Differences);
            calculatePredictedValues(part2Differences, isPart1);
        }
        else
        {
            calculatePredictedValues(lastDifferences, isPart1);
        }
    }
    return std::accumulate(cbegin(predictedValues), cend(predictedValues), 0LL);
}

void OASIS::calculateDifferences(std::vector<long long>& diff)
{
    std::adjacent_difference(begin(diff), end(diff), begin(diff));
    diff.erase(begin(diff));
}

bool OASIS::allZeroes(const std::vector<long long>& diff)
{
    return std::all_of(cbegin(diff), cend(diff), [](const auto& d) { return d == 0; });
}

void OASIS::calculatePredictedValues(const std::vector<long long>& partial, bool isPart1)
{
    auto predictedValue = 0LL;

    if (isPart1)
        predictedValue = std::accumulate(cbegin(partial), cend(partial), 0LL);
    else
        predictedValue = partial[partial.size() - 1];

    predictedValues.push_back(predictedValue);
}

void OASIS::calculatePart2Differences(std::vector<long long>& in, std::vector<long long>& out)
{
    out.push_back(0);
    auto idx = 0;
    std::reverse(begin(in), end(in));
    for (const auto& difference : in)
    {
        auto previousReading = -out[idx] + difference;
        out.push_back(previousReading);
        idx++;
    }
}
