#include "opdef.hpp"

// Function pointer for operator function
typedef double (*OPERATION)(double[]);

// Type of operator ie. Unary or Binary
// The type can also be used as the number of operands
enum OpType {
    UNARY = 1,
    BINARY,
    INVALID_OP
};

// Precedence Levels
enum PrecLevels {
    INVALID_PREC = -1,
    NEGATIVE,
    ARITHMETIC_L1,
    ARITHMETIC_L2,
    COMPARATOR,
    LOGICAL,
    FUNCTION
};

// Data about operators
struct OpData
{
    OpType type;
    const char* name;
    const char* str;
    PrecLevels prec;
    OPERATION operate;

    OpData(OpType type, const char* name, const char* str, PrecLevels prec, OPERATION op)
    : type(type), name(name), str(str), prec(prec), operate(op) {}
};

// List of operators
// Add new operators to this list
const OpData opDataList[] = {
    OpData(UNARY,       "Negation",         "-",        NEGATIVE,       NEG),

    OpData(BINARY,      "Multiplication",   "*",        ARITHMETIC_L1,  MULTIPLY),
    OpData(BINARY,      "Division",         "/",        ARITHMETIC_L1,  DIVIDE),
    OpData(BINARY,      "Exponentiation",   "^",        ARITHMETIC_L1,  EXPONENT),

    OpData(BINARY,      "Addition",         "+",        ARITHMETIC_L2,  ADD),
    OpData(BINARY,      "Subtraction",      "-",        ARITHMETIC_L2,  SUBTRACT),

    OpData(BINARY,      "Equal",            "==",       COMPARATOR,     EQUAL),
    OpData(BINARY,      "Greater",          ">",        COMPARATOR,     GREATER),
    OpData(BINARY,      "Greater Equal",    ">=",       COMPARATOR,     GREATER_EQUAL),
    OpData(BINARY,      "Lesser",           "<",        COMPARATOR,     LESSER),
    OpData(BINARY,      "Lesser Equal",     "<=",       COMPARATOR,     LESSER_EQUAL),
    OpData(BINARY,      "Not Equal",        "!=",       COMPARATOR,     NOT_EQUAL),

    OpData(UNARY,       "Not",              "!",        LOGICAL,        NOT),
    OpData(UNARY,       "Not",              "not",      LOGICAL,        NOT),
    OpData(BINARY,      "And",              "&&",       LOGICAL,        AND),
    OpData(BINARY,      "And",              "and",      LOGICAL,        AND),
    OpData(BINARY,      "Or",               "||",       LOGICAL,        OR),
    OpData(BINARY,      "Or",               "or",       LOGICAL,        OR),

    // Logarithmic Functions
    OpData(UNARY,       "Natural Log",      "ln",       FUNCTION,       NATURAL_LOG),
    OpData(BINARY,      "Log",              "log",      FUNCTION,       LOG),
    
    // Trigonometric Functions
    OpData(UNARY,       "Sin",              "sin",      FUNCTION,       SIN),
    OpData(UNARY,       "Cos",              "cos",      FUNCTION,       COS),
    OpData(UNARY,       "Tan",              "tan",      FUNCTION,       TAN),
    OpData(UNARY,       "Sec",              "sec",      FUNCTION,       SEC),
    OpData(UNARY,       "Cosec",            "cosec",    FUNCTION,       COSEC),
    OpData(UNARY,       "Cot",              "cot",      FUNCTION,       COT),

    // Marks the end of list
    OpData(INVALID_OP,  "Invalid",          "`",        INVALID_PREC,   INVALID)
};