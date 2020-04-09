#ifndef ENIGMA_MACHINE_H
#define ENIGMA_MACHINE_H

#include <vector>
#include "rotor.h"

class EnigmaMachine {

    public:
        EnigmaMachine(Rotor reflector, std::vector<Rotor> rotors);
        char press(char c);
        std::string encrypt(const std::string& text);
        void reset();

    private:
        void rotateFirstRotor();
        std::vector<Rotor> _rotors;
        Rotor _reflector;
};


#endif // ENIGMA_MACHINE_H