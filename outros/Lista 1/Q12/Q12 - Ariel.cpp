#include <iostream>

using namespace std;

//minha expressão é xy - x^2 + y
int maximo(int &m, int &n) {    //passo por referência para poder fazer múltiplos retornos
    int maximo = 0;

    int m_aux = m, n_aux = n;   //precisamos de variáveis auxiliares para os índices, pq 'm' e 'n' estão mudando.
    for (int x=0; x<=m_aux; x++) {
        for (int y=0; y<=n_aux; y++) {
            if (x*y - x*x + y > maximo) {
                maximo = x*y - x*x + y;
                m = x;
                n = y;
            }
        }
    }

    return maximo;
}


int main() {

    int m, n;

    cout << "Digite um valor para 'm': ";
    cin >> m;
    cout << endl << "Digite um valor para 'n': ";
    cin >> n;
    cout << endl;

    int m_aux = m, n_aux = n; //armazenando só para facilitar a apresentação das informações

    cout << "o valor maximo da expressao para os numeros m = " << m_aux << " e n = " << n_aux << " eh: " << maximo(m,n) << " e o par eh (" << m << ", " << n <<")." << endl;

    return 0;
}
