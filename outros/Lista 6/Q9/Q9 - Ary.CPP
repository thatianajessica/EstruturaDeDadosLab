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
	int n = 13;
    char exp[n] = {'(', '(', 'A', '*', 'B', ')', '-',  '(', 'C', '/', 'D', ')', ')'};
    for(int i=0; i<n; i++){
        if(exp[i] == '*' || exp[i] == '+' ||exp[i] == '-' ||exp[i] == '/'){
            empilhar(&minhapilha, exp[i]);
        }
        else if(exp[i] != '*' && exp[i] != '+' && exp[i] != '-' && exp[i] != '/' && exp[i] != '(' && exp[i] != ')'){
            cout<<exp[i];
        }
        else if(exp[i] == ')'){
            cout<<desempilhar(&minhapilha);
        }
    }
}