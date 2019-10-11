#include <iostream>

using namespace std;

int pilha[10][5];
int cap=10, topo=-1;

void empilhar(int n, int p1, int p2, int p3, int flag ){
    if(topo>=cap-1){
        cout<<"overflow"<<endl;
        exit(1);
    }
    else{
        topo++;
        pilha[topo][0]= n;
        pilha[topo][1]= p1;
        pilha[topo][2]= p2;
        pilha[topo][3]= p3;
        pilha[topo][4]= flag;
    }
}

void desempilhar(){
    if(topo<=-1){
        cout<<"underflow"<<endl;
        exit(1);
    }
    else{
        topo--;
    }
}

void display(){
    for(int i=0;i<=topo;i++){
        cout<<pilha[i][0]<<" "<<pilha[i][1]<<" "<<pilha[i][2]<<" "<<pilha[i][3]<<" "<<pilha[i][4]<<endl;
    }
}

void hanoi(int n){
    int p1=1, p2=2,p3=3,flag=0;
    empilhar(n,p1,p2,p3,flag);
    int *aux;
    while(topo!=-1){
        aux=pilha[topo];
        if(aux[0]==1){
            cout<<"P"<<aux[1]<<" -> P"<<aux[2]<<endl;
            desempilhar();
            while(pilha[topo][4]==1){desempilhar();}
            if(pilha[topo][4]==0 && topo!=-1){
                aux=pilha[topo];
                aux[4]=1;
                desempilhar();
                empilhar(aux[0],aux[1],aux[2],aux[3],aux[4]);
            }
        }
        else{
            if(aux[4]==0){
                empilhar(aux[0]-1,aux[1],aux[3],aux[2],0);
            }
            else{
                cout<<"P"<<aux[1]<<" ->> P"<<aux[2]<<endl;
                empilhar(aux[0]-1,aux[3],aux[2],aux[1],0);

            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    hanoi(n);
    return 0;
}
