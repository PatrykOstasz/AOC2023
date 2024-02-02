#pragma once

#include <string>

struct Hand
{
	Hand(const std::string& in_cards, unsigned int in_bid) : cards(in_cards), bid(in_bid) {}

	std::string cards;
	unsigned int bid;
};

