#include <iostream>

using namespace std;

int main()
{
    int num;
    cout<<"Digite o numero:"<<endl;
    cin>>num;


    for (int i=0;;i++) {
        int valor = i*(i+1)*(i+2);
        if(valor == num){
            cout<<"Numero eh triangular"<<endl;
            cout<<i<<"*" <<i+1<<"*"<<i+2<<endl;
            break;
        }
        if(valor > num){//varreu ate o proprio numero
            break;
        }
    }

    return 0;
}
