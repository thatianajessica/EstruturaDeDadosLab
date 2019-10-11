#include <iostream>
#define MAX 100

using namespace std;

int n = 0;

void subir(int H[],int i){
    int j= (i-1)/2; //pai
    if(j>=0){
        if(H[i]>H[j]){
            int aux = H[i];
            H[i] = H[j];
            H[j] = aux;
            subir(H,j);
        }
    }
}

void subir_iter(int H[],int i){
    int j=(i-1)/2; //pai
    while(j>=0){
        if(H[i]>H[j]){
            int aux = H[i];
            H[i] = H[j];
            H[j] = aux;
            j=(j-1)/2;
        }
        else{
            j=(j-1)/2;
        }
    }
}

void descer(int H[],int i, int n){
    int j= 2*i+1; // filho esquerdo
    if(j<=n){
        if(j<n){
            if(H[j+1]>H[j]){
                j++;
            }
        }
        if(H[i]<H[j]){
            int aux = H[i];
            H[i]=H[j];
            H[j]=aux;
            descer(H,j,n);
        }
    }
}

void descer_iter(int H[],int i){
    int j= 2*(i-1); // filho esquerdo
    while(j<n){
        if(j<n-1){
            if(H[j+1]>H[j]){
                j++;
            }
        }
        if(H[i]<H[j]){
            int aux = H[i];
            H[i]=H[j];
            H[j]=aux;
            j=2*(j-1);
        }
    }
}

void inserir(int H[], int novo){
    if(n<MAX){
        n++;
        H[n-1]=novo;
        subir(H,n-1);
    }
    else{
        cout<<"Nao ha espaco"<<endl;
    }
}

void remover(int H[]){
    if(n>0){
        int elemento = H[0];
        H[0] = H[n-1];
        n--;
        descer(H,n-1);
    }
    else{
        cout<<"Heap vazia"<<endl;
    }
}

int main()
{
    int H[MAX];
    int temp;
    while(1){
        cin>>temp;
        if(temp==0){
            break;
        }
        inserir(H,temp);
    }
    while(1){
        cin>>temp;
        if(temp==0){
            break;
        }
        remover(H);
    }

    for(int i=0;i<n;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;


    return 0;
}
