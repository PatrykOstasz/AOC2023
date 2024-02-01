#pragma once

#include <string>

class Hand
{
public:
	Hand(const std::string& in_cards, unsigned int in_bid);
	std::string getCards() const { return cards; }
	unsigned int getBid() const { return bid; }

private:
	std::string cards;
	unsigned int bid;
};

