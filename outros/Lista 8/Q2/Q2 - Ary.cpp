#include <iostream>
using namespace std;

typedef struct s{
	int chave;
	struct s *right;
	struct s *left;
	struct s *pai;
} No;

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
		novo_no->pai = NULL;
		if (f==0) *raiz = novo_no; // o unico caso em que o ponteiro da raiz é modificado
		else {
            novo_no->pai = pt_retorno;
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


int getAltura(No *raiz){
	if (raiz!=NULL){
			int left = getAltura(raiz->left);  // chamada recursiva para a esqueda
			int right = getAltura(raiz->right); // chamada recursiva para a direita
			if (left>right) return left + 1; // soma +1 na altura (sobe o nível)
			else return right +1;
	}
	return 0;
}

int getSuc(No **raiz, int x){
    int f = 0;
    No *busca;
    buscaABB_recursiva(*raiz, &busca, x, f);
    if(busca->right == NULL){
        if((busca->pai)->left == busca){
            return busca->pai->chave;
        }else{
            busca = busca->pai;
        }
    }else{
        busca = busca->right;
        while(busca->left != NULL){
            busca = busca->left;
        }
        return busca->chave;
    }
}

int getAnt(No **raiz, int x){
    int f = 0;
    No *busca;
    buscaABB_recursiva(*raiz, &busca, x, f);
    if(busca->left == NULL){
        if((busca->pai)->right == busca){
            return busca->pai->chave;
        }else{
            busca = busca->pai;
        }
    }else{
        busca = busca->left;
        while(busca->right != NULL){
            busca = busca->right;
        }
        return busca->chave;
    }
}

int main(int argc, char const *argv[])
{
	No *raiz = NULL;
	insert(27, &raiz);
	insert(82, &raiz);
	insert(30, &raiz);
	insert(38, &raiz);
	insert(2, &raiz);
	insert(17, &raiz);
	insert(70, &raiz);
	insert(8, &raiz);
	insert(21, &raiz);
	insert(35, &raiz);
	insert(3, &raiz);
	insert(93, &raiz);
	in_ordem(raiz);
	cout<<endl;
	cout<<"O sucessor e: "<<(getSuc(&raiz, 8))<<endl;
	cout<<"O antecessor e: "<<(getAnt(&raiz, 8))<<endl;


	return 0;
}
