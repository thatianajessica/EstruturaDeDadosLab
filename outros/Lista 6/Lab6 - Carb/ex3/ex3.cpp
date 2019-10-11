#include <iostream>
using namespace std;

/*
========================================================================================================

Copyright Islame Felipe da Costa Fernandes (2019)
Compilar: g++ ListaDuplamenteEncadeada.cpp -o ListaDuplamenteEncadeada
Executar: ./ListaDuplamenteEncadeada

Este c�digo foi implementado para a disciplina DCA0214.1 ESTRUTURAS DE DADOS - LABORAT�RIO
Com vistas a elucidar as d�vidas dos alunos quanto � manipula��o
de ponteiros em listas duplamente encadeadas.

Esta implmenta�ao mant�m uma lista circular duplamente encadeada com cabe�a
cujos elementos devem ser mantidos em ordem crescente

Os demais tipos de listas encadeadas podem ser FACILMENTE implementadas
de modo direto e an�logo a essa implementa��o. Deixo-os como exerc�cio para voc�s! =)

========================================================================================================
*/


/*estrutura que representa um elemento da lista*/
typedef struct s{
	int chave; // chave (conte�do armazenado)
	struct s *next; // ponteiro para o pr�ximo elemento
	struct s *prev; // ponteiro para o elemento anterior
} No;


/*
Aloca o cabe�a e retorna seu ponteiro .
Dada a aloca�ao do n� cabe�a, temos, pois, a uma lista vazia
*/
No *criarCabeca(){
	No *cabeca = new No (); // aloca�ao
	if (cabeca!=NULL){ // apenas pra verificar se a aloca�ao foi bem sucedida
		cabeca->chave = -1; // Somente pra dizer que o conteudo da ceb�a � desprez�vel
		cabeca->next = cabeca; // lista vazia
		cabeca->prev = cabeca; // lista vazia
	}
	return cabeca;
}

// busca em lista duplamente encadeada com cabe�a
// recebe a chave a ser buscada x, bem como a cabe�a da lista
// retorna o ponteiro para o elemento encontrado
// Se o elemento nao for encontrado, entao retorna um ponteiro para onde o elemento "v",
// onde "v" possui a menor chave maior que x (ou seja, x deveria estar imediatamente antes de "v")
// complexidade O(n), onde n � a quantidade de elemento da lista
No * busca(No *cabeca, int x){
	No * ultimo = cabeca->prev; // pega o ultimo elemento da lista
	if (x<=ultimo->chave){
		No *aux = cabeca->next;
		while (aux->chave <x) aux = aux->next;
		return aux;
	} else return cabeca;
}


// Insere um novoValor na lista
// recebe o no cabe�a e o novoValor
// Nao permite elementos com chave repetidas
// Exerc�cio: modificar esta implementa�ao para permitir elementos repetidos =)
void inserir(No *cabeca, int novoVaor){
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
		cout<<"Elemento "<<novoVaor<<" j� se encontra na lista"<<endl;
	}
}


void remover(No *cabeca, int valor){
	No *resulBusca = busca(cabeca, valor);
	if (resulBusca!=cabeca && resulBusca->chave==valor){ // o elemento deve estar na lista
		No * ant = resulBusca->prev;
		No * prox = resulBusca->next;
		ant->next = prox;
		prox->prev = ant;
		delete resulBusca; // IMPORTANTE NAO ESQUECER
	} else {
		cout<<"Elemento "<<valor<<" n�o se encontra na lista"<<endl;
	}
}


// Imprime a lista da cabe�a at� o �ltimo elemento (ordem crescente)
void printDireto(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}

void jogo(No *cabeca, int m){
    No *aux = new No();
    while(1){
        aux=cabeca->next;
        printDireto(cabeca);
        if(aux == cabeca){
            return;
        }
        for(int i=0;i<m;i++){
            aux=aux->next;
        }
        if(aux!=cabeca){
            remover(cabeca, aux->chave);
        }
        else{
            aux=aux->next;
            remover(cabeca,aux->chave);
        }
    }



}

int main(){
	No *cabeca = criarCabeca();
    int numcriancas;
    int m;
    cin>>numcriancas>>m;
    if(cabeca!=NULL){
        for(int i=1;i<=numcriancas;i++){
            inserir(cabeca,i);
        }
    }
    jogo(cabeca,m-1);

	return 0;
}
