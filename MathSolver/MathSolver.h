#ifndef __MATH_SOLVER_H__
#define __MATH_SOLVER_H__

#include <string>

class MathSolver
{
public:
    double solve(const std::string& _expression);
private:
    bool isOperator(char _char);
    int operatorPriority(char _operator);
    std::string convertToPostfix(const std::string& _expression);
    double calculation(double _operandLeft, double _operandRight, char _operator);
};

#endif // __MATH_SOLVER_H__