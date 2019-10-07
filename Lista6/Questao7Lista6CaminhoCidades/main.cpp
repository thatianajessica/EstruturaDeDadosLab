#include <iostream>

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

int** createGrid(int n)
{
    //int **grid = new int*;

    int **grid = (int **) malloc( n * sizeof(int*)  );
    for (int i=0; i < n; i++){
        grid[i] = (int *) malloc( n * sizeof(int) );

    }
    return grid;
}

void fillGridExample1(int n, int** grid)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            grid[i][j] = 0;
        }
    }
    grid[0][1] = 1;
    grid[1][2] = 1;
    grid[2][4] = 1;
    grid[3][2] = 1;
    grid[3][4] = 1;
    grid[4][0] = 1;
    grid[5][1] = 1;
}

void printGrid(int n, int** grid)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            if (grid[i][j] >= 0){
                cout << " " <<grid[i][j] << "\t";
            }
            else{
                cout <<grid[i][j] << "\t";
            }

        }
        cout << endl;
    }
    cout << endl;
}

int* createVetorDistancias(int n){
    int *vetor_distancias = new int[n];
    for (int i = 0; i < n; i++) {
        vetor_distancias[i] = -1;
    }
    return vetor_distancias;
}

bool* createVetorJaVisitou(int n){
    bool *vetor_distancias = new bool[n];
    for (int i = 0; i < n; i++) {
        vetor_distancias[i] = false;
    }
    return vetor_distancias;
}

void printVetorDistancias(int* vetor_distancias, int n){
    for (int i = 0; i < n; i++){
        cout <<vetor_distancias[i] << " ";
    }
    cout <<endl;
}

void encontrarMenorCaminho(int n, int origem, int** matriz_estradas){
    int* vetor_distancias = createVetorDistancias(n);
    bool* vetor_javisitou = createVetorJaVisitou(n);

    vetor_distancias[origem] = 0;
    vetor_javisitou[origem] = true;

    Fila *nova_fila = criarFilaVazia();
    inserir(nova_fila,origem);

    while(true){

        if(nova_fila->inicio == NULL){
            break;
        }
        int cidade = remover(nova_fila);


        for (int col = 0; col < n; col++) {

            if(matriz_estradas[cidade][col] == 1 && vetor_javisitou[col] == false){
                inserir(nova_fila,col);
                vetor_distancias[col] = vetor_distancias[cidade] + 1;
                vetor_javisitou[col] = true;
            }
        }

    }
    printVetorDistancias(vetor_distancias,n);

}



int main()
{
    int n=6;
    int** grid = createGrid(n);
    int* vetor_distancias = createVetorDistancias(n);
    int origem = 3;

    fillGridExample1(n, grid);
    printGrid(n, grid);


    encontrarMenorCaminho(n,origem,grid);




    return 0;
}
