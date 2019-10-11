#include <iostream>

using namespace std;

void printH(int H[], int n){
    for(int i=0;i<n;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

void troca(int &x, int &y){
    int aux=x;
    x=y;
    y=aux;
}

void descer(int H[],int V[],int i, int n){
    int j= 2*i+1; // filho esquerdo
    if(j<n){
        if(j<n-1){
            if(V[j+1]<V[j]){
                j++;
            }
            cout<<"Checkpoint 1 descer "<<j<<endl;
        }
        if(V[i]>V[j]){
            troca(H[i],H[j]);
            troca(V[i],V[j]);
            cout<<"Checkpoint 2 descer "<<j<<endl;
            printH(H,n);
            printH(V,n);
            descer(H,V,j,n);
        }
    }
}

void arranjar(int H[],int V[],int n){
    for(int i=(n+1)/2;i>=0;i--){
        cout<<"Checkpoint 1 arranjar "<<H[i]<<" "<<i<<endl;
        printH(H,n);
        printH(V,n);
        descer(H,V,i,n);
    }
}

void HeapSort(int H[],int V[],int n,int k){
    arranjar(H,V,n);
    cout<<"Checkpoint 1 heap"<<endl;
    int m=n-1;
    printH(H,n);
    printH(V,n);
    while(m>=k-1){
        troca(H[0],H[m]);
        troca(V[0],V[m]);
        cout<<"Checkpoint 2 heap "<<m-1<<endl;
        m--;
        printH(H,n);
        printH(V,n);
        descer(H,V,0,m);
    }
}

void maisProx(int H[], int n, int x, int k, int resp[]){
    int V[n];
    for(int i =0;i<n;i++){
        V[i]=abs(H[i]-x);
    }
    HeapSort(H,V,n,k);

    for(int i=0;i<k;i++){
        resp[i]=H[n-i-1];
    }

}


int main()
{
    int n,x,k;
    cout<<"n"<<endl;
    cin>>n;

    int H[n];
    cout<<"H"<<endl;
    for(int i=0;i<n;i++){
        cin>>H[i];
    }

    cout<<"x"<<endl;
    cin>>x;
    cout<<"k"<<endl;
    cin>>k;

    int resp[k];
    maisProx(H,n,x,k,resp);

    printH(resp,k);

    cout<<endl;


    return 0;
}
