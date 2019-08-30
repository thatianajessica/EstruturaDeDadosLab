#include <iostream>

using namespace std;

int buscaBinariaRecurssiva(int *vec, int n_elements, int elemento_buscado, int inferior, int superior){
    if(superior >= n_elements || inferior >= n_elements){
        return -1;
    }
    if(superior < 0 || inferior <0){
        return -1;
    }


    if(inferior > superior){
        return -1;
    }
    int meio = (inferior+superior)/2;
    if(vec[meio] == elemento_buscado){
        return meio;
    }
    else if(vec[meio] > elemento_buscado){
        return buscaBinariaRecurssiva(vec, n_elements, elemento_buscado, inferior, meio -1);
    }else{
        return buscaBinariaRecurssiva(vec, n_elements,elemento_buscado, meio+1, superior);
    }

}

int main()
{
    int vec[5] = {1,2,3,4,5};
    int elemento = 4;

    int resposta = buscaBinariaRecurssiva(vec,5,elemento,0,4);


    cout << resposta << endl;
    return 0;
}
