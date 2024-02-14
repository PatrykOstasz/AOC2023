#include "StepCalculator.h"
#include <iostream>

long StepCalculator::solution = 0;

void StepCalculator::calculateSteps(const NetworkMap& map)
{
	const auto maxDirectionIdx = map.navigationPattern.size() - 1;
	auto directionIdx = 0;

	std::string location = "AAA";
	auto networkNode = map.network.find(location);
	while (location != "ZZZ")
	{
		if (directionIdx == maxDirectionIdx)
			directionIdx = 0;

		if (map.navigationPattern[directionIdx] == 'L')
		{
			location = map.network.find(networkNode->second.first)->first;
			networkNode = map.network.find(networkNode->second.first);
			solution++;

			std::cout << solution << std::endl;
		}
		else
		{
			location = map.network.find(networkNode->second.second)->first;
			networkNode = map.network.find(networkNode->second.second);
			solution++;
		}

		directionIdx++;
	}
}

long StepCalculator::getSolution()
{
	return solution;
}
