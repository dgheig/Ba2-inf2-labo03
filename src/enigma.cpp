/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : enigma.cpp
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Function definition for header enigma.h
Remark(s)   :

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include "enigma.h"

// #define DEBUG

#ifdef DEBUG
#include <iostream>
#endif
#include <cctype>

Enigma::Enigma(Reflector reflector, const Rotors& rotors): _reflector(reflector), _rotors(rotors) {

}

char Enigma::encrypt(char c) {

    if(islower(c))
        return (char)tolower(_encrypt((char)toupper(c)));

    return _encrypt(c);
}

char Enigma::_encrypt(char c) {

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
        crypted.push_back(encrypt(c));
    }
    return crypted;
}


Enigma& Enigma::reset() {
    for(auto& rotor: _rotors) {
        rotor.reset();
    }
    return *this;
}

Rotors& Enigma::getRotors() {
    return _rotors;
}

Enigma& Enigma::setReflector(const Reflector& reflector) {
    _reflector = reflector;
    return *this;
}
