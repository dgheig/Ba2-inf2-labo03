/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : reflector.h
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Declare class Reflector
Remark(s)   : About setting _match as const,
              It is a choice, not an omission

              https://www.reddit.com/r/cpp/comments/8wbeom/coding_guideline_avoid_const_member_variables/
              https://stackoverflow.com/questions/38155699/are-there-advantages-of-using-const-member-variable-in-c

              Speaking with my own words, those objects are designed as copyable and movable.
              Since all explicit functions are const qualified, the constness of the string is granted
              except for assignation, what we want.

              Breaking the const with a cast is a bad practice and sign of bad design.

              An other choice of implementation would be to not make copies and only hold references,
              using static allocation. In this case, defining member as const would have sense.

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
        /*!
        * @param match string containing all uppercase letter once and only once, otherwise, the behaviour is undefined
        */
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

        /*!
        * @return Return the wiring of the reflector
        */
        std::string getWiring() const;

    private:
        std::string _match;
};

extern const Reflector REFLECTOR_B;


#endif // REFLECTOR_H