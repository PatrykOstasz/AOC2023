#include <iostream>

#include "MapParser.h"
#include "StepCalculator.h"

int main()
{
    auto output = MapParser::parse("input2.txt");
    StepCalculator::calculateSteps(output);
    std::cout << StepCalculator::getSolution() << std::endl;
}