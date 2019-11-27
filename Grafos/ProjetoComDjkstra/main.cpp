#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#define INFINITO 2147483647
#define NORMAL 0
#define FABRICA 1
#define OBRA 2
#include <time.h>

using namespace std;

// ================================= Estruturas Utilizadas ===================================================

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

typedef struct Grafo{
    bool **matrizAdjacencia;
    float **matrizPesos;
    int n_vertices;
    int *tipo_vertice;//0 - normal, 1 - fabrica, 2 - obra
    bool *carga_descarga;//tudo false na criacao, a medida que vai visitando, vai marcando com true indicando que ja abasteceu e nao eh para nao abastecer mais la, ou pra nao descarregar la
}Grafo;

// ==================================================================================================================


No* criarNo(int chave);
void deletarNo(No **no);

Fila* criarFilaVazia();
void inserir(Fila *fila, int chave);
int remover(Fila *fila);

Pilha* criarPilhaVazia();
void empilhar(Pilha *pilha, int chave);
int desempilha(Pilha *pilha);

Grafo* criarGrafoVazio(int n_vertices);
void adicionarArestas(Grafo *grafo, int v1, int v2, float peso);
void nosAdjacentes(Grafo *grafo);
void printarAjacentesPesos(Grafo *grafo);
bool verificarAdjacencia(Grafo *grafo, int rotulo_verticev1, int rotulo_verticev2);
void printCargaDescarga(Grafo *grafo);

bool temVerticeAberto(bool *vetor_vertices, int n);
void menorDistanciaParaDjkstra(float *vetor_distancias, bool *vertices_abertos, int n, float &menor_distancia, int &indice);
void inicilizaTodosVerticesAbertos(bool *vertices_abertos, int n);
void djkstra(Grafo *grafo, int fonte, float *distancias, int *predecessor);

void printarVetorDistancias(float *vetor, int n);
void printarVetorTipos(Grafo *grafo);
void printarVetorAntecessores(int *predecessores, int n);

bool temCargaDescarga(Grafo *grafo);
int decidirQualFabrica(float *distancias, Grafo *grafo);
int decidirQualObra(float *distancias, Grafo *grafo);
void apagarVetorDistancias(float *vetor_distancias, int n);
void apagarVetorPredecessores(int *vetor_predecessores, int n);
void criarCargaDescarga(Grafo *grafo, int indice, int tipo);
void printarRota(Fila *fila);
void guardarCaminhoCompleto(Pilha *caminho_invertido, int *vetor_predecessores,int n, int index_menor_distancia, int index_vertice_inicial_trajeto, Fila *salvar_caminho );
Pilha* recuperarCaminhoOrdemCerta(Pilha *caminho_reverso);
void calculaRota(Grafo *grafo, int posicao_caminhao);
vector<string> split_string(string s);
Grafo* lerGrafoDoFile(const char* nome_arquivo, int &posicial_inicial);

int main()
{
    Grafo* grafo = NULL;
    int posicao_inicial = 0;
    int opcao_arquivo;

    cout << "Digite qual o arquivo que deseja executar" << endl;
    cin >> opcao_arquivo;

    if(opcao_arquivo==1){
        grafo = lerGrafoDoFile("C:\\Users\\Matus\\Desktop\\Trabalho ED\\completo\\10Completo.in",posicao_inicial);//mudar o diretorio local do txt
    }
    else if(opcao_arquivo==2){
        grafo = lerGrafoDoFile("C:\\Users\\Matus\\Desktop\\Trabalho ED\\completo\\30Completo.in",posicao_inicial);
    }
    else if(opcao_arquivo==3){
        grafo = lerGrafoDoFile("C:\\Users\\Matus\\Desktop\\Trabalho ED\\completo\\50Completo.in",posicao_inicial);
    }
    else if(opcao_arquivo==4){
        grafo = lerGrafoDoFile("C:\\Users\\Matus\\Desktop\\Trabalho ED\\completo\\100Completo.in",posicao_inicial);
    }
    else if(opcao_arquivo==5){
        grafo = lerGrafoDoFile("C:\\Users\\Matus\\Desktop\\Trabalho ED\\completo\\1000Completo.in",posicao_inicial);
    }
    else if(opcao_arquivo==6){
        grafo = lerGrafoDoFile("C:\\Users\\Matus\\Desktop\\Trabalho ED\\completo\\5000Completo.in",posicao_inicial);
    }
    else if(opcao_arquivo==7){
        grafo = lerGrafoDoFile("C:\\Users\\Matus\\Desktop\\Trabalho ED\\completo\\6000Completo.in",posicao_inicial);
    }
    else if(opcao_arquivo == 0){
        grafo = lerGrafoDoFile("C:\\Users\\thaty\\Desktop\\EstruturaDeDadosLab\\Grafos\\ProjetoComDjkstra\\Instancias\\instancia_teste.in",posicao_inicial);
    }
    else if(opcao_arquivo == 8){
        grafo = lerGrafoDoFile("C:\\Users\\thaty\\Desktop\\EstruturaDeDadosLab\\Grafos\\ProjetoComDjkstra\\Instancias\\10Completo.in",posicao_inicial);
    }
    else if(opcao_arquivo == 9){
        grafo = lerGrafoDoFile("C:\\Users\\thaty\\Desktop\\EstruturaDeDadosLab\\Grafos\\ProjetoComDjkstra\\Instancias\\instancia_teste_qdaerrado.in",posicao_inicial);
    }
    else{
        cout << "arquivo invalido!" << endl;
        return 0;
    }

    clock_t tInicio, tFim, tDecorrido;

    tInicio = clock();

    calculaRota(grafo,posicao_inicial);

    tFim = clock();

    tDecorrido = (double(tFim - tInicio) / CLOCKS_PER_SEC)*1000;

    cout << "Tempo de execucao do algoritmo : " << tDecorrido << "ms" << endl;

    return 0;
}

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
        for (int j = 0; j < grafo->n_vertices; j++) {
            if (grafo->matrizAdjacencia[i][j] == true){
                cout << "Aresta de " << i << " ate " << j << " com peso " << grafo->matrizPesos[i][j] << endl;
            }
        }
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

void printarVetorDistancias(float *vetor, int n){
    cout <<"Vetor de distancias: " ;
    for (int i = 0 ; i < n; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
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

void djkstra(Grafo *grafo, int fonte, float *distancias, int *predecessor){

    distancias[fonte] = 0;//a distancia da fonte ate ela mesma eh 0

    bool *vertices_abertos = new bool[grafo->n_vertices];

    inicilizaTodosVerticesAbertos(vertices_abertos,grafo->n_vertices);

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



    delete[]vertices_abertos;
}


void printarVetorTipos(Grafo *grafo){
    cout <<"Vetor de tipos: " ;
    for (int i = 0 ; i < grafo->n_vertices; i++) {
        cout << grafo->tipo_vertice[i] << " ";
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
    //printarVetorDistancias(distancias,grafo->n_vertices);
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

void printarRota(Fila *fila){
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

Pilha* recuperarCaminhoOrdemCerta(Pilha *caminho_reverso){
    Pilha *nova_pilha_invertida = criarPilhaVazia();
    int aux = -1;
    while(caminho_reverso->n != 0){
        aux = desempilha(caminho_reverso);
        empilhar(nova_pilha_invertida, aux);
    }
    return nova_pilha_invertida;
}

void calculaRota(Grafo *grafo, int posicao_caminhao){


    //variavel que vai tar controlando qual djkstra realizar  : fonte -> fabrica ou fabrica ->obra,
    //comeca procurando uma fabrica, logo é true
    bool irParaFabrica = true;

    int *predecessores = new int[grafo->n_vertices];

    float *distancias = new float[grafo->n_vertices];

    Fila *salvar_caminho = criarFilaVazia();

    Pilha *caminho_invertido = criarPilhaVazia();

    float distancia_acumulada = 0;

    //inicia a lista dos caminhos com a posicao inicial
    //coloca ponto inicial do caminho na fila
    inserir(salvar_caminho,posicao_caminhao);

    //empilhar(caminho_invertido,posicao_caminhao);
    //abre todos os vertices = true
    while(true){

        //se nao tiver mais vertices especiais de obra ou fabrica pra ser visitados, parar o algoritmo
        if(temCargaDescarga(grafo) == false){
            break;
        }

        if(irParaFabrica == true){

            //calcula as distancias tendo como base a posicao do caminhao, que inicialmente é passada pelo usuario
            djkstra(grafo,posicao_caminhao,distancias,predecessores);

            //analisa o vetor de distancias resultante do djkstra em busca da fabrica com menor distancia que ainda está disponivel para fornecer carga
            int fabrica_prox = decidirQualFabrica(distancias,grafo);

            //printarVetorDistancias(distancias,grafo->n_vertices);
            grafo->carga_descarga[fabrica_prox] = false;//garantir que nao vai mais reabastecer nessa fabrica

            distancia_acumulada += distancias[fabrica_prox];

            guardarCaminhoCompleto(caminho_invertido,predecessores,grafo->n_vertices,fabrica_prox,posicao_caminhao, salvar_caminho);

            //atualiza a posicao do caminhao
            posicao_caminhao = fabrica_prox;

            //setando para falso, agora ele vai pro outro djkstra procurar a obra na prox execucao do while
            irParaFabrica = false;

        } else {
            //calcula as distancias tendo como base a posicao do caminhao, que é uma fabrica
            djkstra(grafo,posicao_caminhao,distancias,predecessores);

            //analisa o vetor de distancias resultante do djkstra em busca da obra com menor distancia que ainda está disponivel para receber carga
            int obra_prox = decidirQualObra(distancias,grafo);

            //printarVetorDistancias(distancias,grafo->n_vertices);
            grafo->carga_descarga[obra_prox] = false;//garantir que nao vai mais abastecer essa obra

            distancia_acumulada += distancias[obra_prox];

            guardarCaminhoCompleto(caminho_invertido,predecessores,grafo->n_vertices,obra_prox,posicao_caminhao,salvar_caminho);

            //atualiza a posicao do caminhao
            posicao_caminhao = obra_prox;

            //setando para falso, agora ele vai pro outro djkstra procurar a proxima fabrica pra reabastecer na prox execucao do while
            irParaFabrica = true;
        }
        //tem que limpar os vetores e abrir todos os vertices novamente para cada vez que ele for rodar um djkstra novo
        apagarVetorDistancias(distancias,grafo->n_vertices);
        apagarVetorPredecessores(predecessores, grafo->n_vertices);

    }

    printarRota(salvar_caminho);

    cout <<"Distancia acumulada total para abastecer as obras = " <<distancia_acumulada <<endl;
    delete[] predecessores;
    delete[] distancias;
}

Grafo *lerGrafoDoFile(const char *nome_arquivo, int &posicao_inicial)
{
    ifstream arquivo(nome_arquivo);

    if (arquivo.is_open())
    {
        cout << "arquivo foi aberto\n";
    }
    else
    {
        cout << "arquivo nao foi aberto\n";
    }

    Grafo *grafo = NULL;
    string line;
    int current_row = 0;
    int n_vertices = 0;
    int n_fabricas = 0;
    int n_obras = 0;
    int indice_no = 0;
    while (getline(arquivo, line))
    {
        if (current_row == 0) // le numero de vertices
        {
            n_vertices = atoi(line.c_str());
            grafo = criarGrafoVazio(n_vertices);
        }

        else if (current_row == 1) // le numero de fabricas e indices de fabricas
        {
            size_t pos = 0;
            bool firstElement = true;
            int end_row = false;
            int start_index = 0;
            int end_index = 0;
            while (true)
            {
                pos = line.find(' ');
                if (pos == string::npos)
                {
                    end_index = line.size();
                    end_row = true;
                }
                else
                {
                    end_index = pos;
                }

                string aux = line.substr(start_index, end_index);
                if (firstElement == true)
                {
                    n_fabricas = atoi(aux.c_str());
                    firstElement = false;
                }
                else
                {
                    indice_no = atoi(aux.c_str());
                    criarCargaDescarga(grafo, indice_no, FABRICA);
                }

                if (end_row)
                {
                    break;
                }
                line.erase(0, end_index + 1);
            }
        }

        else if (current_row == 2) // le numero de obras e indices de obras
        {
            size_t pos = 0;
            bool firstElement = true;
            int end_row = false;
            int start_index = 0;
            int end_index = 0;
            while (true)
            {
                pos = line.find(' ');
                if (pos == string::npos)
                {
                    end_index = line.size();
                    end_row = true;
                }
                else
                {
                    end_index = pos;
                }

                string aux = line.substr(start_index, end_index);
                if  (firstElement == true)
                {
                    n_obras = atoi(aux.c_str());
                    firstElement = false;
                }
                else
                {
                    indice_no = atoi(aux.c_str());
                    criarCargaDescarga(grafo, indice_no, OBRA);
                }

                if (end_row)
                {
                    break;
                }
                line.erase(0, end_index + 1);
            }
        }

        else if (current_row == 3)
        { // le posicao inciial
            posicao_inicial = atoi(line.c_str());
        }

        else
        { // le arestas
            size_t pos = 0;
            bool firstElement = true;
            int end_row = false;
            int start_index = 0;
            int end_index = 0;
            int vertice_i = 0;
            int vertice_j = 0;
            float peso = 0;
            while (true)
            {
                pos = line.find(' ');
                if (pos == string::npos)
                {
                    end_index = line.size();
                    string aux = line.substr(start_index, end_index);
                    peso = atof(aux.c_str());
                    break;
                }
                else
                {
                    end_index = pos;
                    string aux = line.substr(start_index, end_index);
                    if (firstElement == true){
                        firstElement = false;
                        vertice_i = atoi(aux.c_str());
                    }else{
                        vertice_j = atoi(aux.c_str());
                    }
                }

                line.erase(0, end_index + 1);
            }
            adicionarArestas(grafo, vertice_i, vertice_j, peso);
        }

        current_row++;
    }

    arquivo.close();

    return grafo;
}


