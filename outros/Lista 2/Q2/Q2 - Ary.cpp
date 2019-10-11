#include <iostream>
#include <math.h>
using namespace std;

void quebra(int n, int &prim, int &ult, int &miolo){
    ult = n%10;
    int cont = 0, hold = n;
    miolo = n/10;
    while(n>10){
        n = n/10;
        cont++;
    }
    prim = n;
    miolo = (hold - (pow(10,cont)*prim))/10;

}
bool palindromo(int n){
    int prim, ult, miolo;
    int ndigitos, holder = n;
    while(holder>=10){
        holder = holder /10;
        ndigitos++;
    }
    for(int i = 0; i<ndigitos/2; i++){
        quebra(n, prim, ult, miolo);
        if(prim != ult){
            return false;
        }
    }
    return true;
}

int main(){
    int n, prim, ult, miolo;
    cout<<"Digite o valor: "<<endl;
    cin>>n;
    quebra(n, prim, ult, miolo);
    cout<<"Primeiro: "<<prim<<" Miolo: "<<miolo<<" Ultimo: "<<ult<<endl;
    cout<<palindromo(n);
    return 0;
}