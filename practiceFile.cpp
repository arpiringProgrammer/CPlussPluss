#include <iostream>
#include <cmath>
#include "headerFileCpp.h"

using namespace std;

Hexadecimal::Hexadecimal(string hexadecimal) {
    this->hexadecimal = hexadecimal;
}

void Hexadecimal::setNumber(string hexadecimal) {
    this->hexadecimal = hexadecimal;
}

string Hexadecimal::getHexadecimal() {
    return this->hexadecimal;
}

unsigned int Hexadecimal::decimal() {
    int number = 0;
    int counter = 0;

    for (int index = hexadecimal.length() - 1; index >= 0; index--, counter++) {
        char hexa = hexadecimal[index];
        if (hexa >= '0' && hexa <= '9') {
            number += (hexa - '0') * pow(16, counter);
        } else if (hexa >= 'A' && hexa <= 'F') {
            number += (hexa - 'A' + 10) * pow(16, counter);
        } else if (hexa >= 'a' && hexa <= 'f') {
            number += (hexa - 'a' + 10) * pow(16, counter);
        }
    }

    return number;
}

Hexadecimal::operator int() {
    setNumber("f");
    cout << "The hexadecimal of the number " << getHexadecimal()
         << " is " << decimal() << endl;
    return 0;
}

int main() {
    return Hexadecimal();
}
