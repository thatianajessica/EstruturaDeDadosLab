#include <iostream>

using namespace std;

void merge(int *vec, int inicio, int meio, int final){
    int n1 = meio - inicio + 1;
    int n2 = final - meio;
    int *parteEsquerda = new int[n1+1];
    int *parteDireita = new int[n2+1];

    for(int i = 0; i < n1; i++){
        parteEsquerda[i] = vec[inicio+i-1];
        cout << parteEsquerda[i]<<endl;
    }
    for(int i = 0; i < n2; i++){
        parteDireita[i] = vec[meio+i];
        cout << parteDireita[i]<<endl;

    }
    parteEsquerda[n1 + 1] = 2147483647;
    parteDireita[n2 + 1] = 2147483647;
    int i = 0, j = 0;
    for(int k = inicio; k < final; k++){
        if(parteEsquerda[i]<=parteDireita[j]){
            vec[k] = parteEsquerda[i];
            i = i+1;
        }else{
            vec[k] = parteDireita[j];
            j = j+1;
        }
    }
}


void mergeSort(int *vec, int inicio, int final){
    if(inicio < final){
        int meio = (inicio+final)/2;
        mergeSort(vec, inicio, meio);
        mergeSort(vec, meio+1, final);
        merge(vec, inicio, meio, final);
    }
}

int main(int argc, char *argv[])
{
    int tam_vec, numero;

    cout << "Quantos numeros tem na sequencia?" << endl;
    cin >> tam_vec;

    int *vec = new int[tam_vec];


    for(int i = 0; i<tam_vec ; i++){
        cout << "Digite os numeros:" << endl;
        cin >> numero;
        vec[i] = numero;
    }

    mergeSort(vec,0,tam_vec);

    for(int i = 0; i<tam_vec ; i++){
        cout <<vec[i]<< " ";
    }

    cout << endl;
    return 0;
}
