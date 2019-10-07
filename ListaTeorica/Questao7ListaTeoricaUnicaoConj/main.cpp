#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    struct No *prox;
    struct No *ant;
}No;

typedef struct Lista{
    int n;
    No *cabeca;
}Lista;

No* criarNo(int chave){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->ant = NULL;
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
    }else{
        No *cauda = lista->cabeca;
        for (int i = 0 ; i < ((lista->n)-1); i++) {
            cauda = cauda->prox;
        }
        no_adc->ant = cauda;
        cauda->prox = no_adc;
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
        no_adc->ant = lista->cabeca;
    }else{
        No *aux;
        aux = lista->cabeca;
        for (int cont = 0; cont < lista->n-1; cont++) {
            aux = aux->prox;
        }
        lista->cabeca->ant = no_adc;
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
            if(aux == NULL){
                lista_existe = false;
            }else{
                cout << aux->chave <<" ";
                aux = aux->prox;
                if(aux == lista->cabeca){
                lista_existe = false;
                }
            }
        }
    }
    cout << endl;
}

No* removerCabeca(Lista *lista){
    No *aux = lista->cabeca;
    if(lista->n == 0 ){
        return NULL;
    }else if(lista->n == 1){
        lista->cabeca = NULL;
        lista->n -=1;
    }else{
        lista->cabeca = lista->cabeca->prox;
        lista->n -= 1;
    }
    return aux;
}

Lista* concatenarListas(Lista* l1, Lista* l2){
    Lista* l3 = NULL;
    if(l1->cabeca == NULL && l2->cabeca == NULL){
        return NULL;
    }else if(l1->cabeca == NULL){
        l3 = l2;
    }else if(l2->cabeca == NULL){
        l3 = l1;
    }
    else if(l1->cabeca != NULL && l2->cabeca != NULL){
        while(aux != NULL && aux2 != NULL){
            No *aux1 = l1->cabeca;
            No *aux2 = l2->cabeca;
            if(aux2->chave != aux )
        }




    return l3;
    }
}

void printarListaNo(No* cabeca){
    while(cabeca->prox != NULL){
        cout << cabeca->chave << " ";
        cabeca = cabeca->prox;
    }
    cout << endl;
}

int main()
{
    No *no1 = criarNo(1);
    No *no2 = criarNo(2);
    No *no3 = criarNo(3);
    No *no4 = criarNo(4);


    Lista *lista1 = criarListaVazia();

    adicionaListaCauda(lista1,no1);
    adicionaListaCauda(lista1,no2);
    adicionaListaCauda(lista1,no3);
    adicionaListaCauda(lista1,no4);

    cout <<"Lista 1" << endl;
    printarLista(lista1);


    No *no5 = criarNo(9);
    No *no6 = criarNo(8);
    No *no7 = criarNo(7);
    No *no8 = criarNo(6);


    Lista *lista2 = criarListaVazia();

    adicionaListaCauda(lista2,no5);
    adicionaListaCauda(lista2,no6);
    adicionaListaCauda(lista2,no7);
    adicionaListaCauda(lista2,no8);

    cout <<"Lista 2" << endl;
    printarLista(lista2);

    Lista* lista3 = criarListaVazia();
    lista3 = concatenarListas(lista1,lista2);

    cout <<"Uniao" << endl;

    printarLista(lista3);



    return 0;
}
