#include "checkers.cpp"

// Returns length of string
int strlen(const char* str)
{
    int len = 0;
    while (str[len++]);

    return len - 1;
}

// Converts string to double and moves idx to end of the number
double strToDouble(const char* str, int& idx)
{
    double d = 0.0, m = 1.0;
    bool decimal = false;

    for (; str[idx] == '.' || isDigit(str[idx]); idx++)
    {
        if (str[idx] == '.')
        {
            decimal = true;
            continue;
        }

        if (!decimal)
            d *= 10;
        else
            m /= 10;

        d += m * (str[idx] - '0');
    }

    idx--;
    return d;
}

// Compares substring
bool compareSubString(const char* str1, int beg, const char* str2, int len)
{
    int idx = 0;
	while (idx < len)
	{	
		if (str1[beg + idx] != str2[idx])
			return false;
		
		idx++;
	}
	
	return true;
}