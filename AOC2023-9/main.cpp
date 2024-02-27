#include <iostream>

#include "OASIS.h"
#include "OASISReportParser.h"

int main()
{
    const auto readings = OASISReportParser::parse("input.txt");

    OASIS oasis(readings);

    bool isPart1 = true, isPart2 = false;
    auto solution = oasis.calculateSolution(isPart1);
    std::cout << solution << std::endl;
}

