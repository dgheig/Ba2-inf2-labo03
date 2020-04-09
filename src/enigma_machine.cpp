#include "enigma_machine.h"

// #define DEBUG

#ifdef DEBUG
#include <iostream>
#endif
#include <iostream>

Enigma::Enigma(Reflector reflector, std::vector<Rotor> rotors): _reflector(reflector), _rotors(rotors) {

}

char Enigma::press(char c) {

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

void Enigma::rotateFirstRotor() {
    bool rotate = true;
    for(size_t index = 0; index < _rotors.size() and rotate; ++index) {
        rotate = _rotors[index].rotate();
    }
}

std::string Enigma::encrypt(const std::string& text) {
    std::string crypted;
    for(char c: text) {
        crypted.push_back(press(c));
    }
    return crypted;
}


void Enigma::reset() {
    for(auto& rotor: _rotors) {
        rotor.reset();
    }
}

Rotors& Enigma::getRotors() {
    return _rotors;
}
