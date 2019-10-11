#include <iostream>

using namespace std;

typedef struct s{
    int chave;
    struct s *right;
    struct s *left;
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


void inserir(int x, No **raiz){
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

void getMM(No *raiz, int &menor, int &maior){
    No *aux = raiz;
    menor = 0; maior = 0;
    while(aux->left != NULL){
        aux=aux->left;
    }
    menor = aux->chave;
    while(raiz->right != NULL){
        raiz=raiz->right;
    }
    maior = raiz->chave;
}


int main()
{
    No *raiz = NULL; // NO raiz inicialmente nulo
    int num = 0;
    while(1){
        cin>>num;
        if(num==-1){
            break;
        }
        inserir(num,&raiz);
    }
    in_ordem(raiz);
    int maior, menor;
    getMM(raiz,menor,maior);

    cout<<"Menor "<<menor<<", Maior "<<maior<<endl;

    return 0;
}
