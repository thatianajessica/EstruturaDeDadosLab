#include <iostream>

using namespace std;

int main()
{
    int num1, num2;

    cout<<"Digite o primeiro numero:"<<endl;
    cin>>num1;
    cout<<"Digite o segundo numero:"<<endl;
    cin>>num2;

    while(num1 != 0 && num2 !=0){
        if (num1 >= num2){
            num1 = num1 % num2;
        }else{
            num2 = num2 % num1;
        }
    }

    if(num1 >= num2){
        cout<<"MDC="<<num1<<endl;
    }else{

        cout<<"MDC="<<num2<<endl;
    }

    return 0;
}
