#include <iostream>
#include <math.h>

using namespace std;

typedef struct No{
    int n_discos;
    char P1;
    char P2;//destino
    char P3;//aux
    int volta = 0; //primeira recursao = 1, segunda recursao = 2
    struct No *prox;
}No;

typedef struct Pilha{
    struct No *topo;
    int n;
}Pilha;

No* criarNo(int n_discos, char P1, char P2, char P3){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->n_discos = n_discos;
    novo_no->P1 = P1;
    novo_no->P2 = P2;
    novo_no->P3 = P3;
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

void empilhar(Pilha *pilha, int n_discos, char P1, char P2, char P3){
    No *novo_no = criarNo(n_discos,P1,P2,P3);
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    pilha->n += 1;
}

No* desempilha(Pilha *pilha){
    No *valor;
    if(pilha->topo != NULL){
        No *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        valor = aux;
        pilha->n -= 1;
    }else{
        cout <<"PILHA VAZIA" <<endl;
    }
    return valor;
}

void printPilha(Pilha *pilha){
    No *aux = pilha->topo;
    while(aux != NULL){
        cout <<"(Discos: " << aux->n_discos <<" , Source: " << aux->P1 << " ,Dest: " << aux->P2 << " ,Aux: " << aux->P3 << " ,Rec: " << aux->volta <<" )" ;
        aux = aux->prox;
    }
    cout <<endl;
}

void hanoiIterativo(int n_discos, char P1, char P2, char P3){
    Pilha *nova_pilha = criarPilhaVazia();
    empilhar(nova_pilha,n_discos,P1,P2,P3);

    while(true){
        printPilha(nova_pilha);
        if(nova_pilha->topo == NULL){
            break;
        }
        No *novo_no = nova_pilha->topo;
        if(novo_no->n_discos == 1){
            desempilha(nova_pilha);
            cout <<novo_no->P1 << " -> " <<novo_no->P2 <<endl;
            continue;
        }

        if(novo_no->volta == 0){
            empilhar(nova_pilha,novo_no->n_discos-1,novo_no->P1,novo_no->P3,novo_no->P2);
            novo_no->volta = 1;
            continue;
        }
        if(novo_no->volta == 1){
            cout <<novo_no->P1 << " -> " <<novo_no->P2 <<endl;
            empilhar(nova_pilha,novo_no->n_discos-1,novo_no->P3,novo_no->P2,novo_no->P1);
            novo_no->volta = 2;
            continue;
        }
        desempilha(nova_pilha);

    }
}




int main()
{
    char p1 = 'a';
    char p2 = 'b';
    char p3 = 'c';

    int n_discos = 3;

    hanoiIterativo(n_discos,p1,p2,p3);



    return 0;
}
