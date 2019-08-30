#include <iostream>

using namespace std;

int FibonacciIterativa(int n, int k){
    int *fn = new int[n];
    int resultado = 0;
    for (int i = 1; i <= n; i++) {
        if(i <= k){
            fn[i-1] = n-1;
        }else{
            fn[i-1] = fn[i-2] + fn[i-3];
        }
    }
    resultado = fn[n-1];
    for (int i = 0; i < n-1; i++) {
       cout <<fn[i] <<" ";
    }
    cout <<endl;

    delete[]fn;
    return resultado;
}

int main()
{
    int k = 3;
    int n = 5;

    int result = FibonacciIterativa(n, k);



    cout << result << endl;
    return 0;
}
