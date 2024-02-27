#include "CalibrationsParser.h"

#include <fstream>

std::vector<std::string> CalibrationsParser::parse(const std::string& filename)
{
    auto output = std::vector<std::string>();
    std::ifstream file;
    file.open(filename.c_str());
    if (!file.good()) exit(EXIT_FAILURE);

    std::string line = "";
    while (std::getline(file, line) or !file.eof())
    {
        output.push_back(line);
    }

    file.close();
    return output;
}
