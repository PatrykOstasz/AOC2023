#include <iostream>

#include "MapParser.h"
#include "StepCalculator.h"

int main()
{
    auto output = MapParser::parse("input.txt");
    //StepCalculator::calculateSteps(output);

    StepCalculator::findParallelNodes(output);
    StepCalculator::calculateParallelSteps(output);
    std::cout << StepCalculator::getSolution() << std::endl;
}