#include <iostream>

using namespace std;

void ordena(int *vec, int m){
    int j, chave;
    for (int i = 1; i < m; i++) {//comeca do segundo elemento
        chave = vec[i];
        j = i - 1;
        while(j >= 0 && chave < vec[j]){
            vec[j+1] = vec[j];
            j -= 1;
        }
        vec[j+1] = chave;
    }
}

int main()
{
    int n_elements=0, numero;

    cin >> n_elements;

    int *vec = new int[n_elements];

    for (int i = 0 ; i < n_elements; i++) {
        cin >> numero;
        vec[i] = numero;
    }

    ordena(vec, n_elements);

    for (int j = 0; j < n_elements; j++) {
        cout << vec[j] <<" " ;
    }

    cout << endl;
    return 0;
}
