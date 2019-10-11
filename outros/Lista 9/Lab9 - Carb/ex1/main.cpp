#include <iostream>

using namespace std;

void checkMaxMin(int heap[], int n){
    bool max= 1;
    bool min = 1;
    for(int i=1;i<n;i++){
        if(heap[i]>heap[(i-1)/2]){
            max=0;
        }
    }
    for(int i=1;i<n;i++){
        if(heap[i]<heap[(i-1)/2]){
            min=0;
        }
    }
    if(!min && !max){
        cout<<"Nao eh max nem min"<<endl;
    }
    else if(!min && max){
        cout<<"Heap Max"<<endl;
    }
    else if (min && !max){
        cout<<"Heap Min"<<endl;
    }

}

int main()
{
    int n;
    cout<<"Numero de elementos"<<endl;
    cin>>n;
    int lista[n];
    cout<<"Lista:"<<endl;

    for(int i=0;i<n;i++){
        cin>>lista[i];
    }

    checkMaxMin(lista,n);

    return 0;
}
