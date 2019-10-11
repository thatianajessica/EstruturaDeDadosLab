#include <iostream>

using namespace std;

struct nodo{
    int chave;
    int conteudo;
    struct nodo *left;
    struct nodo *right;
    struct nodo *pai;
};
typedef struct nodo No;


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
            if (f==2){
                pt_retorno->left = novo_no; // o novo nó eh filho esquerdo
                novo_no->pai = pt_retorno;
            }
            else {
                pt_retorno->right = novo_no; // idem
                novo_no->pai = pt_retorno;
            }
        }
    }
}

void getCamInEx_aux(No *raiz,int nivel,int &ci, int &ce){

    if (raiz->left !=NULL){
        nivel++;
        getCamInEx_aux(raiz->left,nivel,ci,ce);
        nivel--;
    }

    ci+= nivel;

    if(raiz->left==NULL){
        ce+=nivel;
    }
    if(raiz->right == NULL){
        ce+= nivel;
    }

    cout<<raiz->chave<<", ci ="<<ci<<", ce= "<<ce<<endl;

    if (raiz->right !=NULL){
        nivel++;
        getCamInEx_aux(raiz->right,nivel,ci,ce);
        nivel--;
    }

}

void getCamInEx(No *raiz, int &ci, int &ce){
    int nivel = 1;
    if (raiz!=NULL) getCamInEx_aux(raiz,nivel,ci,ce);
}

int main(){
    No *arv = NULL;
    int x=-1;
    int f=0;
    cout<<"Inserir valores na arvore"<<endl;
    while(1){
        cin>>x;
        if(x==0){
            break;
        }
        insert(x,&arv);
    }

    int ce = 0;
    int ci = 0;

    getCamInEx(arv,ci,ce);

    cout<<endl<<ci<<"x"<<ce<<endl;


    return 0;
}

