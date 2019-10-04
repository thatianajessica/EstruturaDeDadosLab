#include <iostream>
#include <math.h>

using namespace std;

typedef struct No{
    int chave;
    struct No *prox;
}No;

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

void torreHanoiRecurssivo(int n, Pilha *P1, Pilha *P2, Pilha *P3){
    if(n == 1){
        //cout <<"Disco de source para destination " <<endl;
        int val = desempilha(P1);
        empilhar(P2,val);
    }else{
        torreHanoiRecurssivo(n-1, P1, P3, P2);
        //cout <<"Disco de " <<source <<" para" <<dest <<endl;
        int val = desempilha(P1);
        empilhar(P2,val);
        torreHanoiRecurssivo(n-1, P3, P2, P1);
    }
}

void hanoiMoveDisco(Pilha *pilha1, Pilha *pilha2){
    if(pilha1->topo == NULL){
        int val = desempilha(pilha2);
        empilhar(pilha1,val);
    }else if(pilha2->topo == NULL){
        int val = desempilha(pilha1);
        empilhar(pilha2, val);
    }else if(pilha1->topo->chave > pilha2->topo->chave){
        int val = desempilha(pilha2);
        empilhar(pilha1,val);
    }else{
        int val = desempilha(pilha1);
        empilhar(pilha2,val);
    }
}

void torreHanoiIterativo(int n, Pilha *P1, Pilha *P2, Pilha *P3){
    int max = pow(2, n) - 1;
    Pilha *source = P1;
    Pilha *dest = P2;
    Pilha *aux = P3;

    for (int i = 1; i <= max ; i++) {
        if(i % 3 == 1){
            hanoiMoveDisco(source,dest);
        }else if(i % 3 == 2){
            hanoiMoveDisco(source,aux);
        }else if(i % 3 == 0){
            hanoiMoveDisco(aux,dest);
        }
    }
}

void printPilha(Pilha *pilha){
    No *aux = pilha->topo;
    while(aux != NULL){
        cout <<aux->chave <<" ";
        aux = aux->prox;
    }
    cout <<endl;
}

int main()
{
    Pilha *pilha1 = criarPilhaVazia();
    Pilha *pilha2 = criarPilhaVazia();
    Pilha *pilha3 = criarPilhaVazia();

    empilhar(pilha1,4);
    empilhar(pilha1,3);
    empilhar(pilha1,2);
    empilhar(pilha1,1);

    printPilha(pilha1);

    //torreHanoiRecurssivo(3,pilha1, pilha2, pilha3);
    torreHanoiIterativo(4,pilha1,pilha2,pilha3);

    cout<<"Pilha1"<<endl;
    printPilha(pilha1);
    cout<<"Pilha2"<<endl;
    printPilha(pilha2);
    cout<<"Pilha3"<<endl;
    printPilha(pilha3);




    return 0;
}
