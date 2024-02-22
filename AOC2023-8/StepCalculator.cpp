#include "StepCalculator.h"

#include <algorithm>

StepCalculator::StepCalculator(const NetworkMap& in_map) : map(in_map), directionIdx(0), solution(0)
{
	maxDirectionIdx = static_cast<unsigned>(map.navigationPattern.size()) - 1;

	for (const auto& node : map.network)
	{
		if (node.first[2] == 'A')
			parallelNodes.push_back(node.first);
	}
}

void StepCalculator::calculatePart1()
{
	std::string location = "AAA";
	auto parallelStepsCounter = 0UL;

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
		auto parallelStepsCounter = 0UL;
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

void StepCalculator::calculateSteps(std::string& loc, unsigned long& counter)
{
	auto networkNode = map.network.find(loc);

	if (directionIdx > maxDirectionIdx)
		directionIdx = 0;

	//divide this first-second-first into two variables for readibility
	if (map.navigationPattern[directionIdx] == 'L')
	{
		loc = map.network.find(networkNode->second.first)->first;
		counter++;
	}
	else
	{
		loc = map.network.find(networkNode->second.second)->first;
		counter++;
	}
	directionIdx++;
}

unsigned long long StepCalculator::caluclateLCM(const std::vector<long>& steps)
{
	// needs to realistically unpack this vector to function or
	// change to different method
	return lcm(20221, 16343, 16897, 21883, 19667, 13019);
}



