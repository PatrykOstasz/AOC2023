#pragma once

#include <string>
#include <unordered_map>

using NavigationNode = std::pair<std::string, std::string>;

struct NavigationMap
{
	static std::string directionPattern;
	std::unordered_map<std::string, NavigationNode> navMap;

	NavigationMap() = default;
	void addNode(const std::string& currentLoc, const std::string& nextLocLeft, const std::string& nextLocRight);

	static void setDirectionPattern(const std::string& pattern);
};

