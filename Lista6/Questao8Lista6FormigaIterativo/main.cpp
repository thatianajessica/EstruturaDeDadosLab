#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

typedef struct Pilha{
    struct No *topo;
    int n;
}Pilha;

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

Pilha* criarPilhaVazia(){
    Pilha *nova_pilha = new Pilha();
    nova_pilha->topo = NULL;
}

void empilhar(Pilha *pilha, int row, int col){
    Cell *nova_cell = criarCell(row,col);
    No *novo_no = criarNo(nova_cell);
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    pilha->n += 1;
}

Cell* desempilha(Pilha *pilha){
    Cell *valor;
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

void solvePuzzle(int n, int **grid, bool **mapa_recurssao, int row_source, int col_source, bool &end){
    cout <<"( " <<row_source <<" , " <<col_source <<" )" <<endl;

    if(row_source == n-1 && col_source == n-1){
        cout <<"Formiguinha chegou! Congratz!" <<endl;
        end = true;
        return;
    }
    //descer
    if(end == false){
        if(row_source+1 < n){
            if(mapa_recurssao[row_source+1][col_source] == false){
                if(grid[row_source+1][col_source] == 0){
                    mapa_recurssao[row_source+1][col_source] = true;
                    solvePuzzle(n,grid,mapa_recurssao,row_source+1,col_source,end);
                }
            }
        }
    }


    //direita
    if(end == false){
        if(col_source+1 < n){
            if(mapa_recurssao[row_source][col_source+1] == false){
                if(grid[row_source][col_source+1] == 0){
                    mapa_recurssao[row_source][col_source+1] = true;
                    solvePuzzle(n,grid,mapa_recurssao,row_source,col_source+1,end);
                }
            }
        }
    }

    //cima
    if(end == false){
        if(row_source-1 >= 0){
            if(mapa_recurssao[row_source-1][col_source] == false){
                if(grid[row_source-1][col_source] == 0){
                    mapa_recurssao[row_source-1][col_source] = true;
                    solvePuzzle(n,grid,mapa_recurssao,row_source-1,col_source,end);
                }
            }
        }
    }

    //direita
    if(end == false){
        if(col_source-1 >= 0){
            if(mapa_recurssao[row_source][col_source-1] == false){
                if(grid[row_source][col_source-1] == 0){
                    mapa_recurssao[row_source][col_source-1] = true;
                    solvePuzzle(n,grid,mapa_recurssao,row_source,col_source-1,end);
                }
            }
        }
    }


}

void printPilha(Pilha *pilha){
    No *aux = pilha->topo;
    while(aux != NULL){
        cout <<"( " <<aux->chave->row <<" , " <<aux->chave->col <<" )" <<endl;
        aux = aux->prox;
    }
    cout <<endl;
}

void solvePuzzleInterativo(int n, int **grid, bool **mapa_recurssao){
    Pilha *nova_pilha = criarPilhaVazia();
    empilhar(nova_pilha,0,0);
    mapa_recurssao[0][0] = true;

    while (true) {
        if(nova_pilha->topo == NULL){
            break;
        }

        int current_row = nova_pilha->topo->chave->row;
        int current_col = nova_pilha->topo->chave->col;
        cout <<"( " <<current_row <<" , " <<current_col <<" )" <<endl;

        if(current_col == n-1 && current_row == n-1){
            cout <<"chegou" <<endl;
            break;
        }

        if(current_row+1 < n){
            if(mapa_recurssao[current_row+1][current_col] == false){
                if(grid[current_row+1][current_col] == 0){
                    cout <<"entrou" <<endl;
                    mapa_recurssao[current_row+1][current_col] = true;
                    empilhar(nova_pilha,current_row+1,current_col);
                    continue;
                }
            }
        }
        if(current_col+1 < n){
            if(mapa_recurssao[current_row][current_col+1] == false){
                if(grid[current_row][current_col+1] == 0){
                    mapa_recurssao[current_row][current_col+1] = true;
                    empilhar(nova_pilha,current_row,current_col+1);
                    continue;
                }
            }
        }
        if(current_row-1 >= 0){
            if(mapa_recurssao[current_row-1][current_col] == false){
                if(grid[current_row-1][current_col] == 0){
                    mapa_recurssao[current_row-1][current_col] = true;
                    empilhar(nova_pilha,current_row-1,current_col);
                    continue;
                }

            }
        }
        if(current_col-1 >= 0){
            if(mapa_recurssao[current_row][current_col-1] == false){
                if(grid[current_row][current_col-1] == 0){
                    mapa_recurssao[current_row][current_col-1] = true;
                    empilhar(nova_pilha,current_row,current_col-1);
                    continue;
                }
            }
        }
        desempilha(nova_pilha);

    }

    cout <<"#####################" <<endl;
    printPilha(nova_pilha);

}



int main()
{
    //V[3][3] = {{3, 2, 3},{2,5,1},{5,3,1}};
    int n=6;
    int** grid = createGrid(n);
    bool** map = createMap(n);
    bool encontrou_caminho = false;
    //fillGridRandomly(n, grid, 25);
    fillGridExample1(n, grid);
    printGrid(n, grid);

    //solvePuzzle(n,grid,map,0,0,encontrou_caminho);
    solvePuzzleInterativo(n,grid,map);





    return 0;
}
