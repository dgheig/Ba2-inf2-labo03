#include "enigma_machine.h"

#ifdef DEBUG
#include <iostream>
#endif

EnigmaMachine::EnigmaMachine(Rotor reflector, std::vector<Rotor> rotors): _reflector(reflector), _rotors(rotors) {

}

char EnigmaMachine::press(char c) {

    #ifdef DEBUG
        std::cout << "receive: " << c << std::endl;
    #endif

    rotateFirstRotor();
    for(auto& rotor: _rotors) {
        c = rotor.translate(c);
        #ifdef DEBUG
            std::cout << "translated to: " << c << std::endl;
        #endif
    }

    c = _reflector.translate(c);
    #ifdef DEBUG
        std::cout << "reflected to: " << c << std::endl;
    #endif

    for(size_t index = _rotors.size(); index > 0 ; --index) {
        c = _rotors[index - 1].backwardTranslate(c) ;
        #ifdef DEBUG
            std::cout << "backwardTranslated to: " << c << std::endl;
        #endif
    }

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