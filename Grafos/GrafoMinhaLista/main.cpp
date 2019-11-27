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

typedef struct Aresta{
    struct No *v1;
    struct No *v2;
    float peso;
}Aresta;

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

int main(int argc, char *argv[])
{
    int n_vertices = 10;
    Grafo *novo_grafo = criarGrafoVazio(n_vertices);

    conectarVerticesNaoDirecionado(novo_grafo,0,2,1);
    conectarVerticesNaoDirecionado(novo_grafo,1,2,3);
    conectarVerticesNaoDirecionado(novo_grafo,3,2,4);
    conectarVerticesNaoDirecionado(novo_grafo,2,5,7);
    conectarVerticesNaoDirecionado(novo_grafo,4,5,5);
    conectarVerticesNaoDirecionado(novo_grafo,6,5,7);
    conectarVerticesNaoDirecionado(novo_grafo,8,5,10);
    conectarVerticesNaoDirecionado(novo_grafo,7,8,17);
    conectarVerticesNaoDirecionado(novo_grafo,9,8,12);

    bool teste_adj = verificarAdjacencia(novo_grafo,0,3);
    cout << teste_adj << endl;
    bool teste_adj2 = verificarAdjacencia(novo_grafo,0,2);
    cout << teste_adj2 << endl;

    printarListasAdj(novo_grafo);

    cout << "############################" <<endl;
    printarListasAdjComPesos(novo_grafo);





    return 0;
}
