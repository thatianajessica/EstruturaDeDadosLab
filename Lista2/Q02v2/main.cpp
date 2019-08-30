#include <iostream>

using namespace std;

void quebra (int n, int &prim, int &ult, int &miolo){
    int base=1;
    int temp=n;
    while (temp>=10){
        temp=temp/10;
        base=base*10;
    }
    prim = n/base;
    ult = n%10;

    miolo=n-prim*base;
    miolo=miolo/10;
}

bool palindromo(int n){
    int prim,ult,miolo;
    int dig=1;
    int temp=n;
    while (temp>=10){
        temp=temp/10;
        dig++;
    }
    dig=dig/2;

    for(int i=0;i<dig;i++){
        quebra(n,prim,ult,miolo);
        if(prim!=ult){
            return false;
        }
    }
    return true;
}

int main(){
    int n;

    cin>>n;

    cout<<palindromo(n)<<endl;

    return 0;
}
