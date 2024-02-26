#pragma once

#include "NavigationMap.h"

#include <numeric>

class StepCalculator
{
public:
	StepCalculator(const NavigationMap& inMap);

	void calculatePart1();
	void calculatePart2();
	unsigned long long getSolution() const;

private:
	void calculateSteps(std::string& loc, unsigned long long& counter);
	unsigned long long caluclateLCM(const std::vector<unsigned long long> & steps);

	std::vector<std::string> parallelNodes;
	std::vector<unsigned long long> parallelSteps;

	NavigationMap map;
	unsigned directionIdx;
	unsigned maxDirectionIdx;
	unsigned long long solution;
};

