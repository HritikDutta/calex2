#include "operators.hpp"
#include "opdef.hpp"

// Function pointer for operator function
typedef double (*OPERATION)(double[]);

// Keyword types: Constant or Operator
// Empty is used to mark the end of keywords list
enum KeywordType {
    CONSTANT,
    OPERATOR,
    EMPTY
};

// Structure to store data about keywords
// All keywords have a type, name and string

// Constants have values

// Operators have optype(Unary or Binary),
// precedence level and an operate function
struct KeywordData
{
    KeywordType type;
    const char* name;
    const char* str;

    union {
        // CONSTANT
        struct {
            const double value;
        };

        // OPERATOR
        struct {
            OpType opType;
            PrecLevel prec;
            OPERATION operate;
        };
    };

    // For CONSTANT
    KeywordData(const char* name, const char* str, const double value)
    : type(CONSTANT), name(name), str(str), value(value) {}

    // For OPERATOR
    KeywordData(OpType opType, const char* name, const char* str, PrecLevel prec, OPERATION op)
    : type(OPERATOR), opType(opType), name(name), str(str), prec(prec), operate(op) {}

    KeywordData()
    : type(EMPTY), name(nullptr), str(nullptr) {}

};

// List of Allowed Keywords
const KeywordData keywords[] = {

    /*-------------------------------------CONSTANTS--------------------------------------*/

    KeywordData("Pi",       "pi",   M_PI),
    KeywordData("Exponent", "e",    M_E),

    /*-------------------------------------OPERATORS--------------------------------------*/

    KeywordData(UNARY,       "Negation",         "-",        NEGATIVE,       NEG),

    KeywordData(UNARY,       "Square Root",      "sqrt",     ARITHMETIC_L1,  SQRT),
    KeywordData(UNARY,       "Exponentiation",   "exp",      ARITHMETIC_L1,  EXP),
    KeywordData(BINARY,      "Multiplication",   "*",        ARITHMETIC_L1,  MULTIPLY),
    KeywordData(BINARY,      "Division",         "/",        ARITHMETIC_L1,  DIVIDE),
    KeywordData(BINARY,      "Power",            "^",        ARITHMETIC_L1,  POW),
    KeywordData(BINARY,      "Power",            "pow",      ARITHMETIC_L1,  POW),

    KeywordData(BINARY,      "Addition",         "+",        ARITHMETIC_L2,  ADD),
    KeywordData(BINARY,      "Subtraction",      "-",        ARITHMETIC_L2,  SUBTRACT),

    KeywordData(BINARY,      "Equal",            "==",       COMPARATOR,     EQUAL),
    KeywordData(BINARY,      "Greater",          ">",        COMPARATOR,     GREATER),
    KeywordData(BINARY,      "Greater Equal",    ">=",       COMPARATOR,     GREATER_EQUAL),
    KeywordData(BINARY,      "Lesser",           "<",        COMPARATOR,     LESSER),
    KeywordData(BINARY,      "Lesser Equal",     "<=",       COMPARATOR,     LESSER_EQUAL),
    KeywordData(BINARY,      "Not Equal",        "!=",       COMPARATOR,     NOT_EQUAL),

    KeywordData(UNARY,       "Not",              "!",        LOGICAL,        NOT),
    KeywordData(UNARY,       "Not",              "not",      LOGICAL,        NOT),
    KeywordData(BINARY,      "And",              "&&",       LOGICAL,        AND),
    KeywordData(BINARY,      "And",              "and",      LOGICAL,        AND),
    KeywordData(BINARY,      "Or",               "||",       LOGICAL,        OR),
    KeywordData(BINARY,      "Or",               "or",       LOGICAL,        OR),

    // Logarithmic Functions
    KeywordData(UNARY,       "Natural Log",      "ln",       FUNCTION,       NATURAL_LOG),
    KeywordData(BINARY,      "Log",              "log",      FUNCTION,       LOG),
    
    // Trigonometric Functions
    KeywordData(UNARY,       "Sin",              "sin",      FUNCTION,       SIN),
    KeywordData(UNARY,       "Cos",              "cos",      FUNCTION,       COS),
    KeywordData(UNARY,       "Tan",              "tan",      FUNCTION,       TAN),
    KeywordData(UNARY,       "Sec",              "sec",      FUNCTION,       SEC),
    KeywordData(UNARY,       "Cosec",            "cosec",    FUNCTION,       COSEC),
    KeywordData(UNARY,       "Cot",              "cot",      FUNCTION,       COT),

    /*------------------------------------END OF LIST-------------------------------------*/
    KeywordData()   //Empty keyword
};