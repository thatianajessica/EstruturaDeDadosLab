#include <iostream>
using namespace std;

typedef struct s{
	int chave;
	struct s *right;
	struct s *left;
	struct s *pai;
} No;

typedef struct Pilha {

	int topo; /* posição elemento topo */
	int capa;
	No *pElem;

} Nop;

void criarpilha(Nop *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = new No();

}

void empilhar ( Nop *p, No v){

	p->topo++;
	p->pElem [p->topo] = v;

}

No desempilhar ( Nop *p ){

   No aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

int estavazia ( Nop *p ){
   if( p-> topo == -1 )
      return 1;
   else
      return 0;
}

int getAltura(No *raiz){
	if (raiz!=NULL){
			int left = getAltura(raiz->left);  // chamada recursiva para a esqueda
			int right = getAltura(raiz->right); // chamada recursiva para a direita
			if (left>right) return left + 1; // soma +1 na altura (sobe o nível)
			else return right +1;
	}
	return 0;
}

void preordemit(No *raiz) {
    Nop minhapilha;
    criarpilha(&minhapilha, 100);
    empilhar(&minhapilha, *raiz);
    while (!estavazia(&minhapilha)) {
        *raiz = desempilhar(&minhapilha);
        cout<<raiz->chave<<" ";
        if (raiz->right != NULL) empilhar(&minhapilha, *raiz->right);
        if (raiz->left != NULL) empilhar(&minhapilha, *raiz->left);
    }
}


/*void inordemit(No *raiz) {
    Nop minhapilha;
    criarpilha(&minhapilha, 100);
    empilhar(&minhapilha, *raiz);
    while (!estavazia(&minhapilha)) {
        if (raiz->right != NULL) empilhar(&minhapilha, *raiz->right);
        *raiz = desempilhar(&minhapilha);
        cout<<raiz->chave<<" ";
        if (raiz->left != NULL) empilhar(&minhapilha, *raiz->left);
    }
}

void posordemit(No *raiz) {
    Nop minhapilha;
    criarpilha(&minhapilha, 100);
    empilhar(&minhapilha, *raiz);
    while (!estavazia(&minhapilha)) {
        if (raiz->right != NULL) empilhar(&minhapilha, *raiz->right);
        if (raiz->left != NULL) empilhar(&minhapilha, *raiz->left);
        *raiz = desempilhar(&minhapilha);
        cout<<raiz->chave<<" ";
    }
}
*/
int main(){
    No *raiz = new No();
    No *n1 = new No();
    No *n2= new No();
    No *n3 = new No();
    No *n4 = new No();
    raiz->chave = 50;
    n1->chave = 40;
    n2->chave = 20;
    n3->chave = 41;
    n4->chave = 60;
    raiz->left = n1;
    n1->left = n2;
    n1->right = n3;
    raiz->right = n4;
    cout<<"Imprimindo em pre-ordem"<<endl;
    preordemit(raiz);
    cout<<endl<<"Imprimindo em pre-ordem"<<endl;
    inordemit(raiz);
    cout<<endl<<"Imprimindo em pre-ordem"<<endl;
    posordemit(raiz);
}
