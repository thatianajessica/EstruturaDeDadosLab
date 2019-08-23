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

    for(int i = 0; i < tam_vec; i++){
        int pos_min = i;
        for(int j = i+1; j < tam_vec; j++){
            if(vec[j] < vec[pos_min]){
                pos_min = j;
            }
        }
        aux = vec[i];
        vec[i] = vec[pos_min];
        vec[pos_min] = aux;

    }

    for(int i = 0; i < tam_vec; i++){
        cout <<vec[i] << " ";
    }

    cout << endl;
    return 0;
}
