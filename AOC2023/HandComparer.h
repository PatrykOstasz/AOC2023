#pragma once

#include<vector>

#include "Hand.h"

class HandComparer
{
public:
	HandComparer() = default;
	void compareByFirstOrderRule(const Hand& hand);
	void compareBySecondOrderRule();
	std::vector<Hand> justGlueIt();

private:
	void groupSimilarHands(const std::vector<unsigned>& vec, const Hand& hand);

private:
	std::vector<Hand> fiveOfAKind;
	std::vector<Hand> fourOfAKind;
	std::vector<Hand> fullHouse;
	std::vector<Hand> threeOfAKind;
	std::vector<Hand> twoPairs;
	std::vector<Hand> pairs;
	std::vector<Hand> oldestCard;

};

