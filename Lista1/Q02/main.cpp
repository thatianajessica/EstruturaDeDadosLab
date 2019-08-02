#include <iostream>

using namespace std;

int main()
{
    int num, digito, cont=0, ultimo=-1;

    cout <<"Digite numero:"<<endl;
    cin >> num;
    do{


        digito = num % 10;//resto da divisao por 10 resulta no digito corrente
        num = num/10;//restante do numero para proxima iteracao

        if(cont == 0){
            ultimo = digito;//ultimo digito do numero
        }
        cont++;
//        cout <<"num:"<<digito << endl;
//        cout <<"primeiro:"<<ultimo << endl;

    }while(num != 0);



    if(ultimo == digito){
        cout << "Primeiro e ultimo digito iguais" << endl;
    }else{
        cout << "Primeiro e ultimo digito diferentes" << endl;
    }

    return 0;
}
