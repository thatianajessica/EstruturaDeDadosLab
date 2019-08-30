#include <iostream>

using namespace std;

void merge(int *vec, int inicio, int meio, int final, int &n_inv){
    int n1 = meio - inicio + 1;//numero de elementos na parte da esquerda
    int n2 = final - meio;//numero de elementos no vetor da direita
    int *parteEsquerda = new int[n1+1];
    int *parteDireita = new int[n2+1];

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
            n1--;
        }else{
            vec[k] = parteDireita[j];
            j = j+1;
            n2--;
            n_inv += n1;
        }
    }
}


void mergeSort(int *vec, int inicio, int final, int &n_inv){
    if(inicio < final){
        int meio = (inicio+final)/2;
        mergeSort(vec, inicio, meio, n_inv);
        mergeSort(vec, meio+1, final,n_inv);
        merge(vec, inicio, meio, final, n_inv);
    }
}

int Inversoes(int *vec, int tam_vec){
    int inversoes = 0;
    for (int i = 0; i < tam_vec; i++) {
        for (int j = 0; j < tam_vec; j++) {
            if(i < j && vec[i]>vec[j]){
                inversoes +=1;
            }
        }
    }
    return inversoes;
}

int main()
{
    int vec[] = {1, 5, 6, 8, 0, 11, 3, 2, 25, 30};
    int qnt_trocas = 0, qnt_inv = 0;

    int tam_vec = sizeof(vec)/sizeof(vec[0]);

    qnt_trocas = Inversoes(vec,tam_vec);
    cout << qnt_trocas << endl;

    mergeSort(vec,0, tam_vec-1, qnt_inv);

    cout << qnt_inv << endl;

    for (int i = 0; i< tam_vec; i++) {
        cout <<vec[i] << " ";
    }
    cout <<endl;


    return 0;
}
