#include "utilities.h"

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}
    
int charToInt(char c) { // 'A' <= c <= 'Z'
    return c - 'A';
}

char intToChar(int index) { // 0 <= index < 26
    return char( index + 'A');
}