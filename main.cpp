#include <iostream>

#include "parser.hpp"
#include "solver.hpp"

bool balancedBrackets(const char* str)
{
    int open = 0;

    //Closing brackets before opening brackets make expression unbalanced
    for (int i = 0; str[i] && open >= 0; i++)
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
            open--;
    }

    //Negative means more ')'
	//Positive means more '('
	return open == 0;
}

int main(int argc, char const *argv[])
{
    // Exit if no string is given
    if (argc < 2)
        return 0;

    const char*& expr = argv[1];

    // Check if brackets are balanced
    if (!balancedBrackets(expr))
    {
        std::cerr << "Unbalanced Brackets" << std::endl;
        return 1;
    }

    auto post = in_post(expr);

    double res = solveExpr(post);

    std::cout << res << std::endl;

    return 0;
}
