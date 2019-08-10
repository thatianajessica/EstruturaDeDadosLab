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
    int m, n, d;
    bool resp;

    cout << "m:" << endl;
    cin >> m;
    cout << "n:" << endl;
    cin >> n;
    cout << "d:" << endl;
    cin >> d;

    resp = divisao(m, n, d);
    cout << resp << endl;
    cout << "Quociente m = " << m <<" Quociente n = " << n << endl;

    return 0;
}
