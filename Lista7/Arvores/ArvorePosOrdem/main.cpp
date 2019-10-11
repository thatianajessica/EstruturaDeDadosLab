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
    int chave_int;

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

NoTree* createNoTree2(int v)
{
    NoTree* no = new NoTree;
    no->chave_int = v;
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

void empilhar3(Pilha* p, NoTree* not_t, int v){
    No_Stack*  no_s = new No_Stack;
    no_s->chave_tree = not_t;
    no_s->chave_int = v;
    empilhar(p, no_s);
}


_No_Stack* desimpilhar(Pilha* p)
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


void preOrdemIterativo(_No_Tree *no_raiz){
    Pilha *p = criarPilhaVazia();
    bool fim = false;
    while(fim == false)
    {
        if(no_raiz != NULL)
        {
            cout << no_raiz->chave_char << " ";
            if(no_raiz->right != NULL) empilhar2(p, no_raiz->right);
            no_raiz = no_raiz->left;
        }
        else
        {
            if(p->topo == NULL){
                fim = true;
            }
            else{
                _No_Stack* no_s_aux =  desimpilhar(p);
                no_raiz = no_s_aux->chave_tree;
            }

        }

    }
    cout << endl;
}

void posOrdemIterativo(NoTree *no_raiz){
    Pilha *p = criarPilhaVazia();
    bool sobe = false;
    int m;

    do{
        while(no_raiz!= NULL)
        {
            empilhar3(p, no_raiz, 1);
            no_raiz = no_raiz->left;
        }
        sobe = true;
        while(sobe==true && p->topo != NULL)
        {
            _No_Stack* no_s_aux =  desimpilhar(p);
            no_raiz = no_s_aux->chave_tree;
            m = no_s_aux->chave_int;

            switch(m)
            {
                case 1:
                    empilhar3(p, no_raiz, 2);
                    no_raiz = no_raiz->right;
                    sobe = false;
                    break;
                case 2:
                    cout << no_raiz->chave_char << " ";
                    break;

            }
        }
    }while(p->topo!=NULL);

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
    connectNodes(noD, NULL, noJ);

    connectNodes(noC, noE, noF);
    connectNodes(noF, noI, NULL);
    arvore->raiz = noA;
    return arvore;
}


Arvore* createArvoreExample2()
{
    Arvore *arvore = criarArvoreVazia();

    NoTree* no1 = createNoTree2(20);
    NoTree* no2 = createNoTree2(10);
    NoTree* no3 = createNoTree2(15);
    NoTree* no4 = createNoTree2(40);
    NoTree* no5 = createNoTree2(30);
    NoTree* no6 = createNoTree2(50);
    NoTree* no7 = createNoTree2(60);

    connectNodes(no1, no2, no4);
    connectNodes(no2, NULL, no3);
    connectNodes(no4, no5, no6);
    connectNodes(no6, NULL, no7);


    arvore->raiz = no1;
    return arvore;
}




int main()
{
    Arvore* arvore1 =  createArvoreExample1();
    Arvore* arvore2 =  createArvoreExample2();

    posOrdemIterativo(arvore1->raiz);

    return 0;
}
