#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    float peso;
    struct No *prox;
}No;

typedef struct Lista{
    int n;
    No *cabeca;
}Lista;

typedef struct Grafo{
    int n_vertices;
    Lista *lista_adj;
}Grafo;

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


No* criarNo(int chave, float peso){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->chave = chave;
    novo_no->peso = peso;
    return novo_no;
}

Lista* criarListaVazia(){
    Lista *nova_lista = new Lista;
    nova_lista->cabeca = NULL;
    nova_lista->n = 0;
    return nova_lista;
}

void adicionaListaCauda(Lista *lista, int no_index, float peso){
    No* no_adc = criarNo(no_index, peso);
    if (lista->cabeca == NULL){
        lista->cabeca = no_adc;
    }else{
        No *cauda = lista->cabeca;
        for (int i = 0 ; i < ((lista->n)-1); i++) {
            cauda = cauda->prox;
        }
        cauda->prox = no_adc;
    }
    lista->n += 1;
}

Grafo* criarGrafoVazio(int n_vertices){
    Grafo *novo_grafo = new Grafo;
    novo_grafo->n_vertices = n_vertices;
    novo_grafo->lista_adj = new Lista[n_vertices];//funciona como o vetor sequencial
    for(int i = 0; i < n_vertices; i++){
        novo_grafo->lista_adj[i].cabeca = NULL;
        novo_grafo->lista_adj[i].n = 0;
    }
    return novo_grafo;
}

void conectarVerticesNaoDirecionado(Grafo *grafo, int index_v1, int index_v2, float peso){

    adicionaListaCauda(& (grafo->lista_adj[index_v1]), index_v2, peso);
    adicionaListaCauda(& (grafo->lista_adj[index_v2]), index_v1, peso);
}

bool verificarAdjacencia(Grafo *grafo, int index_v1, int index_v2){
    No *aux = grafo->lista_adj[index_v1].cabeca;
    while(aux != NULL){
        if(aux->chave == index_v2){
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

void printarListasAdj(Grafo *grafo){
    for(int i = 0; i < grafo->n_vertices; i++){
        cout << "Vertice = " << i << " : ";
        No *aux = grafo->lista_adj[i].cabeca;
        while(aux != NULL){
            cout << aux->chave<< " - ";
            aux = aux->prox;
        }
        cout << endl;
    }
}

void printarListasAdjComPesos(Grafo *grafo){
    for(int i = 0; i < grafo->n_vertices; i++){
        cout << "Vertice = " << i << " : ";
        No *aux = grafo->lista_adj[i].cabeca;
        while(aux != NULL){
            cout <<aux->peso <<" | " <<aux->chave<< " - ";
            aux = aux->prox;
        }
        cout << endl;
    }
}

int* codigoPuffer(Grafo *grafo){
    int *pruffer = new int[grafo->n_vertices];
    for(int i = 0; i < grafo->n_vertices; i++){
        if(grafo->lista_adj[i].n == 1){//identificando os index do vertice folha;
            construirHeapMin(vetor_heap, )

        }
    }
}

int main(int argc, char *argv[])
{
    int n_vertices = 10;
    Grafo *novo_grafo = criarGrafoVazio(n_vertices);

    conectarVerticesNaoDirecionado(novo_grafo,0,2,1);
    conectarVerticesNaoDirecionado(novo_grafo,1,2,1);
    conectarVerticesNaoDirecionado(novo_grafo,3,2,1);
    conectarVerticesNaoDirecionado(novo_grafo,2,5,1);
    conectarVerticesNaoDirecionado(novo_grafo,4,5,1);
    conectarVerticesNaoDirecionado(novo_grafo,6,5,1);
    conectarVerticesNaoDirecionado(novo_grafo,8,5,1);
    conectarVerticesNaoDirecionado(novo_grafo,7,8,1);
    conectarVerticesNaoDirecionado(novo_grafo,9,8,1);

    printarListasAdj(novo_grafo);

    cout << "############################" <<endl;






    return 0;
}
