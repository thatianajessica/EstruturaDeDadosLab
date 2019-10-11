#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    struct No *esq;
    struct No *dir;
}No;

void buscaArvBB(No **pt, int valor_buscado, int &f){
    if (pt != NULL){
        if((*pt)->chave == valor_buscado){
            f = 1;
        }else{
            if(valor_buscado < (*pt)->chave){
                if((*pt)->esq == NULL){
                    f = 2;
                }else{
                    *pt = (*pt)->esq;
                    buscaArvBB(pt,valor_buscado,f);
                }
            }else{
                if((*pt)->dir == NULL){
                    f = 3;
                }else{
                    *pt = (*pt)->dir;
                    buscaArvBB(pt,valor_buscado,f);
                }
            }
        }
    }
}

No* criarNovoNo(int chave)
{
    No *novoNo = new No();
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

void insercaoNo(No **pt, int chave,int &f){
    No *aux = new No();
    aux = *pt;
    buscaArvBB(&aux,chave,f);
    if(f == 1){
        cout <<"Elemento ja existe" << endl;
    }else{
        No *No_novo = criarNovoNo(chave);
        if(f == 0){
            *pt = No_novo;
        }else{
            if(f == 2){
                aux->esq = No_novo;

            }else{
                aux->dir = No_novo;
                cout <<"entrou aki" << endl;
            }
        }
    }
}


int main(int argc, char *argv[])
{
    No *no1 = new No();
    No *no2 = new No();
    No *no3 = new No();
    No *no4 = new No();
    No *aux = new No();
    No *aux2 = new No();
    int f = 0;
    int f2 = 0;

    no1->chave = 5;
    no2->chave = 10;//raiz
    no3->chave = 15;
    no4->chave = 20;

    aux = no2; //para nao perder o endereco da raiz

    no2->esq = no1;
    no2->dir = no3;
    no3->dir = no4;

    buscaArvBB(&aux,7,f);

    cout <<f << endl;

    aux2 = no2;

    insercaoNo(&aux2,7,f2);



    return 0;
}
