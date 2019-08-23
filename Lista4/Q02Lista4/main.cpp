#include <iostream>

using namespace std;

int Particiona(int *vec, int inicio, int final){
    int pivo = vec[final]; //adimite que o pivo é o ultimo elemento
    int i = inicio-1;
    for (int j = inicio; j <= final-1; j++) {
        if(vec[j] <= pivo){
            i = i+1;
            int aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
        }
    }
    int aux = vec[i+1];
    vec[i+1] = vec[final];
    vec[final] = aux;
    return i+1;
}

int quickfind(int *vec, int inicio, int final, int indice_buscado){
    if(inicio < final){
        int pos_pivo = Particiona(vec, inicio, final);

        if (pos_pivo == indice_buscado)
        {
            return vec[pos_pivo];
        }
        if (pos_pivo > indice_buscado)
        {
            return quickfind(vec, inicio, pos_pivo-1, indice_buscado);
        }
        else
        {
            return quickfind(vec, pos_pivo+1, final, indice_buscado);
        }

    }
    if (inicio == indice_buscado || final == indice_buscado)
    {
        return vec[indice_buscado];
    }
    return -1;
}



int main()
{
    int vec[8] = {7, 1, 3, 10, 17, 2, 21, 9};
    int tam_vec = 8, resultado, k=9;

    resultado = quickfind(vec,0,tam_vec-1, k);

    for (int i = 0; i < tam_vec; i++) {
        cout <<vec[i]<< " ";
    }
    cout << endl;

    cout<< "O "<<k << " menor elemento do vetor eh = " <<resultado << endl;
    return 0;
}
