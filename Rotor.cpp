/*
 -----------------------------------------------------------------------------------------------
 Laboratoire : Test_Labo03
 Fichier     : Rotor.cpp
 Auteur(s)   : Nils Basset
 Date        : 28.03.2020

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------------------
 */
#include <iostream>
#include "Rotor.h"
#include <algorithm>
using namespace std;

bool Rotor::rotateNextRotor = false;

std::ostream& operator<<(std::ostream& os, const Rotor& rotor){
    os << "rotor ID : " << rotor.id << endl;
    os << "entry    : " << endl;
    os << "wiring   : " << rotor.wiring << endl;
    os << "position : " << endl;
    os << "notch    : " << rotor.notch << endl;
    os << "__________________________" << endl;
    return os;
}

Rotor& Rotor::operator=(const Rotor& rotor){
    (string&)this->id = rotor.id;
    (string&)this->wiring = rotor.wiring;
    this->entry = rotor.entry;
    this->posEntry = rotor.posEntry;
    this->posWiring = rotor.posWiring;
    return *this;
}

//Constructeur
Rotor::Rotor(const std::string& id, const std::string& wiring, const char& notch) : id(id), wiring(wiring), notch(notch){
    this->entry = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    this->posWiring = wiring;
    this->posEntry = entry;
}

//Rotation du Rotor
Rotor& Rotor::RotateRotor() {
    this->rotateNextRotor = posEntry.at(0) == notch;
    std::rotate(posWiring.begin(), posWiring.begin() + 1, posWiring.end());
    std::rotate(posEntry.begin(), posEntry.begin() + 1, posEntry.end());
    return *this;
}

//Rotation du Rotor position d'initialisation de l'Enigma
Rotor& Rotor::RotateRotor(char init) {
    while(*posEntry.begin() != init){
        std::rotate(posWiring.begin(), posWiring.begin() + 1, posWiring.end());
        std::rotate(posEntry.begin(), posEntry.begin() + 1, posEntry.end());
    }
    return *this;
}

//Cryptage d'une lettre de droite à gauche en prenant la lettre du wiring et indique sa position sur l'entrée
unsigned Rotor::CryptRightToLeft(unsigned pos) {
    return posEntry.find(posWiring.at(pos));
}

//Cryptage d'une lettre de gauche à droite en prenant la lettre de l'entrée et indique sa postion sur le wiring
unsigned Rotor::CryptLeftToRight(unsigned pos) {
    return posWiring.find(posEntry.at(pos));
}
