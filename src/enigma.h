/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : enigma.h
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Declare class Enigma
Remark(s)   : The enigma machine normally use 3 rotors but could use more
              Since the user should have full access on the rotors,
              We chose to return the reference on the vector of rotors.
              

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include "rotor.h"
#include "reflector.h"

typedef std::vector<Rotor> Rotors;


/*!
 * @class Enigma
 * @brief Representation of the enigma machine. 
 */
class Enigma {

    public:
        Enigma(Reflector reflector, const Rotors& rotors);

        /*!
        * @param c character we want to encrypt
        * @brief Return the encrypted input if it is an alphabetic character, else return the character
        */
        char encrypt(char c);

        /*!
        * @param text text
        * @brief Return the encrypted input
        */
        std::string encrypt(const std::string& text);

        /*!
        * @brief Reset the enigma machine to its initial configuration
        * @return Reference on the enigma object
        */
        Enigma& reset();

        /*!
        * @brief get the rotors, this is the way to change them
        */
        Rotors& getRotors();

        /*!
        * @brief set the reflector of the enigma machine
        * @return Reference on the enigma object
        */
        Enigma& setReflector(const Reflector& reflector);

    private:
        /*!
        * @param c character we want to encrypt
        * @brief Return the encrypted input if it is an uppercase character, else return the character
        */
        char _encrypt(char c);

        /*!
        * @brief rotate the first rotor and the following while the notch is passed
        */
        void rotateFirstRotor();
        
        Reflector _reflector;
        Rotors _rotors;
};


#endif // ENIGMA_H