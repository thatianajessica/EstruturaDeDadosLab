#include <iostream>

#define PESO_NULO 0

using namespace std;


typedef struct No{
    int chave;
    float peso;
    struct No *prox;
    bool visitado;
}No;

typedef struct Lista{
    int n;
    No *cabeca;
    No *cauda;
}Lista;

typedef struct Grafo{
    int n_vertices;
    Lista *lista_adj;
    bool *marcados;
}Grafo;

No* criarNo(int chave, float peso){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->chave = chave;
    novo_no->peso = peso;
    novo_no->visitado = false;
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
        lista->cauda = no_adc;
    }else{
        lista->cauda->prox = no_adc;
        lista->cauda = no_adc;
    }
    lista->n += 1;
}

void removerCauda(Lista *lista){
    if(lista->n == 0){
        return;
    }
    if (lista->n == 1){
        lista->cabeca = NULL;
        lista->n = lista->n - 1;
    }else{
        No *aux;
        aux = lista->cabeca;
        for (int i = 0; i < lista->n-2; i++) {
            aux = aux->prox;
        }
        aux->prox = NULL;
        lista->n = lista->n - 1;
    }
}

void removerNoListaComChave(Lista *lista, int chave_remover){
    if(lista->n == 0){
        cout <<"Lista vazia" <<endl;
    }else{
        No *aux = lista->cabeca;
        No *ant = NULL;
        while(true){
            if(lista->cabeca->chave == chave_remover){
                lista->cabeca = aux->prox;//elemento ta na propria cabeca da lista
                break;
            }else{
                if(aux->chave == chave_remover){
                    ant = aux;
                    aux = aux->prox;
                    break;
                }
                ant = aux;
                aux = aux->prox;
            }
            if(aux == NULL){
                cout <<" elemento nao removido pois nao tá na lista de adj" << endl;
                break;
            }
        }
    }
    lista->n -= 1;
}

Grafo* criarGrafoVazio(int n_vertices){
    Grafo *novo_grafo = new Grafo;
    novo_grafo->n_vertices = n_vertices;
    novo_grafo->lista_adj = new Lista[n_vertices];//funciona como o vetor sequencial
    novo_grafo->marcados = new bool[n_vertices];
    for(int i = 0; i < n_vertices; i++){
        novo_grafo->lista_adj[i].cabeca = NULL;
        novo_grafo->lista_adj[i].n = 0;
        novo_grafo->marcados[i] = false;
    }

    return novo_grafo;
}



void conectarVerticesNaoDirecionado(Grafo *grafo, int index_v1, int index_v2, float peso){

    adicionaListaCauda(& (grafo->lista_adj[index_v1]), index_v2, peso);
    adicionaListaCauda(& (grafo->lista_adj[index_v2]), index_v1, peso);
}

void removerAresta(Grafo *grafo, int index_v1, int index_v2){
    removerNoListaComChave(&grafo->lista_adj[index_v1], index_v2);
    removerNoListaComChave(&grafo->lista_adj[index_v2], index_v1);
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

void profundidadeVertice(Grafo *grafo, int vertice, bool *visited, int depth){
    visited[vertice] = true;
    cout << "index: " << vertice << " | depth: " << depth << endl;


    No* no = grafo->lista_adj[vertice].cabeca;
    while (no != NULL) {
        if (visited[no->chave] == false){
            profundidadeVertice(grafo, no->chave, visited, depth+1);
        }
        no = no->prox;
    }
}

void buscaProfundidade(Grafo *grafo, int vertice_inicio){
    // Marca todos os nos como não visitados
    bool *visited = new bool[grafo->n_vertices];
    for (int i = 0; i < grafo->n_vertices; i++)
        visited[i] = false;

    profundidadeVertice(grafo, vertice_inicio, visited, 0);
}



void visitar(Grafo *grafo, int index1, int index2){
    No* no = grafo->lista_adj[index1].cabeca;
    while(no != NULL){
        if (no->chave == index2){
            no->visitado = true;
            break;
        }
        no = no->prox;
    }

    no = grafo->lista_adj[index2].cabeca;
    while(no != NULL){
        if (no->chave == index1){
            no->visitado = true;
            break;
        }
        no = no->prox;
    }
}

bool foi_visitado(Grafo *grafo, int index1, int index2)
{
    No* no = grafo->lista_adj[index1].cabeca;
    while(no != NULL){
        if (no->chave == index2 ){
            if (no->visitado == false){
                return false;
            }else{
                break;
            }
        }
        no = no->prox;
    }
    if (no == NULL){
        return false;
    }

    no = grafo->lista_adj[index2].cabeca;
    while(no != NULL){
        if (no->chave == index1){
            if (no->visitado == false){
                return false;
            }else{
                break;
            }
        }
        no = no->prox;
    }
    if (no == NULL){
        return false;
    }
    return true;
}

void BP(Grafo *grafo, int vertice_inicio)
{
    cout << vertice_inicio << endl;
    grafo->marcados[vertice_inicio] = true;
    No* no = grafo->lista_adj[vertice_inicio].cabeca;
    while (no != NULL) {

        int no_index = no->chave;
        if ( grafo->marcados[no_index] == false){
            visitar(grafo, vertice_inicio, no_index);
            grafo->marcados[no_index] = true;
            BP(grafo, no_index);
        }
        else{
            if (!foi_visitado(grafo, vertice_inicio, no_index)){
               visitar(grafo, vertice_inicio, no_index);
            }
        }

        no = no->prox;
    }
}

int main()
{
    Grafo* grafo = criarGrafoVazio(12);

    // https://pt.wikipedia.org/wiki/Busca_em_profundidade FIG 1
    conectarVerticesNaoDirecionado(grafo, 0, 1, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 0, 6, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 0, 7, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 1, 2, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 1, 5, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 2, 3, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 2, 4, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 7, 8, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 7, 11, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 8, 9, PESO_NULO);
    conectarVerticesNaoDirecionado(grafo, 8, 10, PESO_NULO);

    //buscaProfundidade(grafo, 0);
    BP(grafo, 0);

    return 0;
}
