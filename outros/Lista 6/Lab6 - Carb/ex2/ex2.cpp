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

void busca(No *cabeca, No** ant, No **prox, char x, bool flag){
    *ant = cabeca;
    *prox =NULL;
    No *aux = cabeca->prox;
    while( aux != cabeca){
        if(flag){
            *ant = aux;
            aux = aux->prox;
            if(aux->valor == x){
                *prox = aux;
            }
        }
        else{
            if(aux->valor > x){
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
}

void inserir(No *cabeca, char novoValor, bool flag){
    No *ant = NULL;
    No *pont = NULL;
    busca(cabeca,&ant,&pont,novoValor,flag);
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

No *listaReordenada(No *lista){
    No *cabeca1 = new No();
    No *cabeca2 = new No();
    cabeca1 = criarCabeca();
    cabeca2 = criarCabeca();
    No *aux = lista->prox;
    while(aux!=lista){
        if(aux->valor <'A'){
            inserir(cabeca1,aux->valor,0);
        }
        else{
            inserir(cabeca2,aux->valor,1);
        }
        aux=aux->prox;
    }
    No *ant = NULL,*pont=NULL;
    busca(cabeca2,&ant,&pont,255,1);
    ant->prox = cabeca1->prox;
    busca(cabeca1,&ant,&pont,255,1);
    ant->prox = cabeca2;
    delete cabeca1;
    return cabeca2;
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
        inserir(cabeca,valor,1);
    }
    No *reordenado = listaReordenada(cabeca);

    printDireto(reordenado);

    return 0;
}
