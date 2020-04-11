/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : rotor.h
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Declare class Rotor
Remark(s)   : _rotation is a int because it is oriented

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

        /*!
        * @brief Reset the rotor to its initial states
        * @return Reference on the rotor
        */
        Rotor& reset();
        
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

        /*!
        * @param rotation the current rotation of the rotor
        * @brief Set the rotation of the rotor
        * @return Reference on the rotor
        */
        Rotor& setRotation(int rotation);

        /*!
        * @param rotation the current rotation of the rotor
        * @brief Set the rotation of the rotor
        * @return Reference on the rotor
        */
        Rotor& setRotation(char rotation);
        
        /*!
        * @return The current rotation of the rotor
        */
        int getRotation() const;

        /*!
        * @brief Set the notch if it is valid
        * @return true if the notch is valid, else false
        */
        bool setNotch(char notch);

        /*!
        * @return Return the notch of the rotor
        */
        char getNotch() const;

    private:
        /*!
        * @param index index to offset
        * @brief Add offset corresponding to the rotor's rotation 
        */
        int WithRotation(int index) const;

        /*!
        * @param index index to offset
        * @brief Remove offset corresponding to the rotor's rotation 
        */
        int WithoutRotation(int index) const;

        /*!
        * @param c character to offset
        * @brief Add offset corresponding to the rotor's rotation 
        */
        char WithRotation(char c) const;

        /*!
        * @param c character to offset
        * @brief Remove offset corresponding to the rotor's rotation 
        */
        char WithoutRotation(char c) const;
        
        Reflector _match;


        /*!
        * @brief If rotor steps from _notch to another character, the next rotor must be advanced
        */
        char _notch;

        /*!
        * @brief Current rotation state of the rotor
        */
        int _rotation;
        
        /*!
        * @brief Holds the initial rotation for reset
        */
        int _initial_rotation;
};

extern const Rotor rotor_I;
extern const Rotor rotor_II;
extern const Rotor rotor_III;


#endif // ROTOR_H