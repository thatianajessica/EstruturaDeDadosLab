#include <vector>
#include <iostream>
#include <math.h>
using namespace std;


int main(){
    int n, soma =0;
    cout<<"Digite o valor: "<<endl;
    cin>>n;
    int a[n][n], v[n], r[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<"Digite o valor "<<i+1<<" X "<<j+1<< " da matriz:"<<endl;
            cin>>a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
            cout<<"Digite o valor "<<i+1<<" do vetor:"<<endl;
            cin>>v[i];
        }
    for(int i = 0; i < n; i++){
        soma =0;
        for(int j = 0; j < n; j++){
            soma = soma + (a[i][j]*v[j]);
        }
        r[i] = soma;
    }
    cout<<"A multiplicação resultou em [ ";
    for(int i = 0; i < n; i++){
            cout<<r[i]<<" ";
        }
        cout<<"]";
    return 0;
}