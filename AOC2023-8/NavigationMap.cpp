#include "NavigationMap.h"

std::string NavigationMap::directionPattern = "";

void NavigationMap::addNode(const std::string& currentLoc, const std::string& nextLocLeft, const std::string& nextLocRight)
{
	navMap.insert(std::make_pair(currentLoc, std::make_pair(nextLocLeft, nextLocRight)));
}

void NavigationMap::setDirectionPattern(const std::string& pattern)
{
	if (directionPattern == "")
		directionPattern = pattern;
}
