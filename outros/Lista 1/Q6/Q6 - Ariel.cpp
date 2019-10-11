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


int main() {

    unsigned int num1, num2;

    cout << "digite um valor para o 'num1': ";
    cin >> num1;
    cout << "digite um valor para o 'num2': ";
    cin >> num2;

    cout << endl << endl << "fracao inicial: " << num1 << "/" << num2 << endl;
    cout << "fracao reduzida: " << num1/mdc(num1,num2) << "/" << num2/mdc(num1,num2) << endl;

    return 0;
}
