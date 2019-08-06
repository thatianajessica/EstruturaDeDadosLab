#include <iostream>
#include <string.h>



using namespace std;

void quebra(int n, int &prim, int &ult, int &miolo){
    int digito, n_digitos, indice_prim = 0, indice_ult, tamanho_miolo;
    char numeros[40];
    char primeiro_str[2];
    char ult_str[2];
    char miolo_str[40];

    sprintf(numeros,"%d",n);
    n_digitos = strlen(numeros);

    indice_ult = n_digitos - 1;

    primeiro_str[0] = numeros[0];
    primeiro_str[1] = '\0';
    sscanf(primeiro_str, "%d", &prim);

    ult_str[0] = numeros[indice_ult];
    ult_str[1] = '\0';
    sscanf(ult_str, "%d", &ult);


    miolo_str[0] = '\0';

    for(int i = 1; i <= indice_ult - 1; i++){
        miolo_str[i-1] = numeros[i];
        miolo_str[i] = '\0';
    }
    tamanho_miolo = strlen(miolo_str);
    if(tamanho_miolo == 0){
        miolo = 0;
    }else{
        sscanf(miolo_str, "%d", &miolo);
    }

    }


int main()
{
    int num, prim,ult, miolo;
    bool palin;


    cout << "Insira o numero:" << endl;
    cin >> num;

    //quebra(num,prim,ult,miolo);

    //cout << "Primeiro digito = " << prim << endl;
    //cout << "Miolo = " << miolo << endl;
    //cout << "Ultimo digito = " << ult << endl;

    while(true){
        quebra(num,prim,ult,miolo);
        if(prim != ult){
            palin = false;
            break;
        }
        if(miolo == 0){
            palin = true;
            break;
        }
        num = miolo;
    }

    if(palin == 1){
       cout << "O numero eh um palindromo" << endl;
    }else{
       cout << "O numero nao eh um palindromo" << endl;
    }



    return 0;
}
