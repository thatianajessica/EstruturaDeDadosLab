#include <iostream>

using namespace std;

//função para printar o calendário.

void printar_calendario (int qtd_dias_mes, int dia_comeca) {

    int cont = 1;   //variável de formatação
    int dia_printavel = 1; //variável para printar o dia

    while(dia_printavel <= qtd_dias_mes){

        if (cont < dia_comeca) {
            cout << "\t";
        } else {
            cout << dia_printavel << "\t";
            dia_printavel++;
        }

        if (cont%7 == 0) {
            cout << endl;
        }

        cont++;

    }

    cout << endl << endl;

}

int main () {

    //note que, dia que começa é uma variável de formatação visual e qtd_dias_mes é uma variável que ditará o dia a ser printado!
    int qtd_dias_mes, dia_comeca;

    cout << "Qual a quantidade de dias do mes? ";
    cin >> qtd_dias_mes;
    cout << endl << "Em qual dia da semana ele comeca? (de 1 -> domingo a 7 -> sabado)    ";
    cin >> dia_comeca;
    cout << endl;

    printar_calendario(qtd_dias_mes, dia_comeca);


    return 0;
}
