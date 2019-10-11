#include <iostream>
#define MaxTam 30

using namespace std;

typedef struct No
{
  int valorx;
  int valory;
  struct No *prox;
} TipoNo;

typedef struct Pilha
{
  TipoNo *topo;
  int tamanho;
} TipoPilha;

typedef struct Fila
{
  TipoNo *inicio, *fim;
  int tamanho;
} TipoFila;


void IniciaPilha(TipoPilha *pilha)
{
  pilha->topo = NULL;
  pilha->tamanho = 0;
}

int pilhaVazia(TipoPilha *pilha)
{
  return (pilha->topo == NULL);
}

void Empilha(int x,int y, TipoPilha *pilha)
{
  TipoNo *aux;

  aux = (TipoNo *) malloc(sizeof(TipoNo));
  aux->valorx = x;
  aux->valory = y;
  aux->prox = pilha->topo;
  pilha->topo = aux;
  pilha->tamanho++;
}


int *Desempilha(TipoPilha *pilha)
{
  TipoNo *q;  int vx,vy;

  if (pilhaVazia(pilha))
  {
    printf("Erro: Lista vazia\n");
    return 0;
  }
  q = pilha->topo;
  pilha->topo = q->prox;
  vx = q->valorx;
  vy = q->valory;
  free(q);
  pilha->tamanho--;
  int *v = new int();
  v[0]=vx;
  v[1]=vy;
  return v;
}

// Funções basicas para a manipulação de filas

void IniciaFila(TipoFila *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho=0;
}

int filaVazia(TipoFila *fila)
{
  return (fila->inicio == NULL);
}

void Enfileira(int x,int y, TipoFila *fila)
{
  TipoNo *aux;
  aux = (TipoNo *) malloc(sizeof(TipoNo));
  aux->valorx=x;
  aux->valory=y;
  aux->prox=NULL;
  if (filaVazia(fila)){
    fila->inicio=aux;
    fila->fim=aux;
  }
  else {
  fila->fim->prox = aux;
  fila->fim = aux;
  }
  fila->tamanho++;
}

int *Desenfileira(TipoFila *fila)
{
  TipoNo *q; int vx, vy;
  if (filaVazia(fila))
  {
    printf("Fila esta vazia\n");
    return nullptr;
  }
  q = fila->inicio;
  vx = fila->inicio->valorx;
  vy = fila->inicio->valory;
  fila->inicio = fila->inicio->prox;
  free(q);
  fila->tamanho--;
  int *v = new int();
  v[0]=vx;
  v[1]=vy;
  return v;
}

void Imprime(TipoFila *fila)
{
  TipoNo *aux;
  aux = fila->inicio;
  while (aux != NULL)
    {
      cout<<aux->valorx<<" "<<aux->valory<<endl;
      aux = aux->prox;
    }
}

void showLab(int **lab,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<lab[i][j]<<" ";
        }
        cout<<endl;
    }

}

int **Caminho(int **lab, int n){
     TipoFila *fila = new TipoFila();
     IniciaFila(fila);
     TipoPilha *aux = new TipoPilha();
     IniciaPilha(aux);
     TipoPilha *pilha = new TipoPilha();
     IniciaPilha(pilha);
     /////////////////
     int **resp = new int*[n];
     for(int i=0;i<n;i++){
         resp[i]=new int[n];
         for(int j=0;j<n;j++){
             resp[i][j]=lab[i][j];
         }
     }
     //////////////
     lab[1][1]=1;
     int *vet = new int[2];
     vet[0]=1;
     vet[1]=1;
     Enfileira(vet[0],vet[1],fila);
     //////////////// Enfileira todo caminho possivel
     do{
         if(lab[vet[0]-1][vet[1]]==0){
            Enfileira(vet[0]-1,vet[1],fila);
            lab[vet[0]-1][vet[1]]=1;
         }
         if(lab[vet[0]][vet[1]+1]==0){
             Enfileira(vet[0],vet[1]+1,fila);
             lab[vet[0]][vet[1]+1]=1;
         }
         if(lab[vet[0]+1][vet[1]]==0){
             Enfileira(vet[0]+1,vet[1],fila);
             lab[vet[0]+1][vet[1]]=1;
         }
         if(lab[vet[0]][vet[1]-1]==0){
             Enfileira(vet[0],vet[1]-1,fila);
             lab[vet[0]][vet[1]-1]=1;
         }
         Empilha(vet[0],vet[1],aux);
         vet=Desenfileira(fila);
     }while((vet[0]!=n-2) || (vet[1]!=n-2));
     //////////////////////
     Empilha(vet[0],vet[1],aux);
     vet = Desempilha(aux);
     int *auxiliar = new int[2];
     auxiliar=vet;
     Empilha(vet[0],vet[1],pilha);

     /////////////Compara com os vizinhos para achar caminho até 1,1
     do{
         vet=Desempilha(aux);
         if(vet[0]==auxiliar[0]){
             if(vet[1]-1==auxiliar[1]){
                 Empilha(vet[0],vet[1],pilha);
                 auxiliar=vet;
             }
             else if(vet[1]+1==auxiliar[1]){
                 Empilha(vet[0],vet[1],pilha);
                 auxiliar=vet;
             }
         }
         else if(vet[1]==auxiliar[1]){
             if(vet[0]-1==auxiliar[0]){
                 Empilha(vet[0],vet[1],pilha);
                 auxiliar=vet;
             }
             else if(vet[0]+1==auxiliar[0]){
                 Empilha(vet[0],vet[1],pilha);
                 auxiliar=vet;
             }
         }
     }while (vet[0]!=1 || vet[1]!=1);


     //Cria o caminho
     while(!pilhaVazia(pilha)){
         vet=Desempilha(pilha);
         resp[vet[0]][vet[1]]=1;
     }
    return resp;
}



int main()
{
    int n;
    cout<<"Tamanho labirinto (leve em conta as paredes externas)"<<endl;
    cin>>n;

    cout<<"Crie Labirinto e inclua as paredes externas"<<endl;

    int **lab = new int*[n];
    for(int i=0;i<n;i++){
        lab[i]=new int[n];
        cout<<"Linha "<<i<<endl;
        for(int j=0;j<n;j++){
            cin>>lab[i][j];
        }
    }

    int **result;

    result=Caminho(lab,n);
    cout<<"Result"<<endl;
    showLab(result,n);

    return 0;
}
