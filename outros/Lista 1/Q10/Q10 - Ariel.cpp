#include <iostream>
#include <cstdlib> //para usar rand()
#include <ctime>   //para setar a seed

using namespace std;

//funções
bool eh_primo(int num) {       //ideia: para os primos temos dois divisores, o próprio num e 1.
    int num_divisores = 0;

    int cont = 1; //começar em zero seria uma inconsistência.
    while(cont <= num) {
        if (num%cont == 0) {
            num_divisores++;
        }

        cont++;
    }

    if (num_divisores == 2) {
        return true;
    } else {
        return false;
    }

}

int soma_primos(int tamanho) {
    int vetor[tamanho];

    //gerando vetor de numeros inteiros aleatórios
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = rand()%11; //numeros aleatórios entre 0 e 10 (para ampliar para todos inteiros, colocar INT_MAX;
    }

    //printa o vetor na tela para fins de entendimento
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
    }

    //somando os primos
    int somatorio = 0;
    for (int i = 0; i < tamanho; ++i) {
        if(eh_primo(vetor[i])) {
            somatorio = somatorio + vetor[i];
        }
    }

    return somatorio;
}


int main() {

    srand((unsigned) time(0)); //setando a seed

    int tamanho;

    cout << "Quantos números deseja somar: ";
    cin >> tamanho;
    cout << endl;

    int soma = soma_primos(tamanho);

    cout << endl << "A soma de todos primos do vetor eh: " << soma << endl;


    return 0;
}
