#include <iostream>
#define INFINITO 2147483647

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

bool verificarAdjacencia(Grafo *grafo, int rotulo_verticev1, int rotulo_verticev2){
    if(grafo->matrizAdjacencia[rotulo_verticev1][rotulo_verticev2] == true){
        return true;
    }else{
        return false;
    }
}

bool temVerticeAberto(bool *vetor_vertices, int n){
    bool retorno = false;
    for (int i = 0; i < n; i++) {
        if(vetor_vertices[i] == true){
            retorno = true;
        }
    }
    return retorno;
}

void menorDistanciaParaDjkstra(float *vetor_distancias, bool *vertices_abertos, int n, float &menor_distancia, int &indice){
    menor_distancia = INFINITO;
    indice = -1;
    for (int i = 0; i < n ; i++) {
        if(vetor_distancias[i] < menor_distancia && vertices_abertos[i] == true){
            indice = i;
            menor_distancia = vetor_distancias[i];
        }
    }
}


float* djkstra(Grafo *grafo, int fonte, float *distancias, int *predecessor){
    //float *distancias = new float[grafo->n_vertices];
    //int *predecessor = new int[grafo->n_vertices];
    bool *vertices_abertos = new bool[grafo->n_vertices];

    //iniciliza um vetor dos vertices abertos, quando eles forem explorados e o menor caminho ate ele for determinado, ele vai ser falso
    for (int i = 0 ; i < grafo->n_vertices; i++) {
        vertices_abertos[i] = true;
    }

    distancias[fonte] = 0;//a distancia da fonte ate ela mesma eh 0
    vertices_abertos[fonte] = false;//fechando o vertice da fonte

    //iniciando analisando os vertices adjacentes a fonte, e colocando a distancia deles até a mesma, e tambem fazendo a fonte ser o predecessor
    for (int i = 0 ; i < grafo->n_vertices; i++) {
        if(verificarAdjacencia(grafo,fonte,i) == true){
            distancias[i] = grafo->matrizPesos[fonte][i];
            predecessor[i] = fonte;
        }else{
            distancias[i] = INFINITO;//se o vertice nao é adjacente, a distancia é infinito e o antecessor é invalido
            predecessor[i] = -1;
        }
    }

    while(true){
        float menor_distancia = 0;//nao era infinito la dentro da funcao?
        int indice_menor = -1;
        //dentro do vetor de vertices verifica se eles tao aberto (tem true) e percorre o vetor procurando o indice do que tem a menor distancia, pois esse é o novo vertice a ser explorado
        menorDistanciaParaDjkstra(distancias,vertices_abertos,grafo->n_vertices,menor_distancia,indice_menor);
        vertices_abertos[indice_menor] = false;
            for (int j = 0; j < grafo->n_vertices; j++) {
                if(grafo->matrizAdjacencia[indice_menor][j] == true && vertices_abertos[j] == true){
                    if(distancias[j] > (distancias[indice_menor]+grafo->matrizPesos[indice_menor][j])){
                        distancias[j] = distancias[indice_menor]+ grafo->matrizPesos[indice_menor][j];
                        predecessor[j] = indice_menor;
                    }
                }
            }

        if(temVerticeAberto(vertices_abertos,grafo->n_vertices) == true){
            continue;
        }else{
            break;
        }
    }

    return distancias;
}

void printarVetorDistancias(float *vetor, int n){
    cout <<"Vetor de distancias: " ;
    for (int i = 0 ; i < n; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void printarVetorAntecessores(int *predecessores, int n){
    cout <<"Vetor de antecessores: " ;
    for (int i =0 ; i < n; i++) {
        cout <<predecessores[i] << " ";
    }
    cout <<endl;
}

int main()
{
    int n = 7;
    Grafo *novo_grafo = criarGrafoVazio(n);

    printarAjacentesPesos(novo_grafo);

    adicionarArestas(novo_grafo, 0, 1, 2);
    adicionarArestas(novo_grafo, 0, 2, 4);
    adicionarArestas(novo_grafo, 0, 3, 5);
    adicionarArestas(novo_grafo, 1, 3, 2);
    adicionarArestas(novo_grafo, 2, 3, 1);
    adicionarArestas(novo_grafo, 2, 6, 4);
    adicionarArestas(novo_grafo, 3, 5, 2);
    adicionarArestas(novo_grafo, 3, 6, 3);
    adicionarArestas(novo_grafo, 5, 4, 5);
    adicionarArestas(novo_grafo, 4, 6, 2);

    nosAdjacentes(novo_grafo);

    cout << " #################" << endl;

    printarAjacentesPesos(novo_grafo);

    cout << " #################" << endl;

    bool ehadjacente = verificarAdjacencia(novo_grafo,0, 4);
    cout << ehadjacente << endl;
    bool ehadjacente2 = verificarAdjacencia(novo_grafo,0, 2);
    cout << ehadjacente2 << endl;

    cout <<"Djkstra" << endl;

    int *predecessores1 = new int[novo_grafo->n_vertices];
    float *distancias1 = new float[novo_grafo->n_vertices];
    djkstra(novo_grafo,0,distancias1,predecessores1);

    cout << " #################" << endl;

    int n2 = 9;
    Grafo *novo_grafo2 = criarGrafoVazio(n2);

    printarAjacentesPesos(novo_grafo2);

    adicionarArestas(novo_grafo2, 0, 1, 4);
    adicionarArestas(novo_grafo2, 0, 7, 8);
    adicionarArestas(novo_grafo2, 1, 7, 11);
    adicionarArestas(novo_grafo2, 1, 2, 8);
    adicionarArestas(novo_grafo2, 7, 8, 7);
    adicionarArestas(novo_grafo2, 7, 6, 1);
    adicionarArestas(novo_grafo2, 6, 8, 6);
    adicionarArestas(novo_grafo2, 6, 5, 2);
    adicionarArestas(novo_grafo2, 8, 2, 2);
    adicionarArestas(novo_grafo2, 2, 3, 7);
    adicionarArestas(novo_grafo2, 2, 5, 4);
    adicionarArestas(novo_grafo2, 3, 5, 14);
    adicionarArestas(novo_grafo2, 3, 4, 9);
    adicionarArestas(novo_grafo2, 4, 5, 10);

    printarAjacentesPesos(novo_grafo2);

    int *predecessores2 = new int[novo_grafo2->n_vertices];
    float *distancias2 = new float[novo_grafo2->n_vertices];
    djkstra(novo_grafo2,0,distancias2,predecessores2);

    printarVetorDistancias(distancias2,novo_grafo2->n_vertices);
    printarVetorAntecessores(predecessores2, novo_grafo2->n_vertices);


    return 0;
}
