#include <iostream>

using namespace std;

typedef struct Grafo{
    bool **matrizAdjacencia;
    float **matrizPesos;
    int n_vertices;
}Grafo;

Grafo* criarGrafoVazio(int n_vertices){
    Grafo* novo_grafo = new Grafo;
    novo_grafo->n_vertices = n_vertices;
    novo_grafo->matrizAdjacencia = new bool*[n_vertices];
    for (int i=0; i < n_vertices; i++) {
        novo_grafo->matrizAdjacencia[i] = new bool[n_vertices];
    }
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            novo_grafo->matrizAdjacencia[i][j] = false;
        }
    }
    novo_grafo->matrizPesos = new float*[n_vertices];
    for (int i = 0; i <n_vertices; i++) {
        novo_grafo->matrizPesos[i] = new float[n_vertices];
    }
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            novo_grafo->matrizPesos[i][j] = 0;
        }
    }
    return novo_grafo;
}

void adicionarArestas(Grafo *grafo, int v1, int v2, float peso){
    grafo->matrizAdjacencia[v1][v2] = true;
    grafo->matrizAdjacencia[v2][v1] = true;
    grafo->matrizPesos[v1][v2] = peso;
    grafo->matrizPesos[v2][v1] = peso;
}

void nosAdjacentes(Grafo *grafo){
    for (int i = 0; i < grafo->n_vertices; i++) {
        cout << i << " : " ;
        for (int j = 0; j < grafo->n_vertices; j++) {
            if (grafo->matrizAdjacencia[i][j] == true){
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

void printarAjacentesPesos(Grafo *grafo){
    for (int i = 0; i < grafo->n_vertices; i++) {
        cout << i << " : " ;
        for (int j = 0; j < grafo->n_vertices; j++) {
            if (grafo->matrizAdjacencia[i][j] == true){
                cout <<grafo->matrizPesos[i][j] << " | " << j << "  ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    Grafo *novo_grafo = criarGrafoVazio(n);

    adicionarArestas(novo_grafo, 0, 1, 3);
    adicionarArestas(novo_grafo, 0, 4, 2);
    adicionarArestas(novo_grafo, 0, 3, 5);
    adicionarArestas(novo_grafo, 1, 4, 7);
    adicionarArestas(novo_grafo, 3, 4, 9);
    adicionarArestas(novo_grafo, 1, 2, 11);
    adicionarArestas(novo_grafo, 2, 4, 1);

    nosAdjacentes(novo_grafo);

    cout << " #################" << endl;

    printarAjacentesPesos(novo_grafo);


    cout << "Hello World!" << endl;
    return 0;
}
