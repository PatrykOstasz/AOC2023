#include "HandComparer.h"

#include <algorithm>
#include <numeric>

constexpr auto SOLUTION2 = 1;

HandComparer::HandComparer() 
{
	const auto numSumsOfTypes = std::vector<unsigned>({ 5, 7, 9 , 11, 13, 17, 25 });

	handsGrouped.resize(numSumsOfTypes.size());

	for (auto i = 0; i < numSumsOfTypes.size(); ++i)
		numericalToType.insert(std::make_pair(numSumsOfTypes[i], &handsGrouped[i]));
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
		auto handModified = Hand(hand);

		if (SOLUTION2)
			handModified = modifyHandTypeByJoker(hand);

		auto cardsGroupCount = std::vector<unsigned>();
		cardsGroupCount.reserve(handModified.cards.size());

		for (auto it = cbegin(handModified.cards); it != cend(handModified.cards); it++)
		{
			const auto typesOfCardCount = std::count(begin(handModified.cards), end(handModified.cards), *it);
			const auto cardGroupCount = static_cast<unsigned>(typesOfCardCount);
			cardsGroupCount.push_back(cardGroupCount);
		}

		groupSimilarHands(cardsGroupCount, hand);
	}
}

Hand HandComparer::modifyHandTypeByJoker(Hand hand)
{
	if (hand.cards == "JJJJJ")
		std::replace(begin(hand.cards), end(hand.cards), 'J', 'A');
	
	if (std::find(cbegin(hand.cards), cend(hand.cards), 'J') == cend(hand.cards)) return hand;

	const std::string strengthMinusJ = "23456789TQKA";

	auto cardToCount = std::map<char, unsigned>();
	std::for_each(cbegin(strengthMinusJ), cend(strengthMinusJ), [&](const auto& s) { cardToCount.insert(std::make_pair(s, 0)); }); // jako alternatywa do przypomnienia

	for (const auto& card : hand.cards)
	{
		if (card == 'J') continue;
		cardToCount[card]++;
	}

	auto maxComparer = [&strengthMinusJ](const auto& elem1, const auto& elem2)
	{
		if (elem1.second != elem2.second) return elem1.second < elem2.second;

		const auto card1 = static_cast<unsigned>(strengthMinusJ.find(elem1.first));
		const auto card2 = static_cast<unsigned>(strengthMinusJ.find(elem2.first));

		if (card1 == card2) return false;

		return card1 < card2;
	};
	const auto maxElement = std::max_element(cbegin(cardToCount), cend(cardToCount), maxComparer);

	std::replace(begin(hand.cards), end(hand.cards), 'J', maxElement->first);

	return hand;

}

void HandComparer::compareBySecondOrderRule()
{
   std::string strength = SOLUTION2 ? "J23456789TQKA" : "23456789TJQKA";

	auto isCardGreater = [&](const auto& hand1, const auto& hand2) 
	{
		const std::string cards1 = hand1.cards;
		const std::string cards2 = hand2.cards;

		for (auto i = 0; i < cards1.size(); ++i)
		{
			const auto card1 = static_cast<unsigned>(strength.find(cards1.at(i)));
			const auto card2 = static_cast<unsigned>(strength.find(cards2.at(i)));

			if (card1 == card2) continue;

			return card1 < card2;
		}
	};
	
	for (auto& hand : handsGrouped) 
		std::sort(begin(hand), end(hand), isCardGreater);
}

std::vector<Hand> HandComparer::getSortedHands() const
{
	auto handsSorted = std::vector<Hand>();

	for (const auto& hand : handsGrouped)
		handsSorted.insert(end(handsSorted), cbegin(hand), cend(hand));

	return handsSorted;
}

void HandComparer::groupSimilarHands(const std::vector<unsigned>& comparer, const Hand& hand)
{
	const auto numericalType = std::accumulate(cbegin(comparer), cend(comparer), 0);
	numericalToType[numericalType]->push_back(hand);
}
