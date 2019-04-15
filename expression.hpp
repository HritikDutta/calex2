#include <iostream>

#include "keywords.hpp"

// Type of element ie. Data, Operator or Bracket
enum ElementType {
    DATA,
    KEYWORD,
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
        int kwCode;

        // BRACKET
        BracketType isOpen;
    };

    // For DATA
    ElemContainer(double value)
    : type(DATA), value(value) {}

    // For KEYWORD
    ElemContainer(int kwCode)
    : type(KEYWORD), kwCode(kwCode) {}

    // For BRACKET
    ElemContainer(BracketType isOpen)
    : type(BRACKET), isOpen(isOpen) {}

    // Print method for debugging
    void print()
    {
        std::cout << "{";
        switch(type)
        {
        case DATA:
            std::cout << "DATA: " << value;
            break;
        
        case OPERATOR:
            std::cout << "KEYWORD: " << keywords[kwCode].str;
            break;

        case BRACKET:
            std::cout << "BRACKET: " << isOpen;
            break;
        }

        std::cout << "}, ";
    }
};