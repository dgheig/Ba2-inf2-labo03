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

Compiler    : g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "src/rotor.h"
#include "src/enigma_machine.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {
    EnigmaMachine enigma (reflector_B, {rotor_I, rotor_II, rotor_III});
    
    std::string s = "TEST";
    std::string crypted = enigma.encrypt(s);
    cout << s << std::endl;
    cout << crypted << std::endl;
    enigma.reset();
    cout << enigma.encrypt(crypted) << std::endl;

    cout << "Please, press <ENTER> to end the program" << endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
