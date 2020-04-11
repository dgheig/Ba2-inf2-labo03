/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : reflector.h
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Declare class Reflector
Remark(s)   :

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>

/*!
 * @class Reflector
 * @brief Class used to map uppercase letters to others
 */
class Reflector {

    public:
        Reflector(std::string match);

        /*!
        * @param c character to translate
        * @brief Return the char mapped to c, it only handle uppercase characters
        */
        char translate(char c) const;

        /*!
        * @param c character to backward translate
        * @brief This is the inverse function of translate, also only handle uppercase characters
        */
        char backwardTranslate(char c) const;

    private:
        std::string _match;
};

extern const Reflector reflector_B;


#endif // REFLECTOR_H