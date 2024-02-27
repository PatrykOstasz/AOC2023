#include <iostream>

#include "OASIS.h"
#include "OASISReportParser.h"

constexpr auto ISPART1 = false;

int main()
{
    const auto readings = OASISReportParser::parse("input.txt");

    OASIS oasis(readings);

    auto solution = oasis.calculateSolution(ISPART1);
    std::cout << solution << std::endl;
}

