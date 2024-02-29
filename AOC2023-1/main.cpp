#include <iostream>

#include "CalibrationsParser.h"

int main()
{
    static auto sum = 0;
    const auto calibrations = CalibrationsParser::parse("input.txt");
    for (auto& x : calibrations)
    {   
        std::string cal = "", calLeft = "", calRight = "";
        for (auto i = 0; i < x.size(); ++i)
        {
            if (isdigit(x[i]))
            {
                calLeft = x[i];
                break;
            }
        }

        for (auto i = x.size()-1; i >= 0; --i)
        {
            if (isdigit(x[i]))
            {
                calRight = x[i];
                break;
            }
        }
        cal = calLeft + calRight;

        sum += std::atoi(cal.c_str());
    }
    std::cout << sum << std::endl;
}
