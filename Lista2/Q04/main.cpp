#include <iostream>

using namespace std;

void interseccao(int A[100+1], int B[100+1], int C[100+1]){
    int n_elementsC = 0;
    for (int i = 1; i < A[0]; i++) {
        for (int j = 1; j < B[0]; j++) {
            if(A[i] == B[j]){
                C[n_elementsC+1] = A[i];
                n_elementsC += 1;
        }
        }
        C[0] = n_elementsC;
    }
}

int main()
{
    int A[5] = {5, 2, 3, 4, 5};
    int B[4] = {4, 5, 6, 2};
    int C[5] = {0, 0, 0, 0, 0};

    interseccao(A,B,C);

    for (int i = 0 ; i < 5; i++) {
        cout <<C[i] <<" ";
    }
    cout << endl;
    return 0;
}
