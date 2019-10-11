#include <iostream>
using namespace std;
const int n = 3;
void mult(int a[n][n], int c[n], int r[n]){
     for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            r[i] = r[i] + (c[j]*a[j][i]);
        }
     }
     for(int i = 0; i< n; i++){
            cout<<r[i]<<"  ";
}
}
int main()
{
    int a[n][n] = {0,1,2,3,4,5,6,7,8};
    int c[n] = {1,2,3}, r[n] = {0,0,0};
    mult(a,c,r);
    return 0;
}

//A complexidade desta função é de n (número de elementos de A) * n (número de elementos de C), sendo esta n^2.