#include "enigma_machine.h"

EnigmaMachine::EnigmaMachine(std::vector<Rotor> rotors): _rotors(rotors) {

}

char EnigmaMachine::press(char c) {
    return c;
}

std::string EnigmaMachine::encrypt(std::string text) {
    std::string crypted;
    for(char c: text) {
        crypted += press(c);
    }
}