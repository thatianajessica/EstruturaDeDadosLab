#include <iostream>
#include <cmath>

using namespace std;

double raiz_quadrada(double n, double eps){
    double teto=n;
    double piso=0;
    double quad;
    double dif;
    while(1){
        quad=(teto+piso)/2;
        dif=abs(quad*quad-n);
        if(dif<eps){
            return quad;
        }
        else{
            if(quad*quad>n){
                teto=quad-1;
            }
            else{
                piso=quad+1;
            }
        }
    }

}

int main(){
    double n,eps;
    cin>>n>>eps;

    double raiz = raiz_quadrada(n,eps);

    cout<<raiz<<endl;
    return 0;
}
