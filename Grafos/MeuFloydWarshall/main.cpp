#include <iostream>
#define INFINITO 212343242
using namespace std;

typedef struct Grafo{
    bool **matrizAdjacencia;
    float **matrizPesos;
    float **matrizDistancias;
    int n_vertices;
}Grafo;

Grafo* criarGrafoVazio(int n_vertices){
    //cria a estrutura grafo. Inicializa com false na adjacencia, 0 nos pesos e todos os vertices sao do tipo normal
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
    novo_grafo->matrizDistancias = new float*[n_vertices];
    for (int i = 0; i <n_vertices; i++) {
        novo_grafo->matrizDistancias[i] = new float[n_vertices];
    }
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            novo_grafo->matrizDistancias[i][j] = INFINITO;
        }
    }

    return novo_grafo;

}

void adicionarArestas(Grafo *grafo, int v1, int v2, float peso){
    grafo->matrizAdjacencia[v1][v2] = true;
    grafo->matrizAdjacencia[v2][v1] = true;
    grafo->matrizPesos[v1][v2] = peso;
    grafo->matrizPesos[v2][v1] = peso;
    grafo->matrizDistancias[v1][v2] = peso;
    grafo->matrizDistancias[v2][v1] = peso;
}

void printarAjacentesPesos(Grafo *grafo){
    //printa os nos adjacentes com os pesos no formado - index_vertice: peso | vertice_adj
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

void printarMatrizDistancias(Grafo *grafo){
    for (int i = 0; i < grafo->n_vertices; i++) {
        for (int j = 0; j < grafo->n_vertices; j++) {
            cout <<grafo->matrizDistancias[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

float** floydWarshall(Grafo *grafo){
    for (int i = 0 ; i < grafo->n_vertices; i++) {
        for (int j = 0; j <grafo->n_vertices; j++) {
            if(i == j){
                grafo->matrizDistancias[i][j] = 0;
            }
        }
    }

    printarMatrizDistancias(grafo);

    for (int k = 0; k < grafo->n_vertices; k++) {
        for (int i = 0; i < grafo->n_vertices; i++) {
            for (int j = 0; j < grafo->n_vertices; j++) {
                if(grafo->matrizDistancias[i][j] > grafo->matrizDistancias[i][k] + grafo->matrizDistancias[k][j]){
                    cout <<"k = " <<k <<" i = " <<i << " j = " <<j <<endl;
                    grafo->matrizDistancias[i][j] = grafo->matrizDistancias[i][k] + grafo->matrizDistancias[k][j];
                }
            }
        }
        if(k == 1){
            break;
        }
    }
}



int main()
{
    int n = 6;
    Grafo *novo_grafo = criarGrafoVazio(n);

    adicionarArestas(novo_grafo, 0, 1, 1);
    adicionarArestas(novo_grafo, 0, 2, 3);
    adicionarArestas(novo_grafo, 1, 2, 1);
    adicionarArestas(novo_grafo, 1, 4, 2);
    adicionarArestas(novo_grafo, 1, 3, 3);
    adicionarArestas(novo_grafo, 2, 3, 2);
    adicionarArestas(novo_grafo, 3, 4, -3);
    adicionarArestas(novo_grafo, 4, 5, 3);
    adicionarArestas(novo_grafo, 3, 5, 2);

    printarAjacentesPesos(novo_grafo);

    printarMatrizDistancias(novo_grafo);

    floydWarshall(novo_grafo);

    printarMatrizDistancias(novo_grafo);

    return 0;
}
