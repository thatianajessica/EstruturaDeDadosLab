#include <iostream>
#include <list>
#include <cmath>


using namespace std;

void insertionSort(int *seq, int n){
    int j,x;
    for (int i=1; i < n ; i++){
        x=seq[i];
        j=i-1;
        while((j>=0)&&(seq[j]>x)){
            seq[j+1]=seq[j];
            j=j-1;
        }
        seq[j+1]=x;
    }
}

void selectionSort(int *seq, int n){
    int minimo,temp;
    for(int i=0;i<n;i++){
        minimo=i;
        for(int j=i+1;j<n;j++){
            if(seq[j]<seq[minimo]){
                minimo=j;
            }
        }
        temp=seq[minimo];
        seq[minimo]=seq[i];
        seq[i]=temp;
    }
}

void bubbleSort(int *seq, int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(seq[j]>seq[j+1]){
                temp=seq[j+1];
                seq[j+1]=seq[j];
                seq[j]=temp;
            }
        }
    }
}

void mergeSort(int *seq, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(seq,p,q);
        mergeSort(seq,q+1,r);

        int n1 = q-p+2;
        int n2 = r-q+1;
        int L[n1], R[n2];

        for(int i=0;i<n1-1;i++){
            L[i]=seq[p+i];
        }
        for(int j=0;j<n2-1;j++){
            R[j]=seq[q+j+1];
        }
        L[n1-1] = 100000000;
        R[n2-1] = 100000000;

        int i=0;
        int j=0;

        for(int k=p;k<=r;k++){
            if(L[i]<R[j]){
                seq[k]=L[i];
                i++;
            }
            else{
                seq[k]=R[j];
                j++;
            }
        }


    }

}

void quickSort(int *seq, int p, int r){
    if (p<r){
        int temp;
        int x=seq[r];
        int i=p-1;
        for(int j=p;j<r;j++){
            if(seq[j]<x){
                i++;
                temp=seq[i];
                seq[i]=seq[j];
                seq[j]=temp;
            }
        }
        temp=seq[i+1];
        seq[i+1]=seq[r];
        seq[r]=temp;

        int q=i+1;

        quickSort(seq,p,q-1);
        quickSort(seq,q+1,r);

    }


}

void countingSort(int *seq, int *resp, int lim, int n){
    int C[lim];
    for(int i=0;i<lim;i++){
        C[i]=0;
    }
    for( int j=0;j<n;j++){
        C[seq[j]]++;
    }
    for(int i=1;i<lim;i++){
        C[i]+=C[i-1];
    }
    for(int j=(n-1);j>=0;j--){
        resp[C[seq[j]]-1]=seq[j];
        C[seq[j]]--;
    }
}

void insertionSortD(int *seq, int n, int d){
    int *seqD;
    seqD=new int(n);
    int base=1;
    for(int i=1;i<d;i++){
        base=base*10;
    }
    for(int i=0;i<n;i++){
        seqD[i]=seq[i]/base;
        seqD[i]=seqD[i]%10;
    }

    int j,x,y;
    for (int i=1; i < n ; i++){
        x=seqD[i];
        y=seq[i];
        j=i-1;
        while((j>=0)&&(seqD[j]>=x)){
            seq[j+1]=seq[j];
            seqD[j+1]=seqD[j];
            j=j-1;
        }
        seq[j+1]=y;
        seqD[j+1]=x;
    }
    delete seqD;
}

void radixSort(int *seq, int d, int n){
    for(int i=0;i<d;i++){
            insertionSortD(seq,n,d);
    }
}

void bucketSort(int *seq, int n){
    list<int> *B;
    B= new list<int> (n);

    for(int i=0; i<n ;i++){
        B[(int)n*seq[i]].push_back(seq[i]);
    }
    for(int i=0;i<n;i++){
////
    }
    list<int> juntar;

    for(int i=0;i<n;i++){
        juntar.merge(B[i]);
    }
  ////
}

int main(){
    int n;
    cout<<"n"<<endl;
    cin>>n;

    int *sequencia;
    sequencia = new int(n);

    cout<<"sequencia"<<endl;
    for(int i=0;i<n;i++){
        cin>>sequencia[i];
    }
    cout<<endl;

    int *resp;
    resp=new int(n);
    radixSort(sequencia,3,n);

    for(int i=0;i<n;i++){
        cout<<sequencia[i]<<endl;
    }
    cout<<endl;

    delete sequencia;
    return 0;
}
