#include <iostream>

using namespace std;

bool somaDois(int *vec, int tam_vec, int valor){
    bool retorno = false;
    for (int i = 0; i < tam_vec; i++) {
        int soma = 0;
        for (int j = 0; j< tam_vec; j++) {
            soma = vec[i]+vec[j];
            if(soma == valor && i != j){
                retorno = true;
            }
        }
    }
    return retorno;
}

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

int buscaBinaria(int *vetor, int n, int x){
    int inferior = 0, superior = n, meio = 0;
    while(inferior <= superior){
        meio = (superior + inferior)/2;
        if(vetor[meio] == x)
            return meio;
        else if(vetor[meio] < x){
            inferior = meio + 1;
        }else{
            superior = meio - 1;
        }
    }
    return -1;
}

bool encontraSomaDois( int *vec, int tam_vec, int valor){
    int *aux_vec = new int[tam_vec];
    int aux;
    bool resultado = false;

    for (int i = 0; i < tam_vec; i++) {
        aux_vec[i] = vec[i];
    }

    quicksort(aux_vec,0,tam_vec-1);

    for (int i = 0; i < tam_vec; i++) {
        aux = valor - aux_vec[i];
        int indice = buscaBinaria(aux_vec,tam_vec,aux);
        if(indice != -1){
            cout << aux_vec[i] << " , " <<aux_vec[indice] <<endl;
            resultado = true;
            break;
         }
    }
    return resultado;
}

int main()
{
    int vec[] = {1, 5, 6, 8, 11, 3, 2, 25, 30};
    int tam_vec = sizeof(vec)/sizeof(vec[0]);
    bool resultado = false;
    bool resultado2 = false;
    int val = 5;

    resultado = somaDois(vec,tam_vec,val);
    cout <<resultado << endl;

    resultado2 = encontraSomaDois(vec, tam_vec,val);
    cout <<resultado2 << endl;





    return 0;
}
