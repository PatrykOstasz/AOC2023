#pragma once

#include <string>

#include "NavigationMap.h"

class MapParser
{
public:
	static NavigationMap parse(const std::string& filename);
};

