#include <iostream>

using namespace std;

void buscaSequencial(int *vec, int n_vec, int elemento_buscado, int *posicoes, int &quantidade){
    int k = 0;
    for (int i = 0; i < n_vec; i++) {
        if(vec[i] == elemento_buscado){
            posicoes[k] = i;
            quantidade +=1;
            k += 1;
        }
    }
}

void buscaBinaria(int *vetor, int n, int x, int *posicoes, int &qnt ){
    qnt = 0;
    int inferior = 0, superior = n, meio = 0;
    while(inferior <= superior){
        meio = (superior + inferior)/2;
        if(vetor[meio] == x){
            int i = 1, pos_index = 0;
            posicoes[pos_index] = meio;
            pos_index++;
            qnt = 1;
            while(vetor[meio-i] == x && (meio-i >= 0)){
                qnt += 1;
                posicoes[pos_index] = meio -i;
                pos_index++;
                i++;
            }
            i = 1;
            while(vetor[meio+i] == x && (meio+i < n)){
                qnt += 1;
                posicoes[pos_index] = meio + i;
                pos_index++;
                i++;

            }


            return;




        }else if(vetor[meio] < x){
            inferior = meio + 1;
        }else{
            superior = meio - 1;
        }
    }
}

int main()
{
    int vec[5] = {3, 2, 1, 4, 4};
    int elemento = 4, qnt = 0, qnt2 = 0;
    int posicoes[5] = {0, 0, 0, 0, 0};

    int posicoes2[5] = {0, 0, 0, 0, 0};

    buscaSequencial(vec,5,elemento,posicoes,qnt);


    for (int i = 0; i < 5; i++) {

        cout << posicoes[i] <<" ";
    }

    cout << endl;

    cout <<qnt <<endl;

    cout << "******************************************" <<endl;

    buscaBinaria(vec,5,elemento,posicoes2,qnt2);

    for (int i = 0; i < 5; i++) {

        cout << posicoes2[i] <<" ";
    }
    cout <<endl;
    cout <<qnt <<endl;
    return 0;
}
