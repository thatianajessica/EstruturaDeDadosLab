#include <iostream>

using namespace std;

bool tem_digitos_consecutivos(unsigned int num) {
    //se o número só tem um dígito ele não pode ter dígitos consecutivos.
    if (num%10 == 0) {
        return false;
    }

    int ultimo_digito = num%10; //ultimo digito
    int proximo_digito = (num%100-num%10)/10; //penultimo digito

    while (num%10 != 0) {
        if (ultimo_digito == proximo_digito) {
            return true;
        } else {
            num = num/10;
            ultimo_digito = proximo_digito; //ultimo digito ATUALIZADO
            proximo_digito = (num%100-num%10)/10; //penultimo digito ATUALIZADO
        }
    }

    return false;
}


int main() {

    unsigned int numero;

    cout << "Digite um numero: ";
    cin >> numero;
    cout << endl;

    if(tem_digitos_consecutivos(numero) == true) {
        cout << numero << " tem digitos consecutivos" << endl;
    } else {
        cout << "NAO tem digitos consecutivos";
    }

    return 0;
}
