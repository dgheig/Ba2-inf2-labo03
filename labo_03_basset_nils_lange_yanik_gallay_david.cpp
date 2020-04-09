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
    EnigmaMachine enigma ({rotor_I, rotor_II, rotor_III});
    
    cout << enigma.press('A') << endl;
    cout << enigma.press('A') << endl;
    cout << enigma.press('A') << endl;
    cout << enigma.press('A') << endl;
    cout << enigma.press('A') << endl;

    cout << "Please, press <ENTER> to end the program" << endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
