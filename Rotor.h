/*
 -----------------------------------------------------------------------------------------------
 Laboratoire : Test_Labo03
 Fichier     : Rotor.h
 Auteur(s)   : Nils Basset
 Date        : 28.03.2020

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------------------
 */

#ifndef ROTOR_H
#define ROTOR_H
#include <string>
#include <vector>


/*    "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
    "ESOVPZJAYQUIRHXLNFTGKDCMWB",
    "VZBRGITYUPSDNHLXAWMJQOFECK"
*/

class Rotor {
    friend std::ostream& operator<<(std::ostream& os, const Rotor& rotor);

private:
    const std::string id, wiring;
    const char notch;
    std::string entry;
    std::string posWiring, posEntry;

public:
    Rotor(const std::string& id, const std::string& wiring, const char& notch);
    Rotor& RotateRotor();
    Rotor& RotateRotor(char init);
    static bool rotateNextRotor;
    unsigned CryptRightToLeft(unsigned pos);
    unsigned CryptLeftToRight(unsigned pos);
    Rotor& operator=(const Rotor& rotor);
};


#endif //ROTOR_H




