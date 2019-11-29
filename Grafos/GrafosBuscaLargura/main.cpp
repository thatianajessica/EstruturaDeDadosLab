#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    struct No *prox;
}No;

typedef struct NoAresta{
    int vertice_saida;
    int vertice_chegada;
    struct NoAresta *prox;
}NoAresta;

typedef struct Lista{
    int n;
    No *cabeca;
}Lista;

typedef struct ListaAresta{
    int n;
    NoAresta *cabeca;
}ListaAresta;



typedef struct Fila{
    struct No *inicio;
    struct No *fim;
    int n;
}Fila;

typedef struct Grafo{
    int n_vertices;
    Lista *lista_adj;
    bool *vertices_marcados;
}Grafo;

No* criarNo(int chave){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->chave = chave;
    return novo_no;
}

NoAresta* criarNoAresta(int vertice_saida, int vertice_chegada){
    NoAresta *novo_no = new NoAresta;
    novo_no->prox = NULL;
    novo_no->vertice_saida = vertice_saida;
    novo_no->vertice_chegada = vertice_chegada;
    return novo_no;
}


Lista* criarListaVazia(){
    Lista *nova_lista = new Lista;
    nova_lista->cabeca = NULL;
    nova_lista->n = 0;
    return nova_lista;
}

void adicionaListaCauda(Lista *lista, int no_index){
    No* no_adc = criarNo(no_index);
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

ListaAresta* criarListaArestaVazia(){
    ListaAresta *nova_lista = new ListaAresta;
    nova_lista->cabeca = NULL;
    nova_lista->n = 0;
    return nova_lista;
}

void adicionaListaArestaCauda(ListaAresta *lista, int vertice_saida, int vertice_chegada){
    NoAresta* no_adc = criarNoAresta(vertice_saida,vertice_chegada);
    if (lista->cabeca == NULL){
        lista->cabeca = no_adc;
    }else{
        NoAresta *cauda = lista->cabeca;
        for (int i = 0 ; i < ((lista->n)-1); i++) {
            cauda = cauda->prox;
        }
        cauda->prox = no_adc;
    }
    lista->n += 1;
}

bool buscarArestaNaLista(ListaAresta *lista, int vertice_saida, int vertice_chegada){
    bool retorno = false;
    NoAresta *aux = lista->cabeca;
    for(int i = 0; i < lista->n; i++){
        if(aux->vertice_saida == vertice_saida && aux->vertice_saida == vertice_chegada){
            retorno = true;
            return retorno;
        }
    }
    return retorno;
}


Fila* criarFilaVazia(){
    Fila *nova_fila = new Fila();
    nova_fila->n = 0;
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
};


void inserirFila(Fila *fila, int chave){
    No *novo_no = criarNo(chave);
    if(fila->fim != NULL){
        fila->fim->prox = novo_no;
    }else{
        fila->inicio = novo_no;
    }
    fila->fim = novo_no;
    fila->n += 1;
}

void deletarNo(No **no){
    No *aux = *no;
    delete aux;
    no = NULL;
}

int removerFila(Fila *fila){
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

Grafo* criarGrafoVazio(int n_vertices){
    Grafo *novo_grafo = new Grafo;
    novo_grafo->n_vertices = n_vertices;
    novo_grafo->vertices_marcados = new bool[n_vertices];
    novo_grafo->lista_adj = new Lista[n_vertices];//funciona como o vetor sequencial
    for(int i = 0; i < n_vertices; i++){
        novo_grafo->lista_adj[i].cabeca = NULL;
        novo_grafo->lista_adj[i].n = 0;
    }
    for(int i = 0; i< n_vertices; i++){
        novo_grafo->vertices_marcados[i] = false;//vertices ainda nao foram visitados
    }
    return novo_grafo;
}

void conectarVerticesNaoDirecionado(Grafo *grafo, int index_v1, int index_v2){

    adicionaListaCauda(& (grafo->lista_adj[index_v1]), index_v2);
    adicionaListaCauda(& (grafo->lista_adj[index_v2]), index_v1);
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


void printarFila(Fila *fila){
    No *aux = fila->inicio;
    for(int i = 0; i < fila->n; i++){
        cout << aux->chave << " ";
        aux = aux->prox;
    }
    cout << endl;
}

void buscaLargura(Grafo *grafo, int vertice_inicio){
    Fila *nova_fila = criarFilaVazia();
    ListaAresta *arestas_visitadas = criarListaArestaVazia();
    grafo->vertices_marcados[vertice_inicio] = true;
    inserirFila(nova_fila, vertice_inicio);

    while(nova_fila->n != 0){
        printarFila(nova_fila);
        int vertice_corrente = removerFila(nova_fila);
        cout <<"Vertice corrente = " <<vertice_corrente << endl;
        No *aux = grafo->lista_adj[vertice_corrente].cabeca;
        for(int i = 0; i < grafo->lista_adj[vertice_corrente].n; i++){
            if(grafo->vertices_marcados[aux->chave] == false ){
                adicionaListaArestaCauda(arestas_visitadas,vertice_corrente,aux->chave);
                cout << "Marcando vertice = " << aux->chave << endl;
                inserirFila(nova_fila, aux->chave);
                grafo->vertices_marcados[aux->chave] = true;
                aux = aux->prox;
            }else{
                if(buscarArestaNaLista(arestas_visitadas,vertice_corrente,aux->chave) == false){
                    adicionaListaArestaCauda(arestas_visitadas,vertice_corrente,aux->chave);
                    cout << "vertice  = " << aux->chave << endl;
                    aux = aux->prox;
                }
            }
        }
    }
}


int main()
{
    int n_vertices = 10;
    Grafo *grafo = criarGrafoVazio(n_vertices);

    conectarVerticesNaoDirecionado(grafo,0,1);
    conectarVerticesNaoDirecionado(grafo,0,2);
    conectarVerticesNaoDirecionado(grafo,0,3);
    conectarVerticesNaoDirecionado(grafo,1,4);
    conectarVerticesNaoDirecionado(grafo,2,5);
    conectarVerticesNaoDirecionado(grafo,2,6);
    conectarVerticesNaoDirecionado(grafo,3,7);
    conectarVerticesNaoDirecionado(grafo,4,8);
    conectarVerticesNaoDirecionado(grafo,5,9);

    printarListasAdj(grafo);

    buscaLargura(grafo,0);



    cout << "Hello World!" << endl;
    return 0;
}
