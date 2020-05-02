/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : labo_03_basset_nils_lange_yanik_gallay_david.cpp
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Prove the good working of classes defined in others files.
Remark(s)   :
                There is the github repository:
                https://github.com/dgheig/Ba2-labo03

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "src/rotor.h"
#include "src/enigma.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {
    Enigma enigma (REFLECTOR_B, {ROTOR_I, ROTOR_II, ROTOR_III});
    
    std::string s = "VIVELINFORMATIQUEALAHEIGVD";
    std::string crypted = enigma.encrypt(s);
    std::string expected = "EQCDTAFRFJXWBOHFOCPQGRVYMA";
    cout << s << std::endl;
    cout << crypted << std::endl;
    cout << expected << std::endl;
    // enigma.reset();
    // cout << enigma.encrypt(crypted) << std::endl;

    cout << "Please, press <ENTER> to end the program" << endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
