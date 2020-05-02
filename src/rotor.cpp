/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : rotor.cpp
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Function definition for header rotor.h
Remark(s)   :

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include "rotor.h"

#include "utilities.h"
#include <string>
#include <cctype>

// #define DEBUG

#ifdef DEBUG
#include <iostream>
#endif


Rotor::Rotor(const std::string& match, char notch, int rotation): _match(match), _rotation(rotation), _initial_rotation(rotation) {
    setNotch(notch);
}

Rotor::Rotor(const std::string& match, char notch, char position): Rotor(match, notch, alphaIndex(position)) {

}


Rotor& Rotor::reset() {
    _rotation = _initial_rotation;
    return *this;
}

char Rotor::translate(char c) const { // 'A' <= c <= 'Z'
    if(!isupper(c))
        return c; // We do not handle characters that are not letters
    char mappingChar = WithRotation(c);
    #ifdef DEBUG
        std::cout << "receive: " << c << std::endl
                  << "mappingChar: " << mappingChar << std::endl
                  << std::endl;
    #endif
    return WithoutRotation(_match.translate(mappingChar));
}

char Rotor::backwardTranslate(char c) const {
    if(!isupper(c))
        return c; // We do not handle characters that are not letters
    char mappingChar = WithRotation(c);
    #ifdef DEBUG
        std::cout << "receive: " << c << std::endl
                  << "mappingChar: " << mappingChar << std::endl
                  << std::endl;
    #endif

    // if != string::npos
    return WithoutRotation(_match.backwardTranslate(mappingChar));
}

bool Rotor::rotate() {
    bool notch_passed = indexToChar(_rotation) == _notch;
    _rotation = alphaIndex(_rotation + 1);
    return notch_passed;
}


Rotor& Rotor::setRotation(int rotation) {
    _rotation = alphaIndex(rotation);
    return *this;
}

Rotor& Rotor::setRotation(char rotation) {
    if(islower(rotation))
        rotation = (char)toupper(rotation);
    if(isupper(rotation))
        setRotation(alphaIndex(rotation));
    return *this;
}

int Rotor::getRotation() const {
    return _rotation;
}

Rotor& Rotor::setInitialRotation(int rotation) {
    _initial_rotation = alphaIndex(rotation);
    return *this;
}

Rotor& Rotor::setInitialRotation(char rotation) {
    if(islower(rotation))
        rotation = (char)toupper(rotation);
    if(isupper(rotation))
        setInitialRotation(alphaIndex(rotation));
    return *this;
}

int Rotor::getInitialRotation() const {
    return _initial_rotation;
}

bool Rotor::setNotch(char notch) {
    if(islower(notch))
        notch = (char)toupper(notch);

    if(isupper(notch)) {
        _notch = notch;
        return true;
    }
    
    _notch = DEFAULT_NOTCH;
    return false;
}

char Rotor::getNotch() const {
    return _notch;
}

std::string Rotor::getWiring() const {
    return _match.getWiring();
}

int Rotor::WithRotation(int index) const {
    return alphaIndex(index + _rotation);
}

int Rotor::WithoutRotation(int index) const {
    return alphaIndex(index - _rotation);
}

char Rotor::WithRotation(char c) const {
    return indexToChar(WithRotation(alphaIndex(c)));
}

char Rotor::WithoutRotation(char c) const {
    return indexToChar(WithoutRotation(alphaIndex(c)));
}




const Rotor ROTOR_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', 'A');
const Rotor ROTOR_II ("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', 'A');
const Rotor ROTOR_III ("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A');
