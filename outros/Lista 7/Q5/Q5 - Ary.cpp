#include <iostream>
using namespace std;

typedef struct s{
	int chave;
	struct s *right;
	struct s *left;
	struct s *pai;
} No;
int getAltura(No *raiz){
	if (raiz!=NULL){
			int left = getAltura(raiz->left);  // chamada recursiva para a esqueda
			int right = getAltura(raiz->right); // chamada recursiva para a direita
			if (left>right) return left + 1; // soma +1 na altura (sobe o nível)
			else return right +1;
	}
	return 0;
}

int isAVL(No *node)
{
    if (node == NULL)
        return 1;
    int a1 = getAltura(node->left);
    int a2 = getAltura(node->right);
    if(a1 - a2 > 1){
        return 0;
    }
    isAVL(node->left);
    isAVL(node->right);

}

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
    cout<<isAVL(raiz);
}
