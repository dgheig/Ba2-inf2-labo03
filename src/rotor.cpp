#include "rotor.h"


Rotor::Rotor(std::string match, unsigned rotation): _match(match), _rotation(rotation) {

}

char Rotor::translate(char c) { // 'A' < c < 'Z'
    size_t index = int(c) - int('A');
    char res = char(_match[index]);
    return res;
}

void Rotor::rotate() {
    ++_rotation;
}
    