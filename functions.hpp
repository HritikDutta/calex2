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

        d *= ((decimal * 1) + (!decimal * 10));
        m /= ((decimal * 10) + (!decimal * 1));

        d += m * (str[idx] - '0');
    }

    idx--;
    return d;
}

// Compares substring
bool compareSubString(const char* str1, int beg, int len, const char* str2)
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

// Check if brackets are balanced in given string
bool balancedBrackets(const char* str)
{
    int open = 0;

    //Closing brackets before opening brackets make expression unbalanced
    for (int i = 0; str[i] && open >= 0; i++)
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
            open--;
    }

    //Negative means more ')'
	//Positive means more '('
	return open == 0;
}