#ifndef ENIGMA_MACHINE_H
#define ENIGMA_MACHINE_H

#include <vector>
#include "rotor.h"

class EnigmaMachine {

    public:
        EnigmaMachine(std::vector<Rotor> rotors);
        char press(char c);
        std::string encrypt(std::string text);

    private:
        std::vector<Rotor> _rotors;
}


#endif // ENIGMA_MACHINE_H