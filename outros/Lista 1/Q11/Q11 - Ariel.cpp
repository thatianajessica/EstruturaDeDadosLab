#include <iostream>
#include <cmath> //para usar o pow()

using namespace std;

void printar_hipotenusas(int tamanho_maximo) {
    int cateto1, cateto2, hipotenusa;
    bool flag_hipotenusa_ja_achada;

    //para todas as hipotenusas
    for (hipotenusa = 1; hipotenusa <= tamanho_maximo; hipotenusa++) {
        flag_hipotenusa_ja_achada = false;

        //para todos os catetos
        for (cateto1 = 1; cateto1 <= tamanho_maximo && !flag_hipotenusa_ja_achada; cateto1++) {
            cateto2 = cateto1;

            //pode parar quando for uma igualdade ou quando a desigualdade não valer mais
            while(pow(cateto1, 2) + pow(cateto2, 2) < pow(hipotenusa, 2)) {
                cateto2++;
            }

            if(pow(cateto1, 2) + pow(cateto2, 2) == pow(hipotenusa, 2)) {
                cout << hipotenusa << " ";
                flag_hipotenusa_ja_achada = true;
            }
        }
    }

}




int main() {

    int numero;

    cout << "digite um numero qualquer: ";
    cin >> numero;
    cout << endl;

    printar_hipotenusas(numero);

    cout << endl;


    return 0;
}
