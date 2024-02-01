#pragma once

#include<vector>

#include "Hand.h"

class HandValidator
{
public:
	HandValidator() = default;
	void validateByFirstOrderRule(const Hand& hand);
	void validateBySecondOrderRule();

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

