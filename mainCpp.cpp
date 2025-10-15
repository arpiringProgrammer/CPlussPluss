#include <string>
#include <iostream>
#include "headerFileCpp.h"

using namespace std;


int main() {

    NumeroRomano number(1234);

    cout << number.toString() << endl;

    unsigned int arabico = number.converterRomanoParaArabico("MDCCCXCIX");
    cout << "MDCCCXCIX -> " << arabico << endl;
    
    return 0;
}