#include <iostream>
#include <string.h>

using namespace std;

typedef struct No{
    char chave;
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

char desempilha(Pilha *pilha){
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

bool is_number(char c)
{
    bool is_op = true;
    if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^')
    {
        is_op = false;
    }
    return is_op;
}

int computar_score_operador(char c)
{
    if(c == '+' || c == '-')
    {
        return 0;
    }

    if(c == '*' || c == '/')
    {
        return 1;
    }

    if(c == '^' )
    {
        return 2;
    }
}

bool tem_prioridade(char a, char b)
{
    int score_a = computar_score_operador(a);
    int score_b = computar_score_operador(b);
    bool out = (score_b <= score_a);
    return out;
}

void converte_notacao_polonesa(const char* expressao)
{
    Pilha *pilha = criarPilhaVazia();
    int n_parenteses_aberto = 0;
    int n = strlen(expressao);
    for (int i=0; i < n; i++)
    {
        if( is_number( expressao[i] ) )
        {
            cout << expressao[i];
        }
        else
        {
            if(expressao[i] == '(')
            {
                n_parenteses_aberto++;
                empilhar(pilha, expressao[i]);
            }
            else if(expressao[i] == ')')
            {
                while(true)
                {
                    char c = desempilha(pilha);
                    if (c != '(' && c != ')') cout << c;
                    if (c == '(') break;
                }
                n_parenteses_aberto--;
            }
            else if(n_parenteses_aberto==0)
            {
                if(pilha->topo == NULL){
                    empilhar(pilha, expressao[i]);
                }else{
                    if ( tem_prioridade(pilha->topo->chave, expressao[i]) )
                    {
                        char c = desempilha(pilha);
                        cout << c;
                        empilhar(pilha, expressao[i]);
                    }else
                    {
                        empilhar(pilha, expressao[i]);
                    }
                }
            }
            else{
                empilhar(pilha, expressao[i]);
            }

        }
    }

    while(pilha->topo != NULL){
        char c = desempilha(pilha);
        cout << c;
    }
}





int main()
{
    converte_notacao_polonesa("A*B+C/D");
    cout << endl;
    converte_notacao_polonesa("A*(B+C)");
    cout << endl;
    converte_notacao_polonesa("((A*B)-(C/D))");
    cout << endl;
    converte_notacao_polonesa("((A+B)*C-D)*E");
    return 0;
}
