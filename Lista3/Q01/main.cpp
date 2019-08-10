#include <iostream>

using namespace std;

int fibonacci(int n){

    if(n < 2){
        return n;
    }else{
        int n_1 = fibonacci(n-1);
        int n_2 = fibonacci(n-2);
        int result = n_1 + n_2;
        return result;
    }
}


int main(int argc, char *argv[])
{
    int n, resultado;

    cout << "Digite um valor inteiro para n:" << endl;
    cin >> n;

    resultado = fibonacci(n);

    cout << "O " <<n <<" termo da sequencia de fibonacci eh = " <<resultado << endl;
    return 0;
}
