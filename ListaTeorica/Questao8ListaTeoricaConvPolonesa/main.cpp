#include <iostream>
#include <string>

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

bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
        return true;

    return false;
}

bool IsOperand(char C)
{
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}

int pesoOperator(char op)
{
    int weight = -1;
    switch(op)
    {
    case '+':
    case '-':
        weight = 1;
        break;
    case '*':
    case '/':
        weight = 2;
        break;
    case '$':
        weight = 3;
        break;
    }
    return weight;
}

int saberPrecendencia(char op1, char op2)
{
    int op1peso = pesoOperator(op1);
    int op2peso = pesoOperator(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if(op1peso == op2peso)
    {
        return 1;
    }
    int res = op1peso > op2peso;
    return  res;
}

// Function to evaluate Postfix expression and return output
string converterParaPolonesa(string entrada)
{
    Pilha *nova_pilha = criarPilhaVazia();
    string saida = "";
    char aux_desempilha;

    for(int i = 0;i < entrada.length();i++) {

        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(entrada[i] == ' ' || entrada[i] == ',') continue;

        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(entrada[i]) == true)
        {
            while(nova_pilha->topo != NULL && nova_pilha->topo->chave != '(' && saberPrecendencia(nova_pilha->topo->chave,entrada[i]) == 1)
            {
                saida+= nova_pilha->topo->chave;
                aux_desempilha = desempilha(nova_pilha);
            }
            empilhar(nova_pilha,entrada[i]);
        }
        // Else if character is an operand
        else if(IsOperand(entrada[i]) == true)
        {
            saida +=entrada[i];
        }

        else if (entrada[i] == '(')
        {
            empilhar(nova_pilha, entrada[i]);
        }

        else if(entrada[i] == ')')
        {
            while(nova_pilha != NULL && nova_pilha->topo->chave !=  '(') {
                saida += nova_pilha->topo->chave;
                aux_desempilha = desempilha(nova_pilha);
            }
            aux_desempilha = desempilha(nova_pilha);
        }
    }

    while(nova_pilha->topo != NULL) {
        saida += nova_pilha->topo->chave;
        aux_desempilha = desempilha(nova_pilha);
    }

    return saida;
}

int main()
{
    string expression;
    cout<<"Enter Infix Expression \n";
    getline(cin,expression);
    string postfix = converterParaPolonesa(expression);
    cout<<"Output = "<<postfix<<"\n";

    return 0;
}
