#include <iostream>
using namespace std;

bool SAME_SET(int Vetor_Conjuntos[],int v1,int v2){
    if(Vetor_Conjuntos[v1]==Vetor_Conjuntos[v2]){
        //cout << v1 << " e " << v2 << " pertecem ao mesmo conjunto" << endl;
        return true;
    }
    else{
        //cout << v1 << " e " << v2 << " nao pertecem ao mesmo conjunto" << endl;
        return false;
    }
}

void UNION(int Vetor_Conjuntos[],int n,int v1,int v2){
    if(SAME_SET(Vetor_Conjuntos,v1,v2)==false){
        cout << v1 << " e " << v2 << " serao ligados pois nao formam ciclo" << endl;
        for(int i=0;i<n;i++){
            if(Vetor_Conjuntos[i]==Vetor_Conjuntos[v2]){
                Vetor_Conjuntos[i]=Vetor_Conjuntos[v1];
            }
        }
    }
    else{
        cout << v1 << " e " << v2 << " nao serao ligados pois formam ciclo" << endl;
    }

}

void ExibeVetor(int V[],int n){
    for(int i=0;i<n;i++){
        cout << V[i] << " ";
    }
    cout << endl;
}

int main(){

    int n = 10;
    int Vetor_Conjuntos[n];

    for(int i=0;i<n;i++){
        Vetor_Conjuntos[i] = i;
    }

    ExibeVetor(Vetor_Conjuntos,n);

    UNION(Vetor_Conjuntos,10,0,1);

    ExibeVetor(Vetor_Conjuntos,n);

    UNION(Vetor_Conjuntos,10,1,2);

    ExibeVetor(Vetor_Conjuntos,n);

    UNION(Vetor_Conjuntos,10,2,0);

    ExibeVetor(Vetor_Conjuntos,n);

    UNION(Vetor_Conjuntos,10,0,2);

    ExibeVetor(Vetor_Conjuntos,n);

    UNION(Vetor_Conjuntos,10,8,9);

    ExibeVetor(Vetor_Conjuntos,n);

    UNION(Vetor_Conjuntos,10,0,9);

    ExibeVetor(Vetor_Conjuntos,n);

    return 0;
}


