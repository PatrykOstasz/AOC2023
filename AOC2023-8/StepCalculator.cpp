#include "StepCalculator.h"
#include <iostream>
#include <algorithm>

long StepCalculator::solution = 0;
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
	auto networkNode = map.network.find(location);
	while (location != "ZZZ")
	{
		if (directionIdx > maxDirectionIdx)
			directionIdx = 0;


		if (map.navigationPattern[directionIdx] == 'L')
		{
			location = map.network.find(networkNode->second.first)->first;
			networkNode = map.network.find(networkNode->second.first);
			solution++;
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

void StepCalculator::calculateParallelSteps(const NetworkMap& map)
{
	std::cout << map.navigationPattern.size() << std::endl;
	const auto maxDirectionIdx = map.navigationPattern.size() - 1;
	auto directionIdx = 0;

	unsigned 

	while (!allNodesHaveZ())
	{
		if (directionIdx > maxDirectionIdx)
			directionIdx = 0;

		for (auto& location : parallelNodes)
		{	
			if (location[2] == 'Z')
			{
				std::for_each(begin(parallelNodes), end(parallelNodes), [](auto& x) {std::cout << x << " "; });
				std::cout << std::endl;
			}
			auto networkNode = map.network.find(location);

			if (map.navigationPattern[directionIdx] == 'L')
			{
				location = map.network.find(networkNode->second.first)->first;
				//networkNode = map.network.find(networkNode->second.first);
			}
			else
			{
				location = map.network.find(networkNode->second.second)->first;
				//networkNode = map.network.find(networkNode->second.second);
			}
		}
		directionIdx++;
		solution++;
	}
}

long StepCalculator::getSolution()
{
	return solution;
}

