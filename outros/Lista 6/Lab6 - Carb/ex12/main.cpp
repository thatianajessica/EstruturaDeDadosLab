#include <iostream>

using namespace std;

typedef struct s{
    int chave; // chave (conteúdo armazenado)
    struct s *next; // ponteiro para o próximo elemento
    struct s *prev; // ponteiro para o elemento anterior
} No;

/*
Aloca o cabeça e retorna seu ponteiro .
Dada a alocaçao do nó cabeça, temos, pois, a uma lista vazia
*/
No *criarCabeca(){
    No *cabeca = new No (); // alocaçao
    if (cabeca!=NULL){ // apenas pra verificar se a alocaçao foi bem sucedida
        cabeca->chave = -1; // Somente pra dizer que o conteudo da cebça é desprezível
        cabeca->next = cabeca; // lista vazia
        cabeca->prev = cabeca; // lista vazia
    }
    return cabeca;
}
// busca em lista duplamente encadeada com cabeça
// recebe a chave a ser buscada x, bem como a cabeça da lista
// retorna o ponteiro para o elemento encontrado
// Se o elemento nao for encontrado, entao retorna um ponteiro para onde o elemento "v",
// onde "v" possui a menor chave maior que x (ou seja, x deveria estar imediatamente antes de "v")
// complexidade O(n), onde n é a quantidade de elemento da lista
No * busca(No *cabeca, char x){
    No * ultimo = cabeca->prev; // pega o ultimo elemento da lista
    if(x<'A'){
        if (x<=ultimo->chave || ultimo->chave<'A'){
            No *aux = cabeca->next;
            while (aux->chave <x) aux = aux->next;
            return aux;
        } else return cabeca->prev;
    }
    else{
        return cabeca;
    }
}


// Insere um novoValor na lista
// recebe o no cabeça e o novoValor
// Nao permite elementos com chave repetidas
// Exercício: modificar esta implementaçao para permitir elementos repetidos =)
void insertInic(No *cabeca, int novoVaor){
    No *newNo = new No();
    No *aux = cabeca->next;
    cabeca->next = newNo;
    aux->prev = newNo;

    newNo->prev = cabeca;
    newNo->next = aux;
    newNo->chave = novoVaor;


}

void insertFim(No *cabeca, int novoVaor){
    No *newNo = new No();
    No *aux = cabeca->prev;
    cabeca->prev = newNo;
    aux->next = newNo;

    newNo->prev = aux;
    newNo->next = cabeca;

    newNo->chave = novoVaor;
}

void removeInic(No *cabeca){
    No *aux = cabeca->next;
    cabeca->next = aux->next;
    aux->next->prev = cabeca;
    delete aux;
}

void removeFim(No *cabeca){
    No *aux = cabeca->prev;
    cabeca->prev = aux->prev;
    aux->prev->next= cabeca;
    delete aux;
}


// Imprime a lista da cabeça até o último elemento (ordem crescente)
void printDireto(No *cabeca){
    No *aux = cabeca->next;
    while (aux!=cabeca){
        cout<<aux->chave<<" ";
        aux = aux->next;
    }
    cout<<endl;
}

// Imprime a lista do último elemento até a cabeça (ordem decrescente)
void printInverso(No *cabeca){
    No *aux = cabeca->prev;
    while (aux!=cabeca){
        cout<<aux->chave<<" ";
        aux = aux->prev;
    }
    cout<<endl;
}
int main()
{
    No *cabeca = criarCabeca();
    int x;
    cout<<"Inserir comeco, 0 termina etapa"<<endl;
    while(1){
        cin>>x;
        if(x==0){
            break;
        }
        insertInic(cabeca,x);
    }

    cout<<"Inserir fim, 0 termina etapa"<<endl;
    while(1){
        cin>>x;
        if(x==0){
             break;
        }
        insertFim(cabeca,x);
    }
    cout<<"Remocao inic , insira qualquer numero diferente de 0 pra remover, e 0 pra terminar"<<endl;
    while(1){
        cin>>x;
        if(x==0){
             break;
        }
        removeInic(cabeca);
    }
    cout<<"Remocao fim , insira qualquer numero diferente de 0 pra remover, e 0 pra terminar"<<endl;
    while(1){
        cin>>x;
        if(x==0){
             break;
        }
        removeFim(cabeca);
    }

    printDireto(cabeca);
    cout<<endl;


    return 0;
}
