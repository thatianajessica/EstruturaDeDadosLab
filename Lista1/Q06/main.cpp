#include <iostream>

using namespace std;

int calculateMDC(int num1, int num2){
    int mdc;
    while(num1 != 0 && num2 !=0){
        if (num1 >= num2){
            num1 = num1 % num2;
        }else{
            num2 = num2 % num1;
        }
    }

    if(num1 >= num2){
        mdc = num1;
    }else{
        mdc = num2;
    }
    return mdc;
}


int main()
{
    int num1, num2,mdc;

    cout<<"Digite o primeiro numero:"<<endl;
    cin>>num1;
    cout<<"Digite o segundo numero:"<<endl;
    cin>>num2;

    while(true){
        mdc = calculateMDC(num1,num2);
        if(mdc == 1){
            break;
        }else{
            num1 = num1/mdc;
            num2 = num2/mdc;
        }

    }
    cout << "fracao irredutivel =" <<num1 <<" / " << num2 << endl;
    return 0;
}
