/*
 -----------------------------------------------------------------------------------------------
 Laboratoire : Test_Labo03
 Fichier     : Reflector.h
 Auteur(s)   : Nils Basset
 Date        : 28.03.2020

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------------------
 */

#ifndef REFLECTOR_H
#define REFLECTOR_H
#include <string>
#include <vector>

std::vector<std::string> const vWiringReflector{
        "NOT_USE",
        "EJMZALYXVBWFCRQUONTSPIKHGD",
        "YRUHQSLDPXNGOKMIEBFZCWVJAT",
        "FVPJIAOYEDRZXWGCTKUQSBNMHL"
};

class Reflector {
private:
    std::string id, wiring, entry;
    unsigned pos;

public:
    Reflector(const std::string id, const std::string wiring);
    unsigned Crypt(unsigned pos);
};


#endif //REFLECTOR_H
