#pragma once

#include <map>
#include <vector>

#include "Hand.h"

class HandComparer
{
public:
	HandComparer();

	void compareAndSort(const std::vector<Hand>& hands);
	std::vector<Hand> getSortedHands() const;

private:
	void compareByFirstOrderRule(const std::vector<Hand>& hands);
	Hand modifyHandTypeByJoker(Hand h);
	void compareBySecondOrderRule();
	void groupSimilarHands(const std::vector<unsigned>& comparator, const Hand& hand);

private:
	std::vector< std::vector<Hand> > handsGrouped;
	std::map< unsigned, std::vector<Hand>* > numericalToType;

};

