#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>

class Reflector {

    public:
        Reflector(std::string match);
        
        char translate(char c);
        char backwardTranslate(char c);

    private:
        std::string _match;
};

extern const Reflector reflector_B;


#endif // REFLECTOR_H