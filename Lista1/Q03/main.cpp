#include <iostream>

using namespace std;

int main()
{
    int n, i, j,numero;

    cout<<"Digite o numero n:"<<endl;
    cin>>n;
    cout<<"Digite o numero i:"<<endl;
    cin>>i;
    cout<<"Digite o numero j:"<<endl;
    cin>>j;

    int multiploi = 0;
    int multiploj = 0;


    for(int cont = 0; cont < n ; cont++){
       int valor_multiploi = multiploi*i;
       int valor_multiploj = multiploj*j;

       if(valor_multiploi == valor_multiploj){
           multiploi += 1;
           multiploj += 1;
           cout<<valor_multiploi<<", ";
       }else if(valor_multiploi < valor_multiploj){
           multiploi += 1;
           cout<<valor_multiploi<<", ";
       }else{
           multiploj += 1;
           cout<<valor_multiploj<<", ";
       }
    }

    return 0;
}
