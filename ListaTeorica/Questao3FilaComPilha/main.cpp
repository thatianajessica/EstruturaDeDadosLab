#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    struct No *prox;
}No;

typedef struct Fila{
    struct No *inicio;
    struct No *fim;
    int n;
}Fila;

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

Fila* criarFilaVazia(){
    Fila *nova_fila = new Fila();
    nova_fila->n = 0;
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
};

void inserir(Fila *fila, int chave){
    No *novo_no = criarNo(chave);
    if(fila->fim != NULL){
        fila->fim->prox = novo_no;
    }else{
        fila->inicio = novo_no;
    }
    fila->fim = novo_no;
    fila->n += 1;
}

int remover(Fila *fila){
    int valor = 0;
    if(fila->inicio != NULL){
        No* aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL){
            fila->fim = NULL;
        }
        valor = aux->chave;
        deletarNo(&aux);
        fila->n -= 1;
    }else{
        cout <<"FILA VAZIA" <<endl;
    }
    return valor;
}

Pilha* criarPilhaVazia(){
    Pilha *nova_pilha = new Pilha();
    nova_pilha->topo = NULL;
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

void enfileirar(Pilha *pilha1, Pilha *pilha2, int chave){
//    No *novo_no = criarNo(chave);
//    if(fila->fim != NULL){
//        fila->fim->prox = novo_no;
//    }else{
//        fila->inicio = novo_no;
//    }
//    fila->fim = novo_no;
//    fila->n += 1;
        empilhar(pilha1,chave);

}

int desenfileirar(Pilha *pilha1, Pilha *pilha2){
    int valor = 0;
    if(pilha1->topo != NULL){
        while(pilha1->topo != NULL){
            valor = desempilha(pilha1);
            empilhar(pilha2, valor);
        }
        valor = desempilha(pilha2);
        while(pilha2->topo != NULL){
            int aux = desempilha(pilha2);
            empilhar(pilha1,aux);
        }
    }else{
        cout << "FILA VAZIA" << endl;
    }
    return valor;
}

int main()
{

    Fila *fila1 = criarFilaVazia();
    inserir(fila1,3);
    inserir(fila1,5);
    cout <<remover(fila1)<<endl;
    inserir(fila1,4);
    inserir(fila1,7);
    cout <<remover(fila1)<<endl;
    cout <<remover(fila1)<<endl;

    Pilha *pilha1 = criarPilhaVazia();
    Pilha *pilha2 = criarPilhaVazia();
    enfileirar(pilha1,pilha2,3);
    enfileirar(pilha1,pilha2,5);
    cout << desenfileirar(pilha1,pilha2) <<endl;
    enfileirar(pilha1,pilha2,4);
    enfileirar(pilha1,pilha2,7);
    cout << desenfileirar(pilha1,pilha2) <<endl;
    cout << desenfileirar(pilha1,pilha2) <<endl;
    return 0;
}
