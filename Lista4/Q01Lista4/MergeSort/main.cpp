#include <iostream>

using namespace std;
                        //0           //2       //4
void merge(int *vec, int inicio, int meio, int final){
    int n1 = meio - inicio + 1;//3 numero de elementos na parte da esquerda
    int n2 = final - meio;// 2 numero de elementos no vetor da direita
    int *parteEsquerda = new int[n1+1];//4 = 0...3
    int *parteDireita = new int[n2+1];//3 = 0...2

    for(int i = 0; i < n1; i++){
        parteEsquerda[i] = vec[inicio+i];
        //cout << "Esquerda: " <<inicio+i <<endl;
    }
    for(int i = 0; i < n2; i++){
        parteDireita[i] = vec[meio+1+i];
        //cout << "Direita: " <<meio+1+i <<endl;
    }

    parteEsquerda[n1] = 2147483647;
    parteDireita[n2] = 2147483647;

    int i = 0, j = 0;
    for(int k = inicio; k <= final; k++){
        //cout << "indices i j k " <<i << " "<<j <<" "<<k <<endl;
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



    mergeSort(vec,0,tam_vec-1);

    for(int i = 0; i<tam_vec ; i++){
        cout <<vec[i]<< " ";
    }

    cout << endl;
    return 0;
}
