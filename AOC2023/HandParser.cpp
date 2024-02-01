#include "HandParser.h"

#include <fstream>
#include <sstream>

std::vector<Hand> HandParser::parse(const std::string& filename)
{
	auto output = std::vector<Hand>();
	std::ifstream inputFile;

	inputFile.open(filename.c_str());
	std::string line = "";
	if (inputFile.good())
	{
		while (std::getline(inputFile, line) && !inputFile.eof())
		{
			std::stringstream ss(line);
			std::string cards = "";
			unsigned int bid = 0;

			ss >> cards;
			ss >> bid;

			output.emplace_back(Hand(cards, bid));
		}
	}
	inputFile.close();
	return output;
}
