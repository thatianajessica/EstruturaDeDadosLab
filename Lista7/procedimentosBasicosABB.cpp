#include <iostream>
using namespace std;


/* 
========================================================================================================

Copyright Islame Felipe da Costa Fernandes (2019)
Compilar: g++ procedimentosBasicosABB.cpp -o procedimentosBasicosABB
Executar: ./procedimentosBasicosABB
	
Este código foi implementado para a disciplina DCA0214.1 ESTRUTURAS DE DADOS - LABORATÓRIO
Com vistas a elucidar as dúvidas dos alunos quanto à manipulação 
de ponteiros em árvores binárias.

Este código implementa APENAS ALGUMAS funcoes básicas para manipulacao da Avore Binaria de Busca SIMPLES 

========================================================================================================
*/


typedef struct s{
	int chave;
	struct s *right;
	struct s *left;
} No;

/*@param raiz da arvore: um ponteiro simples
  @param pt_retorno: um ponteiro para ponteiro. As modificacoes neste parâmetro precisam ser refletidas fora da funcao
 pt_retorno = raiz inicialmente
  @param x:inteiro é a chave buscada
  @param f:inteiro é uma refência para uma variavel de controle*/

void buscaABB_recursiva(No *raiz, No **pt_retorno, int x, int &f){
	if (raiz!=NULL){
		if (raiz->chave == x){
			*pt_retorno = raiz; // pt_retorno agora aponta apra o elemento encontrado
			f = 1;
		} else {
			if (x < raiz->chave ){
				if (raiz->left == NULL) f=2; // volta na recursao.
				else {
					*pt_retorno = raiz->left; // essa linha é importante porque a busca, 
					// caso nao encontre o nó desejado, precisa retornar o elemento que seria pai do elemento procurado.
					buscaABB_recursiva(raiz->left,pt_retorno, x, f); // Chama recursivamente para a esquerda
				}
			} else{
				if (raiz->right == NULL) f=3; // volta na recursao.
				else {
					*pt_retorno = raiz->right; // idem
					buscaABB_recursiva(raiz->right,pt_retorno, x, f);// chama recursivamente para a direita
				}	
			}
		}
	}

}


/* PROCEDIMENTO DE INSERCAO NUMA ARVORE BINARIA DE BSUCA SIMPLES 
	@param raiz da arvore. Deve ser um ponteiro para ponteiro, pois, em caso de a arvore ser vazia, o parametro raiz deve apontar para a nova raiz da arvore
   O parametro raiz deve ser NULL, inicialmente, caaso a arvore seja vazia
   @param x inteiro no a ser inserido
*/
void insert(int x, No **raiz){
	int f=0;
	No *pt_retorno = *raiz;
	buscaABB_recursiva(*raiz, &pt_retorno, x, f); // NOTEM NOTEM NOTEM NOTEM NOTEM NOTEM NOTEM o &pt_retorno e o *raiz
	if (f==1) cout<<"Elemento "<< x <<" ja existe"<<endl;
	else {
		No *novo_no = new No(); // cria novo nó
		novo_no->chave = x; // atribui a chave
		novo_no->left = NULL; // novo nó inicialmente é folha
		novo_no->right = NULL;
		if (f==0) *raiz = novo_no; // o unico caso em que o ponteiro da raiz é modificado
		else {
			if (f==2) pt_retorno->left = novo_no; // o novo nó eh filho esquerdo
			else pt_retorno->right = novo_no; // idem
		}
	}
}



void in_ordem_aux(No *raiz){
	
	if (raiz->left !=NULL) in_ordem_aux(raiz->left);
	cout<<raiz->chave<<" ";
	if (raiz->right !=NULL) in_ordem_aux(raiz->right);
	
}

void in_ordem(No *raiz){
	if (raiz!=NULL) in_ordem_aux(raiz);
}



// algoritmo recursivo em pos-ordem
int getAltura(No *raiz){
	if (raiz!=NULL){
			int left = getAltura(raiz->left);  // chamada recursiva para a esqueda
			int right = getAltura(raiz->right); // chamada recursiva para a direita
			if (left>right) return left + 1; // soma +1 na altura (sobe o nível)
			else return right +1;
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	No *raiz = NULL; // NO raiz inicialmente nulo
	insert(27, &raiz);
	insert(82, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(30, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(38, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(82, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	in_ordem(raiz);
	cout<<endl;
	in_ordem(raiz);
	cout<<endl;
	insert(2, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(17, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(70, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	in_ordem(raiz);
	cout<<endl;
	insert(8, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(21, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(17, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(35, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(3, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	insert(93, &raiz);
	cout<<"Altura: "<< getAltura(raiz)<<endl;
	in_ordem(raiz);
	cout<<endl;
	return 0;
}