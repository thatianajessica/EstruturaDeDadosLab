#include <iostream>
using namespace std;

typedef struct s{
	int chave;
	struct s *right;
	struct s *left;
	struct s *pai;
} No;

int isABB(No *raiz){
        if (raiz == NULL)
            return 1;
        if((raiz->left != NULL) && raiz->chave < raiz->left->chave){
            return 0;
        }
        if((raiz->right != NULL) && raiz->chave > raiz->right->chave){
            return 0;
        }
        if(!isABB(raiz->left) || !isABB(raiz->right)){
            return 0;
        }
            return 1;

}
int main(){
//criando arvore na mao
    No *raiz = new No();
    No *n1 = new No();
    No *n2= new No();
    No *n3 = new No();
    No *n4 = new No();
    raiz->chave = 50;
    n1->chave = 40;
    n2->chave = 20;
    n3->chave = 41;
    n4->chave = 50;
    raiz->left = n1;
    n1->left = n2;
    n1->right = n3;
    raiz->right = n4;
    cout<<isABB(raiz);
}
