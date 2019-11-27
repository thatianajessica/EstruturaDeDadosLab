#include <iostream>
using namespace std;

//Inês é morta!!!

//Numero de vertices
const int n=11;

//"Infinito"
const int inf = 99999999;

//Exibe matriz
void exibir_matriz(int m[][n],int n);

//Retorna o minimo entre 2 valores
int mini(int a,int b);

//Algoritmo de floyd-warshall
void FloydWarshall(int M_adj[][n],int M_distancias[][n]);

//Função que varre o vetor Visitados e retorna verdadeiro se ainda existe fabrica ou obras não visitadas
bool Verifica_Visitados(bool Visitados[]);

//Função para retornar o vertice fabrica mais proximo do Vertice atual
int Fabrica_proxima(int M_distancias[][n],int Class_Vertices[],bool Visitados[],int Vertice_atual);

//Função para retornar o vertice obra mais proximo do Vertice atual
int Obra_proxima(int M_distancias[][n],int Class_Vertices[],bool Visitados[],int Vertice_atual);

//Algoritmo para encontrar o menor caminho que passe por todos os vertices fabricas e obras seguindo o seguinte criterio :
//Para se passar em uma obra é necessario passar em uma fabrica antes;
//Ao passar em uma fabrica, passar obrigadoriamente em uma obra;
void MenorCaminho(int M_distancias[][n],int Class_Vertices[],bool Visitados[],int Vertice_Inicio);

int main(){

    //Matriz de adjacencia
    int M_adj[n][n] = { {0,1,0,0,0,0,0,0,0}
                        {0,1,0,0,0,0,0,0,0},
                        {1,0,1,0,0,0,0,0,0},
                        {0,1,0,1,0,0,0,0,0},
                        {0,0,1,0,1,0,0,0,0},
                        {0,0,0,1,0,1,0,0,0},
                        {0,0,0,0,1,0,1,1,1},
                        {0,0,0,0,0,1,0,0,0},
                        {0,0,0,0,0,1,0,0,0},
                        {0,0,0,0,0,1,0,0,0},
                        {0,0,0,0,0,1,0,0,0}
                        {0,0,0,0,0,1,0,0,0}
                        {0,0,0,0,0,1,0,0,0}};

    //Matriz contendo as distancias de todos para todos
    int M_distancias[n][n];

    //Vetor de classificação dos vertices : 0 -> Vertice Normal ; 1 -> Vertice Fabrica ; 2->Vertice Obra
    int Class_Vertices[n] = {2,0,1,0,0,1,0,0,0,2,2,1};

    //Vetor de marcação dos vertices visitados
    bool Visitados[n];

    for(int i=0;i<n;i++){ //Iniciar fabricas e obras em falso
        if(Class_Vertices[i]==1 || Class_Vertices[i]==2){
            Visitados[i] = false;
        }
        else{
            Visitados[i] = true;
        }
    }


    //Gera a matriz de distancias utiliando Floyd-Warshall
    FloydWarshall(M_adj,M_distancias);
    //exibir_matriz(M_distancias,n);

    int Vertice_Inicio = 4;
    MenorCaminho(M_distancias,Class_Vertices,Visitados,Vertice_Inicio);

    return 0;
}

void exibir_matriz(int m[][n],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}


int mini(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}

void FloydWarshall(int M_adj[][n],int M_distancias[][n]){

    //Inicializando a matriz de distancias..
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(M_adj[i][j]==0){
                M_distancias[i][j] = inf;
            }
            else{
                M_distancias[i][j] = M_adj[i][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        M_distancias[i][i] = 0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                M_distancias[i][j] = mini(M_distancias[i][j],M_distancias[i][k]+M_distancias[k][j]);
            }
        }
    }
}

bool Verifica_Visitados(bool Visitados[]){
    for(int i=0;i<n;i++){
        if(Visitados[i]==false)
            return true;
    }

    return false;
}

int Fabrica_proxima(int M_distancias[][n],int Class_Vertices[],bool Visitados[],int Vertice_atual){

    int menor_dist = inf;
    int fabrica_proxima;

    for(int i=0;i<n;i++){
        if(Class_Vertices[i]==1 && Visitados[i]==false){
            if(M_distancias[Vertice_atual][i] < menor_dist){
                menor_dist = M_distancias[Vertice_atual][i];
                fabrica_proxima = i;
            }
        }
    }

    return fabrica_proxima;
}

int Obra_proxima(int M_distancias[][n],int Class_Vertices[],bool Visitados[],int Vertice_atual){

    int menor_dist = inf;
    int obra_proxima;

    for(int i=0;i<n;i++){
        if(Class_Vertices[i]==2 && Visitados[i]==false){
            if(M_distancias[Vertice_atual][i] < menor_dist){
                menor_dist = M_distancias[Vertice_atual][i];
                obra_proxima = i;
            }
        }
    }

    return obra_proxima;

}

void MenorCaminho(int M_distancias[][n],int Class_Vertices[],bool Visitados[],int Vertice_Inicio){

    int Soma_distancias=0;
    int aux;

    //Enquanto houver fabricas e/ou obras não visitadas
    while(Verifica_Visitados(Visitados)==true){

        aux = Vertice_Inicio;
        Vertice_Inicio = Fabrica_proxima(M_distancias,Class_Vertices,Visitados,Vertice_Inicio);

        Soma_distancias = Soma_distancias + M_distancias[aux][Vertice_Inicio];

        Visitados[Vertice_Inicio] = true;

        aux = Vertice_Inicio;
        Vertice_Inicio = Obra_proxima(M_distancias,Class_Vertices,Visitados,Vertice_Inicio);

        Soma_distancias = Soma_distancias + M_distancias[aux][Vertice_Inicio];

        Visitados[Vertice_Inicio] = true;

    }

    cout << "Distancia final = " << Soma_distancias << endl;

}

