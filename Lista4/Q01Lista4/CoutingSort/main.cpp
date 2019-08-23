#include <iostream>

using namespace std;

int main()
{
    int vec[6] = {3, 6, 9, 1, 3, 4};
    int aux[10];
    int vec_ord[6];
    int tam_vec = 6, tam_aux = 10;

    //inicializando o vetor auxiliar C para a contagem
    for (int i = 0; i < tam_aux ; i++) {
        aux[i] = 0;
    }

    //fazendo a contagem dos numeros que tao no vetor a ser ordenado (A)
    for (int j = 0; j < tam_vec; j++) {
        aux[vec[j]] = aux[vec[j]] + 1;
    }

    for (int i = 0; i < tam_aux; i++) {
        cout <<aux[i] << " ";
    }
    cout << endl;
    cout << "####################################" <<endl;

    //fazendo o cumulativo do vetor C, nao sei pra q
    for (int i = 1 ; i < tam_aux; i++) {
        aux[i] = aux[i] + aux[i-1];
    }

    for (int i = 0; i < tam_aux; i++) {
        cout <<aux[i] << " ";
    }

    cout << endl;
    cout << "####################################" <<endl;

    for (int k = tam_vec-1; k >= 0; k--) {
        vec_ord[aux[vec[k]]-1] = vec[k];
        aux[vec[k]] = aux[vec[k]] - 1; //tirando o elemento do vetor que conta, porque o numero ja foi pra o vetor ordenado
    }

    for (int i = 0; i < tam_vec; i++) {
        cout <<vec_ord[i] << " ";
    }

    cout<<endl;


    return 0;


}
