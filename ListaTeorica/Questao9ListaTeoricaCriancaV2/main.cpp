#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
        lista->cabeca->prox = lista->cabeca;
        lista->cabeca->ant = lista->cabeca;
    }else{
        No *cauda = lista->cabeca->ant;
        no_adc->ant = cauda;
        cauda->prox = no_adc;
        no_adc->prox = lista->cabeca;
        lista->cabeca->ant = no_adc;
    }
    lista->n += 1;
}

No* copiaNo(No *no){
    No *copia = criarNo(no->chave);
    return copia;
}

void adicionaListaCabeca(Lista *lista, No *no_adc){
    if (lista->cabeca == NULL){
        lista->cabeca = no_adc;
        no_adc->prox = lista->cabeca;
        no_adc->ant = lista->cabeca;
    }else{
        No *cauda = lista->cabeca->ant;

        cauda->prox = no_adc;
        lista->cabeca->ant = no_adc;
        no_adc->prox = lista->cabeca;
        no_adc->ant = cauda;
        lista->cabeca = no_adc;

    }
    lista->n += 1;
}

void removerNoN(Lista *lista, int no_remover){
        if(no_remover == 0){
            cout<<"Nao pode remover a cabeca da lista" <<endl;
        }else if(no_remover == lista->n){
            No *aux;
            aux = lista->cabeca;
            for (int i = 0; i < lista->n-1; i++) {
                aux = aux->prox;
            }
            aux->prox = lista->cabeca;
            lista->cabeca->ant = aux;
            lista->n = lista->n - 1;
        }else{
            No *aux = lista->cabeca;
            for (int cont = 0; cont < no_remover-1; cont++) {
                aux = aux->prox;
            }
            aux->prox = aux->prox->prox;
            aux->prox->prox->ant = aux;
        }
}


No* criancaVencedora(Lista* lista){
    lista->n -= 1;//para nao contar com a cabeca
    int n_remover = -1;
    while(lista->n > 1){
        while(n_remover < 0){
            cout << "Qual crianca quer remover?" <<endl;
            cin >> n_remover;
        }
        removerNoN(lista,n_remover);
    }
    return lista->cabeca->prox;
}

void brincadeira_de_crianca_como_eh_bom(Lista* lista){
    int n = lista->n;
    srand(time(NULL));
    while(lista->cabeca != lista->cabeca->prox)
    {
        int r = (rand() % (n-1)) + 1; // random integer between 1 and n-1
        No* no_a_ser_apagado = lista->cabeca;
        for(int i=0; i<r; i++){
            no_a_ser_apagado = no_a_ser_apagado->prox;
        }
        cout << "removendo o no: " << no_a_ser_apagado->chave << endl;

        No* ant = no_a_ser_apagado->ant;
        No* prox = no_a_ser_apagado->prox;
        ant->prox = prox;
        prox->ant = ant;
        if(no_a_ser_apagado == lista->cabeca)
        {
            lista->cabeca = prox;
        }
    }
    cout << "O no vencedor foi: " << lista->cabeca->chave;
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

        adicionaListaCauda(lista1,no1);
        adicionaListaCauda(lista1,no2);
        adicionaListaCauda(lista1,no3);
        adicionaListaCauda(lista1,no4);
        adicionaListaCauda(lista1,no5);
        adicionaListaCauda(lista1,no6);
        adicionaListaCauda(lista1,no7);

        brincadeira_de_crianca_como_eh_bom(lista1);

    return 0;
}
