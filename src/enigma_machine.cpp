#include "enigma_machine.h"

EnigmaMachine::EnigmaMachine(std::vector<Rotor> rotors): _rotors(rotors) {

}

char EnigmaMachine::press(char c) {
    for(auto& rotor: _rotors) {
        c = rotor.translate(c);
    }
    rotateFirstRotor();
    return c;
}

void EnigmaMachine::rotateFirstRotor() {
    bool rotate = true;
    for(size_t index = 0; index < _rotors.size() and rotate; ++index) {
        rotate = _rotors[index].rotate();
    }
}

std::string EnigmaMachine::encrypt(std::string text) {
    std::string crypted;
    for(char c: text) {
        crypted += press(c);
    }
}