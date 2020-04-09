#include "reflector.h"

#include "utilities.h"
#include <string>

// #define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

Reflector::Reflector(std::string match): _match(match) {

}

char Reflector::translate(char c) { // 'A' <= c <= 'Z'
    if( c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    #ifdef DEBUG
        std::cout << "reflector receive: " << c << std::endl;
    #endif
    return _match[charToInt(c)];
}

char Reflector::backwardTranslate(char c) {
    if( c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    #ifdef DEBUG
        std::cout << "reflector receive: " << c << std::endl;
    #endif
    int index = _match.find(c);
    // if index != string::npos
    return intToChar(index);
}

const Reflector reflector_B("YRUHQSLDPXNGOKMIEBFZCWVJAT");