#include "StepCalculator.h"

#include <algorithm>

StepCalculator::StepCalculator(const NavigationMap& navMap) : map(navMap), directionIdx(0), solution(0)
{
	maxDirectionIdx = static_cast<unsigned>(map.directionPattern.size()) - 1;

	for (const auto& node : map.navMap)
	{
		if (node.first[2] == 'A')
			parallelNodes.push_back(node.first);
	}
}

void StepCalculator::calculatePart1()
{
	std::string location = "AAA";
	auto parallelStepsCounter = 0ULL;

	while (location != "ZZZ")
	{
		calculateSteps(location, parallelStepsCounter);
	}
	solution = parallelStepsCounter;
}

void StepCalculator::calculatePart2()
{
	for (auto& location : parallelNodes)
	{
		auto parallelStepsCounter = 0ULL;
		while (location[2] != 'Z')
		{
			calculateSteps(location, parallelStepsCounter);
		}
		parallelSteps.push_back(parallelStepsCounter);
	}

	solution = caluclateLCM(parallelSteps);
}

unsigned long long StepCalculator::getSolution() const
{
	return solution;
}

void StepCalculator::calculateSteps(std::string& loc, unsigned long long& counter)
{
	auto networkNode = map.navMap.find(loc);

	if (directionIdx > maxDirectionIdx)
		directionIdx = 0;

	auto& nextLocationPair = networkNode->second;
	if (map.directionPattern[directionIdx] == 'L')
	{	
		std::string nextLocationLeft = nextLocationPair.first;
		auto newNode = map.navMap.find(nextLocationLeft);
		loc = newNode->first;
		counter++;
	}
	else
	{
		std::string nextLocationRight = nextLocationPair.second;
		auto newNode = map.navMap.find(nextLocationRight);
		loc = newNode->first;
		counter++;
	}
	directionIdx++;
}

unsigned long long StepCalculator::caluclateLCM(const std::vector<unsigned long long>& steps)
{
	static auto result = steps[0];
	for (int i = 1; i < steps.size(); ++i)
	{
		result = std::lcm(result, steps[i]);
	}
	return result;
}
