#include "rotor.h"

#include "utilities.h"
#include <string>

// #define DEBUG

#ifdef DEBUG
#include <iostream>
#endif


Rotor::Rotor(std::string match, char notch, int rotation): _match(match), _notch(notch), _rotation(rotation), _initial_rotation(rotation) {

}

Rotor::Rotor(std::string match, char notch, char position): Rotor(match, notch, charToInt(position)) {

}


void Rotor::reset() {
    _rotation = _initial_rotation;
}

char Rotor::translate(char c) { // 'A' <= c <= 'Z'
    if(c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    char mappingChar = WithRotation(c);
    return WithoutRotation(_match.translate(mappingChar));
}

char Rotor::backwardTranslate(char c) {
    if(c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    char charForMapping = WithRotation(c);

    // if != string::npos
    return WithoutRotation(_match.backwardTranslate(charForMapping));
}

bool Rotor::rotate() {
    bool notch_passed = _match.translate(intToChar(_rotation)) == _notch;
    _rotation = mod(_rotation + 1, 26);
    return notch_passed;
}


int Rotor::getRotation() {
    return _rotation;
}

int Rotor::WithRotation(int index) {
    return mod(index + _rotation, 26);
}

int Rotor::WithoutRotation(int index) {
    return mod(index - _rotation, 26);
}

char Rotor::WithRotation(char c) {
}

char Rotor::WithoutRotation(char c) {
    return intToChar(WithoutRotation(charToInt(c)));
}




const Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', 'A');
const Rotor rotor_II ("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', 'A');
const Rotor rotor_III ("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A');
