#include <iostream>
#define MAX 100

using namespace std;

struct No{
    char valor;
    struct No *prox;
};

No *criarCabeca(){
    No *cabeca = new No();
    if(cabeca !=NULL){
        cabeca->valor = -1;
        cabeca->prox = cabeca;
    }
    return cabeca;
}

void busca(No *cabeca, No** ant, No **prox, char x){
    *ant = cabeca;
    *prox =NULL;
    No *aux = cabeca->prox;
    while( aux != cabeca){
        if( aux->valor < x){
            *ant = aux;
            aux = aux->prox;
        }
        else{
            if(aux->valor == x){
                *prox = aux;
            }
            aux = cabeca;
        }
    }
}

void inserir(No *cabeca, char novoValor){
    No *ant = NULL;
    No *pont = NULL;
    busca(cabeca,&ant,&pont,novoValor);
    if (pont==NULL){
		No *novoNo = new No();
		if (novoNo!=NULL){
			novoNo->valor = novoValor;
			novoNo->prox = ant->prox;
			ant->prox = novoNo;
		}
	} else {
		cout<<"Elemento "<<novoValor<<" já se encontra na lista"<<endl;
	}
}

void printDireto(No *cabeca){
	No *aux = cabeca->prox;
	while (aux!=cabeca){
		cout<<aux->valor<<" ";
		aux = aux->prox;
	}
	cout<<endl;
}

void remover(No *cabeca, char valor){
	No *ant=NULL, *pont=NULL;
	busca(cabeca, &ant, &pont, valor); // ATENCAO:  &ant, &pont
	if (pont!=NULL){ // o elemento deve estar na lista
		ant->prox = pont->prox;
		delete pont; // IMPORTANTE NAO ESQUECER
	} else {
		cout<<"Elemento "<<valor<<" não se encontra na lista"<<endl;
	}
}

int main(){
	cout<<"Simulando ListaEncadeada"<<endl;
	No *cabeca = criarCabeca();
	char valor;
    while(1){
        cin>>valor;
        if(valor=='-'){
            break;
        }
        inserir(cabeca,valor);
    }
    printDireto(cabeca);

    return 0;
}
