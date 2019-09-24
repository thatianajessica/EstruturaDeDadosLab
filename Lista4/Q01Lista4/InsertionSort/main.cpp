#include <iostream>

using namespace std;

void insertionSort(int vec[], int tam_vec){
    for(int i = 1; i < tam_vec; i++){
                int chave = vec[i];
                int j = i - 1;

                while (j >= 0 && vec[j] > chave)
                {
                    vec[j + 1] = vec[j];
                    j = j - 1;
                }
                vec[j + 1] = chave;
            }


}

int main(int argc, char *argv[])
{
    int tam_vec, numero;
    int tam_max = 10;
    int vec[tam_max];
    cout << "Quantos numeros tem na sequencia?" << endl;
    cin >> tam_vec;

    //int *vec = new int[tam_vec];

    for(int i = 0; i<tam_vec ; i++){
        cout << "Digite os numeros:" << endl;
        cin >> numero;
        vec[i] = numero;
    }


insertionSort(vec,tam_vec);

    for(int i = 0; i < tam_vec ; i++){
        cout <<vec[i] <<" ";
    }

    cout << endl;

    return 0;
}
