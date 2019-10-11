#include <iostream>

using namespace std;

bool is_triangular (unsigned int num) {

    unsigned int numero_teste = 1;

    while( numero_teste*(numero_teste + 1)*(numero_teste + 2) <= num) {
        if (numero_teste*(numero_teste + 1)*(numero_teste + 2) == num) {
            return true;
        } else {
            numero_teste++;
        }
    }

    return false;

}

int main () {

    unsigned int numero;

    cout << "Digite o valor de um numero: ";
    cin >> numero;

    if (is_triangular(numero) == 1) {
        cout << "O numero eh triangular" << endl;
    } else {
        cout << "NAO eh triangular" << endl;
    }

    return 0;
}
