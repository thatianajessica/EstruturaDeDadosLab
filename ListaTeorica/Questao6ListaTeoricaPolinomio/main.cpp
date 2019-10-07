#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    struct No *prox;
}No;

typedef struct Lista{
    int n;
    No *cabeca;
}Lista;

No* criarNo(int chave){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->chave = chave;
    return novo_no;
}

Lista* criarListaVazia(){
    Lista *nova_lista = new Lista;
    nova_lista->cabeca = NULL;
    nova_lista->n = 0;
    return nova_lista;
}

void adicionaListaCauda(Lista *lista, No *no_adc){
    if (lista->cabeca == NULL){
        lista->cabeca = no_adc;
        //lista->cabeca->prox = lista->cabeca;
    }else{
        No *cauda = lista->cabeca;
        for (int i = 0 ; i < ((lista->n)-1); i++) {
            cauda = cauda->prox;
        }
        cauda->prox = no_adc;
        //no_adc->prox = lista->cabeca;
    }
    lista->n += 1;
}

No* copiaNo(No *no){
    No *copia = criarNo(no->chave);
    return copia;
}

void adicionaListaCaudaCopia(Lista *lista, No *no_adc){
    adicionaListaCauda(lista,copiaNo(no_adc));
}

void adicionaListaCabeca(Lista *lista, No *no_adc){
    if (lista->cabeca == NULL){
        lista->cabeca = no_adc;
        //no_adc->prox = lista->cabeca;
    }else{
        // No *aux;
        // aux = lista->cabeca;
        // for (int cont = 0; cont < lista->n-1; cont++) {
        //     aux = aux->prox;
        // }
        // aux->prox = no_adc;
        no_adc->prox = lista->cabeca;
        lista->cabeca = no_adc;

    }
    lista->n += 1;
}

void printarLista(Lista *lista){
    if(lista->n > 0);
    {
        No *aux = lista->cabeca;
        for(int i = 0; i < lista->n; i++){
            cout << aux->chave <<" ";
            aux = aux->prox;
        }
    }
    cout << endl;
}

void printarLista2(Lista *lista){
    bool lista_existe = true;
    if(lista->n > 0);
    {
        No *aux = lista->cabeca;
        while(lista_existe == true){
            cout << aux->chave <<" ";
            aux = aux->prox;
            if(aux == lista->cabeca){
                lista_existe = false;
            }

        }

    }
    cout << endl;
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
        aux->prox = lista->cabeca;//mudei aqui
        //aux->prox = NULL;
        lista->n = lista->n - 1;
    }
}

void removerCabeca(Lista *lista){
    if(lista->n == 0 ){
        return;
    }else{
        No *aux = lista->cabeca->prox;
        lista->cabeca = aux;
        lista->n -= 1;
    }
}

void removerNoN(Lista *lista, int no_remover){
    if(lista->n == 0){
        cout <<"Lista vazia" <<endl;
    }else{
        if(no_remover == 0){
            removerCabeca(lista);
        }else if(no_remover == lista->n-1){
            removerCauda(lista);
        }else{
            int no_atual = 0;
            No *aux = lista->cabeca;
            No *anterior;
            while(no_atual < no_remover){
                anterior = aux;
                aux = aux->prox;
                no_atual +=1;
            }
            aux = aux->prox;
            anterior->prox = aux;
        }
    }
}

void inserirNoN(Lista *lista, int posicao_inserir, int chave){
    No *novo_no = criarNo(chave);
    if(lista->n == 0){
        lista->cabeca = novo_no;
        lista->cabeca->prox = lista->cabeca;
        lista->n += 1;
    }else{
        No *aux = lista->cabeca;
        for (int cont = 0; cont <posicao_inserir-1; cont++) {
            aux = aux->prox;
        }
        novo_no->prox = aux->prox;
        aux->prox= novo_no;
        lista->n +=1;
    }
}

No* getNo(Lista *lista, int index){
    No* out = NULL;
    if(lista->n == 0){
        cout <<"Lista vazia" << endl;
    }else if(index > lista->n-1 || index < 0){
        cout <<"No nao existente" <<endl;
    }else{
        No* aux = lista->cabeca;
        int indice_atual = 0;

        while ( (aux != NULL) && (indice_atual != index)  ) {
            aux = aux->prox;
            indice_atual += 1;
        }
        out = aux;
    }
    return out;
}

void printLista(No *cabeca) {
    No *current_node = cabeca;
    while ( current_node != cabeca)
    {
        cout <<current_node->chave << " ";
        current_node = current_node->prox;
    }
    cout << endl;
}

float computePolinomio(Lista* p, float x)
{
    float x_acc = 1;
    No* aux = p->cabeca;
    float res = 0;
    while(aux != NULL)
    {
        res += aux->chave * x_acc;
        aux = aux->prox;
        x_acc *= x;
    }
    return res;
}

Lista* addPolinomio(Lista* p1, Lista* p2)
{
    Lista* p3 = criarListaVazia();
    No* aux1 = p1->cabeca;
    No* aux2 = p2->cabeca;

    while( (aux1 != NULL) || (aux2 != NULL)  )
    {
        float coef1 = 0;
        float coef2 = 0;

        if( (aux1 != NULL)  ){
            coef1 = aux1->chave;
        }

        if( (aux2 != NULL)  ){
            coef2 = aux2->chave;
        }

        No* no = criarNo( coef1 +  coef2);
        adicionaListaCauda(p3, no);

        if( (aux1 != NULL)   )
        {
            aux1 = aux1->prox;
        }

        if( (aux2 != NULL)  )
        {
            aux2 = aux2->prox;
        }

    }
    return p3;
}

int computa_ordem_polinomio(Lista* p)
{
    No* aux = p->cabeca;
    float res = 0;
    int ordem = -1;
    while(aux != NULL)
    {
        ordem++;
        aux = aux->prox;
    }
    return ordem;

}

Lista* mulPolinomio(Lista* p1, Lista* p2)
{
    int ordem1 = computa_ordem_polinomio(p1);
    int ordem2 = computa_ordem_polinomio(p2);
    int n_nos = ordem1 + ordem2 + 1;
    Lista* p3 = criarListaVazia();
    for(int i=0; i<n_nos ; i++)
    {
        No* no = criarNo(0);
        adicionaListaCabeca(p3, no);
    }


    int ordem_atual_no1 = 0;
    No* aux1 = p1->cabeca;
    while( aux1 != NULL  )
    {
        int ordem_atual_no2 = 0;
        No* aux2 = p2->cabeca;
        while( aux2 != NULL  )
        {
            int ordem_termo = ordem_atual_no1 + ordem_atual_no2;
            No* no = getNo(p3, ordem_termo);
            no->chave += aux1->chave * aux2->chave;

            aux2 = aux2->prox;
            ordem_atual_no2++;
        }
        aux1 = aux1->prox;
        ordem_atual_no1++;

    }
    return p3;
}

int main()
{
    // 5x^2 - 2x + 3
    Lista* P = criarListaVazia();
    No* no1 = criarNo(5);
    No* no2 = criarNo(-2);
    No* no3 = criarNo(3);
    adicionaListaCabeca(P, no1);
    adicionaListaCabeca(P, no2);
    adicionaListaCabeca(P, no3);

    // x^3 + 3x^2 - 5x - 1
    Lista* Q = criarListaVazia();
    No* no4 = criarNo(1);
    No* no5 = criarNo(3);
    No* no6 = criarNo(-5);
    No* no7 = criarNo(-1);
    adicionaListaCabeca(Q, no4);
    adicionaListaCabeca(Q, no5);
    adicionaListaCabeca(Q, no6);
    adicionaListaCabeca(Q, no7);

    Lista* PaddQ = addPolinomio(P, Q);
    Lista* PmulQ = mulPolinomio(P, Q);

    printarLista(P);
    printarLista(Q);
    printarLista(PaddQ);
    printarLista(PmulQ);


    float x = 2;

    float res_p = computePolinomio(P, x);
    float res_q = computePolinomio(Q, x);
    float res_paddq = computePolinomio(PaddQ, x);
    float res_pmulq = computePolinomio(PmulQ, x);


    cout << "res_p: " << res_p << endl;
    cout << "res_q: " << res_q << endl;
    cout << "res_paddq: " << res_paddq << endl;
    cout << "res_pmulq: " << res_pmulq << endl;

    cout << "ordem_p: " << computa_ordem_polinomio(P) << endl;
    cout << "ordem_q: " << computa_ordem_polinomio(Q) << endl;

    return 0;
}
