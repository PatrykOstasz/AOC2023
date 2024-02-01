#include <iostream>

#include "HandParser.h"
#include "HandValidator.h"

int main()
{
    HandValidator validator;
    auto myHands = HandParser::parse("input.txt");

    for (auto& hand : myHands)
    {
        validator.validateByFirstOrderRule(hand);
    }
}
