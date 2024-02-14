#pragma once

#include <unordered_map>
#include <string>

using NetworkNode = std::pair<std::string, std::string>;

struct NetworkMap
{
	static std::string navigationPattern;
	std::unordered_map<std::string, NetworkNode> network;

	NetworkMap() = default;
	void addNode(const std::string& in_location, const std::string& in_left, const std::string& in_right);

	static void setNavigationPattern(const std::string& pattern);
};

