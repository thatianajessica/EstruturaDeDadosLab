#include <iostream>

using namespace std;

int main()
{
    int n_seq, soma_primos = 0, numero, n_divisores = 0;


    cout << "Quantos numeros?" << endl;
    cin >> n_seq;

    for (int i = 0; i < n_seq; i++) {
        numero = -1;
        while(numero < 0){
            cout << "Digite o numero:" << endl;
            cin >> numero;
            for (int j = 1; j <= numero;j++) {
                if(numero % j == 0){
                    n_divisores += 1;
                }
            }
            if(n_divisores == 2){
                soma_primos += numero;
            }
        }
        n_divisores = 0;
    }

    cout << "Soma dos numeros primos = " <<soma_primos << endl;




    return 0;
}
