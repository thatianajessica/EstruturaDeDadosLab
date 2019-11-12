#include <iostream>
#define INFINITO 2147483647
#define NORMAL 0
#define FABRICA 1
#define OBRA 2


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
};

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
        cout <<"FILA VAZIA" <<endl;
    }
    return valor;
}


typedef struct Grafo{
    bool **matrizAdjacencia;
    float **matrizPesos;
    int n_vertices;
    int *tipo_vertice;//0 - normal, 1 - fabrica, 2 - obra
    bool *carga_descarga;//tudo false na criacao, a medida que vai visitando, vai marcando com true indicando que ja abasteceu e nao eh para nao abastecer mais la, ou pra nao descarregar la
}Grafo;

void printCargaDescarga(Grafo *grafo){
    for (int i = 0; i < grafo->n_vertices; i++) {
        cout <<grafo->carga_descarga[i] << " ";
    }
    cout << endl;
}

Grafo* criarGrafoVazio(int n_vertices){
    //cria a estrutura grafo. Inicializa com false na adjacencia, 0 nos pesos e todos os vertices sao do tipo normal
    Grafo* novo_grafo = new Grafo;
    novo_grafo->n_vertices = n_vertices;
    novo_grafo->matrizAdjacencia = new bool*[n_vertices];
    novo_grafo->tipo_vertice = new int[n_vertices];
    novo_grafo->carga_descarga = new bool[n_vertices];

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
        novo_grafo->carga_descarga[i] = false;
    }
    return novo_grafo;
}

void adicionarArestas(Grafo *grafo, int v1, int v2, float peso){
    //considerando grafo nao direcional peso 1 -> 2 = peso 2 -> 1
    grafo->matrizAdjacencia[v1][v2] = true;
    grafo->matrizAdjacencia[v2][v1] = true;
    grafo->matrizPesos[v1][v2] = peso;
    grafo->matrizPesos[v2][v1] = peso;
}

void nosAdjacentes(Grafo *grafo){
    //printa os vertices adjacentes
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

bool verificarAdjacencia(Grafo *grafo, int rotulo_verticev1, int rotulo_verticev2){
    if(grafo->matrizAdjacencia[rotulo_verticev1][rotulo_verticev2] == true){
        return true;
    }else{
        return false;
    }
}

bool temVerticeAberto(bool *vetor_vertices, int n){
    //percorrer o vetor de vertices para identificar se ainda tem pelo ao menos um vertice aberto para ser explorado la no djkstra
    bool retorno = false;
    for (int i = 0; i < n; i++) {
        if(vetor_vertices[i] == true){
            retorno = true;
        }
    }
    return retorno;
}

void menorDistanciaParaDjkstra(float *vetor_distancias, bool *vertices_abertos, int n, float &menor_distancia, int &indice){
    //dentre os vertices que estao abertos ainda, verifica qual tem menor distancia em relacao a fonte, o vertice encontrado será o proximo a ser explorado. Retorna tanto a distancia quanto o indice
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
    //iniciliza um vetor dos vertices abertos, quando eles forem explorados no djkstra e o menor caminho ate ele for determinado, ele vai ser falso
    for (int i = 0 ; i < n; i++) {
        vertices_abertos[i] = true;
    }
}

float* djkstra(Grafo *grafo, int fonte, float *distancias, int *predecessor, bool *vertices_abertos){

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
        float menor_distancia = INFINITO;
        int indice_menor = -1;
        //dentro do vetor de vertices verifica se eles tao aberto (tem true) e percorre o vetor procurando o indice do que tem a menor distancia, pois esse é o novo vertice a ser explorado
        menorDistanciaParaDjkstra(distancias,vertices_abertos,grafo->n_vertices,menor_distancia,indice_menor);
        //fecha o vertice q ta sendo explorado
        vertices_abertos[indice_menor] = false;
            for (int j = 0; j < grafo->n_vertices; j++) {
                //procura os adjacentes de indice_menor que estao abertos
                if(grafo->matrizAdjacencia[indice_menor][j] == true && vertices_abertos[j] == true){
                    //verifica a desigualdade triangular, se a distancia da fonte diretamente ao vertice j é maior que a distancia passando pelo indice explorado e depois do indice explorado para o vertice j se for, substitue dj e atualiza o predecessor para o indice_menor, que é o vertice explorado corrente
                    if(distancias[j] > (distancias[indice_menor]+grafo->matrizPesos[indice_menor][j])){
                        distancias[j] = distancias[indice_menor]+ grafo->matrizPesos[indice_menor][j];
                        predecessor[j] = indice_menor;
                    }
                }
            }
        //enquanto tiver vertice aberto, executa. Todos os vertices fechados, encerra e retorna as distancias. Lembrar que ao fim o vetor vertices_abertos ta tudo false
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

bool temCargaDescarga(Grafo *grafo){
    //verificar se ainda tem vertices obra ou fabrica para o caminhao ir visitar
    bool retorno = false;
    for (int i = 0; i < grafo->n_vertices; i++) {
        if(grafo->carga_descarga[i] == true){
            retorno = true;
            break;
        }
    }
    return retorno;
}

int decidirQualFabrica(float *distancias, Grafo *grafo){
    //verifica nao só a distancia, mas tambem se o vertice é uma fabrica e se o caminhao ja pegou carga la para entao decidir o vertice fabrica q ele vai
    float menor_distancia = INFINITO;
    int indice_fabrica = -1;
    printarVetorDistancias(distancias,grafo->n_vertices);
    for (int i = 0; i < grafo->n_vertices; i++) {
        if(distancias[i] < menor_distancia){
            if(grafo->tipo_vertice[i] == FABRICA && grafo->carga_descarga[i] == true){
                indice_fabrica = i;
                menor_distancia = distancias[i];
            }
        }
    }
    return indice_fabrica;
}

int decidirQualObra(float *distancias, Grafo *grafo){
    //verifica nao só a distancia, mas tambem se o vertice é uma obra e se o caminhao ja deixou carga la (vetor carga_descarga) la para entao decidir o vertice fabrica q ele vai
    float menor_distancia = INFINITO;
    int indice_obra = -1;
    for (int i = 0; i < grafo->n_vertices; i++) {
        if(distancias[i] < menor_distancia){
            if(grafo->tipo_vertice[i] == OBRA && grafo->carga_descarga[i] == true){
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

void criarCargaDescarga(Grafo *grafo, int indice, int tipo){
    //atribui verdadeiro a carga_descarga pois todos os vertices especiais (fabrica ou obra) estao aptos a disponibilizar/receberem carga
    grafo->carga_descarga[indice] = true;
    grafo->tipo_vertice[indice] = tipo;
}

void calculaRota(Grafo *grafo, int posicao_caminhao){
    bool irParaFabrica = true;//variavel que vai tar controlando qual djkstra realizar  : fonte -> fabrica ou fabrica ->obra, comeca procurando uma fabrica, logo é true
    int *predecessores = new int[grafo->n_vertices];
    float *distancias = new float[grafo->n_vertices];
    bool *vertices_abertos = new bool[grafo->n_vertices];
    Fila *salvar_caminho = criarFilaVazia();

    inserir(salvar_caminho,posicao_caminhao);//coloca ponto inicial do caminho na fila
    inicilizaTodosVerticesAbertos(vertices_abertos,grafo->n_vertices);

    while(true){
        //se nao tiver mais vertices especiais de obra ou fabrica pra ser visitados, parar o algoritmo
        if(temCargaDescarga(grafo) == false){
            break;
        }
        if(irParaFabrica == true){
            //calcula as distancias tendo como base a posicao do caminhao, que inicialmente é passada pelo usuario
            djkstra(grafo,posicao_caminhao,distancias,predecessores,vertices_abertos);
            //analisa o vetor de distancias resultante do djkstra em busca da fabrica com menor distancia que ainda está disponivel para fornecer carga
            int fabrica_prox = decidirQualFabrica(distancias,grafo);
            grafo->carga_descarga[fabrica_prox] = false;//garantir que nao vai mais reabastecer nessa fabrica
            inserir(salvar_caminho,fabrica_prox);//armazena fabrica no caminho
            cout <<posicao_caminhao << " -> " <<fabrica_prox << endl;
            //atualiza a posicao do caminhao
            posicao_caminhao = fabrica_prox;
            //setando para falso, agora ele vai pro outro djkstra procurar a obra na prox execucao do while
            irParaFabrica = false;
        }else{
            //calcula as distancias tendo como base a posicao do caminhao, que é uma fabrica
            djkstra(grafo,posicao_caminhao,distancias,predecessores,vertices_abertos);
            //analisa o vetor de distancias resultante do djkstra em busca da obra com menor distancia que ainda está disponivel para receber carga
            int obra_prox = decidirQualObra(distancias,grafo);
            grafo->carga_descarga[obra_prox] = false;//garantir que nao vai mais abastecer essa obra
            inserir(salvar_caminho,obra_prox);//armazena obra no caminho
            cout <<posicao_caminhao << " -> " <<obra_prox << endl;
            //atualiza a posicao do caminhao
            posicao_caminhao = obra_prox;
            //setando para falso, agora ele vai pro outro djkstra procurar a proxima fabrica pra reabastecer na prox execucao do while
            irParaFabrica = true;
        }
        //tem que limpar os vetores e abrir todos os vertices novamente para cada vez que ele for rodar um djkstra novo
        apagarVetorDistancias(distancias,grafo->n_vertices);
        apagarVetorPredecessores(predecessores, grafo->n_vertices);
        inicilizaTodosVerticesAbertos(vertices_abertos,grafo->n_vertices);

    }

    while(salvar_caminho->n != 0){
        cout << remover(salvar_caminho) << " -> ";
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

    criarCargaDescarga(novo_grafo,3,FABRICA);
    criarCargaDescarga(novo_grafo,4,OBRA);

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

    criarCargaDescarga(novo_grafo2,0,OBRA);
    criarCargaDescarga(novo_grafo2,1,FABRICA);
    criarCargaDescarga(novo_grafo2,4,FABRICA);
    criarCargaDescarga(novo_grafo2,8,OBRA);
    criarCargaDescarga(novo_grafo2,9,FABRICA);
    criarCargaDescarga(novo_grafo2,10,OBRA);

    calculaRota(novo_grafo2,2);

    return 0;
}
