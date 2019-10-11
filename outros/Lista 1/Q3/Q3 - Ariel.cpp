#include <iostream>

using namespace std;

void printa_sequencia(unsigned int num, unsigned int i, unsigned int j) {

    unsigned int cont = 0;
    unsigned int numero_multiplo = 0;

    while (cont < num) {
        if (numero_multiplo%i == 0 || numero_multiplo%j == 0) { //o número pode ser múltiplo de i, de j ou de ambos
            cout << numero_multiplo << " ";                     //o número que passar é exatamente o que quero printar;
            cont++;
        }

        numero_multiplo++;

    }

}


int main () {

    unsigned int numero, i, j;

    cout << "Digite um valor para 'numero': ";
    cin >> numero;
    cout << endl << "Digite um valor para 'i' ";
    cin >> i;
    cout << endl << "Digite um valor para 'j' ";
    cin >> j;

    printa_sequencia(numero, i, j);


    return 0;
}
