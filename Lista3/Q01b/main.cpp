#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;


    cout << "Digite um valor inteiro para n:" << endl;
    cin >> n;

    int *vetor_seq = new int[n];

    vetor_seq[0] = 0;
    vetor_seq[1] = 1;

    if(n >= 2){

        for (int i = 2; i <= n; i++){
            vetor_seq[i] = vetor_seq[i-1] + vetor_seq[i-2];
            cout <<vetor_seq[i]<<endl;
        }
    }

    return 0;
}
