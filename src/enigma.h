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
        void setReflector(const Reflector& reflector);

    private:
        char _press(char c);
        void rotateFirstRotor();
        
        Reflector _reflector;
        Rotors _rotors;
};


#endif // ENIGMA_H