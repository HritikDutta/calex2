#include <iostream>
#include <vector>

#include "expression.hpp"
#include "stack.hpp"
#include "functions.hpp"

// Check if first operator has higher precedence than second
bool greaterPrec(int op1, int op2)
{
    if (keywords[op1].opType == OpType::UNARY
        && keywords[op2].opType == OpType::BINARY)
        return false;
    
    if (keywords[op1].prec < keywords[op2].prec)
        return false;

    return true;
}

// Parse string into a postfix expression
std::vector<ElemContainer> in_post(const char*& expr)
{
    std::vector<ElemContainer> post;
    Stack<ElemContainer> opStack;

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
        if (expr[idx] == BracketType::OPENING_BRACKET)
        {
            opStack.push(ElemContainer(expr[idx]));
            
            // '-' after opening bracket is unary
            allow_neg = true;
            continue;
        }

        // If closing bracket is encountered
        if (expr[idx] == BracketType::CLOSING_BRACKET)
        {
            while (opStack.top().type != ElementType::BRACKET)
            {
                post.push_back(opStack.top());
                opStack.pop();
            }

            // Pop bracket
            opStack.pop();

            // '-' after closing bracket is binary
            allow_neg = false;
            continue;
        }

        // Check for keywords

        // Find code for keyword
        int kwCode = 0;
        bool found = false;

        for (int i = 0; keywords[i].type != EMPTY; i++)
        {
            // Don't check for negation if allow_neg is false
            if (keywords[i].prec == NEGATIVE && !allow_neg)
                continue;

            const char* kw = keywords[i].str;
            if (compareSubString(expr, idx, strlen(kw), kw))
            {
                // The longest matching substring is considered the correct keyword
                if (!found || strlen(keywords[kwCode].str) <= strlen(kw))
                    kwCode = i;

                found = true;
            }
        }

        // If not found
        if (!found)
            continue;

        // If keyword is a constant
        if (keywords[kwCode].type == CONSTANT)
            // Value is pushed directly
            post.push_back(ElemContainer(keywords[kwCode].value));
        else {
            // Pop operators and push them into expression until the stack is empty,
            // a bracket is encountered or the next operator has greater precedence
            while (!opStack.empty()
                && opStack.top().type != ElementType::BRACKET
                && greaterPrec(kwCode, opStack.top().kwCode))
            {
                post.push_back(opStack.top());
                opStack.pop();
            }

            // Push operator into stack
            opStack.push(ElemContainer(kwCode));
        }

        // Move idx to the end of the keyword
        idx += strlen(keywords[kwCode].str) - 1;

        // '-' after any keyword is unary
        allow_neg = true;
    }

    // Add all remaining operators to expression
    while (!opStack.empty())
    {
        post.push_back(opStack.top());
        opStack.pop();
    }

    return post;
}