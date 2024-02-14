#pragma once

#include <string>

#include "NetworkMap.h"

class MapParser
{
public:
	static NetworkMap parse(const std::string& filename);
};

