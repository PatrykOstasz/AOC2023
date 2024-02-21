#pragma once

#include "NetworkMap.h"

class StepCalculator
{
public:
	StepCalculator() = default;

	static void findParallelNodes(const NetworkMap& map);
	static void calculateSteps(const NetworkMap& map);
	static void calculateParallelSteps(const NetworkMap& map);
	static long getSolution();

	static bool allNodesHaveZ()
	{
		unsigned counter = 0;
		for (const auto& x : parallelNodes)
		{
			if (x[2] != 'Z') return false;
		}
		return true;
	}

	static long solution;
	static std::vector<std::string> parallelNodes;
};

