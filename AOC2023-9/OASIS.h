#pragma once

#include <vector>

class OASIS
{
public:
	OASIS(const std::vector<std::vector<long long>>& r);
	long long calculateSolution(bool isPart1);
private:
	void calculateDifferences(std::vector<long long>& diff);
    bool allZeroes(const std::vector<long long>& diff);
	void calculatePredictedValues(const std::vector<long long>& partial);

	std::vector<std::vector<long long>> readings;
	std::vector<long long> predictedValues;
};

