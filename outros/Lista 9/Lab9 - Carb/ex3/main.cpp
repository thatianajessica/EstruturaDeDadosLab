#include <iostream>

using namespace std;

void descer(int H[],int i, int n){
    int j= 2*i+1; // filho esquerdo
    if(j<=n){
        if(j<n){
            if(H[j+1]>H[j]){
                j++;
            }
            cout<<"Checkpoint 1 descer "<<j<<endl;
        }
        if(H[i]<H[j]){
            int aux = H[i];
            H[i]=H[j];
            H[j]=aux;
            cout<<"Checkpoint 2 descer "<<j<<endl;
            descer(H,j,n);
        }
    }
}

void arranjar(int H[],int n){
    for(int i=(n+1)/2;i>=0;i--){
        cout<<"Checkpoint 1 arranjar "<<i<<endl;
        descer(H,i,n);
    }
}

void printH(int H[], int n){
    for(int i=0;i<n;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

void HeapSort(int H[],int n){
    arranjar(H,n);
    cout<<"Checkpoint 1 heap"<<endl;
    int m=n-1;
    printH(H,n);
    while(m>0){
        int aux = H[0];
        H[0] = H[m];
        H[m] = aux;
        cout<<"Checkpoint 2 heap "<<m-1<<endl;
        m--;
        printH(H,n);
        descer(H,0,m);
    }
}


int main()
{
    int n;
    cin>>n;

    int H[n];

    for(int i=0;i<n;i++){
        cin>>H[i];
    }

    HeapSort(H,n);

    printH(H,n);

    cout<<endl;


    return 0;
}
