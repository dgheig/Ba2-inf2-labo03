#ifndef ROTOR_H
#define ROTOR_H

#include <string>
#include "reflector.h"

class Rotor {

    public:
        Rotor(std::string match, char notch = 'A', int rotation = 0);
        Rotor(std::string match, char notch, char position);

        // Rotor& operator=(const Rotor& rotor);
        void reset();
        
        char translate(char c);
        char backwardTranslate(char c);

        bool rotate(); // return true if notch is passed

        void setRotation(int rotation);
        void setRotation(char rotation);
        int getRotation() const;

    private:
        int WithRotation(int c) const;
        int WithoutRotation(int c) const;
        char WithRotation(char c) const;
        char WithoutRotation(char c) const;
        
        Reflector _match;
        char _notch; // rotor I, notch Q 	If rotor steps from Q to R, the next rotor is advanced
        int _rotation;

        int _initial_rotation;
};

extern const Rotor rotor_I;
extern const Rotor rotor_II;
extern const Rotor rotor_III;


#endif // ROTOR_H