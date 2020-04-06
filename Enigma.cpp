/*
 -----------------------------------------------------------------------------------------------
 Laboratoire : Test_Labo03
 Fichier     : enigma.cpp
 Auteur(s)   : Nils Basset
 Date        : 28.03.2020

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------------------
 */

#include "enigma.h"
#include <iostream>
using namespace std;

Enigma::Enigma(Rotor rotorLeft, const char& posRotorLeft, Rotor rotorMiddle, const char& posRotorMiddle,
               Rotor rotorRight, const char& posRotorRight, const Reflector& reflectorEnigma):
        rotorLeft(rotorLeft), posRotorLeft(posRotorLeft), rotorMiddle(rotorMiddle),
        posRotorMiddle(posRotorMiddle), rotorRight(rotorRight), posRotorRight(posRotorRight), reflectorEnigma(reflectorEnigma){

    this->rotorLeft = rotorLeft.RotateRotor(posRotorLeft);
    this->rotorMiddle = rotorMiddle.RotateRotor(posRotorMiddle);
    this->rotorRight = rotorRight.RotateRotor(posRotorRight);

}
unsigned nextPos;
string msgFinal;
string Enigma::EncryptMsg(std::string encryptMsg) {
    this->rotorRight = rotorRight.RotateRotor();
    nextPos = rotorRight.CryptRightToLeft(encryptMsg.at(0) - 65);

    if(Rotor::rotateNextRotor)
        this->rotorMiddle = rotorMiddle.RotateRotor();
    nextPos = rotorMiddle.CryptRightToLeft(nextPos);

    if(Rotor::rotateNextRotor)
        this->rotorLeft = rotorLeft.RotateRotor();
    nextPos = rotorLeft.CryptRightToLeft(nextPos);

    nextPos = reflectorEnigma.Crypt(nextPos);

    nextPos = rotorLeft.CryptLeftToRight(nextPos);

    nextPos = rotorMiddle.CryptLeftToRight(nextPos);

    nextPos = rotorRight.CryptLeftToRight(nextPos);

    msgFinal += clavier.at(nextPos);

    encryptMsg = encryptMsg.erase(0,1);
    if(not encryptMsg.empty()){
        EncryptMsg(encryptMsg);
    }
    return msgFinal;
}
