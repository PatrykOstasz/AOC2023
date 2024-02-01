#pragma once

#include <vector>
#include <string>

#include "Hand.h"

class Hand;

class HandParser
{
public:
	static std::vector<Hand> parse(const std::string& filename);
};

