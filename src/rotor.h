#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor {

    public:
        Rotor(std::string match, char notch = 'A', unsigned rotation = 0);
        Rotor(std::string match, char notch, char position);
        
        char translate(char c);

        bool rotate(); // return true if notch is passed

    private:
        char _notch; // rotor I, notch Q 	If rotor steps from Q to R, the next rotor is advanced
        unsigned _rotation;
        std::string _match;
};

extern Rotor rotor_I;
extern Rotor rotor_II;
extern Rotor rotor_III;


#endif // ROTOR_H