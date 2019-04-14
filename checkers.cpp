// Checks if character is a digit
bool isDigit(const char& ch)
{
    return ((ch >= '0') && (ch <= '9'));
}

// Checks if character is an alphabet
bool isAlphabet(const char& ch)
{
    return ((ch >= 'a') && (ch <= 'z'))
        || ((ch >= 'A') && (ch <= 'Z'));
}

// Checks if character is a whitespace
bool isWhiteSpace(const char& ch)
{
    return ch == ' ' || ch == '\t' || ch == '\n';
}