#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    struct No *filho_esq;
    struct No *filho_dir;
    struct No *prox;
}No;

typedef struct Fila{
    struct No *inicio;
    struct No *fim;
    int n;
}Fila;

No* criarNo(int chave){
    No *novo_no = new No;
    novo_no->filho_dir = NULL;
    novo_no->filho_esq = NULL;
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

void inserir(Fila *fila, No* novo_no){
    if(fila->fim != NULL){
       fila->fim->prox = novo_no;//mas o nó de uma arvore nao tem ponteiro pro prox elemento
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

int numeroFolhas(No *raiz){
    if(raiz == NULL){
        return 0;
    }
    Fila *nova_fila = criarFilaVazia();
    int n_folhas = 0;
    inserir(nova_fila,raiz);

    while(nova_fila->n != 0){
        No *aux = nova_fila->inicio;
        int valor = remover(nova_fila);
        if(aux->filho_esq != NULL){
            inserir(nova_fila,aux);
        }
        if(aux->filho_dir != NULL){
            inserir(nova_fila, aux);
        }
        if(aux->filho_dir == NULL && aux->filho_esq == NULL){
            n_folhas += 1;
        }

    }

    return n_folhas;
}



int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
