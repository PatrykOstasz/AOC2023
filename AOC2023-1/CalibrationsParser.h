#pragma once

#include <string>
#include <vector>

class CalibrationsParser
{
public:
	static std::vector<std::string> parse(const std::string& filename);
};

