#include <iostream>

using namespace std;

int main()
{
    int m, n, maior = 0, resultado = 0, maior_n = 0, maior_m = 0;

    cout << "Insira o primeiro limite:" << endl;
    cin >> m;
    cout << "Insira o segundo limite:" << endl;
    cin >> n;

    for(int x = 0; x <= m; x++){
        for(int y = 0; y <=n; y++){
            resultado = (x*y)-(x*x)+y;
            if(resultado > maior){
                maior = resultado;
                maior_n = y;
                maior_m = x;
            }
        }
    }
    cout << "(" << maior_m << "," << maior_n <<")" << endl;
    cout << "Maior resultado = " << maior << endl;
    return 0;
}
