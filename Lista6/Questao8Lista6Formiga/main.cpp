#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int** createGrid(int n)
{
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
int main()
{
    //V[3][3] = {{3, 2, 3},{2,5,1},{5,3,1}};
    int n=6;
    int** grid = createGrid(n);
    bool** map = createMap(n);
    bool encontrou_caminho = false;
    fillGridRandomly(n, grid, 25);
    //fillGridExample1(n, grid);
    printGrid(n, grid);

    solvePuzzle(n,grid,map,0,0,encontrou_caminho);



    return 0;
}
