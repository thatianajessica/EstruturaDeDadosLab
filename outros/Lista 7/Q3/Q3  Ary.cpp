#include <iostream>
using namespace std;

typedef struct s{
	int chave;
	struct s *right;
	struct s *left;
	struct s *pai;
} No;

void printInorder(No *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->chave << " ";
    printInorder(node->right);
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
    printInorder(raiz);
}
