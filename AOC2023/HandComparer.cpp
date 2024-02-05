#include "HandComparer.h"

#include <algorithm>
#include <iostream>
#include <numeric>

constexpr auto SOLUTION2 = 1;

HandComparer::HandComparer() 
{
	std::vector<unsigned> numSumsOfTypes{ 5, 7, 9 , 11, 13, 17, 25 };

	handsGrouped.resize(numSumsOfTypes.size());

	for (auto i = 0; i < numSumsOfTypes.size(); ++i)
	{
		recognizeToType.insert(std::make_pair(numSumsOfTypes[i], &handsGrouped[i]));
	}
}


void HandComparer::compareAndSort(std::vector<Hand>& hands)
{
	compareByFirstOrderRule(hands);
	compareBySecondOrderRule();
}

void HandComparer::compareByFirstOrderRule(std::vector<Hand>& hands)
{
	for (const auto& hand : hands)
	{
		Hand modifiedHand {"", 0};
		if (SOLUTION2)
		{
			modifiedHand = modifyHandByJoker(hand);
		}

		std::vector<unsigned int> cardsGroupCount;

		cardsGroupCount.reserve(modifiedHand.cards.size());

		for (auto it = begin(modifiedHand.cards); it != end(modifiedHand.cards); it++)
		{
			const auto typesOfCardCount = std::count(begin(modifiedHand.cards), end(modifiedHand.cards), *it);
			auto cardGroupCount = static_cast<unsigned int>(typesOfCardCount);
			cardsGroupCount.push_back(cardGroupCount);
		}

		groupSimilarHands(cardsGroupCount, hand);
	}
}

Hand HandComparer::modifyHandByJoker(Hand h)
{
	const std::string strengthMinusJ = "23456789TQKA";
	std::map<char, unsigned> cardToCount;

	for (auto& s : strengthMinusJ)
	{
		cardToCount.insert(std::make_pair(s, 0));
	}

	for (const auto& s : h.cards)
	{
		if (s == 'J') continue;
		cardToCount[s]++;
	}

	if (std::find(begin(h.cards), end(h.cards), 'J') != end(h.cards))
	{

		if (h.cards == "JJJJJ")
		{
			std::replace(begin(h.cards), end(h.cards), 'J', 'A');
		}

		auto maxComparer = [&](const auto& elem1, const auto& elem2)
		{
			if (elem1.second == elem2.second)
			{
				auto card1 = static_cast<unsigned>(strengthMinusJ.find(elem1.first));
				auto card2 = static_cast<unsigned>(strengthMinusJ.find(elem2.first));

				if (card1 == card2) return false;

				return card1 < card2;

			}
			return elem1.second < elem2.second;
		};

		auto maxElement = std::max_element(begin(cardToCount), end(cardToCount), maxComparer);
		std::replace(begin(h.cards), end(h.cards), 'J', maxElement->first);

		return h;
	}
	return h;

}

void HandComparer::compareBySecondOrderRule()
{
	std::string strength = "23456789TJQKA";
	if (SOLUTION2)
	{
		strength = "J23456789TQKA";
	}
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
