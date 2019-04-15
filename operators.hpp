// Type of operator ie. Unary or Binary
// The type can also be used as the number of operands
enum OpType {
    UNARY = 1,
    BINARY,
    TERNARY
};

// Precedence Levels
enum PrecLevel {
    INVALID_PREC = -1,
    NEGATIVE,
    ARITHMETIC_L1,
    ARITHMETIC_L2,
    COMPARATOR,
    LOGICAL,
    FUNCTION,
    CONDITIONAL
};