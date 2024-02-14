#pragma once

#include "NetworkMap.h"

class StepCalculator
{
public:
	static long solution;
	static void calculateSteps(const NetworkMap& map);
	static long getSolution();
};

