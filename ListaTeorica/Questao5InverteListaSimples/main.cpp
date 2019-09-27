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

typedef struct Pilha{
    struct No *topo;
    int n;
}Pilha;

No* criarNo(int chave){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->chave = chave;
    return novo_no;
}

void deletarNo(No **no){
    No *aux = *no;
    delete aux;
    no = NULL;
}

void empilhar(Pilha *pilha, int chave){
    No *novo_no = criarNo(chave);
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    pilha->n += 1;
}

int desempilha(Pilha *pilha){
    int valor = 0;
    if(pilha->topo != NULL){
        No *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        valor = aux->chave;
        deletarNo(&aux);
        pilha->n -= 1;
    }else{
        cout <<"PILHA VAZIA" <<endl;
    }
    return valor;
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

No* removerCabeca(Lista *lista){
    if(lista->n == 0 ){
        return NULL;
    }else{
        No *cabeca = lista->cabeca;
        No *aux = lista->cabeca->prox;
        lista->cabeca = aux;
        lista->n -= 1;
        return cabeca;
    }
}

No* copiaNo(No *no){
    No *copia = criarNo(no->chave);
    return copia;
}

Lista* copiarLista(Lista *lista){
    Lista *copia_lista = criarListaVazia();
    No *aux = lista->cabeca;
    adicionaListaCauda(copia_lista,copiaNo(aux));
    for (int cont = 0; cont < lista->n -1; cont++) {
        aux = aux->prox;
        adicionaListaCauda(copia_lista, copiaNo(aux));
    }
    return copia_lista;
}

Pilha* criarPilhaVazia(){
    Pilha *nova_pilha = new Pilha();
    nova_pilha->topo = NULL;
}

Lista* inverteLista(Lista *lista){
    if(lista->n == 0){
        cout <<"Lista vazia"<<endl;
        return NULL;
    }else{
        Lista *copia_lista = copiarLista(lista);
        Lista *lista_invertida = criarListaVazia();
        Pilha *pilha1 = criarPilhaVazia();
        No *aux = lista->cabeca;
        while(copia_lista->n != 0) {
            No *cabeca_removida = removerCabeca(copia_lista);
            empilhar(pilha1,cabeca_removida->chave);
        }
        while(pilha1->topo != NULL){
            int chave = desempilha(pilha1);
            No *no = criarNo(chave);
            adicionaListaCauda(lista_invertida,no);
        }
        return lista_invertida;
    }
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
int main()
{
        No *no1 = criarNo(1);
        No *no2 = criarNo(2);
        No *no3 = criarNo(3);
        No *no4 = criarNo(4);
        No *no5 = criarNo(5);
        No *no6 = criarNo(6);
        No *no7 = criarNo(7);

        Lista *lista1 = criarListaVazia();
        printarLista(lista1);

        adicionaListaCauda(lista1,no1);
        printarLista(lista1);
        adicionaListaCauda(lista1,no2);
        printarLista(lista1);
        adicionaListaCauda(lista1,no3);
        printarLista(lista1);
        adicionaListaCauda(lista1,no4);
        printarLista(lista1);
        adicionaListaCauda(lista1,no5);
        printarLista(lista1);
        adicionaListaCauda(lista1,no6);
        printarLista(lista1);
        adicionaListaCauda(lista1,no7);
        cout <<"Lista 1" << endl;
        printarLista(lista1);

        Lista *lista2 = criarListaVazia();
        lista2 = copiarLista(lista1);
        cout <<"Lista 2" << endl;
        printarLista(lista2);
        cout <<"Lista 1" << endl;
        printarLista(lista1);

        cout <<"#########################" <<endl;
        Lista *lista3 = criarListaVazia();
        lista3 = inverteLista(lista1);
        cout <<"Lista invertida" << endl;
        printarLista(lista3);
        cout <<"Lista original" << endl;
        printarLista(lista1);



    return 0;
}
