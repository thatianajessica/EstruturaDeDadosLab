#include <iostream>

using namespace std;

int primeiro_digito(unsigned int num) {
    int digito = 0;

    while(num%10 != 0) {
        digito = num%10;
        num = num/10;
    }

    return digito;
}

int ultimo_digito(unsigned int num) {
    return num%10;
}


int main () {

    unsigned int numero;

    cout << "Digite um numero: ";
    cin >> numero;
    cout << endl;

    if (primeiro_digito(numero) == ultimo_digito(numero)) {
        cout << "o primeiro e o ultimo digito sao iguais." << endl;
    } else {
        cout << "NAO sao iguais" << endl;
    }

    return 0;
}
