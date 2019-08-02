#include <iostream>

using namespace std;

int main()
{
    int dias, dia_da_semana, n_blanks;

    cout<<"quantos dias tem no mes?"<<endl;
    cin>>dias;
    cout<<"em que dia da semana comeca o mes?"<<endl;
    cin>>dia_da_semana;

    n_blanks = dia_da_semana - 1 ;


    for (int i = 0; i < n_blanks; i++) {
        cout<<"  "<<"\t";
    }

    for (int i = 1, j = dia_da_semana; i <= dias ; i++,j++) {
        if((j-1) % 7 == 0){
            cout<<"\n";
        }
          cout << i <<"\t";
    }

    cout<<"\n";



    return 0;
}
