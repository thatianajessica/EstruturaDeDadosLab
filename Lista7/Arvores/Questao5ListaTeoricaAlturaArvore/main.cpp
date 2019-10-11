#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    struct No *filho_esq;
    struct No *filho_dir;
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

int alturaIterativo(No* raiz){
    Fila *nova_fila = criarFilaVazia();
    int altura = 0;
    int contador_nos = 0;
    if (raiz == NULL){
        return 0;
    }
    inserir(nova_fila,raiz);

    while(true){
        if(nova_fila->n == 0){
            return altura;
        }
        altura += 1;

        while(nova_fila->n > 0){
            No *aux = nova_fila->inicio;
            int removido = remover(nova_fila);
            if(aux->filho_esq != NULL){
                inserir(nova_fila,aux->filho_esq);
            }
            if(aux->filho_dir != NULL){
                inserir(nova_fila,aux->filho_dir);
            }

        }
    }


}


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
