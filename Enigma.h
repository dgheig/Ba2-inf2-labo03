/*
 -----------------------------------------------------------------------------------------------
 Laboratoire : Test_Labo03
 Fichier     : Enigma.h
 Auteur(s)   : Nils Basset
 Date        : 28.03.2020

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------------------
 */

#ifndef ENIGMA_H
#define ENIGMA_H

#include "Rotor.h"
#include "Reflector.h"

class Enigma {
private:
    Rotor rotorLeft;
    const char posRotorLeft;
    Rotor rotorMiddle;
    const char posRotorMiddle;
    Rotor rotorRight;
    const char posRotorRight;
    Reflector reflectorEnigma;
    const std::string clavier = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
    Enigma(Rotor rotorLeft, const char& posRotorLeft, Rotor rotorMiddle, const char& posRotorMiddle, Rotor rotorRight, const char& posRotorRight, const Reflector& reflectorEnigma);
    std::string EncryptMsg(std::string encryptMsg);
};


#endif //ENIGMA_H
