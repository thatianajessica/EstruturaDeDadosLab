#include <iostream>

using namespace std;

int buscaSequencial(int n, int *vetor, int valor){
    int posicao_elemento;

    for(int i = 0; i < n; i++){
        if(vetor[i] == valor){
            posicao_elemento = i;
            return posicao_elemento;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int n, valor = 10, numero, posicao_resultado;

    cout << "Insira a quantidade de elementos no vetor:" << endl;
    cin >> n;

    int *vetor_seq = new int[n];

    for(int i  = 0; i < n; i++){
       cout << "Insira um numero:" << endl;
       cin >> numero;
       vetor_seq[i] = numero;
    }

    posicao_resultado = buscaSequencial(n, vetor_seq, valor);
    cout << posicao_resultado << endl;

    return 0;
}
