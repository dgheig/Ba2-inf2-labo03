#include <iostream>
#include "Rotor.h"
#include "Enigma.h"
#include <cstdlib>

using namespace std;

int main() {
    Rotor rot1("I", "EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');
    Rotor rot2("II", "AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E');
    Rotor rot3("III", "BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V');
    Rotor rot4("IV", "ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J');
    Rotor rot5("V", "VZBRGITYUPSDNHLXAWMJQOFECK", 'Z');
    Reflector ref1("UKW-A", "EJMZALYXVBWFCRQUONTSPIKHGD");
    Reflector ref2("UKW-B", "YRUHQSLDPXNGOKMIEBFZCWVJAT");
    Reflector ref3("UKW-C", "FVPJIAOYEDRZXWGCTKUQSBNMHL");


    Enigma e1(rot2, 'C', rot4, 'K', rot1, 'M', ref2);
    cout << e1.EncryptMsg("CLZJVMUOAQAGFQJSMOYQLPLCTN");

    return EXIT_SUCCESS;
}
