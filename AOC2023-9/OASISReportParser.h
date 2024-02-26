#pragma once

#include <string>
#include <vector>

class OASISReportParser
{
public:
	static std::vector<std::vector<long long>> parse(const std::string& filename);
};

