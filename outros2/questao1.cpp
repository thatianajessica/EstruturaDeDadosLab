#include <iostream>
using namespace std;


typedef struct s{
	int coeficiente;
	struct s *next;
	struct s *prev;
} No;
// minha lista é duplamente encadeada e sem cabeça
// ATENCAO: para um polinômio de grau n, a lista precisa ter n+1 elementos


//Parâmetro: n é a quantidade de elementos da lista 
void print(No *first, int n){
		
	if (first!=NULL){
		n--;
		No *aux = first;
		do{
			cout<<aux->coeficiente<<"* X^"<<n<<"+  ";
			n--;
			aux = aux->next;
		} while (aux!=first);
		cout<<endl;
	}
}

// questao a)
// minha lista é duplamente encadeada e sem cabeça
// se a lista for vazia, entao first = null
// se a lista tiver apenas um elemento, entao first->next = first->prev = first (e isso representa um "polinômio constante". Exemplo P(x) = 3)
double polinomio_k(No *first, int k){
	if (first!=NULL){ // como a lista é sem cabeça, testamos se tal lista é vazia 
		No *ultimo = first->prev; // pegamos o ultimo elemento (expoente 1)
		double multiplicador = 1;
		double resultado = 0;
		while (ultimo!=first){
			resultado += ultimo->coeficiente*multiplicador;
			multiplicador = multiplicador*k;
			ultimo = ultimo->prev;
		}
		resultado +=  ultimo->coeficiente*multiplicador;
		return resultado;
	}
	return -1;
}

// precondicao: P e Q precisam ter a mesma quantidade de nós
// ou seja, os polinômios têm o mesmo grau
// minha lista é duplamente encadeada e sem cabeça
// se a lista for vazia, entao first = null
// se a lista tiver apenas um elemento, entao first->next = first->prev = first (e isso representa um "polinômio constante". Exemplo P(x) = 3)
No *somaPolinomios(No *firstP, No *firstQ){
	No *firstResul = NULL;
	if (firstP!=NULL && firstQ!=NULL){
		No *auxP = firstP;
		No *auxQ = firstQ;
		do{
			No *novo = new No();
			novo->coeficiente = auxP->coeficiente+auxQ->coeficiente;
			if (firstResul==NULL){ // paciência...
				firstResul = novo;
				firstResul->next = firstResul;
				firstResul->prev = firstResul;
			} else {
				No *ultimo = firstResul->prev;
				firstResul->prev = novo;
				ultimo->next = novo;
				novo->prev = ultimo;
				novo->next = firstResul;
			}
			auxP = auxP->next;
			auxQ = auxQ->next;
		} while (auxP!=firstP && auxQ!=firstQ);
	}
	return firstResul;
}

// minha lista é sem cabeça
int main(void){

	// polinômio de grau 2
	// 8x^2 + 4x^1 + 5x^0
	No *P = NULL;
	No *p1 = new No();
	No *p2 = new No();
	No *p3 = new No();
	p1->next = p2;
	p1->prev = p3;
	p1->coeficiente = 8;
	p2->next = p3;
	p2->prev = p1;
	p2->coeficiente = 4;
	p3->next = p1;
	p3->prev = p2;
	p3->coeficiente = 5;
	P = p1;
	print(P,3);
	No *resultPolinomio = somaPolinomios(P,P);
	print(resultPolinomio,3);
	cout<<polinomio_k(resultPolinomio,6)<<endl;

	// // polinômio de grau 1
	// // 4x^1 + 5x^0
	// No *P = NULL;
	// No *p1 = new No();
	// No *p2 = new No();
	// p1->next = p2;
	// p1->prev = p2;
	// p1->coeficiente = 4;
	// p2->next = p1;
	// p2->prev = p1;
	// p2->coeficiente = 5;
	// P = p1;
	// print(P,2);
	// cout<<polinomio_k(P,6)<<endl;

	// // Descomentar = teste para um polinômio constante (lista com uma unica constante)
	// No *P = NULL;
	// No *p1 = new No();
	// p1->next = p1;
	// p1->prev = p1;
	// p1->coeficiente = 4;
	// P = p1;
	// print(P,1);
	// No *resultPolinomio = somaPolinomios(P,P);
	// print(resultPolinomio,1);
	// cout<<polinomio_k(resultPolinomio,6)<<endl;
	return 0;
}
