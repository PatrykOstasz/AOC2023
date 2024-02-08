#include "BidCalculator.h"

long BidCalculator::calculate(const std::vector<Hand>& handsSorted)
{
	unsigned rank = 1;
	long bidSum = 0;

	for (const auto& hand : handsSorted)
	{
		bidSum += hand.bid * rank;
		rank++;
	}

	return bidSum;
}
