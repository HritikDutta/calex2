// Definitions for operators
// Every function takes an double array and returns a double
// Function names must be in capital letters

#include <cmath>

// Negation Operator
double NEG(double operands[])
{
    return -1 * operands[0];
}

// Multiplication Operator
double MULTIPLY(double operands[])
{
    return operands[0] * operands[1];
}

// Division Operator
double DIVIDE(double operands[])
{
    return operands[0] / operands[1];
}

// Addition Operator
double ADD(double operands[])
{
    return operands[0] + operands[1];
}

// Subtraction Operator
double SUBTRACT(double operands[])
{
    return operands[0] - operands[1];
}

// Power Operator
double POW(double operands[])
{
    return pow(operands[0], operands[1]);
}

// And Operator
double AND(double operands[])
{
    return operands[0] && operands[1];
}

// Or Operator
double OR(double operands[])
{
    return operands[0] || operands[1];
}

// Not Operator
double NOT(double operands[])
{
    return !operands[0];
}

// Greater Than Operator
double GREATER(double operands[])
{
    return operands[0] > operands[1];
}

// Lesser Than Operator
double LESSER(double operands[])
{
    return operands[0] < operands[1];
}

// Greater Than/Equal To Operator
double GREATER_EQUAL(double operands[])
{
    return operands[0] >= operands[1];
}

// Lesser Than/Equal To Operator
double LESSER_EQUAL(double operands[])
{
    return operands[0] <= operands[1];
}

// Equal To Operator
double EQUAL(double operands[])
{
    return operands[0] == operands[1];
}

// Not Equal To Operator
double NOT_EQUAL(double operands[])
{
    return operands[0] != operands[1];
}

// Natural Log Function
double NATURAL_LOG(double operands[])
{
    return log(operands[0]);
}

// Log Function
double LOG(double operands[])
{
    return log(operands[1]) / log(operands[0]);
}

// Sine Function
double SIN(double operands[])
{
    return sin(operands[0]);
}

// Cosine Function
double COS(double operands[])
{
    return cos(operands[0]);
}

// Tangent Function
double TAN(double operands[])
{
    return tan(operands[0]);
}

// Secant Function
double SEC(double operands[])
{
    return 1 / cos(operands[0]);
}

// Cosecant Function
double COSEC(double operands[])
{
    return 1 / sin(operands[0]);
}

// Cotangent Function
double COT(double operands[])
{
    return 1 / tan(operands[0]);
}

// Square Root Function
double SQRT(double operands[])
{
    return sqrt(operands[0]);
}

// Exponentiation (e^x) Function
double EXP(double operands[])
{
    return exp(operands[0]);
}