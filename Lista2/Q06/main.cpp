#include <iostream>
#define MAX 100

using namespace std;

void multAV(int A[MAX][MAX],int V[MAX],int R[MAX], int m){
    for(int i=0;i<m;i++){
        int soma=0;
        for(int j=0;j<m;j++){
            soma+=A[i][j]*V[j];
        }
        R[i]=soma;
    }
}



int main(){
    int m;
    cout<<"A"<<endl;
    cin>>m;
    int MA[m][MAX];
    for(int i=0 ;i<m;i++){
        cout<<"linha "<<i<<endl;
        for(int j=0;j<m;j++){
            cin>>MA[i][j];
        }
    }

    cout<<"V"<<endl;
    int V[m],R[m];
    for(int i=0;i<m;i++){
        cin>>V[i];
    }

    multAV(MA,V,R,m);

    for(int i =0;i<m;i++){
        cout<<R[i]<<" ";
    }
    cout<<endl;


    return 0;
}
