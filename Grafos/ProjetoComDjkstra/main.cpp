#include <iostream>
#define INFINITO 2147483647
#define NORMAL 0
#define FABRICA 1
#define OBRA 2


using namespace std;

typedef struct Grafo{
    bool **matrizAdjacencia;
    float **matrizPesos;
    int n_vertices;
    int *tipo_vertice;
    bool *attention_nos;
}Grafo;

void printAttentionNode(Grafo *grafo){
    for (int i = 0; i < grafo->n_vertices; i++) {
        cout <<grafo->attention_nos[i] << " ";
    }
    cout << endl;
}

Grafo* criarGrafoVazio(int n_vertices){
    Grafo* novo_grafo = new Grafo;
    novo_grafo->n_vertices = n_vertices;
    novo_grafo->matrizAdjacencia = new bool*[n_vertices];
    novo_grafo->tipo_vertice = new int[n_vertices];
    novo_grafo->attention_nos = new bool[n_vertices];

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
    for (int i = 0; i < n_vertices; i++) {
        novo_grafo->tipo_vertice[i] = NORMAL;
    }
    for (int i = 0; i < n_vertices; i++) {
        novo_grafo->attention_nos[i] = false;
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

void inicilizaTodosVerticesAbertos(bool *vertices_abertos, int n){
    //iniciliza um vetor dos vertices abertos, quando eles forem explorados e o menor caminho ate ele for determinado, ele vai ser falso
    for (int i = 0 ; i < n; i++) {
        vertices_abertos[i] = true;
    }
}

float* djkstra(Grafo *grafo, int fonte, float *distancias, int *predecessor, bool *vertices_abertos){
    //float *distancias = new float[grafo->n_vertices];
    //int *predecessor = new int[grafo->n_vertices];

    distancias[fonte] = 0;//a distancia da fonte ate ela mesma eh 0
    vertices_abertos[fonte] = false;//fechando o vertice da fonte

    //iniciando analisando os vertices adjacentes a fonte, e colocando a distancia deles até a mesma, e tambem fazendo a fonte ser o predecessor
    for (int i = 0 ; i < grafo->n_vertices; i++) {
        if(i != fonte){
            if(verificarAdjacencia(grafo,fonte,i) == true){
                distancias[i] = grafo->matrizPesos[fonte][i];
                predecessor[i] = fonte;
            }else{
                distancias[i] = INFINITO;//se o vertice nao é adjacente, a distancia é infinito e o antecessor é invalido
                predecessor[i] = -1;
            }
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

bool temAttentionNode(Grafo *grafo){
    bool retorno = false;
    for (int i = 0; i < grafo->n_vertices; i++) {
        if(grafo->attention_nos[i] == true){
            retorno = true;
            break;
        }
    }
    return retorno;
}

int decidirQualFabrica(float *distancias, Grafo *grafo){
    int menor_distancia = INFINITO;
    int indice_fabrica = -1;
    printarVetorDistancias(distancias,grafo->n_vertices);
    for (int i = 0; i < grafo->n_vertices; i++) {
        if(distancias[i] < menor_distancia){
            if(grafo->tipo_vertice[i] == FABRICA && grafo->attention_nos[i] == true){
                indice_fabrica = i;
                menor_distancia = distancias[i];
            }
        }
    }
    return indice_fabrica;
}

int decidirQualObra(float *distancias, Grafo *grafo){
    int menor_distancia = INFINITO;
    int indice_obra = -1;
    for (int i = 0; i < grafo->n_vertices; i++) {
        if(distancias[i] < menor_distancia){
            if(grafo->tipo_vertice[i] == OBRA && grafo->attention_nos[i] == true){
                indice_obra = i;
                menor_distancia = distancias[i];
            }
        }
    }
    return indice_obra;
}

void apagarVetorDistancias(float *vetor_distancias, int n){
    for (int i = 0; i < n; i++) {
        vetor_distancias[i] = INFINITO;
    }
}

void apagarVetorPredecessores(int *vetor_predecessores, int n){
    for (int i = 0; i < n; i++) {
        vetor_predecessores[i] = -1;
    }
}

void criarAttentionNode(Grafo *grafo, int indice, int tipo){
    grafo->attention_nos[indice] = true;
    grafo->tipo_vertice[indice] = tipo;
}

void calculaRota(Grafo *grafo, int posicao_caminhao){
    bool irParaFabrica = true;
    int *predecessores = new int[grafo->n_vertices];
    float *distancias = new float[grafo->n_vertices];
    bool *vertices_abertos = new bool[grafo->n_vertices];
    inicilizaTodosVerticesAbertos(vertices_abertos,grafo->n_vertices);

    while(true){
        if(temAttentionNode(grafo) == false){
            break;
        }
        if(irParaFabrica == true){
            djkstra(grafo,posicao_caminhao,distancias,predecessores,vertices_abertos);
            int fabrica_prox = decidirQualFabrica(distancias,grafo);
            grafo->attention_nos[fabrica_prox] = false;//garantir que nao vai mais reabastecer nessa fabrica
            //guarda caminho de A para B na fila
            cout <<posicao_caminhao << " -> " <<fabrica_prox << endl;
            posicao_caminhao = fabrica_prox;
            irParaFabrica = false;
        }else{
            djkstra(grafo,posicao_caminhao,distancias,predecessores,vertices_abertos);
            int obra_prox = decidirQualObra(distancias,grafo);
            grafo->attention_nos[obra_prox] = false;//garantir que nao vai mais reabastecer nessa fabrica
            //guarda caminho de A para B na fila
            cout <<posicao_caminhao << " -> " <<obra_prox << endl;
            posicao_caminhao = obra_prox;
            irParaFabrica = true;
        }
        apagarVetorDistancias(distancias,grafo->n_vertices);
        apagarVetorPredecessores(predecessores, grafo->n_vertices);
        inicilizaTodosVerticesAbertos(vertices_abertos,grafo->n_vertices);

    }

    //desenfileirar e printar
    delete[] predecessores;
    delete[] distancias;
    delete[] vertices_abertos;
}


int main()
{
    int n = 7;
    Grafo *novo_grafo = criarGrafoVazio(n);
//    int tipo_vertice[n];//0 é nada, 1 é fabrica, 2 é obra
//    bool *vertices_abertos = new bool[n];
//    inicilizaTodosVerticesAbertos(vertices_abertos,n);
//    int fonte = 0;

//    //vertice 3 eh fabrica, vertice 4 eh obra
//    for (int i= 0 ; i < n; i++) {
//        tipo_vertice[i] = 0;
//    }
//    tipo_vertice[3] = 1;
//    tipo_vertice[4] = 2;

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

    cout << " #################" << endl;

    criarAttentionNode(novo_grafo,3,FABRICA);
    criarAttentionNode(novo_grafo,4,OBRA);

//    calculaRota(novo_grafo,0);

    cout << " #################" << endl;

    int n2 = 11;
    Grafo *novo_grafo2 = criarGrafoVazio(n2);

    adicionarArestas(novo_grafo2, 0, 1, 1);
    adicionarArestas(novo_grafo2, 1, 2, 1);
    adicionarArestas(novo_grafo2, 2, 3, 1);
    adicionarArestas(novo_grafo2, 3, 4, 1);
    adicionarArestas(novo_grafo2, 4, 5, 1);
    adicionarArestas(novo_grafo2, 5, 6, 1);
    adicionarArestas(novo_grafo2, 6, 7, 1);
    adicionarArestas(novo_grafo2, 7, 8, 1);
    adicionarArestas(novo_grafo2, 7, 9, 1);
    adicionarArestas(novo_grafo2, 7, 10, 1);

    criarAttentionNode(novo_grafo2,0,OBRA);
    criarAttentionNode(novo_grafo2,1,FABRICA);
    criarAttentionNode(novo_grafo2,4,FABRICA);
    criarAttentionNode(novo_grafo2,8,OBRA);
    criarAttentionNode(novo_grafo2,9,FABRICA);
    criarAttentionNode(novo_grafo2,10,OBRA);

    calculaRota(novo_grafo2,2);

//    printarAjacentesPesos(novo_grafo);

//    cout << " #################" << endl;

//    cout <<"Djkstra" << endl;

//    int *predecessores1 = new int[novo_grafo->n_vertices];
//    float *distancias1 = new float[novo_grafo->n_vertices];


//    while(temObraAberta(vertices_abertos,tipo_vertice,n) == true){
//        cout <<"Iniciando trajeto no vertice: " <<fonte << " do tipo: " <<tipo_vertice[fonte] << "que esta aberto?" <<vertices_abertos[fonte] << endl;
//        djkstra(novo_grafo,fonte,distancias1,predecessores1, vertices_abertos);
//        int prox_fabrica = decidirQualFabrica(distancias1,tipo_vertice, n);
//        apagarVetorDistancias(distancias1, n);
//        apagarVetorPredecessores(predecessores1,n);
//        cout <<"Iniciando trajeto no vertice: " <<prox_fabrica << " do tipo: " <<tipo_vertice[prox_fabrica] << "que esta aberto?" <<vertices_abertos[prox_fabrica] << endl;
//        cout <<"Iniciando trajeto no vertice: " <<4 << " do tipo: " <<tipo_vertice[4] << "que esta aberto?" <<vertices_abertos[4] << endl;
//        djkstra(novo_grafo,prox_fabrica,distancias1,predecessores1,vertices_abertos);
//        int prox_obra = decidirQualObra(distancias1,tipo_vertice, n);
//        fonte = prox_obra;
//    }

//    cout <<"vetor vertices abertos = ";
//    for (int i = 0; i < n; i++) {
//        cout << vertices_abertos[i] << " ";
//    }
//    cout << endl;


    return 0;
}
