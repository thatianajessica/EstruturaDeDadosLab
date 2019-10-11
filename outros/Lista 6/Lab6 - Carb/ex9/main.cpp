#include <iostream>
#define capacidade 50

using namespace std;

struct Pilha
{
       int topo;
       char item[capacidade];
};

void inic_pilha (struct Pilha *p)
{
     p->topo = -1;
}

bool pilha_vazia (struct Pilha *p)
{
    if (p->topo == -1)
    {
         cout<<"Underflow"<<endl;
         return 1;
    }
    else
     return 0;
}

void push (struct Pilha *p, char valor)
{
    p->item[++(p->topo)] = valor;
}

char pop (struct Pilha *p)
{
    int aux;
    aux = p->item[(p->topo)--];
    return aux;
}


char *notPol(string seq){
    int n = seq.size();
    char *res = new char();
    char popped;
    int j=0;
    Pilha *op = new Pilha();
    inic_pilha(op);
    for(int i=0;i<n;i++){
        if(seq[i]<'A' && seq[i]!=')'){
            push(op,seq[i]);
        }
        else if(seq[i]>='A'){
            res[j]=seq[i];
            j++;
        }
        else{
            popped = pop(op);
            do{
                res[j]=popped;
                j++;
                popped = pop(op);
            }while(popped!='(');
        }
    }
    return res;
}

char *invPol(string seq){
    int n = seq.size();

}

int main(){
    string seq;
    cin>>seq;
    char *result = new char();

    result=notPol(seq);

    cout<<result;



    return 0;
}




