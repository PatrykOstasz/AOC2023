#pragma once

#include <string>
#include <vector>

#include "Hand.h"

class HandParser
{
public:
	static std::vector<Hand> parse(const std::string& filename);
};

