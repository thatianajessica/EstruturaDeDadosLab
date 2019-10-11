#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
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

void subir(int arr[], int n, int i)
{
    // Encontra seu vizinho
    int parent = (i - 1) / 2;
    if (arr[parent] > 0) {
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            subir(arr, n, parent);
        }
    }
}

void insertNode(int arr[], int& n, int Key)
{
    // Inrementa o tamanho da heap
    n = n + 1;
    // Insere o elemento no fim da heap
    arr[n - 1] = Key;
    // Sobe o nó até sua posição definida de prioridade
    subir(arr, n, n - 1);
}

void deleteRoot(int arr[], int& n)
{
    //coloca o ultimo elemento na raiz e decrementa em 1
    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    //desce a partir da raiz, agora, sendo o ultimo elemento
    descer(arr, n, 0);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout<<""<<endl;

}
int main()
{
    // Array representando a maxheap
    // 10
    //    /  \
    // 5    3
    //  / \
    // 2   4
    int arr[] = { 10, 5, 3, 2, 4, 6, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    cout<<"Deletando raiz da heap"<<endl;
    deleteRoot(arr, n);
    print(arr, n);
    cout<<"Deletando raiz da heap"<<endl;
    deleteRoot(arr, n);
    print(arr, n);
    cout<<"Inserindo no na heap"<<endl;
    insertNode(arr, n, 1);
    print(arr, n);
    cout<<"Deletando raiz da heap"<<endl;
    deleteRoot(arr, n);
    print(arr, n);
    return 0;
}
