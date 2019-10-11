
#include <iostream>

using namespace std;

void descer(int H[],int n, int i){
    int j= 2*i+1; // filho esquerdo
    if(j<=n){
        if(j<n){
            if(H[j]>H[j-1]){
                j++;
            }
        }
        if(H[i]<H[j-1]){
            int aux = H[i];
            H[i]=H[j-1];
            H[j-1]=aux;
            descer(H,n, j-1);
        }
    }
}


void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout<<""<<endl;

}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        descer(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        descer(arr, i, 0);
    }
}
int main()
{
    // Array representando a maxheap
    // 10
    //    /  \
    // 5    3
    //  / \
    // 2   4
    int arr[] = { 10, 20, 45, 1, 5, 3, 2, 4, 6, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    cout<<"Ordenado pelo heapSort"<<endl;
    heapSort(arr, n);
    print(arr, n);
    return 0;
}
