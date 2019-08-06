#include <iostream>

using namespace std;

int main()
{
    int n_sequencias, numero, seq = 0;


    cout << "Digite o numero de sequencias: " << endl;
    cin >> n_sequencias;

    int *soma = new int[n_sequencias];


    cout << "==========================================================" << endl;
    while(seq < n_sequencias){
        numero = 1;
        soma[seq] = 0;
        while(numero != 0){
            cout << "Digite os numeros da sequencia: " << endl;
            cin >> numero;
            if(numero % 2 == 0){
                soma[seq] += numero;
            }

        }
        cout << "soma pares = " << soma[seq] << endl;
        seq += 1;

        cout << "==========================================================" << endl;
    }

    delete[] soma;

    return 0;
}
