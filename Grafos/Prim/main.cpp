#include <iostream>

using namespace std;

typedef struct aresta{
    int vi;
    int vo;
    int peso;
} A;

bool marca [6];
void prim(A Va[]){
    int cont = 0, contArvore = 0;
    A menorPeso;
    A nulo;
    nulo.vi = 0;
    nulo.vo = 0;
    nulo.peso = 99999;
    menorPeso.peso = 999999;
    A Vcorte[10];
    A Varvore[6];
    int select = Va[0].vi;
    marca[select] = 1;
    for(int i = 0; i<5; i++){
        Vcorte[i] = nulo;
    }
    for(int i = 0; i<5; i++){
        if(Va[i].vi == select){
            Vcorte[cont] = Va[i];
            cont++;
        }
    }

    while (contArvore < 4){
        //ARESTA DE MENOR PESO
        for(int i = 0; i<5; i++){
            if(Vcorte[i].peso < menorPeso.peso){
                menorPeso = Vcorte[i];
            }
        }
        cout<<"Aresta de Menor Peso"<<endl;
        cout<<menorPeso.vi<<"|||"<<menorPeso.vo<<endl;
        //ADICIONA NA ARVORE
        Varvore[contArvore] = menorPeso;
        contArvore++;
        //EXCLUI ARESTA DO CORTE
        for(int i = 0; i<5; i++){
            if(Vcorte[i].vi == menorPeso.vi && Vcorte[i].vo == menorPeso.vo){
                Vcorte[i] = nulo;
            }
        }
        select = menorPeso.vo;
        cout<<select<<endl;
        marca[menorPeso.vo] = 1;
        marca[menorPeso.vi] = 1;
        for(int i = 0; i<6; i++){
            if((Va[i].vi == select && marca[Va[i].vo] == 0) || Va[i].vo == select && marca[Va[i].vi] == 0){
                Vcorte[cont] = Va[i];
                cont++;
            }
        }

        cout<<endl;
        cout<<"Vetor de Marca"<<endl;
        for(int i = 0; i<6; i++){
            cout<<marca[i]<<" ---- ";
        }
        cout<<endl;
        cout<<"Vetor de corte"<<endl;
        for(int i = 0; i<5; i++){
            cout<<Vcorte[i].vi<<" || "<<Vcorte[i].vo<<" ---- ";
        }
        menorPeso = nulo;
    }
}

int main(int argc, char *argv[])
{
    for(int i = 0; i<5; i++){
        marca[i] = 0;
    }
    A a1; a1.vi = 1; a1.vo = 3; a1.peso = 2;
    A a2; a2.vi = 1; a2.vo = 5; a2.peso = 3;
    A a3; a3.vi = 2; a3.vo = 3; a3.peso = 10;
    A a4; a4.vi = 2; a4.vo = 4; a4.peso = 4;
    A a5; a5.vi = 2; a5.vo = 5; a5.peso = 5;
    A Varesta[5] = {a1,a2,a3,a4,a5};
    prim(Varesta);
    return 0;
}
