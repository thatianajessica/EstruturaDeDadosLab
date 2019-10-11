#include <iostream>
using namespace std;


/* 
========================================================================================================

Copyright Islame Felipe da Costa Fernandes (2019)
Compilar: g++ ListaEncadeada.cpp -o ListaEncadeada
Executar: ./ListaEncadeada
	
Este código foi implementado para a disciplina DCA0214.1 ESTRUTURAS DE DADOS - LABORATÓRIO
Com vistas a elucidar as dúvidas dos alunos quanto à manipulação 
de ponteiros em listas SIMPLESMENTE encadeadas.

Esta implmentaçao mantém uma lista circular SIMPLESMENTE encadeada com cabeça 
cujos elementos devem ser mantidos em ordem crescente

Os demais tipos de listas encadeadas podem ser FACILMENTE implementadas 
de modo direto e análogo a essa implementação. Deixo-os como exercício para vocês! =)

========================================================================================================
*/


/*estrutura que representa um elemento da lista*/
typedef struct s{ 
	int chave; // chave (conteúdo armazenado)
	struct s *next; // ponteiro para o próximo elemento
} No;


/*
Aloca o cabeça e retorna seu ponteiro . 
Dada a alocaçao do nó cabeça, temos, pois, a uma lista vazia
*/
No *criarCabeca(){
	No *cabeca = new No (); // alocaçao
	if (cabeca!=NULL){ // apenas pra verificar se a alocaçao foi bem sucedida
		cabeca->chave = -1; // Somente pra dizer que o conteudo da cebça é desprezível 
		cabeca->next = cabeca; // lista vazia
	}
	return cabeca;
}

// busca em lista SIMPLESMENTE encadeada com cabeça
// recebe a cabeça da lista, um ponteito para ponteiro para o ant, um ponteito para ponteiro para o  pont, a chave a ser buscada x. 
// retorna o ponteiro para o elemento encontrado
// pont é o ponteiro para o elemento encontrado
// ant é o ponteiro para o anterior ao pont
// Se o elemento nao for encontrado, entao retorna um ponteiro para onde o elemento "v", 
// onde "v" possui a menor chave maior que x (ou seja, x deveria estar imediatamente antes de "v") 
// complexidade O(n), onde n é a quantidade de elemento da lista
void busca(No *cabeca, No **ant, No **pont, int x){
	*ant = cabeca; // ant agora aponta pra cabeça e isso se reflete fora da funçao
	*pont = NULL;
	No *aux = cabeca->next;
	while (aux!=cabeca){
		if (aux->chave < x){
			*ant = aux; // ant agora aponta pra aux e isso se reflete fora da funçao
			aux = aux->next;
		} else{
			if(aux->chave==x){
				*pont = aux;
			}
			aux = cabeca;
		}
	}
}


// Insere um novoValor na lista
// recebe o no cabeça e o novoValor
// Nao permite elementos com chave repetidas
// Exercício: modificar esta implementaçao para permitir elementos repetidos =)
void insert(No *cabeca, int novoVaor){
	No *ant=NULL, *pont=NULL;
	busca(cabeca, &ant, &pont, novoVaor); // ATENCAO:  &ant, &pont  
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


// Imprime a lista da cabeça até o último elemento (ordem crescente)
void printDireto(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}


void remove(No *cabeca, int valor){
	No *ant=NULL, *pont=NULL;
	busca(cabeca, &ant, &pont, valor); // ATENCAO:  &ant, &pont 
	if (pont!=NULL){ // o elemento deve estar na lista
		ant->next = pont->next;
		delete pont; // IMPORTANTE NAO ESQUECER
	} else {
		cout<<"Elemento "<<valor<<" não se encontra na lista"<<endl;
	}
}

int main(){
	cout<<"Simulando ListaEncadeada"<<endl;
	No *cabeca = criarCabeca();
	if (cabeca!=NULL){
		insert(cabeca, 10);
		insert(cabeca, 100);
		insert(cabeca, 7);
		insert(cabeca, 30);
		cout<<"Ordem direta: ";
		printDireto(cabeca);
		insert(cabeca, 2);
		insert(cabeca, 7);
		insert(cabeca, 11);
		insert(cabeca, 101);
		insert(cabeca, 2);
		cout<<"Ordem direta: ";
		printDireto(cabeca);
		remove(cabeca, 30);
		cout<<"Ordem direta depois da remoçao de 30: "<<endl;
		printDireto(cabeca);
		remove(cabeca, 30);
		remove(cabeca, 101);
		cout<<"Ordem direta depois da remoçao de 101: "<<endl;
		printDireto(cabeca);
		remove(cabeca, 2);
		cout<<"Ordem direta depois da remoçao de 2: "<<endl;
		printDireto(cabeca);
		cout<<"Insere o 30 novamente:"<<endl;
		insert(cabeca, 30);
		printDireto(cabeca);
	}
	return 0;
}

