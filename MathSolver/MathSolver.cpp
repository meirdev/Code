#include <stack>
#include <cctype>
#include <cmath>

#include "MathSolver.h"

bool MathSolver::isOperator(char _char)
{
    switch (_char)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            return true;
    }

    return false;
}

int MathSolver::operatorPriority(char _operator)
{
    switch (_operator)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }

    return -1;
}

std::string MathSolver::convertToPostfix(const std::string& _expression)
{
    std::string postfix;
    std::stack<char> expStack;

    for (size_t i = 0, length = _expression.length(); i < length; ++i)
    {
        if (isOperator(_expression[i]))
        {
            while (!expStack.empty())
            {
                char top = expStack.top();
                expStack.pop();

                if (top == '(' || operatorPriority(top) < operatorPriority(_expression[i]))
                {
                    expStack.push(top);
                    break;
                }

                postfix += top;
                postfix += ' ';
            }

            expStack.push(_expression[i]);
        }
        else if (_expression[i] == '(')
        {
            expStack.push(_expression[i]);
        }
        else if (_expression[i] == ')')
        {
            while (!expStack.empty())
            {
                char top = expStack.top();
                expStack.pop();

                if (top == ')')
                {
                    break;
                }

                postfix += top;
                postfix += ' ';
            }
        }
        else if (std::isdigit(_expression[i]))
        {
            while (std::isdigit(_expression[i]))
            {
                postfix += _expression[i++];
            }

            postfix += ' ';

            --i;
        }
    }

    while (!expStack.empty())
    {
        char top = expStack.top();
        expStack.pop();

        postfix += top;
        postfix += ' ';
    }

    return postfix;
}

double MathSolver::calculation(double _operandLeft, double _operandRight, char _operator)
{
    double result;

    switch (_operator)
    {
        case '-':
            result = _operandLeft - _operandRight;
            break;
        case '+':
            result = _operandLeft + _operandRight;
            break;
        case '/':
            result = _operandLeft / _operandRight;
            break;
        case '*':
            result = _operandLeft * _operandRight;
            break;
        case '^':
            result = std::pow(_operandLeft, _operandRight);
            break;
        case '%':
            result = std::fmod(_operandLeft, _operandRight);
            break;
    }

    return result;
}

double MathSolver::solve(const std::string& _expression)
{
    std::string postfixExpression = convertToPostfix(_expression);

    std::stack<double> calStack;

    for (size_t i = 0, length = postfixExpression.length(); i < length; ++i)
    {
        if (isOperator(postfixExpression[i]))
        {
            double right, left;

            right = calStack.top();
            calStack.pop();

            left = calStack.top();
            calStack.pop();

            double result = calculation(left, right, postfixExpression[i]);

            calStack.push(result);
        }
        else if (std::isdigit(postfixExpression[i]))
        {
            double result = 0;

            while (std::isdigit(postfixExpression[i]))
            {
                result = (result*10)+(postfixExpression[i]-'0');
                ++i;
            }

            calStack.push(result);

            --i;
        }
    }

    double result = calStack.top();
    calStack.pop();

    return result;
}