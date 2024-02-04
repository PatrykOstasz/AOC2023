#pragma once

#include <vector>

#include "Hand.h"

class BidCalculator
{
public:
	BidCalculator() = default;
	static long calculate(const std::vector<Hand>& handsSorted);
};

