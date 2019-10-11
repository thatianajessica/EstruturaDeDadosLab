#include <iostream>
using namespace std;

typedef struct s{
    int linha;
    int coluna;
    int chave; // chave (conteúdo armazenado)
    struct s *next; // ponteiro para o próximo elemento
    struct s *prev; // ponteiro para o elemento anterior
} No;


/*
Aloca o cabeça e retorna seu ponteiro .
Dada a alocaçao do nó cabeça, temos, pois, a uma lista vazia
*/
No *criarCabeca(){
    No *cabeca = new No (); // alocaçao
    if (cabeca!=NULL){ // apenas pra verificar se a alocaçao foi bem sucedida
        cabeca->chave = -1; // Somente pra dizer que o conteudo da cebça é desprezível
        cabeca->linha = -1;
        cabeca->coluna = -1;
        cabeca->next = cabeca; // lista vazia
        cabeca->prev = cabeca; // lista vazia
    }
    return cabeca;
}

No * busca(No *cabeca, int l, int c){
    No *aux = cabeca->next;
    while (aux->linha < l && aux !=cabeca){
        aux = aux->next;
    }
    if(aux->linha>l || aux == cabeca){
        return aux;
    }
    while(aux->coluna < c && aux!=cabeca){
        aux = aux->next;
    }
    return aux;
}

void insert(No *cabeca,int l, int c, int novoValor){
    No *resulBusca = busca(cabeca, l, c);
    if (resulBusca == cabeca || resulBusca->linha != l || resulBusca->coluna !=c ){
        No *anterior = resulBusca->prev;
        No *novoNo = new No();
        if (novoNo!=NULL){
            novoNo->chave = novoValor;
            novoNo->linha = l;
            novoNo->coluna = c;
            novoNo->prev = anterior;
            novoNo->next = resulBusca;
            anterior->next = novoNo;
            resulBusca->prev = novoNo;
        }
    } else if(resulBusca->linha==l && resulBusca->coluna == c) {
        cout<<"Linha "<<l<<" e Coluna "<<c<<" ja se encontram na lista"<<endl;
    }
}

void remove(No *cabeca){
        No * ant = cabeca->prev;
        No * prox = cabeca->next;
        ant->next = prox;
        prox->prev = ant;
        delete cabeca; // IMPORTANTE NAO ESQUECER
}


// Imprime a lista da cabeça até o último elemento (ordem crescente)
void printDireto(No *cabeca){
    No *aux = cabeca->next;
    while (aux!=cabeca){
        cout<<"l "<<aux->linha<<", c "<<aux->coluna<<", x "<<aux->chave<<endl;
        aux = aux->next;
    }
    cout<<endl;
}



int buscaElem(No *cabeca, int l, int c){
    No *aux = cabeca->next;
    while (aux->linha != l){
        aux = aux->next;
        if(aux == cabeca){
            return 0;
        }
    }
    while(aux->coluna != c){
        aux = aux->next;
        if(aux == cabeca || aux->linha>l){
            return 0;
        }
    }

    return aux->chave;


}
// Imprime a lista do último elemento até a cabeça (ordem decrescente)



No* somar(No* l1, No* l2){
    No *aux=criarCabeca();
    No *l = aux;
    while(l1->next!=l1 && l2->next!=l2){
        if(l1->next->linha < l2->next->linha){
            l->next = l1->next;
            l1->next->prev = l;
            l1->next=l1->next->next;
            l->next->next = aux;
            aux->prev = l->next;
            l=l->next;
        }
        else if(l1->next->linha < l2->next->linha){
            l->next = l2->next;
            l2->next->prev = l;
            l2->next=l2->next->next;
            l->next->next = aux;
            aux->prev = l->next;
            l=l->next;
        }
        else{
            if(l1->next->coluna < l2->next->coluna){
                l->next = l1->next;
                l1->next->prev = l;
                l1->next=l1->next->next;
                l->next->next = aux;
                aux->prev = l->next;
                l=l->next;
            }
            else if(l1->next->coluna > l2->next->coluna){
                l->next = l2->next;
                l2->next->prev = l;
                l2->next=l2->next->next;
                l->next->next = aux;
                aux->prev = l->next;
                l=l->next;
            }
            else{
                l->next = l1->next;
                l->next->chave = l1->next->chave + l2->next->chave;
                l1->next->prev = l;
                l1->next=l1->next->next;
                l2->next->prev = l;
                l2->next=l2->next->next;
                l->next->next = aux;
                aux->prev = l->next;
                l=l->next;
                if(l->chave == 0){
                    remove(l);
                }
            }
        }
    }
    while(l1->next!=l1){
        l->next = l1->next;
        l1->next->prev = l;
        l1->next=l1->next->next;
        l->next->next = aux;
        aux->prev = l->next;
        l=l->next;

    }
    while(l2->next!=l2){
        l->next = l2->next;
        l2->next->prev = l;
        l2->next=l2->next->next;
        l->next->next = aux;
        aux->prev = l->next;
        l=l->next;

    }
    return aux;
}

int main(){
    No *mat1 = criarCabeca();
    int l,c,x;
    cout<<"Insira linha,coluna e valor, pra cancelar insira 0 em valor"<<endl;
    while(1){
        cin>>l>>c>>x;
        if(x==0){
            break;
        }
        insert(mat1,l,c,x);
    }
    cout<<endl;
    No* mat2 = criarCabeca();
    cout<<"Matriz 2"<<endl;
    while(1){
        cin>>l>>c>>x;
        if(x==0){
            break;
        }
        insert(mat2,l,c,x);
    }

    printDireto(mat1);
    cout<<endl;
    printDireto(mat2);
    cout<<endl;
    No *soma = somar(mat1,mat2);

    printDireto(soma);




    return 0;
}
