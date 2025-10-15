#include <string>
#include <iostream>
#include "headerFileCpp.h"

using namespace std;


// Inicia os atributos do objeto NumeroRomano com os valores do número arábico e romano.
NumeroRomano::NumeroRomano(unsigned int numeroArabico) : numeroArabico(numeroArabico) {}
// Inicia os atributos do objeto NumeroRomano com os valores do número romano e arábico.
NumeroRomano::NumeroRomano(string numeroRomano) : numeroRomano(numeroRomano) {}
// Retorna o valor do número romano.
string NumeroRomano::getNumeroRomano() {
    return numeroRomano;
}
// Retorna o valor do número arábico.
unsigned int NumeroRomano::getNumeroArabico() {
    return numeroArabico;
}
/* Retorna uma string usando o formato NúmeroArábico -> NúmeroRomano
Exemplos:

27 -> XXVII
150 -> CL

*/
string NumeroRomano::toString() {
    string roman = converterArabicoParaRomano(numeroArabico);
    return to_string(numeroArabico) + "-> " + roman;
}
// Converte o número arábico para romano.
string NumeroRomano::converterArabicoParaRomano(unsigned int numeroArabico) {
    string romanNumber;
    while(numeroArabico > 0) {
        if(numeroArabico >= 1000) {
            romanNumber += 'M';
            numeroArabico -= 1000;
        } else if(numeroArabico >= 900) {
            romanNumber += "CM";
            numeroArabico -= 900;
        } else if(numeroArabico >= 500) {
            romanNumber += 'D';
            numeroArabico -= 500;
        } else if(numeroArabico >= 400) {
            romanNumber += "CD";
            numeroArabico -= 400;
        } else if(numeroArabico >= 100) {
            romanNumber += 'C';
            numeroArabico -= 100;
        } else if(numeroArabico >= 90) {
            romanNumber += "XC";
            numeroArabico -= 90;
        } else if(numeroArabico >= 50) {
            romanNumber += 'L';
            numeroArabico -= 50;
        } else if(numeroArabico >= 40) {
            romanNumber += "XL";
            numeroArabico -= 40;
        } else if(numeroArabico >= 10) {
            romanNumber += 'X';
            numeroArabico -= 10;
        } else if(numeroArabico == 9) {
            romanNumber += "IX";
            numeroArabico -= 9;
        } else if(numeroArabico >= 5) {
            romanNumber += 'V';
            numeroArabico -= 5;
        } else if(numeroArabico == 4) {
            romanNumber += "IV";
            numeroArabico -= 4;
        }else if(numeroArabico >= 1) {
            romanNumber += 'I';
            numeroArabico -= 1;
        }
    }
    return romanNumber;
}
// Converte o número romano para arábico.
unsigned int NumeroRomano::converterRomanoParaArabico(string numeroRomano) {
    int number = 0, index = 0;
    while(numeroRomano[index] != '\0') {
        if(numeroRomano[index] == 'M') {
            number += 1000;
        }
        else if(numeroRomano[index] == 'C') {
            if((index + 1 < numeroRomano.length()) && numeroRomano[index + 1] == 'D') {
                number += 400;
                index++;
            } else if((index + 1 < numeroRomano.length()) && numeroRomano[index + 1] == 'M') {
                number += 900;
                index++;
            } else {
                number += 100;
            }
        }
        else if(numeroRomano[index] == 'D') {
            number += 500;
        }
        else if(numeroRomano[index] == 'X') {
            if((index + 1 < numeroRomano.length()) && numeroRomano[index + 1] == 'L') {
                number += 40;
                index++;
            } else if((index + 1 < numeroRomano.length()) && numeroRomano[index + 1] == 'C') {
                number += 90;
                index++;
            } else {
                number += 10;
            }
        }
        else if(numeroRomano[index] == 'L') {
            number += 50;
        }
        else if(numeroRomano[index] == 'I') {
            if((index + 1 < numeroRomano.length()) && numeroRomano[index + 1] == 'X') {
                number += 9;
                index++;
            } else if((index + 1 < numeroRomano.length()) && numeroRomano[index + 1] == 'V') {
                number += 4;
                index++;
            } else {
                number += 1;
            }
        }
        else if(numeroRomano[index] == 'V') {
            number += 5;
        }
        index++; 
    }
    return number;
}