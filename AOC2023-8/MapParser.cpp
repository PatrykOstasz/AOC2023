#include "MapParser.h"

#include <fstream>
#include <iostream>

NetworkMap MapParser::parse(const std::string& filename)
{
	auto output = NetworkMap();

	std::ifstream inputFile;
	inputFile.open(filename.c_str());

	if (!inputFile.good()) exit(EXIT_FAILURE);

	std::string networkPattern = "";
	std::getline(inputFile, networkPattern);

	std::string nextLine = "";
	while (std::getline(inputFile, nextLine) && !inputFile.eof())
	{
		if (nextLine == "") continue;
		std::string location = nextLine.substr(0, 3);
		std::string nodeLeft = nextLine.substr(7 ,3);
		std::string nodeRight = nextLine.substr(12, 3);


		output.addNode(location, nodeLeft, nodeRight);
	}

	output.setNavigationPattern(networkPattern);

	inputFile.close();

	return output;
}
