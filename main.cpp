#include <iostream>

using namespace std;

typedef struct No{
    int valor;
    struct No *prox;
}No;

void JuntaListas(int *lista1, int tam_1, int *lista2, int tam_2, int *lista3){
    int tam_3 = tam_1 + tam_2;
    int i = 0, j=0, k= 0;

    while(k < tam_3){
        if(lista1[i] <= lista2[j]){
            lista3[k] = lista1[i];
            // cout <<lista3[k] << endl;
            i++;
            k++;
        }
        else{
            lista3[k] = lista2[j];
            //cout <<"##############" <<endl;
            //cout <<lista3[k] << endl;
            j++;
            k++;
        }
        if(i == tam_1){
            while(j< tam_2){
                lista3[k] = lista2[j];
                j++;
                k++;
                break;
            }
        }
        if(j == tam_2){
            while(i< tam_1){
                lista3[k] = lista1[i];
                i++;
                k++;
                break;
            }
        }
    }
}

No* JuntarListasSimples(No *cabecal1, No *cabecal2){
    No *cabeca_ptlistafinal = new No();


    if( ((cabecal1->prox)->chave) <= ((cabecal2->prox)->chave) )
        No *novoNo = new No();
        novoNo = cabecal1->prox;
        cabeca_ptlistafinal->prox = novoNo;
        novoNo->prox = cabeca_ptlistafinal;
    }
    else{
        No *novoNo = new No();
        novoNo = cabecal2->prox;
        cabeca_ptlistafinal->prox = novoNo;
        novoNo->prox = cabeca_ptlistafinal;
    }
    if()

int main(int argc, char *argv[])
{
    //lista sequencial
    int list1[4] = {1, 3, 5, 6};
    int list2[3] = {4, 6, 8};

    int tam_1 = sizeof(list1)/sizeof(list1[0]);
    int tam_2 = sizeof(list2)/sizeof(list2[0]);

    int *list3 = new int[tam_1+tam_2];

    JuntaListas(list1, tam_1, list2, tam_2, list3);

    for(int i = 0; i < tam_1+tam_2; i++){
        cout <<list3[i]<<" ";
    }

    cout <<endl;

    //lista simplesmente encadeada

    No *cabecalista1 = new No()
            No *cabecalista2 = new No()

            return 0;
}
