#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
typedef struct Pilha {

	int topo;
	int capa;
	int *pElem[5];

} Nop;

void criarpilha( Nop *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem[0] = new int();
   p->pElem[1] = new int();
   p->pElem[2] = new int();
   p->pElem[3] = new int();
   p->pElem[4] = new int();

}

void empilhar ( Nop *p, int chave, int p1, int p2, int p3, int flag){
	p->topo++;
	p->pElem[0] [p->topo] = chave;
	p->pElem[1] [p->topo] = p1;
	p->pElem[2] [p->topo] = p2;
	p->pElem[3] [p->topo] = p3;
	p->pElem[4] [p->topo] = flag;

}

int estavazia ( Nop *p ){
   if( p-> topo == -1 )
      return 1;   // true
   else
      return 0;   // false
}

int desempilhar ( Nop *p ){
    int aux[5];
    aux[0] = p->pElem[0] [p->topo];
    aux[1] = p->pElem[1] [p->topo];
    aux[2] = p->pElem[2] [p->topo];
    aux[3] = p->pElem[3] [p->topo];
    aux[4] = p->pElem[4] [p->topo];
    p->topo--;
    return *aux;
}

void hannoi(int n){
    Nop pilha;
    criarpilha (&pilha, 100);
    int p1=1, p2=2,p3=3,flag=0;
    empilhar(&pilha,n,p1,p2,p3,flag);
    int aux[5];
    while(estavazia(&pilha)){
        aux = pilha->pElem[0] [pilha->topo]
        if (aux[0] == 1){
            cout<<"Move de "<<aux[1] <<" para "<<aux[2]<<endl;
            desempilhar(&pilha);
        }else{
            if(aux[4] == 0){
                aux[0] =- 1;
                aux[2] = 'P3';
                aux[3] = 'P2';
                aux[4] = 1;
                empilha(aux);
                cout<<"Move de "<<aux[1] <<" para "<<aux[2]<<endl;

            }else{
                aux[0] =- 1;
                aux[1] = 'P3'
                aux[2] = 'P2';
                aux[3] = 'P1';
                aux[4] = 0;
                empilha(aux);
            }
        }
    }
}

int main(){
	int capacidade, op, cont = 0;
	float valor;
	int n = 5;
    hannoi(n);
}
