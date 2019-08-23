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

void quicksort(int *vec, int inicio, int final){
    if(inicio < final){
        int pos_pivo = Particiona(vec, inicio, final);
        quicksort(vec, inicio, pos_pivo-1);
        quicksort(vec, pos_pivo+1, final);
    }
}

int main()
{
    int vec[10] = {1, 4, 5, 2, 0, 2, 6, 8, 11, 1};
    int tam_vec = 10;

    quicksort(vec,0,tam_vec-1);

    for (int i = 0; i < tam_vec; i++) {
        cout <<vec[i]<< " ";
    }
    cout << endl;
    return 0;
}
