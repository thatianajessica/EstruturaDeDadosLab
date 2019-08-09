#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n, n_1 = 0, n_2 = 1, resposta = 1;


    cout << "Digite um valor inteiro para n:" << endl;
    cin >> n;

    if (n >= 2){
       for (int i = 2; i<= n; i++){//n-2
           resposta = n_1 + n_2;
           n_1 = n_2;
           n_2 = resposta;
           cout << resposta << endl;
       }
    }




    return 0;
}
