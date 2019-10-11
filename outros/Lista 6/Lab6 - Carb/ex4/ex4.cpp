#include <iostream>

using namespace std;

char pilha[100];
int n=100, topo=-1;

void push(char val){
    if(topo>=n-1){
        cout<<"Overflow"<<endl;
    }
    else{
        topo++;
        pilha[topo]=val;
    }
}

char pop(){
    char aux;
    if(topo<=-1){
        cout<<"Underflow"<<endl;
        aux=-1;
    }
    else{
        cout<<"Saiu "<<pilha[topo-1]<<endl;
        aux=pilha[topo-1];
        topo--;
    }
    return aux;
}

void display(){
    if(topo>=0){
        cout<<"Elementos: "<<endl;
        for(int i=0;i<topo;i++){
            cout<<pilha[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"Vazio"<<endl;
    }
}


bool palindromo(string palavra){
    char letra;
    cout<<topo<<endl;
    for(int i=0;i<topo/2 +1;i++){
        letra=pop();
        cout<<letra<<" ";
        cout<<palavra[i]<<endl;
        if(palavra[i]!=letra){
            return false;
        }
    }
    return true;

}

int main(){
    string palavra;
    cin>>palavra;
    for(int i=0;i<=palavra.size();i++){
        push(palavra[i]);
    }
    display();

    return palindromo(palavra);
}
