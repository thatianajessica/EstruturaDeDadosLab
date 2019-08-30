#include <iostream>
#define MAX 100

using namespace std;

void multMat(int **A,int **B, int **C, int m,int n,int c){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int soma=0;
            for(int k=0;k<c;k++){
                soma+=A[i][k]*B[k][j];
            }
            C[i][j]=soma;
        }
    }
}

int main(){
    int m,n,c;

    cin>>m>>n>>c;
    int **A,**B,**C;
    A= new int*[m];
    B= new int*[c];
    C= new int*[m];
    A[0]=new int[m*c];
    B[0]=new int[n*c];
    C[0]=new int[m*n];
    for (int i=0;i<m;i++){
        A[i+1]=A[i]+c;
    }

    for (int i=0;i<c;i++){
        B[i+1]=B[i]+n;
    }

    for (int i=0;i<m;i++){
        C[i+1]=C[i]+n;
    }

    cout<<"A"<<endl;
    for(int i=0;i<m;i++){
        cout<<"linha "<<i<<endl;
        for(int j=0;j<c;j++){
            cin>>A[i][j];
        }
    }

    cout<<"B"<<endl;
    for(int i=0;i<c;i++){
        cout<<"linha "<<i<<endl;
        for(int j=0;j<n;j++){
            cin>>B[i][j];
        }
    }

    multMat(A,B,C,m,n,c);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

