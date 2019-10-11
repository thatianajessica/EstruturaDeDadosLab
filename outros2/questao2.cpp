#include <iostream>

using namespace std;

#define MAX1 1000

typedef struct nn{
	int chave;
	struct nn *esq;
	struct nn *dir;
} No;



// este procdimento recebe a raiz de uma Árvore binária de busca e um inteiro 1<=k<=n, onde n é a quantidade de nós da arvore
// retorna o k-ésimo menor elemento armazenado na arvore de busca
// o procedimento manipula uma pilha. Note que a manipulacao respeita a definiçao de pilha (LIFO), mas sem precisar definir funçoes auxiliares.
int getKmenor_iterativo(No *raiz, int k){
	No *pilha[MAX1];
	int topo=0;
	bool fim = false;

	while (fim == false){
		while (raiz!=NULL) {
			pilha[topo++] = raiz;
			raiz = raiz->esq;
		}
		if (topo>0){
			raiz = pilha[--topo];
			k--;
			if (k==0) return raiz->chave;
			raiz = raiz->dir;
		} else {
			fim = true;
		}
	}
	return -1;
}

/*
A questao nao pedia para criar um procedimento de inserçao de nós na Arvore Binária de Busca
Portanto, o aluno (nem pro professor =)) não precisaria criar tal procedimento. 
Poderia criar a árvore binária de busca na mao, atribuindo os ponteiros.

*/

int main(int argc, char const *argv[])
{
	No * n10 = new No();
	No * n2 = new No();
	No * n1 = new No();
	No * n3 = new No();
	No * n15 = new No();
	No * n14 = new No();
	No * n13 = new No();
	n10->chave = 10;
	n10->esq = n2;
	n10->dir = n15;
	n2->chave = 2;
	n2->esq = n1;
	n2->dir = n3;
	n1->chave = 1;
	n1->esq = NULL;
	n1->dir = NULL;
	n3->esq = NULL;
	n3->dir = NULL;
	n3->chave = 3;
	n15->esq = n14;
	n15->dir = NULL;
	n15->chave = 15;
	n14->esq = n13;
	n14->dir = NULL;
	n14->chave = 14;
	n13->esq = NULL;
	n13->dir = NULL;
	n13->chave = 13;

	No *raiz = n10;

	cout<<getKmenor_iterativo(raiz, 5)<<endl;
	cout<<endl;
}
