#include "rotor.h"

#include "utilities.h"
#include <string>

// #define DEBUG

#ifdef DEBUG
#include <iostream>
#endif


Rotor::Rotor(std::string match, char notch, int rotation): _match(match), _notch(notch), _rotation(rotation) {

}

Rotor::Rotor(std::string match, char notch, char position): Rotor(match, notch, charToInt(position)) {

}

char Rotor::translate(char c) { // 'A' <= c <= 'Z'
    if( c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    size_t index = mod((charToInt(c) + _rotation), 26);
    return intToChar(mod(charToInt(_match[index]) - _rotation, 26));
}

char Rotor::backwardTranslate(char c) {
    if( c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    char charForMapping = intToChar(mod(charToInt(c) + _rotation, 26));
    int mappingIndex = _match.find(charForMapping);
    int index = mod(mappingIndex - _rotation, 26);

    #ifdef DEBUG
        std::cout << "got char: "                   << c
                  << " found mappingIndex: "        << mappingIndex
                  << " with char for mapping: "     << charForMapping
                  << " | found index for result: "  << index
                  << std::endl;
    #endif

    // if != string::npos
    return intToChar(index);
}

bool Rotor::rotate() {
    bool notch_passed = _match[_rotation] == _notch;
    _rotation = mod(_rotation + 1, 26);
    return notch_passed;
}


int Rotor::getRotation() {
    return _rotation;
}



const Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', 'A');
const Rotor rotor_II ("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', 'A');
const Rotor rotor_III ("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A');

const Rotor reflector_B("YRUHQSLDPXNGOKMIEBFZCWVJAT");