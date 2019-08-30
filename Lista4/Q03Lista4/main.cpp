#include <iostream>

using namespace std;

void insertionSortRec(int *vec, int n){
    if (n <= 1){
        return;
    }
    insertionSortRec(vec, n-1);
    int chave = vec[n-1];
    int j = n-2;
    while (j >= 0 && vec[j] > chave)
    {
        vec[j + 1] = vec[j];
        j = j - 1;
    }
    vec[j + 1] = chave;
    return;
}
//T(1) = 2
//T(2) = 1 + T(1) + 2+ sumj=1 ate 1 (2+2) + 2
//T(3) = 1 + T(2) + 2+ sumj=1 ate 2 (2+2) + 2
//     = 1 + [ 1 + T(1) + 2 + sumj=1 ate 1 (2+2) + 2 ] + 2 + sumj=1 ate 2 (2+2) + 2
//     = (3 - 1) + (4*(3-1)) + T(1) + sumj=1 ate (3-1) (4*(3-j))


//T(n) = 1 + T(n-1) + 2 + sumj=1 ate n-1 (2+2) + 2


int main()
{
    int vec[6] = {3, 1, 5, 10, 9, 7};
    int tam_vec = 6;

    insertionSortRec(vec,tam_vec);

    for (int i = 0; i < tam_vec; i++) {
        cout <<vec[i]<< " ";
    }

    cout << endl;
    return 0;
}
