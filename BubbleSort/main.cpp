#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int tam_vec, numero, aux;

    cout << "Quantos numeros tem na sequencia?" << endl;
    cin >> tam_vec;

    int *vec = new int[tam_vec];


    for(int i = 0; i<tam_vec ; i++){
        cout << "Digite os numeros:" << endl;
        cin >> numero;
        vec[i] = numero;
    }

    for(int i = 0; i <= tam_vec - 2; i++){
        for( int j = 0; j < tam_vec - i; j++){
            if(vec[j] > vec[j+1]){
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }

    for(int i = 0; i < tam_vec; i++){
        cout <<vec[i]<<" ";
    }

    cout << endl;


    return 0;
}
