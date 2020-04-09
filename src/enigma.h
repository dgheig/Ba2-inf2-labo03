#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include "rotor.h"
#include "reflector.h"

typedef std::vector<Rotor> Rotors;

class Enigma {

    public:
        Enigma(Reflector reflector, std::vector<Rotor> rotors);
        char press(char c);
        std::string encrypt(const std::string& text);
        void reset();
        Rotors& getRotors();

    private:
        void rotateFirstRotor();
        Rotors _rotors;
        Reflector _reflector;
};


#endif // ENIGMA_H