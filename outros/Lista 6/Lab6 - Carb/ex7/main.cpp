#include <iostream>

using namespace std;

typedef struct No
{
  int valor;
  struct No *prox;
} TipoNo;

typedef struct Fila
{
  TipoNo *inicio, *fim;
  int tamanho;
} Fila;

void IniciaFila(Fila *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho=0;
}

bool Vazia(Fila *fila)
{
  return (fila->inicio == NULL);
}

void Enfileira(int x, Fila *fila)
{
  TipoNo *aux = new TipoNo;
  aux->valor=x;
  aux->prox=NULL;
  if (Vazia(fila)){
    fila->inicio=aux;
    fila->fim=aux;
  }
  else {
  fila->fim->prox = aux;
  fila->fim = aux;
  }
  fila->tamanho++;
}

int Desenfileira(Fila *fila)
{
  TipoNo *q; int v;
  if (Vazia(fila))
  {
    printf("Fila esta vazia\n");
    return 0;
  }
  q = fila->inicio;
  v = fila->inicio->valor;
  fila->inicio = fila->inicio->prox;
  delete (q);
  fila->tamanho--;
  return v;
}

int *distancias(Fila *fila,char **matrix, int origem, int num){
    int *d = new int[num];
    bool *visitados = new bool[num];
    for(int i=0;i<num;i++){
        visitados[i]=0;
        d[i]=-1;
    }
    IniciaFila(fila);
    Enfileira(origem,fila);

    d[origem]=0;
    visitados[origem]=1;
    int caso;

    int cont=0;

    while(!Vazia(fila)){
        cont++;
        caso=Desenfileira(fila);
        for(int i=0;i<num;i++){
            if(matrix[caso][i]=='1'){
                if(!visitados[i]){
                    Enfileira(i,fila);
                    visitados[i]=1;
                    d[i]=cont;
                }
                else{
                    cont--;
                    continue;
                }
            }
        }
    }
    return d;

}

int main()
{
    Fila *caminho = new Fila();
    IniciaFila(caminho);
    int *d = new int();
    int num,origem;
    cout<<"Número de Cidades"<<endl;
    cin>>num;

    char **mat = new char*[num] ;
    for(int i=0;i<num;i++){
        mat[i]=new char[num];
        cout<<"linha "<<i<<endl;
        for(int j=0;j<num;j++){
            cin>>mat[i][j];
        }
    }

    cout<<"Origem"<<endl;
    cin>>origem;

    d=distancias(caminho,mat,origem,num);

    for(int i=0;i<num;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;

    return 0;
}
