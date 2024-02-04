#pragma once

#include <vector>
#include <map>

#include "Hand.h"

class HandComparer
{
public:
	HandComparer();

	void compareAndSort(const std::vector<Hand>& hands);
	std::vector<Hand> getSortedHands() const;

private:
	void compareByFirstOrderRule(const std::vector<Hand>& hands);
	void compareBySecondOrderRule();
	void groupSimilarHands(const std::vector<unsigned>& vec, const Hand& hand);

private:
	std::vector< std::vector<Hand> > handsGrouped;
	std::map< unsigned, std::vector<Hand>* > recognizeToType;

};

