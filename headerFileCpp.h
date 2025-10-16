#ifndef HEADERFILECPP_H
#define HEADERFILECPP_H

#include <string>
using namespace std;

class Hexadecimal {
private:
    string hexadecimal;

public:
    Hexadecimal() = default;
    Hexadecimal(string hexadecimal);

    void setNumber(string hexadecimal);
    string getHexadecimal(); // ← nome alterado
    unsigned int decimal();

    operator int(); // permite retorno direto no main
};

#endif
