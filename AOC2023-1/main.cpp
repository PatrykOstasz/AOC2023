#include <iostream>

#include "CalibrationsParser.h"

int main()
{
    const auto calibrations = CalibrationsParser::parse("input2.txt");
    for (auto& x : calibrations)
        std::cout << x << std::endl;
}
