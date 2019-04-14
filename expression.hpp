#include <iostream>

#include "operators.hpp"

// Type of element ie. Data, Operator or Bracket
enum ElementType {
    DATA,
    OPERATOR,
    BRACKET
};

// Type of bracket ie. Opening or Closing
enum BracketType {
    OPENING_BRACKET,
    CLOSING_BRACKET
};

// All elements in the expression are stored in a container
struct ElemContainer
{
    ElementType type;

    union {
        // DATA
        double value;

        // OPERATOR
        int opCode;

        // BRACKET
        BracketType isOpen;
    };

    // For DATA
    ElemContainer(double value)
    : type(DATA), value(value) {}

    // For OPERATOR
    ElemContainer(int opCode)
    : type(OPERATOR), opCode(opCode) {}

    // For BRACKET
    ElemContainer(BracketType isOpen)
    : type(BRACKET), isOpen(isOpen) {}

    void print()
    {
        std::cout << "{";
        switch(type)
        {
        case DATA:
            std::cout << "DATA, " << value;
            break;
        
        case OPERATOR:
            std::cout << "OPERATOR, " << opDataList[opCode].str;
            break;

        case BRACKET:
            std::cout << "BRACKET, " << isOpen;
            break;
        }

        std::cout << "}, ";
    }
};