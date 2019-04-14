// Definitions for operators
// Every function takes an double array and returns a double
// Function names must be in capital letters

#include <cmath>

double NEG(double operands[])
{
    return -1 * operands[0];
}

double MULTIPLY(double operands[])
{
    return operands[0] * operands[1];
}

double DIVIDE(double operands[])
{
    return operands[0] / operands[1];
}

double ADD(double operands[])
{
    return operands[0] + operands[1];
}

double SUBTRACT(double operands[])
{
    return operands[0] - operands[1];
}

double EXPONENT(double operands[])
{
    return pow(operands[0], operands[1]);
}

double INVALID(double operands[])
{
    return -1.0;
}

double AND(double operands[])
{
    return operands[0] && operands[1];
}

double OR(double operands[])
{
    return operands[0] || operands[1];
}

double NOT(double operands[])
{
    return !operands[0];
}

double GREATER(double operands[])
{
    return operands[0] > operands[1];
}

double LESSER(double operands[])
{
    return operands[0] < operands[1];
}

double GREATER_EQUAL(double operands[])
{
    return operands[0] >= operands[1];
}

double LESSER_EQUAL(double operands[])
{
    return operands[0] <= operands[1];
}

double EQUAL(double operands[])
{
    return operands[0] == operands[1];
}

double NOT_EQUAL(double operands[])
{
    return operands[0] != operands[1];
}

double NATURAL_LOG(double operands[])
{
    return log(operands[0]);
}

double LOG(double operands[])
{
    return log(operands[1]) / log(operands[0]);
}