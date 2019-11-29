#include <iostream>
#define INFINITO 2147483647

using namespace std;

typedef struct No{
    int chave;
    struct No *prox;
}No;


typedef struct Fila{
    struct No *inicio;
    struct No *fim;
    int n;
}Fila;

typedef struct Pilha{
    struct No *topo;
    int n;
}Pilha;

No* criarNo(int chave){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->chave = chave;
    return novo_no;
}

void deletarNo(No **no){
    No *aux = *no;
    delete aux;
    no = NULL;
}

Fila* criarFilaVazia(){
    Fila *nova_fila = new Fila();
    nova_fila->n = 0;
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
}

void inserir(Fila *fila, int chave){
    No *novo_no = criarNo(chave);
    if(fila->fim != NULL){
        fila->fim->prox = novo_no;
    }else{
        fila->inicio = novo_no;
    }
    fila->fim = novo_no;
    fila->n += 1;
}

int remover(Fila *fila){
    int valor = 0;
    if(fila->inicio != NULL){
        No* aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL){
            fila->fim = NULL;
        }
        valor = aux->chave;
        deletarNo(&aux);
        fila->n -= 1;
    }else{
        cout <<"FIM" <<endl;
    }
    return valor;
}

Pilha* criarPilhaVazia(){
    Pilha *nova_pilha = new Pilha();
    nova_pilha->topo = NULL;
}

void empilhar(Pilha *pilha, int chave){
    No *novo_no = criarNo(chave);
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    pilha->n += 1;
}

int desempilha(Pilha *pilha){
    int valor = 0;
    if(pilha->topo != NULL){
        No *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        valor = aux->chave;
        deletarNo(&aux);
        pilha->n -= 1;
    }else{
        cout <<"PILHA VAZIA" <<endl;
    }
    return valor;
}


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

void menorDistanciaParaDjkstra(int *vetor_distancias, bool *vertices_abertos, int n, int &menor_distancia, int &indice){
    menor_distancia = INFINITO;
    indice = -1;
    for (int i = 0; i < n ; i++) {
        if(vetor_distancias[i] < menor_distancia && vertices_abertos[i] == true){
            indice = i;
            menor_distancia = vetor_distancias[i];
        }
    }
}


int* djkstra(Grafo *grafo, int fonte, int *distancias, int *predecessor){
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
        int menor_distancia = 0;//nao era infinito la dentro da funcao?
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

int decidirQualVerticeVai(int *distancias, int n, bool *vertices_visitados){
    //verifica nao só a distancia, mas tambem se o vertice é uma fabrica e se o caminhao ja pegou carga la para entao decidir o vertice fabrica q ele vai
    float menor_distancia = INFINITO;
    int indice_vertice = -1;
    for (int i = 0; i < n; i++) {
        if(distancias[i] < menor_distancia && vertices_visitados[i] == false){
                indice_vertice = i;
                menor_distancia = distancias[i];
        }
    }
    return indice_vertice;
}

void apagarVetorDistancias(int *vetor_distancias, int n){
    for (int i = 0; i < n; i++) {
        vetor_distancias[i] = INFINITO;
    }
}

void apagarVetorPredecessores(int *vetor_predecessores, int n){
    for (int i = 0; i < n; i++) {
        vetor_predecessores[i] = -1;
    }
}

void guardarCaminhoCompleto(Pilha *caminho_invertido, int *vetor_predecessores,int n, int index_menor_distancia, int index_vertice_inicial_trajeto, Fila *salvar_caminho ){
    int index = index_menor_distancia;//comeca do index do vertice fabrica ou obra que vai ter a menor distancia pro ponto inicial da iteracao
    if (index == index_vertice_inicial_trajeto){
        return;
    }
    empilhar(caminho_invertido,index);
    while(vetor_predecessores[index] != index_vertice_inicial_trajeto){//agora vai empilhando os indices ate que chegue no ponto inicial do trajeto local
        empilhar(caminho_invertido, vetor_predecessores[index]);
        index = vetor_predecessores[index];//atualiza o indice para  a proxima iteracao, que será o conteudo do vetor no indice atual
    }
    if(vetor_predecessores[index] == index_vertice_inicial_trajeto){
        empilhar(caminho_invertido,index_vertice_inicial_trajeto);//empilha o vertice do inicio do trajeto local no topo, temos entao a pilha contendo o trajeto de tras pra frente
    }
    //desempilha da pilha e insere na fila para obter a ordem correta do trajeto
    while(caminho_invertido->topo != NULL){
        int aux = desempilha(caminho_invertido);
        if(aux == salvar_caminho->fim->chave){//condicional para nao repetir os vertices final (da iteracao anterior) e inicial da iteracao atual
            continue;
        }
        inserir(salvar_caminho,aux);//insere os elementos da pilha na fila, deixando o trajeto na ordem correta

    }
}

void printarCaminho(Fila *fila){
    //printando caminho
    cout << "Printando a rota:" <<endl;
    while(fila->n != 0){
        cout << remover(fila) << " -> " ;
        if(fila->n == 1){
            cout << remover(fila) ;
        }
    }
    cout << endl;
}

void jogoTabuleiro(Grafo *grafo, int indice_origem, int target){
    bool *vertices_visitados = new bool[grafo->n_vertices];
    int *vetor_distancias = new int[grafo->n_vertices];
    int *predecessores = new int[grafo->n_vertices];
    int distancia_acumulada = 0;
    Fila *caminho = criarFilaVazia();
    Pilha *caminho_invertido = criarPilhaVazia();

    for (int i =0; i < grafo->n_vertices; i++){
        vertices_visitados[i] = false;
    }
    vertices_visitados[indice_origem] = true;
    inserir(caminho, indice_origem);
    while(true){
        djkstra(grafo,indice_origem,vetor_distancias,predecessores);
        int prox_index_visitar = decidirQualVerticeVai(vetor_distancias,grafo->n_vertices,vertices_visitados);
        vertices_visitados[prox_index_visitar] = true;
        distancia_acumulada += vetor_distancias[prox_index_visitar];

        guardarCaminhoCompleto(caminho_invertido,predecessores,grafo->n_vertices,prox_index_visitar,indice_origem, caminho);

        if(prox_index_visitar == target){
            break;
        }
        indice_origem = prox_index_visitar;

        apagarVetorDistancias(vetor_distancias,grafo->n_vertices);
        apagarVetorPredecessores(predecessores,grafo->n_vertices);
    }
    printarCaminho(caminho);
    cout <<"Distancia total = " <<distancia_acumulada <<endl;
}

int main()
{
    int n = 12;
    Grafo *novo_grafo = criarGrafoVazio(n);

    printarAjacentesPesos(novo_grafo);

    adicionarArestas(novo_grafo, 0, 1, 3);
    adicionarArestas(novo_grafo, 0, 4, 2);
    adicionarArestas(novo_grafo, 1, 2, 6);
    adicionarArestas(novo_grafo, 1, 5, 5);
    adicionarArestas(novo_grafo, 2, 3, 4);
    adicionarArestas(novo_grafo, 2, 6, 6);
    adicionarArestas(novo_grafo, 3, 7, 4);
    adicionarArestas(novo_grafo, 4, 8, 3);
    adicionarArestas(novo_grafo, 4, 5, 5);
    adicionarArestas(novo_grafo, 5, 9, 7);
    adicionarArestas(novo_grafo, 5, 6, 6);
    adicionarArestas(novo_grafo, 6, 10, 8);
    adicionarArestas(novo_grafo, 6, 7, 4);
    adicionarArestas(novo_grafo, 7, 11, 3);
    adicionarArestas(novo_grafo, 8, 9, 7);
    adicionarArestas(novo_grafo, 9, 10, 8);
    adicionarArestas(novo_grafo, 10, 11, 3);


    nosAdjacentes(novo_grafo);

    cout << " #################" << endl;

    printarAjacentesPesos(novo_grafo);

    cout <<"Djkstra" << endl;

    int *predecessores1 = new int[novo_grafo->n_vertices];
    int *distancias1 = new int[novo_grafo->n_vertices];
    djkstra(novo_grafo,0,distancias1,predecessores1);

    jogoTabuleiro(novo_grafo,0,11);


    return 0;
}
