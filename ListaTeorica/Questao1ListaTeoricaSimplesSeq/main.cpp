#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    struct No *prox;
}No;

typedef struct Lista{
    int n;
    No *cabeca;
}Lista;

No* criarNo(int chave){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->chave = chave;
    return novo_no;
}

Lista* criarListaVazia(){
    Lista *nova_lista = new Lista;
    nova_lista->cabeca = NULL;
    nova_lista->n = 0;
    return nova_lista;
}

void adicionaListaCauda(Lista *lista, No *no_adc){
    if (lista->cabeca == NULL){
        lista->cabeca = no_adc;
        lista->cabeca->prox = lista->cabeca;
    }else{
        No *cauda = lista->cabeca;
        for (int i = 0 ; i < ((lista->n)-1); i++) {
            cauda = cauda->prox;
        }
        cauda->prox = no_adc;
        no_adc->prox = lista->cabeca;
    }
    lista->n += 1;
}

No* copiaNo(No *no){
    No *copia = criarNo(no->chave);
    return copia;
}

void adicionaListaCaudaCopia(Lista *lista, No *no_adc){
    adicionaListaCauda(lista,copiaNo(no_adc));
}

void adicionaListaCabeca(Lista *lista, No *no_adc){
    if (lista->cabeca == NULL){
        lista->cabeca = no_adc;
        no_adc->prox = lista->cabeca;
    }else{
        No *aux;
        aux = lista->cabeca;
        for (int cont = 0; cont < lista->n-1; cont++) {
            aux = aux->prox;
        }
        aux->prox = no_adc;
        no_adc->prox = lista->cabeca;
        lista->cabeca = no_adc;

    }
    lista->n += 1;
}

void printarLista(Lista *lista){
    if(lista->n > 0);
    {
        No *aux = lista->cabeca;
        for(int i = 0; i < lista->n; i++){
            cout << aux->chave <<" ";
            aux = aux->prox;
        }
    }
    cout << endl;
}

void printarLista2(Lista *lista){
    bool lista_existe = true;
    if(lista->n > 0);
    {
        No *aux = lista->cabeca;
        while(lista_existe == true){
            cout << aux->chave <<" ";
            aux = aux->prox;
            if(aux == lista->cabeca){
                lista_existe = false;
            }

        }

    }
    cout << endl;
}

void removerCauda(Lista *lista){
    if(lista->n == 0){
        return;
    }
    if (lista->n == 1){
        lista->cabeca = NULL;
        lista->n = lista->n - 1;
    }else{
        No *aux;
        aux = lista->cabeca;
        for (int i = 0; i < lista->n-2; i++) {
            aux = aux->prox;
        }
        aux->prox = lista->cabeca;//mudei aqui
        //aux->prox = NULL;
        lista->n = lista->n - 1;
    }
}

void removerCabeca(Lista *lista){
    if(lista->n == 0 ){
        return;
    }else{
        No *aux = lista->cabeca->prox;
        lista->cabeca = aux;
        lista->n -= 1;
    }
}

void removerNoN(Lista *lista, int no_remover){
    if(lista->n == 0){
        cout <<"Lista vazia" <<endl;
    }else{
        if(no_remover == 0){
            removerCabeca(lista);
        }else if(no_remover == lista->n-1){
            removerCauda(lista);
        }else{
            int no_atual = 0;
            No *aux = lista->cabeca;
            No *anterior;
            while(no_atual < no_remover){
                anterior = aux;
                aux = aux->prox;
                no_atual +=1;
            }
            aux = aux->prox;
            anterior->prox = aux;
        }
    }
}

void inserirNoN(Lista *lista, int posicao_inserir, int chave){
    No *novo_no = criarNo(chave);
    if(lista->n == 0){
        lista->cabeca = novo_no;
        lista->cabeca->prox = lista->cabeca;
        lista->n += 1;
    }else{
        No *aux = lista->cabeca;
        for (int cont = 0; cont <posicao_inserir-1; cont++) {
            aux = aux->prox;
        }
        novo_no->prox = aux->prox;
        aux->prox= novo_no;
        lista->n +=1;
    }
}

No* getNo(Lista *lista, int no){
    No *aux = lista->cabeca;
    if(lista->n == 0){
        cout <<"Lista vazia" << endl;
        return NULL;
    }else if(no > lista->n-1 || no < 0){
        cout <<"No nao existente" <<endl;
        return NULL;
    }else{
        int no_atual = 0;
        while (no_atual < no-1) {
            aux = aux->prox;
            no_atual += 1;
        }
    }
    return aux;
}


//listas sequenciais
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

//listas simplesmente encadeadas
Lista* JuntarListasSimples(Lista *lista1, Lista *lista2){
    Lista *lista3 = criarListaVazia();
    No *aux_l1 = lista1->cabeca;
    No *aux_l2 = lista2->cabeca;
    int cont_l1 = 0;
    int cont_l2 = 0;
    bool acabou_lista = false;

    while(acabou_lista == false){

        if(aux_l1->chave <= aux_l2->chave){
            adicionaListaCaudaCopia(lista3,aux_l1);
            aux_l1 = aux_l1->prox;
            cont_l1++;
        }else{
            adicionaListaCaudaCopia(lista3,aux_l2);
            aux_l2 = aux_l2->prox;
            cont_l2++;
        }
        if(cont_l1 == lista1->n){
            while(cont_l2 != lista2->n){
                adicionaListaCaudaCopia(lista3,aux_l2);
                aux_l2 = aux_l2->prox;
                cont_l2++;
            }
            acabou_lista = true;
        }
        if(cont_l2 == lista2->n){
            while(cont_l1 != lista1->n){
                adicionaListaCaudaCopia(lista3,aux_l1);
                aux_l1 = aux_l1->prox;
                cont_l1++;
            }
            acabou_lista = true;
        }
    }
    return lista3;
}

void printLista(No *cabeca) {
    No *current_node = cabeca;
    while ( current_node != cabeca) {
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

    //    No *cabecalista1 = new No();
    //    No *cabecalista2 = new No();
    //    No *no1_l1 = new No();
    //    No *no2_l1 = new No();
    //    No *no3_l1 = new No();
    //    No *no1_l2 = new No();
    //    No *no2_l2 = new No();
    //    No *no3_l2 = new No();

    //    //inicializando a lista 1

    //    cabecalista1->prox = no1_l1;
    //    cabecalista1->chave = 0;
    //    no1_l1->chave = 2;
    //    no1_l1->prox = no2_l1;
    //    no2_l1->chave = 3;
    //    no2_l1->prox = no3_l1;
    //    no3_l1->chave = 4;
    //    no3_l1->prox = cabecalista1;

    //    //inicializando a lista 2

    //    cabecalista2->prox = no1_l2;
    //    no1_l2->chave = 4;
    //    no1_l2->prox = no2_l2;
    //    no2_l2->chave = 6;
    //    no2_l2->prox = no3_l2;
    //    no3_l2->chave = 8;
    //    no3_l2->prox = cabecalista2;

    //    No *cabecalista3 = JuntarListasSimples(cabecalista1, cabecalista2);

    //    printLista(cabecalista3);

    //aqui

    No *no1 = criarNo(1);
    No *no2 = criarNo(2);
    No *no3 = criarNo(3);
    No *no4 = criarNo(4);
    No *no5 = criarNo(5);
    No *no6 = criarNo(6);
    No *no7 = criarNo(7);

    Lista *lista1 = criarListaVazia();
    printarLista(lista1);

    adicionaListaCabeca(lista1,no1);
    printarLista(lista1);
    adicionaListaCauda(lista1,no2);
    printarLista(lista1);
    adicionaListaCabeca(lista1,no3);
    printarLista(lista1);
    adicionaListaCauda(lista1,no4);
    printarLista(lista1);
    adicionaListaCabeca(lista1,no5);
    printarLista(lista1);
    adicionaListaCauda(lista1,no6);
    printarLista(lista1);
    adicionaListaCabeca(lista1,no7);
    cout <<"Lista 1" << endl;
    printarLista(lista1);

    printf("########################## \n");
    //    removerCauda(lista1);
    //    printarLista2(lista1);
    //    removerCauda(lista1);
    //    printarLista2(lista1);
    //    removerCauda(lista1);
    //    printarLista2(lista1);
    //    removerCauda(lista1);
    //    printarLista2(lista1);
    //    removerCauda(lista1);
    //    printarLista2(lista1);
    //    removerCauda(lista1);
    //    printarLista2(lista1);
    //    removerCauda(lista1);
    //    printarLista2(lista1);

    //    removerCabeca(lista1);
    //    printarLista2(lista1);
    //    removerCabeca(lista1);
    //    printarLista2(lista1);
    //    removerCabeca(lista1);
    //    printarLista2(lista1);
    //    removerCabeca(lista1);
    //    printarLista2(lista1);
    //    removerCabeca(lista1);
    //    printarLista2(lista1);
    //    removerCabeca(lista1);
    //    printarLista2(lista1);
    //    removerCabeca(lista1);
    //    printarLista2(lista1);

//    removerNoN(lista1,6);
//    printarLista2(lista1);
//    No *no_buscado = new No();
//    int indice = 3;
//    no_buscado = getNo(lista1,indice);
//    cout <<"Chave do no " <<indice <<" = " <<no_buscado->chave << endl;

//    cout << "#############################################" <<endl;

    //nova lista para mergear

    No *no8 = criarNo(1);
    No *no9 = criarNo(2);
    No *no10 = criarNo(3);
    No *no11 = criarNo(4);
    No *no12 = criarNo(5);
    No *no13 = criarNo(6);

    Lista *lista2 = criarListaVazia();
    adicionaListaCabeca(lista2,no8);
    adicionaListaCauda(lista2,no9);
    adicionaListaCauda(lista2,no10);
    adicionaListaCauda(lista2,no11);
    adicionaListaCauda(lista2,no12);
    adicionaListaCauda(lista2,no13);
    cout <<"Lista 2" << endl;
    printarLista2(lista2);


    No *no14 = criarNo(7);
    No *no15 = criarNo(8);
    No *no16 = criarNo(9);
    No *no17 = criarNo(10);
    No *no18 = criarNo(11);
    No *no19 = criarNo(12);

    Lista *lista3 = criarListaVazia();
    adicionaListaCabeca(lista3,no14);
    adicionaListaCauda(lista3,no15);
    adicionaListaCauda(lista3,no16);
    adicionaListaCauda(lista3,no17);
    adicionaListaCauda(lista3,no18);
    adicionaListaCauda(lista3,no19);
    cout <<"Lista 3" << endl;
    printarLista2(lista3);

    Lista *lista4 = criarListaVazia();
    //lista4 = JuntarListasSimplesDedeu(lista2, lista3);
    lista4 = JuntarListasSimples(lista2, lista3);
    cout <<"Lista 4" << endl;
    printarLista2(lista4);

    cout <<"############################"<<endl;

    removerNoN(lista4,3);
    printarLista2(lista4);

    cout <<"############################"<<endl;

    inserirNoN(lista4,3,20);
    printarLista2(lista4);


    return 0;
}
