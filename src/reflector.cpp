#include "reflector.h"

#include "utilities.h"
#include <string>
#include <cctype>

// #define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

Reflector::Reflector(std::string match): _match(match) {

}

char Reflector::translate(char c) const { // 'A' <= c <= 'Z'
    if(!isupper(c))
        return c; // We do not handle characters that are not uppercase letters
    #ifdef DEBUG
        std::cout << "reflector receive: " << c << std::endl;
    #endif
    return _match[alphaIndex(c)];
}

char Reflector::backwardTranslate(char c) const {
    if(!isupper(c))
        return c; // We do not handle characters that are not letters
    #ifdef DEBUG
        std::cout << "reflector receive: " << c << std::endl;
    #endif
    int index = _match.find(c);
    // if index != string::npos
    return indexToChar(index);
}

const Reflector reflector_B("YRUHQSLDPXNGOKMIEBFZCWVJAT");