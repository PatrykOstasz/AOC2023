#include <iostream>

#include "OASISReportParser.h"

int main()
{
    const auto output = OASISReportParser::parse("input.txt");

    for (const auto& vec : output)
    {
        for (const auto reading : vec)
            std::cout << reading << " ";
        std::cout << std::endl;
    }
}
