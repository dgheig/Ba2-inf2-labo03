#include "rotor.h"
#include <string>

unsigned charToUnsigned(char c);

Rotor::Rotor(std::string match, char notch, unsigned rotation): _match(match), _notch(notch), _rotation(rotation) {

}

Rotor::Rotor(std::string match, char notch, char position): Rotor(match, notch, charToUnsigned(position)) {

}

char Rotor::translate(char c) { // 'A' < c < 'Z'
    if( c < 'A' or c > 'Z')
        return c; // We do not handle characters that are not letters
    size_t index = (charToUnsigned(c) + _rotation) % 26;
    return _match[index];
}

bool Rotor::rotate() {
    bool notch_passed = _match[_rotation] == _notch;
    _rotation = (_rotation + 1) % 26;
    return notch_passed;
}
    
unsigned charToUnsigned(char c) { // 'A' < c < 'Z'
    return c - 'A';
}


Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', 'A');
Rotor rotor_II ("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', 'A');
Rotor rotor_III ("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A');