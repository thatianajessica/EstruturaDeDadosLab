#include <iostream>
#include <time.h>

using namespace std;

typedef struct Cell{
    int row;
    int col;
}Cell;

typedef struct No{
    Cell *chave;
    struct No *prox;
}No;

typedef struct Fila{
    struct No *inicio;
    struct No *fim;
    int n;
}Fila;

Cell* criarCell(int row, int col){
    Cell *nova_cell = new Cell;
    nova_cell->row = row;
    nova_cell->col = col;
    return nova_cell;
}

No* criarNo(Cell* chave){
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

void inserir(Fila *fila, int row, int col){
    Cell *nova_cell = criarCell(row,col);
    No *novo_no = criarNo(nova_cell);
    if(fila->fim != NULL){
        fila->fim->prox = novo_no;
    }else{
        fila->inicio = novo_no;
    }
    fila->fim = novo_no;
    fila->n += 1;
}

No* remover(Fila *fila){
    No *valor;
    if(fila->inicio != NULL){
        No* aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL){
            fila->fim = NULL;
        }
        valor = aux;
        fila->n -= 1;
    }else{
        cout <<"FILA VAZIA" <<endl;
    }
    return valor;
}

void printFila(Fila *fila){
    No *aux = fila->inicio;
    while(aux != NULL){
        cout <<"( " <<aux->chave->row <<" , " <<aux->chave->col <<" )" <<endl;
        aux = aux->prox;
    }
    cout <<endl;
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

bool** createMap(int n)
{
    bool **grid = (bool **) calloc (n , sizeof(bool*)  );
    for (int i=0; i < n; i++){
        grid[i] = (bool *) calloc( n , sizeof(bool) );
    }
    return grid;
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

void fillGridRandomly(int n, int** grid, int level)
{
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if( (i == 0 && j == 0) || (i == n-1 && j == n-1) )
            {
                grid[i][j] = 0;
            }
            else
            {
                int r = rand() % 100; // random integer between 0 and 99
                if (r > level){
                    grid[i][j] = 0;
                }else{
                    grid[i][j] =-1;
                }

            }
        }
    }
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
    grid[0][1] = -1;
    grid[0][5] = -1;
    grid[1][2] = -1;
    grid[1][4] = -1;
    grid[2][5] = -1;
    grid[3][1] = -1;
    grid[3][2] = -1;
    grid[4][0] = -1;
    grid[4][4] = -1;
    grid[4][5] = -1;
    grid[5][2] = -1;
}

void solvePuzzleFila(int n, int **grid){
    Fila *nova_fila = criarFilaVazia();
    inserir(nova_fila,0,0);

    while(true){

        if(nova_fila->inicio == NULL){
            break;
        }

        No *novo_no = remover(nova_fila);

        int current_row = novo_no->chave->row;
        int current_col = novo_no->chave->col;


        if(grid[current_row][current_col] == -1){
            continue;
        }

        cout <<"( " <<current_row <<" , " <<current_col <<" )" <<endl;


        grid[current_row][current_col] = -1;

        if(current_col == n-1 && current_row == n-1){
            cout <<"chegou" <<endl;
            break;
        }


        if(current_row+1 < n){
            if(grid[current_row+1][current_col] == 0){
                inserir(nova_fila,current_row+1,current_col);
            }
        }
        if(current_col+1 < n){
            if(grid[current_row][current_col+1] == 0){
                inserir(nova_fila,current_row,current_col+1);
            }
        }
        if(current_row-1 >= 0){
            if(grid[current_row-1][current_col] == 0){
                inserir(nova_fila,current_row-1,current_col);
            }

        }
        if(current_col-1 >= 0){
            if(grid[current_row][current_col-1] == 0){
                inserir(nova_fila,current_row,current_col-1);
            }
        }

    }


}




int main()
{
    //V[3][3] = {{3, 2, 3},{2,5,1},{5,3,1}};
    int n=6;
    int** grid = createGrid(n);
    fillGridRandomly(n, grid, 60);
    //fillGridExample1(n, grid);
    printGrid(n, grid);

    solvePuzzleFila(n,grid);

    return 0;
}
