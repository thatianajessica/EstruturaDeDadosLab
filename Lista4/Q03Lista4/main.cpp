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
}

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
