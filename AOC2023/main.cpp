#include <iostream>

#include "BidCalculator.h"
#include "HandParser.h"
#include "HandComparer.h"

int main()
{
    auto myHands = HandParser::parse("input.txt");

    HandComparer handComparer;
    handComparer.compareAndSort(myHands);

    const auto handsSorted = handComparer.getSortedHands();

    auto solution = BidCalculator::calculate(handsSorted);
    std::cout << solution << std::endl;

}
