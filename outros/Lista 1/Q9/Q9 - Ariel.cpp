#include <iostream>

using namespace std;

unsigned int fatorial(unsigned int num) {
    unsigned int fat = 1; //inicia em um pois é o termo neutro da multiplicação

    for (unsigned int cont = num; cont >= 1; --cont) {
        fat = fat*cont;
    }

    return fat;
}



int main () {

    unsigned int numero;

    cout << "Digite um numero: ";
    cin >> numero;
    cout << endl;

    cout << numero << "! = " << fatorial(numero) << endl;



    return 0;
}
