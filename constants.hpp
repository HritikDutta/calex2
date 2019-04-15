#include <cmath>

struct ConstData
{
    const char* name;
    const char* str;
    const double value;

    ConstData(const char* name, const char* str, double value)
    : name(name), str(str), value(value) {}
};

const ConstData constDataList[] = {
    ConstData("Pi",         "pi",   M_PI),

    // Marks the end of the list
    ConstData("Zero",       "0",    0.0)
};