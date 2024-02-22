#include "StepCalculator.h"
#include <iostream>
#include <algorithm>

unsigned long long StepCalculator::solution = 0;
std::vector<long> StepCalculator::parallelSteps{};
std::vector<std::string> StepCalculator::parallelNodes{};

void StepCalculator::findParallelNodes(const NetworkMap& map)
{
	for (const auto& node : map.network)
	{
		if (node.first[2] == 'A')
			parallelNodes.push_back(node.first);
	}
}

void StepCalculator::calculateSteps(const NetworkMap& map)
{
	const auto maxDirectionIdx = map.navigationPattern.size() - 1;
	auto directionIdx = 0;

	std::string location = "AAA";
	while (location != "ZZZ")
	{
		auto networkNode = map.network.find(location);
		if (directionIdx > maxDirectionIdx)
			directionIdx = 0;


		if (map.navigationPattern[directionIdx] == 'L')
		{
			location = map.network.find(networkNode->second.first)->first;
			solution++;
		}
		else
		{
			location = map.network.find(networkNode->second.second)->first;
			solution++;
		}

		directionIdx++;
	}
}

void StepCalculator::calculateParallelSteps(const NetworkMap& map)
{
	const auto maxDirectionIdx = map.navigationPattern.size() - 1;
	static auto directionIdx = 0;

	for (auto& location : parallelNodes)
	{
		unsigned long parallelStepsCounter = 0;

		while (location[2] != 'Z')
		{
			auto networkNode = map.network.find(location);

			if (directionIdx > maxDirectionIdx)
				directionIdx = 0;

			if (map.navigationPattern[directionIdx] == 'L')
			{
				location = map.network.find(networkNode->second.first)->first;
				parallelStepsCounter++;
			}
			else
			{
				location = map.network.find(networkNode->second.second)->first;
				parallelStepsCounter++;
			}
			directionIdx++;
		}
		std::cout << parallelStepsCounter << std::endl;
		parallelSteps.push_back(parallelStepsCounter);
	}

	solution = caluclateLCM(parallelSteps);
}

unsigned long long StepCalculator::getSolution()
{
	return solution;
}

