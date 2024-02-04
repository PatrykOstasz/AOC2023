#include "BidCalculator.h"

long BidCalculator::calculate(const std::vector<Hand>& handsSorted)
{
	unsigned rank = 1;
	long result = 0;

	for (const auto& hand : handsSorted)
	{
		result += hand.bid * rank;
		rank++;
	}

	return result;
}
