#include <iostream>

#include "parser.hpp"
#include "solver.hpp"

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

    // Rudimentary Error Handling
    // If post expression is empty, close program
    if (post.size() == 0)
        return 1;
    
    for (auto p: post)
        p.print();

    std::cout << "\b\b " << std::endl;

    double res = solveExpr(post);

    std::cout << res << std::endl;

    return 0;
}
