#include <iostream>


using namespace std;

int main()
{
    int numero, hipotenusa = 0;

    cout << "Insira um numero inteiro:" << endl;
    cin >> numero;

    for (int i = 1; i <= numero; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k < j; k++){
                hipotenusa = (k*k + j*j);
                if(i*i == hipotenusa){
                    cout << "Hipotenusa= " <<i << endl;

                    cout << "cateto1= " <<j << endl;

                    cout << "cateto2= " <<k << endl;
                }
            }
        }
    }
return 0;
}
