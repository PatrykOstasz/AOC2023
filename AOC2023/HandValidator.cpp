#include "HandValidator.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>

void HandValidator::validateByFirstOrderRule(const Hand& hand)
{
	std::string temporaryHand = hand.getCards();
	std::sort(begin(temporaryHand), end(temporaryHand));

	std::vector<unsigned int> cardsGroupCount;
	for (auto it = temporaryHand.begin(); it != temporaryHand.end(); it++)
	{
		auto cardGroupCount = static_cast<unsigned int>(std::count(temporaryHand.begin(), temporaryHand.end(), *it));
		cardsGroupCount.push_back(cardGroupCount);
	}

	groupSimilarHands(cardsGroupCount, hand);
}

void HandValidator::validateBySecondOrderRule()
{
	std::map<std::string, unsigned> cardsToNumbers {
		std::make_pair("T", 10),
		std::make_pair("J", 11),
		std::make_pair("Q", 12),
		std::make_pair("K", 13),
		std::make_pair("A", 14)
	};

	auto isCardGreater = [&](const std::string& card1, const std::string& card2) {
		const auto it1 = cardsToNumbers.find(card1);
		const auto it2 = cardsToNumbers.find(card2);

		unsigned int numCard1 = 0, numCard2 = 0;
		if (it1 != cardsToNumbers.end())
			numCard1 = cardsToNumbers[card1];
		else
			numCard1 = atoi(card1.c_str());

		if (it2 != cardsToNumbers.end())
			numCard2 = cardsToNumbers[card2];
		else
			numCard2 = atoi(card2.c_str());

		return numCard1 > numCard2;
		};


}

void HandValidator::groupSimilarHands(const std::vector<unsigned>& vec, const Hand& hand)
{
	const auto magicNumber = std::accumulate(cbegin(vec), cend(vec), 0);
	switch (magicNumber)
	{
	case 25:
		fiveOfAKind.push_back(hand);
		break;
	case 17:
		std::cout << hand.getCards() << std::endl;
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
