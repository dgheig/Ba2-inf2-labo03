#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include "rotor.h"
#include "reflector.h"

class Enigma {

    public:
        Enigma(Reflector reflector, std::vector<Rotor> rotors);
        char press(char c);
        std::string encrypt(const std::string& text);
        void reset();

    private:
        void rotateFirstRotor();
        std::vector<Rotor> _rotors;
        Rotor _reflector;
};


#endif // ENIGMA_H