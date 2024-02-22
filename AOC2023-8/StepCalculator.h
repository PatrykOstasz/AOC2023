#pragma once

#include "NetworkMap.h"

#include <numeric>

namespace math {

	template <typename M, typename N>
	constexpr unsigned long long lcm(const M& m, const N& n) {
		return std::lcm(m, n);
	}

	template <typename M, typename ...Rest>
	constexpr unsigned long long lcm(const M& first, const Rest&... rest) {
		return std::lcm(first, lcm(rest...));
	}
}

class StepCalculator
{
public:
	StepCalculator() = default;

	static void findParallelNodes(const NetworkMap& map);
	static void calculateSteps(const NetworkMap& map);
	static void calculateParallelSteps(const NetworkMap& map);
	static unsigned long long getSolution();

	static unsigned long long caluclateLCM(const std::vector<long> & steps)
	{
		return math::lcm(20221, 16343, 16897, 21883, 19667, 13019);
	}

	static unsigned long long solution;
	static std::vector<std::string> parallelNodes;
	static std::vector<long> parallelSteps;
};

