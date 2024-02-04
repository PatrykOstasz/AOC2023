#include "HandComparer.h"

#include <algorithm>
#include <iostream>
#include <numeric>

HandComparer::HandComparer() 
{
	std::vector<unsigned> numSumsOfTypes{ 5, 7, 9 , 11, 13, 17, 25 };

	handsGrouped.resize(numSumsOfTypes.size());

	for (auto i = 0; i < numSumsOfTypes.size(); ++i)
	{
		recognizeToType.insert(std::make_pair(numSumsOfTypes[i], &handsGrouped[i]));
	}
}


void HandComparer::compareAndSort(const std::vector<Hand>& hands)
{
	compareByFirstOrderRule(hands);
	compareBySecondOrderRule();
}

void HandComparer::compareByFirstOrderRule(const std::vector<Hand>& hands)
{
	for (const auto& hand : hands)
	{
		std::vector<unsigned int> cardsGroupCount;
		cardsGroupCount.reserve(hand.cards.size());
		for (auto it = begin(hand.cards); it != end(hand.cards); it++)
		{
			const auto typesOfCardCount = std::count(begin(hand.cards), end(hand.cards), *it);
			auto cardGroupCount = static_cast<unsigned int>(typesOfCardCount);
			cardsGroupCount.push_back(cardGroupCount);
		}

		groupSimilarHands(cardsGroupCount, hand);
	}
}

void HandComparer::compareBySecondOrderRule()
{
	const std::string strength = "23456789TJQKA";
	auto isCardGreater = [&](const auto& hand1, const auto& hand2) 
	{
		std::string cards1 = hand1.cards;
		std::string cards2 = hand2.cards;

		for (int i = 0; i < cards1.size(); ++i)
		{
			auto card1 = static_cast<unsigned>(strength.find(cards1.at(i)));
			auto card2 = static_cast<unsigned>(strength.find(cards2.at(i)));

			if (card1 == card2) continue;

			return card1 < card2;
		}
	};
	
	for (auto& hand : handsGrouped) 
	{
		std::sort(begin(hand), end(hand), isCardGreater);
	}
}

std::vector<Hand> HandComparer::getSortedHands() const
{
	std::vector<Hand> output;
	for (const auto& hand : handsGrouped)
	{
		output.insert(end(output), cbegin(hand), cend(hand));
	}
	return output;
}

void HandComparer::groupSimilarHands(const std::vector<unsigned>& vec, const Hand& hand)
{
	const auto magicNumber = std::accumulate(cbegin(vec), cend(vec), 0);
	recognizeToType[magicNumber]->push_back(hand);
}
