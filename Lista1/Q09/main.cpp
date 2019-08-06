#include <iostream>

using namespace std;

int main()
{
    int numero, n_seq;


    n_seq = -1;
    while(n_seq < 0){
        cout << "Quantos numeros tera a sequencia?: " << endl;
        cin >> n_seq;
    }
    int *seq = new int[n_seq];
    int *fatorial = new int[n_seq];

    for (int i=0; i < n_seq; i++) {
        numero = -1;
        while(numero < 0){
            cout << "Digite o numero: " << endl;
            cin >> numero;
            seq[i] = numero;
            fatorial[i] = 1;
            for (int j=0; j < numero; j++) {
                fatorial[i] = fatorial[i] * (numero-j);
            }
        }
    }


    for (int k = 0; k < n_seq; k++ ){
        cout << "Numero = " <<seq[k] << endl;
        cout << "Fatorial = " <<fatorial[k] << endl;
    }

    return 0;
}
