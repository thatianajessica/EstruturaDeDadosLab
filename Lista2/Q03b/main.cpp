#include <iostream>

using namespace std;

bool divisao(int &m, int &n, int d){
    bool divisivel = false;
    if(m % d == 0){
       m = m/d;
       divisivel = true;
    }
    if(n % d == 0){
        n = n/d;
        divisivel = true;
    }
    return divisivel;
}

int main()
{
    int m, n, d, maior, mmc;
    bool resp;

    cout << "m:" << endl;
    cin >> m;
    cout << "n:" << endl;
    cin >> n;

    if(m>=n){
        maior = m;
    }else{
        maior = n;
    }
    mmc = 1;
    //m =2 n=3
    while(true){
        for (int i = 2; i <= maior ; i++) {
            resp = divisao(m,n,i);
            if(resp == true){
                mmc *= i;
                break;
            }
        }
        if(m == 1 && n == 1){
            break;
        }

    }

    cout << mmc << endl;

    return 0;
}
