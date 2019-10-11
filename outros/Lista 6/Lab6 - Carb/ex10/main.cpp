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
} TipoFila;

void IniciaFila(TipoFila *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho=0;
}

bool filaVazia(TipoFila *fila)
{
  return (fila->inicio == NULL);
}

void Enfileira(int x, TipoFila *fila)
{
  TipoNo *aux;
  aux = (TipoNo *) malloc(sizeof(TipoNo));
  aux->valor=x;
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

int Desenfileira(TipoFila *fila)
{
  TipoNo *q; int v;
  if (filaVazia(fila))
  {
    printf("Fila esta vazia\n");
    return 0;
  }
  q = fila->inicio;
  v = fila->inicio->valor;
  fila->inicio = fila->inicio->prox;
  free(q);
  fila->tamanho--;
  return v;
}

int calculo(TipoFila *fila, int x){
    int resp = 0;
    int cont =0;
    int indice;

    while(!filaVazia(fila)){
        indice = Desenfileira(fila);
        int op = 1;
        for(int i=0;i<cont;i++){
            op=op*x;
        }
        resp += indice*op;
        cont++;
    }
    return resp;
}

Fila *somaPol(Fila *P, Fila *Q, int t){
    Fila *R = new Fila();
    IniciaFila(R);
    int temp,temp1;
    for(int i=0;i<t;i++){
        temp = Desenfileira(P);
        temp1 = Desenfileira(Q);
        temp +=temp1;
        Enfileira(temp,R);
    }
    return R;
}

Fila *multPol(Fila *P, Fila *Q, int t){
    int ind[2*t];
    int t1[t],t2[t];
    Fila *Res = new Fila();

    for(int i=0;i<t;i++){
        t1[i] = Desenfileira(P);
        t2[i] = Desenfileira(Q);
        for(int j=0;j<t;j++){
            ind[i+j]=0;
        }
    }

    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            ind[i+j]+= t1[i]*t2[j];
        }
    }
    for(int i=0;i<2*t;i++){
        Enfileira(ind[i],Res);
    }
    return Res;

}

int main()
{
    TipoFila *P = new TipoFila();
    IniciaFila(P);
    TipoFila *Q = new TipoFila();
    IniciaFila(Q);
    cout<<"Grau do polinomio P"<<endl;
    int n;
    cin>>n; n++; //0 a n, não 0 a n-1
    cout<<"Insira indices A0 ate An, coloque 0 quando nao houver"<<endl;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        Enfileira(temp,P);
    }
    cout<<"Grau do polinomio Q"<<endl;
    int m;
    cin>>m; m++; //0 a n, não 0 a n-1
    cout<<"Insira indices A0 ate An, coloque 0 quando nao houver"<<endl;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        Enfileira(temp,Q);
    }

    ////Se os graus forem diferentes:
    while(m>n){
        Enfileira(0,P);
        n++;
    }
    while(n>m){
        Enfileira(0,Q);
        m++;
    }
    ////

    Fila *R = multPol(P,Q,n);

    for(int i=0;i<2*n;i++){
        cout<<Desenfileira(R)<<" ";
    }
    cout<<endl;

    return 0;
}
