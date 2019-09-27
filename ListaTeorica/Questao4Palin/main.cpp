#include <iostream>
#include <string.h>

using namespace std;

typedef struct No{
    int chave;
    struct No *prox;
}No;

typedef struct Pilha{
    struct No *topo;
    int n;
}Pilha;

No* criarNo(char chave){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->chave = chave;
    return novo_no;
}

void deletarNo(No **no){
    No *aux = *no;
    delete aux;
    no = NULL;
}

Pilha* criarPilhaVazia(){
    Pilha *nova_pilha = new Pilha();
    nova_pilha->topo = NULL;
}

void empilhar(Pilha *pilha, char chave){
    No *novo_no = criarNo(chave);
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    pilha->n += 1;
}

int desempilha(Pilha *pilha){
    char valor;
    if(pilha->topo != NULL){
        No *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        valor = aux->chave;
        deletarNo(&aux);
        pilha->n -= 1;
    }else{
        cout <<"PILHA VAZIA" <<endl;
    }
    return valor;
}

Pilha* copiarPilha(Pilha* p)
{
    Pilha* p_aux = criarPilhaVazia();
    Pilha* p_out = criarPilhaVazia();
    while(p->topo != NULL)
    {
        char chave = desempilha(p);
        empilhar(p_aux, chave);
    }

    while(p_aux->topo != NULL)
    {
        char chave = desempilha(p_aux);
        empilhar(p_out, chave);
        empilhar(p, chave);
    }
    return p_out;
}

bool ehPalindromo(const char* word){
    int w_size = strlen(word);
    int index = 0;
    Pilha* p1 = criarPilhaVazia();
    Pilha* p2 = criarPilhaVazia();
    while(index < w_size)
    {
        empilhar(p1, word[index]);
        index++;
    }
    Pilha* p1_copy = copiarPilha(p1);

    while(p1->topo != NULL)
    {
        char chave = desempilha(p1);
        empilhar(p2, chave);
    }

    bool isPalin = true;
    while(p2->topo != NULL)
    {
        char chave1 = desempilha(p1_copy);
        char chave2 = desempilha(p2);
        if (chave1 != chave2)
        {
            isPalin =  false;
            break;
        }
    }

    return isPalin;
}


int main()
{
    bool palin = ehPalindromo("arara");
        cout << "is palindormo " << palin << endl;

        bool palin2 = ehPalindromo("mato");
            cout << "is palindormo " << palin2 << endl;
    return 0;
}
