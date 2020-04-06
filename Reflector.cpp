/*
 -----------------------------------------------------------------------------------------------
 Laboratoire : Test_Labo03
 Fichier     : Reflector.cpp
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
#include "Reflector.h"

Reflector::Reflector(const std::string id, const std::string wiring) : id(id), wiring(wiring) {
    this->entry = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

unsigned Reflector::Crypt(unsigned pos) {
    return entry.find(wiring.at(pos));
}