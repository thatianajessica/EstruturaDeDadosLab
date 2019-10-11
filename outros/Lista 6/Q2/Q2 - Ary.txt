#include <iostream>
using namespace std;

typedef struct s{
	int chave; 
	struct s *next; 
} No;


No *criarCabecaChar(){
	No *cabeca = new No (); 
	if (cabeca!=NULL){ 
		cabeca->chave = -1;
		cabeca->next = cabeca; 
	}
	return cabeca;
}

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

void buscaChar(No *cabeca, No **ant, No **pont, int x){
	*ant = cabeca; 
	*pont = NULL;
	No *aux = cabeca->next;
	while (aux!=cabeca){
		if (aux->chave < x){
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

void insert(No *cabeca, int novoVaor){
	No *ant=NULL, *pont=NULL;
	busca(cabeca, &ant, &pont, novoVaor); 
	if (pont==NULL){
		No *novoNo = new No();
		if (novoNo!=NULL){
			novoNo->chave = novoVaor;
			novoNo->next = ant->next;
			ant->next = novoNo;
		}
	} else {
		cout<<"Elemento "<<novoVaor<<" já se encontra na lista"<<endl;
	}
}

void insertChar(No *cabeca, char novoVaor){
	No *ant=NULL, *pont=NULL;
	buscaChar(cabeca, &ant, &pont, novoVaor); 
	if (pont==NULL){
		No *novoNo = new No();
		if (novoNo!=NULL){
			novoNo->chave = novoVaor;
			novoNo->next = ant->next;
			ant->next = novoNo;
		}
	} else {
		cout<<"Elemento "<<novoVaor<<" já se encontra na lista"<<endl;
	}
}

void printLista1(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}

void printLista2(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<(char)(aux->chave)<<" ";
		aux = aux->next;
	}
}


int main(){
	cout<<"Simulando ListaEncadeada"<<endl;
	No *cabeca = criarCabeca();
	No *cabecaChar = criarCabecaChar();
	if (cabeca!=NULL){
		insertChar(cabecaChar, 'A');
		insert(cabeca, 1);
		insertChar(cabecaChar, 'E');
		insert(cabeca, 5);
		insertChar(cabecaChar, 'T');
		insert(cabeca, 7);
		insertChar(cabecaChar, 'W');
		insert(cabeca, 8);
		insertChar(cabecaChar, 'G');
		cout<<"Ordem direta: ";
		printLista2(cabecaChar);
		printLista1(cabeca);
	}
	return 0;
}