#include "NetworkMap.h"

std::string NetworkMap::navigationPattern = "";

void NetworkMap::addNode(const std::string& in_location, const std::string& in_left, const std::string& in_right)
{
	network.insert(std::make_pair(in_location, std::make_pair(in_left, in_right)));
}

void NetworkMap::setNavigationPattern(const std::string& pattern)
{
	if (navigationPattern == "")
		navigationPattern = pattern;
}
