#include <iostream>

using namespace std;

void cedulas(float v, int &um, int &cinco, int &dez, int &vin){
    int value = v;
    vin = value/20;
    value = value % 20;
    dez = value/10;
    value = value % 10;
    cinco = value/5;
    value = value % 5;
    um = value;

}

int main()
{
    float valor = 0;
    int um = 0, cinco = 0, dez = 0, vin = 0;


    cout << "Insira o valor que deseja sacar" << endl;
    cin >> valor;

    cedulas(valor, um, cinco, dez, vin);

    cout << "Cedulas de 20= " << vin << endl;
    cout << "Cedulas de 10= " << dez << endl;
    cout << "Cedulas de 5= " << cinco << endl;
    cout << "Cedulas de 1= " << um << endl;

    return 0;
}
