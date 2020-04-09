#include "reflector.h"

#include "utilities.h"
#include <string>

Reflector::Reflector(std::string match): _match(match) {

}

char Reflector::translate(char c) { // 'A' <= c <= 'Z'
    if( c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    return _match[charToInt(c)];
}

char Reflector::backwardTranslate(char c) {
    if( c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    int index = _match.find(c);
    // if index != string::npos
    return intToChar(index);
}

const Reflector reflector_B("YRUHQSLDPXNGOKMIEBFZCWVJAT");