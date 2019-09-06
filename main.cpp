#include <iostream>

using namespace std;

typedef struct No{
    int chave;
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
    No *corrente_l1 = cabecal1;
    No *corrente_l2 = cabecal2;
    No *corrente_listafinal = cabeca_ptlistafinal;

    cabeca_ptlistafinal->prox = cabeca_ptlistafinal;

    while(corrente_l1->prox != cabecal1 || corrente_l2->prox != cabecal2){

        if( ((corrente_l1->prox)->chave) <= ((corrente_l2->prox)->chave) ){

            No *novoNo = new No();
            novoNo->chave = (corrente_l1->prox)->chave;
            corrente_listafinal->prox = novoNo;
            novoNo->prox = cabeca_ptlistafinal;
            corrente_l1 = corrente_l1->prox;
        }
        else{
            No *novoNo = new No();
            novoNo->chave = corrente_l2->chave;
            corrente_listafinal->prox = novoNo;
            novoNo->prox = cabeca_ptlistafinal;
            corrente_l2 = corrente_l2->prox;
        }
        if(corrente_l1->prox == cabecal1){
            while(corrente_l2->prox == cabecal2){
                No *novoNo = new No();
                novoNo->chave = corrente_l2->chave;
                corrente_listafinal->prox = novoNo;
                novoNo->prox = cabeca_ptlistafinal;
                corrente_l2 = corrente_l2->prox;
            }
        }
        if(corrente_l2->prox == cabecal2){
            while(corrente_l1->prox == cabecal1){
                No *novoNo = new No();
                novoNo->chave = corrente_l1->chave;
                corrente_listafinal->prox = novoNo;
                novoNo->prox = cabeca_ptlistafinal;
                corrente_l1 = corrente_l1->prox;
            }
        }
    }

return cabeca_ptlistafinal;
}


void printLista(No *cabeca) {
    No *current_node = cabeca;
    while ( current_node->prox != cabeca) {
        cout <<current_node->chave << " ";
        current_node = current_node->prox;
    }
    cout << endl;
}

//void ocuparPt(No *cabeca, int valor){
//    (cabeca->prox)->chave = valor;
//    cabeca =
//}

int main(int argc, char *argv[])
{
//    //lista sequencial
//    int list1[4] = {1, 3, 5, 6};
//    int list2[3] = {4, 6, 8};

//    int tam_1 = sizeof(list1)/sizeof(list1[0]);
//    int tam_2 = sizeof(list2)/sizeof(list2[0]);

//    int *list3 = new int[tam_1+tam_2];

//    JuntaListas(list1, tam_1, list2, tam_2, list3);

//    for(int i = 0; i < tam_1+tam_2; i++){
//        cout <<list3[i]<<" ";
//    }

//    cout <<endl;

    //lista simplesmente encadeada

    No *cabecalista1 = new No();
    No *cabecalista2 = new No();
    No *no1_l1 = new No();
    No *no2_l1 = new No();
    No *no3_l1 = new No();
    No *no1_l2 = new No();
    No *no2_l2 = new No();
    No *no3_l2 = new No();

    //inicializando a lista 1

    cabecalista1->prox = no1_l1;
    no1_l1->chave = 2;
    no1_l1->prox = no2_l1;
    no2_l1->chave = 3;
    no2_l1->prox = no3_l1;
    no3_l1->chave = 4;
    no3_l1->prox = cabecalista1;

    //inicializando a lista 2

    cabecalista2->prox = no1_l2;
    no1_l2->chave = 4;
    no1_l2->prox = no2_l2;
    no2_l2->chave = 6;
    no2_l2->prox = no2_l2;
    no3_l2->chave = 8;
    no3_l2->prox = cabecalista2;

    No *cabecalista3 = JuntarListasSimples(cabecalista1, cabecalista2);

    printLista(cabecalista3);


            return 0;
}
