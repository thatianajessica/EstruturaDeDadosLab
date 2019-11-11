#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct NoGrafo{
    int n_adjacentes;
    NoGrafo **no_adjacentes;
    int rotulo_vertice;
}NoGrafo;

typedef struct Grafo{
    NoGrafo **nos;
    int n_vertices;
}Grafo;

NoGrafo* criarNo(int rotulo){
    NoGrafo *novo_no = new NoGrafo;
    novo_no->rotulo_vertice = rotulo;
    novo_no->no_adjacentes = NULL;
    novo_no->n_adjacentes = 0;
    return novo_no;
}

//coloca o no2 na lista de adjacencia do no1
void conectarNo(NoGrafo *no1, NoGrafo *no2){
    if(no1->no_adjacentes == NULL){
        no1->no_adjacentes = (NoGrafo**) calloc(1, sizeof(NoGrafo*));
        no1->no_adjacentes[0] = no2;
        no1->n_adjacentes += 1;
    }else{
        int size = (no1->n_adjacentes + 1) * sizeof (NoGrafo*);
        no1->no_adjacentes =  (NoGrafo**) realloc(no1->no_adjacentes, size);
        no1->no_adjacentes[no1->n_adjacentes] = no2;
        no1->n_adjacentes += 1;
    }
}

void criarAresta(NoGrafo *no1, NoGrafo *no2){
    conectarNo(no1,no2);
    conectarNo(no2,no1);
}

bool verificarAdjacencia(NoGrafo *no1, NoGrafo *no2){
    for (int i = 0 ; i < no1->n_adjacentes; i++) {
        if((no1->no_adjacentes[no1->rotulo_vertice][i]) == no2->rotulo_vertice){
            return true;
        }else{
            return false;
        }
    }
}

Grafo* criarGrafoVazio(){
    Grafo *novo_grafo = new Grafo;
    novo_grafo->nos = NULL;
    novo_grafo->n_vertices = 0;
}

//adiciona novo no ao grafo no_adc
void adicionarNoGrafo(Grafo *grafo, NoGrafo *no_adc){
    if(grafo->nos == NULL){
        grafo->nos = (NoGrafo**) calloc(1, sizeof(NoGrafo*));//aloca e inicializa com zeros
        grafo->nos[0] = no_adc;
        grafo->n_vertices += 1;
    }else{
        int size = (grafo->n_vertices + 1) * sizeof (NoGrafo*);
        grafo->nos =  (NoGrafo**) realloc(grafo->nos, size);
        grafo->nos[grafo->n_vertices] = no_adc;
        grafo->n_vertices += 1;
    }
}

void printarGrafo(Grafo *grafo){
    for (int i = 0; i <grafo->n_vertices; i++) {
        cout << grafo->nos[i]->rotulo_vertice <<" : " ;
        for (int j = 0; j < grafo->nos[i]->n_adjacentes; j++) {
            cout << grafo->nos[i]->no_adjacentes[j]->rotulo_vertice << " ";
        }
        cout << endl;
    }
}

void djkstra(Grafo *grafo, int distancias, int predecessor_rotulo){
    bool vertices_abertos[grafo->n_vertices];

    for (int i = 0 ; i < grafo->n_vertices; i++) {
        vertices_abertos[i] = true;
    }

    for (int i = 0 ; i <;) {

    }

}



int main()
{
    NoGrafo *no1 =  criarNo(0);
    NoGrafo *no2 =  criarNo(1);
    NoGrafo *no3 =  criarNo(2);
    NoGrafo *no4 =  criarNo(3);
    NoGrafo *no5 =  criarNo(4);

    criarAresta(no1, no2);
    criarAresta(no1, no5);
    criarAresta(no1, no4);
    criarAresta(no2, no5);
    criarAresta(no4, no5);
    criarAresta(no2, no3);
    criarAresta(no3, no5);

    Grafo *novo_grafo = criarGrafoVazio();
//    novo_grafo->nos = (NoGrafo**) calloc(5, sizeof(NoGrafo*));//aloca e inicializa com zeros
//    novo_grafo->nos[0] = no1;
//    novo_grafo->nos[1] = no2;
//    novo_grafo->nos[2] = no3;
//    novo_grafo->nos[3] = no4;
//    novo_grafo->nos[4] = no5;
//    novo_grafo->n_vertices = 5;
    adicionarNoGrafo(novo_grafo,no1);
    adicionarNoGrafo(novo_grafo,no2);
    adicionarNoGrafo(novo_grafo,no3);
    adicionarNoGrafo(novo_grafo,no4);
    adicionarNoGrafo(novo_grafo,no5);

    printarGrafo(novo_grafo);


    cout << "Hello World!" << endl;
    return 0;
}
