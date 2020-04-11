/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : reflector.cpp
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Function definition for header reflector.h
Remark(s)   :

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include "reflector.h"

#include "utilities.h"
#include <string>
#include <cctype>

// #define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

Reflector::Reflector(std::string match): _match(match) {

}

char Reflector::translate(char c) const { // 'A' <= c <= 'Z'
    if(!isupper(c))
        return c; // We do not handle characters that are not uppercase letters
    #ifdef DEBUG
        std::cout << "reflector receive: " << c << std::endl;
    #endif
    return _match[alphaIndex(c)];
}

char Reflector::backwardTranslate(char c) const {
    if(!isupper(c))
        return c; // We do not handle characters that are not letters
    #ifdef DEBUG
        std::cout << "reflector receive: " << c << std::endl;
    #endif
    int index = (int)_match.find(c);
    // if index != string::npos
    return indexToChar(index);
}

const Reflector reflector_B("YRUHQSLDPXNGOKMIEBFZCWVJAT");