#include <iostream>

#include "BidCalculator.h"
#include "HandComparer.h"
#include "HandParser.h"

int main()
{
    const auto myHands = HandParser::parse("input.txt");

    auto handComparer = HandComparer();
    handComparer.compareAndSort(myHands);

    const auto handsSorted = handComparer.getSortedHands();

    const auto solution = BidCalculator::calculate(handsSorted);
    std::cout << solution << std::endl;

}
