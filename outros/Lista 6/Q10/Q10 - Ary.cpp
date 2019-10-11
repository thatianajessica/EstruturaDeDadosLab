#include <iostream>
using namespace std;


typedef struct s{
	int chave;
	int coef;
	struct s *next;
} No;


No *criarCabeca(){
	No *cabeca = new No ();
	if (cabeca!=NULL){
		cabeca->chave = -1;
		cabeca->next = cabeca;
	}
	return cabeca;
}

void busca(No *cabeca, No **ant, No **pont, int x){
	*ant = cabeca;
	*pont = NULL;
	No *aux = cabeca->next;
	while (aux!=cabeca){
		if (aux->chave > x){
			*ant = aux;
			aux = aux->next;
		} else{
			if(aux->chave==x){
				*pont = aux;
			}
			aux = cabeca;
		}
	}
}



void insert(No *cabeca, int novoVaor, int coef){
	No *ant=NULL, *pont=NULL;
	busca(cabeca, &ant, &pont, novoVaor);
	if (pont==NULL){
		No *novoNo = new No();
		if (novoNo!=NULL){
			novoNo->chave = novoVaor;
			novoNo->coef = coef;
			novoNo->next = ant->next;
			ant->next = novoNo;
		}
	} else {
		cout<<"Elemento "<<novoVaor<<" já se encontra na lista"<<endl;
	}
}



void printDireto(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<aux->coef<<"x^"<<aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}


void remove(No *cabeca, int valor){
	No *ant=NULL, *pont=NULL;
	busca(cabeca, &ant, &pont, valor);
	if (pont!=NULL){
		ant->next = pont->next;
		delete pont;
	} else {
		cout<<"Elemento "<<valor<<" não se encontra na lista"<<endl;
	}
}

No *addpol(No *p1, No *p2){
    
}
int main(){
	cout<<"Simulando ListaEncadeada"<<endl;
	No *p1 = criarCabeca();
		insert(p1, 1, 10);
		insert(p1, 3, 4);
		insert(p1, 5, 6);
		insert(p1, 4, 1);
		cout<<"Polinomio 1: ";
		printDireto(p1);
    No *p2 = criarCabeca();
		insert(p2, 1, 10);
		insert(p2, 3, 4);
		insert(p2, 5, 6);
		insert(p2, 4, 1);
		cout<<"Polinomio 2: ";
		printDireto(p1);
    No *soma = addpol(p1, p2);
	return 0;
}

