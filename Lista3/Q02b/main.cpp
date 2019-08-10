#include <iostream>

using namespace std;

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

int main()
{
    int n, numero, elemento_procurado = 5, resultado = 0;

    cout << "Insira a quantidade de elementos no vetor:" << endl;
    cin >> n;

    int *vetor_seq = new int[n];

    for(int i  = 0; i < n; i++){
       cout << "Insira um numero:" << endl;
       cin >> numero;
       vetor_seq[i] = numero;
    }

    resultado = buscaBinaria(vetor_seq, n, elemento_procurado);

    cout << "O indice do elemento é: " << resultado << endl;

    return 0;
}
