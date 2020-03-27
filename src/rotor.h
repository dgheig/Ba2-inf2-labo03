#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor {

    public:
        Rotor(std::string match, unsigned rotation = 0): _match(match), _rotation(rotation) {}
        
        char translate(char c) { // 'A' < c < 'Z'
            if( c < 'A' or c > 'Z')
                return c; // We do not handle characters that are not letters
            size_t index = (int(c) - int('A') + _rotation) % 26;
            return _match[index];
        }

        void rotate() {

        }

    private:
        unsigned _rotation;
        std::string _match;
}


#endif // ROTOR_H