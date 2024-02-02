#include <iostream>

#include "HandParser.h"
#include "HandComparer.h"

int main()
{
    HandComparer handComparer;
    auto myHands = HandParser::parse("input.txt");

    for (auto& hand : myHands)
    {
        handComparer.compareByFirstOrderRule(hand);
    }
    handComparer.compareBySecondOrderRule();
}
