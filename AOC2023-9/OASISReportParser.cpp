#include "OASISReportParser.h"

#include <fstream>
#include <sstream>

std::vector<std::vector<long long>> OASISReportParser::parse(const std::string& filename)
{
    auto output = std::vector<std::vector<long long>>();

    auto file = std::ifstream();
    file.open(filename.c_str());
    if (!file.good()) exit(EXIT_FAILURE);

	std::string line = "";
	while (std::getline(file, line) && !file.eof())
	{
		std::stringstream ss(line);
        std::vector<long long> temp;
        while (!ss.eof())
        {
            long long reading = 0LL;
            ss >> reading;
            temp.push_back(reading);
        }
        output.push_back(temp);
	}
    
    file.close();
    return output;
}
