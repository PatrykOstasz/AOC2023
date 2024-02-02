#include "HandComparer.h"

#include <algorithm>
#include <numeric>

void HandComparer::compareByFirstOrderRule(const Hand& hand)
{
	std::string temporaryHand = hand.cards;
	std::sort(begin(temporaryHand), end(temporaryHand));

	std::vector<unsigned int> cardsGroupCount;
	for (auto it = temporaryHand.begin(); it != temporaryHand.end(); it++)
	{
		auto cardGroupCount = static_cast<unsigned int>(std::count(temporaryHand.begin(), temporaryHand.end(), *it));
		cardsGroupCount.push_back(cardGroupCount);
	}

	// do I need intermediate vectors as a class fields? can it be improved?
	groupSimilarHands(cardsGroupCount, hand);
}

void HandComparer::compareBySecondOrderRule()
{
	std::string rank = "23456789TJQKA";
	auto isCardGreater = [&](const auto& hand1, const auto& hand2) {

		std::string cards1 = hand1.cards;
		std::string cards2 = hand2.cards;

		for (int i = 0; i < cards1.size(); ++i)
		{
			auto card1 = static_cast<unsigned>(rank.find(cards1.at(i)));
			auto card2 = static_cast<unsigned>(rank.find(cards2.at(i)));

			if (card1 == card2) continue;

			return card1 > card2;
		}
	};

	std::sort(begin(fullHouse), end(fullHouse), isCardGreater);
}

std::vector<Hand> HandComparer::justGlueIt()
{
	return std::vector<Hand>();
}

void HandComparer::groupSimilarHands(const std::vector<unsigned>& vec, const Hand& hand)
{
	// can it be simplified? switch is fe
	const auto magicNumber = std::accumulate(cbegin(vec), cend(vec), 0);
	switch (magicNumber)
	{
	case 25:
		fiveOfAKind.push_back(hand);
		break;
	case 17:
		fourOfAKind.push_back(hand);
		break;
	case 13:
		fullHouse.push_back(hand);
		break;
	case 11:
		threeOfAKind.push_back(hand);
		break;
	case 9:
		twoPairs.push_back(hand);
		break;
	case 7:
		pairs.push_back(hand);
		break;
	default:
		oldestCard.push_back(hand);
	}
}
