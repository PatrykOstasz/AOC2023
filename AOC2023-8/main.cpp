#include <iostream>

#include "MapParser.h"
#include "StepCalculator.h"

int main()
{
    const auto networkMap = MapParser::parse("input.txt");

    StepCalculator stepCalculator(networkMap);
    stepCalculator.calculatePart1();
    std::cout << stepCalculator.getSolution() << std::endl;

    stepCalculator.calculatePart2();
    std::cout << stepCalculator.getSolution() << std::endl;
}