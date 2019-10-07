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

Fila* uniaoConjuntos(Fila* f1, Fila* f2){
    if(f1->inicio == NULL && f1->fim == NULL){
        return f2;
    }else if(f1->inicio == NULL && f2->fim == NULL){
        return f1;
    }else{
        f1->fim->prox = f2->inicio;
        f1->fim = f2->fim;
        f1->n += f2->n;
    }
    return f1;
}

void printarFila(Fila* fila){
    No *aux = fila->inicio;
    for (int i=0; i< fila->n; i++) {
        cout << aux->chave << " " ;
        aux = aux->prox;
    }
    cout << endl;
}


int main()
{
    Fila* fila1 = criarFilaVazia();
    inserir(fila1,1);
    inserir(fila1,2);
    inserir(fila1,6);
    cout <<"Fila 1" <<endl;
    printarFila(fila1);

    Fila* fila2 = criarFilaVazia();
    inserir(fila2,4);
    inserir(fila2,5);
    inserir(fila2,6);
    cout <<"Fila 2" <<endl;
    printarFila(fila2);

    Fila* fila3 = criarFilaVazia();
    fila3 = uniaoConjuntos(fila1,fila2);


    cout <<"Uniao" <<endl;
    printarFila(fila3);

    return 0;
}
