#include <iostream>

using namespace std;



typedef struct _No_Tree
{
    // estudar depois templates em C++
    int chave_int;
    char chave_char;

    struct _No_Tree *left;
    struct _No_Tree *right;
}NoTree;

typedef struct _No_Stack
{
    // estudar depois templates em C++
    _No_Tree *chave_tree;
    _No_Stack *next;
}No_Stack;

typedef struct _Pilha
{
    _No_Stack* topo;
    int n;
}Pilha;

struct Arvore{
    _No_Tree *raiz;
    int n;
};

NoTree* createNoTree(char c)
{
    NoTree* no = new NoTree;
    no->chave_char = c;
    no->left = NULL;
    no->right = NULL;
    return no;
}

void connectNodes(NoTree* parent, NoTree* left, NoTree* right)
{
    parent->left = left;
    parent->right = right;
}

Pilha* criarPilhaVazia(){
    Pilha *nova_pilha = new Pilha();
    nova_pilha->n = 0;
    nova_pilha->topo = NULL;
    return nova_pilha;
}

void empilhar(Pilha* p, No_Stack* no){
    if(p != NULL){
        No_Stack* aux = p->topo;
        no->next = aux;
        p->topo = no;
    }
}

void empilhar2(Pilha* p, NoTree* not_t){
    No_Stack*  no_s = new No_Stack;
    no_s->chave_tree = not_t;
    empilhar(p, no_s);
}


_No_Stack* desempilhar(Pilha* p)
{
    if(p != NULL)
    {
        _No_Stack* aux = p->topo;
        p->topo =  p->topo->next;
        return aux;
    }
    return NULL;
}

_No_Tree* criarNo(int chave){
    NoTree *novo_no = new NoTree;
    novo_no->left = NULL;
    novo_no->right = NULL;
    novo_no->chave_int = chave;
    return novo_no;
}

Arvore* criarArvoreVazia(){
    Arvore *nova_arvore = new Arvore();
    nova_arvore->raiz = NULL;
    nova_arvore->n = 0;
    return nova_arvore;
}


void SistematicoOrdemIterativo(_No_Tree *no_raiz){
    Pilha *p = criarPilhaVazia();
    bool fim = false;
    while(fim == false)
    {
        while(no_raiz != NULL)
        {
            empilhar2(p,no_raiz);
            no_raiz = no_raiz->left;
        }
        if(p->topo != NULL)
        {
            _No_Stack* aux = desempilhar(p);
            no_raiz = aux->chave_tree;
            cout << aux->chave_tree->chave_char << " ";
            no_raiz = no_raiz->right;
        }else{
            fim = true;
        }

    }
    cout << endl;
}



Arvore* createArvoreExample1()
{
    Arvore *arvore = criarArvoreVazia();

    NoTree* noA = createNoTree('A');
    NoTree* noB = createNoTree('B');
    NoTree* noC = createNoTree('C');
    NoTree* noD = createNoTree('D');
    NoTree* noE = createNoTree('E');
    NoTree* noF = createNoTree('F');
    NoTree* noH = createNoTree('H');
    NoTree* noI = createNoTree('I');
    NoTree* noJ = createNoTree('J');

    connectNodes(noA, noB, noC);
    connectNodes(noB, noD, noH);
    connectNodes(noD, NULL,noJ);

    connectNodes(noC, noE, noF);
    connectNodes(noF, noI, NULL);
    arvore->raiz = noA;
    return arvore;
}



int main()
{
    Arvore* arvore =  createArvoreExample1();
    SistematicoOrdemIterativo(arvore->raiz);

    return 0;
}
