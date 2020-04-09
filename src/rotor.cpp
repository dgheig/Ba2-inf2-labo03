#include "rotor.h"
#include <string>

#ifdef DEBUG
#include <iostream>
#endif

int charToInt(char c);
char intToChar(int index);

Rotor::Rotor(std::string match, char notch, int rotation): _match(match), _notch(notch), _rotation(rotation) {

}

Rotor::Rotor(std::string match, char notch, char position): Rotor(match, notch, charToInt(position)) {

}

char Rotor::translate(char c) { // 'A' <= c <= 'Z'
    if( c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    size_t index = (charToInt(c) + _rotation) % 26;
    return intToChar(((charToInt(_match[index]) - _rotation) % 26));
}

char Rotor::backwardTranslate(char c) {
    if( c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    char charForMapping = intToChar((charToInt(c) + _rotation)  % 26);
    int index = _match.find(charForMapping);

    #ifdef DEBUG
        std::cout << "got char: "               << c
                << " and found index: "       << index
                << " with char for mapping: " << charForMapping
                << std::endl;
    #endif

    // if != string::npos
    return intToChar((index - _rotation) % 26);
}

bool Rotor::rotate() {
    bool notch_passed = _match[_rotation] == _notch;
    _rotation = (_rotation + 1) % 26;
    return notch_passed;
}


int Rotor::getRotation() {
    return _rotation;
}

    
int charToInt(char c) { // 'A' <= c <= 'Z'
    return c - 'A';
}
char intToChar(int index) { // 0 <= index < 26
    return char( index + 'A');
}


const Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', 'A');
const Rotor rotor_II ("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', 'A');
const Rotor rotor_III ("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A');

const Rotor reflector_B("YRUHQSLDPXNGOKMIEBFZCWVJAT");