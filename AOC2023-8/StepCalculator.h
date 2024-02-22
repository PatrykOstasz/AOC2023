#pragma once

#include "NetworkMap.h"

#include <numeric>

template <typename M, typename N>
constexpr unsigned long long lcm(const M& m, const N& n) {
	return std::lcm(m, n);
}

template <typename M, typename ...Rest>
constexpr unsigned long long lcm(const M& first, const Rest&... rest) {
	return std::lcm(first, lcm(rest...));
}

class StepCalculator
{
public:
	StepCalculator(const NetworkMap& in_map);

	void calculatePart1();
	void calculatePart2();
	unsigned long long getSolution() const;

private:
	void calculateSteps(std::string& loc, unsigned long& counter);
	unsigned long long caluclateLCM(const std::vector<long> & steps);

	NetworkMap map;
	std::vector<std::string> parallelNodes;
	std::vector<long> parallelSteps;

	unsigned directionIdx;
	unsigned maxDirectionIdx;
	unsigned long long solution;
};

