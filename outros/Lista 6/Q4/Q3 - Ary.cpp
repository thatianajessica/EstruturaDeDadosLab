#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
struct Pilha {

	int topo;
	int capa;
	float *pElem;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));

}

void empilhar ( struct Pilha *p, char v){

	p->topo++;
	p->pElem [p->topo] = v;

}

char desempilhar ( struct Pilha *p ){

   char aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

int main(){
	struct Pilha minhapilha;
	int capacidade, op, cont = 0;
	float valor;
	criarpilha (&minhapilha, 100);
	int n = 5;
    char nome[n] = {'S', 'A', 'C', 'O', 'L'};
    for (int i = n/2; i<n; i++){
        empilhar(&minhapilha, nome[i]);
    }
    for (int i = 0; i<n/2; i++){
        if(nome[i] == desempilhar(&minhapilha)){
            cont++;
        }
    }
    if(cont == n/2){
        cout<<"A palavra e palindromo!";
    }else{
        cout<<"A palavra nao e palindromo!";
    }
}