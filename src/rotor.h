#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor {

    public:
        Rotor(std::string match, char notch = 'A', int rotation = 0);
        Rotor(std::string match, char notch, char position);
        
        char translate(char c);
        char backwardTranslate(char c);

        bool rotate(); // return true if notch is passed

        int getRotation();

    private:
        char _notch; // rotor I, notch Q 	If rotor steps from Q to R, the next rotor is advanced
        int _rotation;
        std::string _match;
};

extern const Rotor rotor_I;
extern const Rotor rotor_II;
extern const Rotor rotor_III;


extern const Rotor reflector_B;


#endif // ROTOR_H