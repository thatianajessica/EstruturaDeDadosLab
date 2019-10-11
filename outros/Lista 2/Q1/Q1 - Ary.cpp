#include <vector>
#include <iostream>
using namespace std;

void cedulas(float v, int &um, int &cinco, int &dez, int &vin){
    vin = v/20;
    v = v - (vin*20);
    dez = v/10;
    v = v - (dez*10);
    cinco = v/5;
    v = v - (cinco*5);
    um = v;
    cout<<"Numero de cedulas: Vinte:"<<vin<<" DEZ:  "<<dez<<" CINCO: "<<cinco<<" UM: "<<um;
}
int main(){
    int v, um, cinco, dez, vin;
    cout<<"Digite o valor: "<<endl;
    cin>>v;
    cedulas(v,um,cinco,dez,vin);
    return 0;
}