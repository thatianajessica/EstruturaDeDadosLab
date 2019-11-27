#include <iostream>
#define MAX 1000

using namespace std;

void descer(int *vetor_heap,int n, int i){
    int j = 2*i+1; // filho esquerdo
    if(j<=n-1){
        if(j<n-1){
            if(vetor_heap[j+1]<vetor_heap[j]){//se o filho direito for menor que o da esquerda, atualiza o j para ser o filho direito
                j++;
            }
        }
        if(vetor_heap[i]>vetor_heap[j]){//verifica se eh heap min i = pai, j = filho
            int aux = vetor_heap[i];
            vetor_heap[i]=vetor_heap[j];
            vetor_heap[j]=aux;
            descer(vetor_heap,n, j);
        }
    }
}

void remover(int *vetor_heap, int &n){
    if(n>0){
        vetor_heap[0] = vetor_heap[n-1];
        n = n - 1;
        descer(vetor_heap, n, 0);//removendo sempre a raiz
    }else{
        cout << "Heap vazia" << endl;
    }
}

void subir(int *vetor_heap, int index_elemento){
    int j = (index_elemento - 1) /2;//j = indice do pai, supondo q eh o filho esquerdo q to qurendo subir, se for o direito funciona igual?
    if(j>=0){
        if (vetor_heap[index_elemento] < vetor_heap[j]){//se o valor do filho for maior que o do pai, tem q trocar
            int aux = vetor_heap[j];
            vetor_heap[j] = vetor_heap[index_elemento];
            vetor_heap[index_elemento] = aux;
            subir(vetor_heap,j);
        }
    }
}

void inserir(int *vetor_heap, int &n, int elemento_inserido){
    //realocando mais uma posicao
    //int *novo_heap = new int[n];
    //copiando o vetor antigo para o novo vetor com uma pos a mais
//    for(int i = 0; i < n ; i++){
//        novo_heap[i] = vetor_heap[i];
//    }
    if(n <= MAX){
        n += 1;
        vetor_heap[n-1] = elemento_inserido;
        subir(vetor_heap, n-1);//o elemento que vai subir ta localizado na ultima posicao do vetor, que foi inserida
    }else{
        cout <<"Heap cheia" << endl;
    }
}

void printHeap(int *vetor_heap, int n){
    for(int i = 0; i < n; i++){
        cout << vetor_heap[i] << " ";
    }
    cout << endl;
}
void construirHeapMin(int *vetor_heap, int n){
    //vai deixar a heap maxima, analisando só de n/2 ate raiz
    for(int i = (n/2)-1; i >= 0; i--){
        descer(vetor_heap,n,i);
    }
}




int main()
{
    int *heap = new int[MAX]; //alocando um vetor com no max 1000 posicoes
    heap[0] = 14;
    heap[1] = 1;
    heap[2] = 10;
    heap[3] = 8;
    heap[4] = 7;
    heap[5] = 9;
    heap[6] = 3;
    heap[7] = 2;
    heap[8] = 1;
    int n = 9;

    construirHeapMin(heap,n);
    printHeap(heap,n);


    descer(heap, n,0);
    cout << "##################" << endl;
    printHeap(heap,n);

    cout << "###################" << endl;

    remover(heap,n);
    printHeap(heap,n);

    cout << "###################" << endl;
    inserir(heap,n,13);
    printHeap(heap,n);


    cout << "Hello World!" << endl;
    return 0;
}
