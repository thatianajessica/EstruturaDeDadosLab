#include <iostream>

using namespace std;

bool seqBalanc(int *seq, int n){
    int maior;
    int menor;
    int iMaior;
    int iMenor;
    int soma;
    int temp;
    for(int i=0;i<n/2;i++){
        maior=-1;
        menor=100000000;
        for(int j=i;j<n-i;j++){
            if(seq[j]>maior){
                maior=seq[j];
                iMaior=j;
            }
            else if(seq[j]<menor){
                menor=seq[j];
                iMenor=j;
            }
        }

        if(i==0){
            soma=maior+menor;
        }

        if(soma==maior+menor){
            temp=seq[iMaior];
            seq[iMaior]=seq[n-1-i];
            seq[n-1-i]=temp;

            temp=seq[iMenor];
            seq[iMenor]=seq[i];
            seq[i]=temp;
        }

        else {
            return 0;
        }
    }
    return 1;
}

int main(){
    int *seq;
    int n;
    cin>>n;
    seq= new int[n];

    for(int i =0;i<n;i++){
        cin>>seq[i];
    }

    return seqBalanc(seq,n);
}
