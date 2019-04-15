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

    // Keeps track if '-' is unary or binary
    bool allow_neg = true;

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

            // '-' after a number is binary
            allow_neg = false;
            continue;
        }

        // If opening bracket is encountered
        if (expr[idx] == '(')
        {
            ops.push(ElemContainer(BracketType::OPENING_BRACKET));
            
            // '-' after opening bracket is unary
            allow_neg = true;
            continue;
        }

        // If closing bracket is encountered
        if (expr[idx] == ')')
        {
            while (ops.top().type != ElementType::BRACKET)
            {
                post.push_back(ops.top());
                ops.pop();
            }

            // Pop bracket
            ops.pop();

            // '-' after closing bracket is binary
            allow_neg = false;
            continue;
        }

        // Check for operators

        // Determine opCode for operator
        // Ignore negation if allow_neg is false
        int opIdx = !allow_neg;
        int opCode = opIdx;
        bool found = false;

        while (opDataList[opIdx].prec != -1)
        {
            const char* opStr = opDataList[opIdx].str;
            if (compareSubString(expr, idx, strlen(opStr), opStr))
            {
                // The longest operator string that matches is the correct one
                if (strlen(opDataList[opCode].str) < strlen(opStr))
                {
                    opCode = opIdx;
                    found = true;
                }
            }
            
            opIdx++;
        }

        // If a valid operator is not encountered
        if (!found)
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

        // '-' after any operator is unary
        allow_neg = true;
    }

    // Add all remaining operators to expression
    while (!ops.empty())
    {
        post.push_back(ops.top());
        ops.pop();
    }

    return post;
}