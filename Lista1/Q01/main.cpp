#include <iostream>

using namespace std;

int main()
{
    int num,consecutivo=0, digito, iguais;

    cout <<"Digite numero:"<<endl;
    cin >> num;
    do{


        digito = num % 10;//resto da divisao por 10 resulta no digito corrente
        if(digito == consecutivo){
            iguais = 1;
            break;
        }else{
            iguais = 0;
        }
        consecutivo = digito;//atualiza o digito que vai ser comparado
        num = num/10;//restante do numero para proxima iteracao


    }while(num != 0);

    if(iguais == 1){
        cout << "Ha numeros iguais adjacentes" << endl;
    }else{
        cout << "Nao ha numeros iguais adjacentes" << endl;
    }

    return 0;
}
