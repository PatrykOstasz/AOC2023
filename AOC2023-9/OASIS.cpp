#include "OASIS.h"

#include <algorithm>
#include <functional>
#include <numeric>


OASIS::OASIS(const std::vector<std::vector<long long>>& r) : readings(r)
{
}

long long OASIS::calculateSolution(bool isPart1)
{
    for (auto& reading : readings)
    {
        std::vector<long long> lastDifferences;

        while (!allZeroes(reading))
        {
            lastDifferences.push_back(reading[reading.size() - 1]);
            calculateDifferences(reading);
        }
        calculatePredictedValues(lastDifferences);
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
    return std::all_of(cbegin(diff), cend(diff), [](const auto& i) { return i == 0; });
}

void OASIS::calculatePredictedValues(const std::vector<long long>& partial)
{
    const auto predictedValue = std::accumulate(cbegin(partial), cend(partial), 0LL);
    predictedValues.push_back(predictedValue);
}
