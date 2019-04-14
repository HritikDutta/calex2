#include <iostream>
#include <vector>

#include "expression.hpp"
#include "stack.hpp"
#include "functions.hpp"

// Check if first operator has higher precedence than second
bool greaterPrec(int op1, int op2)
{
    if (opDataList[op1].type == OpType::UNARY
        && opDataList[op2].type == OpType::BINARY)
        return false;
    
    if (opDataList[op1].prec < opDataList[op2].prec)
        return false;

    return true;
}

// Parse string into a postfix expression
std::vector<ElemContainer> in_post(const char* expr)
{
    std::vector<ElemContainer> post;
    Stack<ElemContainer> ops;

    int len = strlen(expr);

    for (int idx = 0; idx < len; idx++)
    {
        // Ignore white spaces
        if (isWhiteSpace(expr[idx]))
            continue;

        // If digits are encountered
        if (isDigit(expr[idx]))
        {
            double val = strToDouble(expr, idx);
            post.push_back(ElemContainer(val));
            continue;
        }

        // If opening bracket is encountered
        if (expr[idx] == '(')
        {
            ops.push(ElemContainer(BracketType::OPENING_BRACKET));
            continue;
        }

        // If closing bracket is encountered
        if (expr[idx] == ')')
        {
            while (ops.top().type != BRACKET)
            {
                post.push_back(ops.top());
                ops.pop();
            }

            // Pop bracket
            ops.pop();
            continue;
        }

        // Determine opCode for operator
        int opCode = 0;
        while (opDataList[opCode].prec != -1)
        {
            const char* opStr = opDataList[opCode].str;
            if (compareSubString(expr, idx, opStr, strlen(opStr)))
                break;
            
            opCode++;
        }

        // If a valid operator is not encountered
        if (opDataList[opCode].prec == -1)
            continue;

        // Keep popping operators and adding to expression till stack is empty,
        // bracket is encountered or an operator of greater precedence is encountered
        while (!ops.empty()
            && ops.top().type != ElementType::BRACKET
            && greaterPrec(opCode, ops.top().opCode))
        {
            post.push_back(ops.top());
            ops.pop();
        }

        ops.push(ElemContainer(opCode));
        
        // Move cursor to end of operator
        idx += strlen(opDataList[opCode].str) - 1;
    }

    // Add all remaining operators to expression
    while (!ops.empty())
    {
        post.push_back(ops.top());
        ops.pop();
    }

    return post;
}