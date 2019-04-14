#include "opdef.hpp"

// Function pointer for operator function
typedef double (*OPERATION)(double*);

// Type of operator ie. Unary or Binary
// The type can also be used as the number of operands
enum OpType {
    UNARY = 1,
    BINARY,
    INVALID_OP
};

// Data about operators
struct OpData
{
    OpType type;
    const char* name;
    const char* str;
    int prec;
    OPERATION operate;

    OpData(OpType type, const char* name, const char* str, int prec, OPERATION op)
    : type(type), name(name), str(str), prec(prec), operate(op) {}
};

// List of operators
// Add new operators to this list
const OpData opDataList[] = {
    OpData(BINARY,      "Multiplication",   "*",    1,  MULTIPLY),
    OpData(BINARY,      "Division",         "/",    1,  DIVIDE),
    OpData(BINARY,      "Exponentiation",   "^",    1,  EXPONENT),

    OpData(BINARY,      "Addition",         "+",    2,  ADD),
    OpData(BINARY,      "Subtraction",      "-",    2,  SUBTRACT),
    
    OpData(INVALID_OP,  "Invalid",          "`",    -1, INVALID)
};