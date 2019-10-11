#include <iostream>

using namespace std;

unsigned int mdc(unsigned int x, unsigned int y) {

    unsigned int termo_multiplicativo = 1;
    unsigned int multiplo_comum = 2; //temos que começar em dois, pois em 1 não sairíamos do lugar

    if (x == 0) {
        return y;
    } else if (y==0) {
        return x;
    }

    while (multiplo_comum < x && multiplo_comum < y) {
        if (x%multiplo_comum == 0 && y%multiplo_comum == 0) {
            termo_multiplicativo = termo_multiplicativo*multiplo_comum;
            x = x/multiplo_comum;
            y = y/multiplo_comum;
        } else {
           multiplo_comum++;
        }
    }

    return termo_multiplicativo;
}


//outra forma, pelo algoritmo de Euclides propriamente dito!
/*unsigned int mdc(unsigned int x, unsigned int y) {
    unsigned int resto = x%y;
    unsigned int divisor = y;
    unsigned int dividendo = x;

    do{
        dividendo = divisor;
        divisor = resto;
        resto = dividendo%divisor;
    } while(y != 0);

    return divisor;
}
*/
int main() {
    unsigned int x;
    unsigned int y;

    cout << "Digite um valor para 'x': ";
    cin >> x;
    cout << "Digite um valor para 'y': ";
    cin >> y;

    cout << "o MDC(" << x << ", " << y <<") = " << mdc(x,y) << endl;


    return 0;
}
