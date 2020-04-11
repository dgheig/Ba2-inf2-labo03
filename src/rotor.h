/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : rotor.h
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Declare class Rotor
Remark(s)   :

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef ROTOR_H
#define ROTOR_H

#include <string>
#include "reflector.h"

const char DEFAULT_NOTCH = 'A';

/*!
 * @class Rotor
 * @brief Representation of a rotor of the enigma machine
 */
class Rotor {

    public:
        Rotor(std::string match, char notch = DEFAULT_NOTCH, int rotation = 0);
        Rotor(std::string match, char notch, char position);

        // Rotor& operator=(const Rotor& rotor);
        void reset();
        
        char translate(char c) const;

        /*!
        * @param c character to backward translate
        * @brief This is the inverse function of translate, also only handle uppercase characters
        */
        char backwardTranslate(char c) const;

        /*!
        * @brief Rotate the rotor
        * @return true if the notch is passed, else return false
        */
        bool rotate(); // return true if notch is passed

        void setRotation(int rotation);
        void setRotation(char rotation);
        int getRotation() const;

        bool setNotch(char notch);
        char getNotch() const;

    private:
        int WithRotation(int c) const;
        int WithoutRotation(int c) const;
        char WithRotation(char c) const;
        char WithoutRotation(char c) const;
        
        Reflector _match;
        char _notch; // rotor I, notch Q 	If rotor steps from Q to R, the next rotor is advanced
        int _rotation;

        int _initial_rotation;
};

extern const Rotor rotor_I;
extern const Rotor rotor_II;
extern const Rotor rotor_III;


#endif // ROTOR_H