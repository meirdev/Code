#include <iostream>
#include <vector>
#include <string>

#include "MathSolver.h"

int main()
{
    MathSolver mathSolver;

    std::vector<std::string> mathExpressions = {
        "2*3+4",
        "2*(3+4)",
        "(2+3)*4",
        "5*2^3",
        "9/3+12*2"
    };

    for (auto& i : mathExpressions)
    {
        std::cout << i << "=" << mathSolver.solve(i) << std::endl;
    }

    return 0;
}