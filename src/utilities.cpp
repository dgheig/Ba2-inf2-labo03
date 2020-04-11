#include "utilities.h"

unsigned mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

unsigned alphaIndex(int a) {
    return mod(a, 26);
}

int alphaIndex(char c) {
    return c - 'A';
}

char indexToChar(int index) { // 0 <= index < 26
    return char( index + 'A');
}