#include <iostream>

using namespace std;

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

void printLista(No *cabeca) {
    No *current_node = cabeca;
    while ( current_node != cabeca) {
        cout <<current_node->chave << " ";
        current_node = current_node->prox;
    }
    cout << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
