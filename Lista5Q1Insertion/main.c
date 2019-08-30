#include <iostream>

using namespace std;


void insertionSort(int *vec, int tam_vec){

    for(int i = 1; i < tam_vec; i++){
        int chave = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > chave)
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = chave;
    }
}



struct funcionario{
    char nome[30];
    float salario;
};



int main(){
    funcionario lista_funcionarios[4];
    int tam_vec = 4;

    lista_funcionarios[0].salario = 200;
    lista_funcionarios[1].salario = 500;
    lista_funcionarios[2].salario = 700;
    lista_funcionarios[3].salario = 1000;
    lista_funcionarios[5].salario = 1500;

    insertionSort(lista_funcionarios.salario, tam_vec);

    for(int i = 0; i <= tam_vec; i++){
        cout <<funcionario.nome << " ";

    }

    cout << endl;



    return 0;
}
