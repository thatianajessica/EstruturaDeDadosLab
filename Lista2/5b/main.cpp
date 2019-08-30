#include <iostream>

using namespace std;

void intercala(int *vec1, int tam_vec1, int *vec2, int tam_vec2, int *vec3, int &tam_vec3){
    tam_vec3 = tam_vec1 + tam_vec2;
    int i = 0, j = 0;
    if(tam_vec1 < tam_vec2){

    }
    for (int k = 0; k < tam_vec3; k++) {
        if(vec1[i] <= vec2[j]){
            vec3[k] = vec1[i];
            cout <<"Elemento do vetor da esquerda:" <<vec3[k] <<endl;
            i += 1;
        }else{
            vec3[k] = vec2[j];
            cout <<"Elemento do vetor da direita:" <<vec3[k] <<endl;
            j += 1;
        }
    }
}

int main()
{
    int vec1[3] = {3, 4, 5};
    int vec2[5] = {1, 2, 3, 4, 5};
    int n_1 = 3;
    int n_2 = 5;
    int n_3 = n_1+n_2;
    int *vec3 = new int[n_3];

    for (int i = 0; i < n_1; i++) {
        cout << vec1[i] << " ";
    }

    cout << "##############################" <<endl;
    for (int i = 0; i < n_2; i++) {
        cout << vec2[i] << " ";
    }
    cout << endl;
    cout << "##############################" <<endl;

    intercala(vec1,n_1,vec2,n_2, vec3, n_3);


    cout << endl;
    cout << "##############################" <<endl;

    for (int i = 0; i < n_3; i++) {
        cout << vec3[i] << " ";
    }


    cout << endl;
    return 0;
}
