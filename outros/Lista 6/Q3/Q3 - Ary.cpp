#include <iostream>
using namespace std;

typedef struct s{
	int chave;
	struct s *next;
	struct s *prev;
} No;


No *criarCabeca(){
	No *cabeca = new No ();
	if (cabeca!=NULL){
		cabeca->chave = -1;
		cabeca->next = cabeca;
		cabeca->prev = cabeca;
	}
	return cabeca;
}


No * busca(No *cabeca, char x){
	No * ultimo = cabeca->prev;
	if (x<=ultimo->chave){
		No *aux = cabeca->next;
		while (aux->chave <x) aux = aux->next;
		return aux;
	} else return cabeca;
}

int tamanhoLista(No *cabeca){
}

void insert(No *cabeca, char novoVaor){
	No *resulBusca = busca(cabeca, novoVaor);
	if (resulBusca == cabeca || resulBusca->chave != novoVaor){
		No *anterior = resulBusca->prev;
		No *novoNo = new No();
		if (novoNo!=NULL){
			novoNo->chave = novoVaor;
			novoNo->prev = anterior;
			novoNo->next = resulBusca;
			anterior->next = novoNo;
			resulBusca->prev = novoNo;
		}
	} else {
		cout<<"Elemento "<<novoVaor<<" já se encontra na lista"<<endl;
	}
}


void remove(No *cabeca, char valor){
	No *resulBusca = busca(cabeca, valor);
	if (resulBusca!=cabeca && resulBusca->chave==valor){
		No * ant = resulBusca->prev;
		No * prox = resulBusca->next;
		ant->next = prox;
		prox->prev = ant;
		delete resulBusca;
	} else {
		cout<<"Elemento "<<valor<<" não se encontra na lista"<<endl;
	}
}


void printDireto(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<(char)aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}

void printInverso(No *cabeca){
	No *aux = cabeca->prev;
	while (aux!=cabeca){
		cout<<(char)aux->chave<<" ";
		aux = aux->prev;
	}
	cout<<endl;
}

int main(){
	No *cabeca = criarCabeca();
	int m, cont = 0, contW = 0;
	No *p, *aux;

	if (cabeca!=NULL){
		insert(cabeca, 'A');
		insert(cabeca, 'B');
		insert(cabeca, 'C');
		insert(cabeca, 'D');
		insert(cabeca, 'E');
		insert(cabeca, 'F');
		cout<<"Lista das criancas na brincadeira"<<endl;
		printDireto(cabeca);
		cout<<"Digite o numero para comecar a brincadeira: ";
		cin>>m;
		p = cabeca->next;
		while(contW != 5){
            if(p->chave == -1){
                p = p->next;
            }else{
                if (cont == m){
                    aux = p->next;
                    remove(cabeca, p->chave);
                    p = aux;
                    printDireto(cabeca);
                    cont = 0;
                    contW++;
                }else{
                    p = p->next;
                    cont++;
                }
            }
		}
	}
	return 0;
}
