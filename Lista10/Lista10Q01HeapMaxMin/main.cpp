#include <iostream>

using namespace std;

bool temFilhoEsq(int index, int n){
    if(2*index+1 < n){
        return true;
    }else{
        return false;
    }
}

bool temFilhoDir(int index, int n){
    if(2*index+2 < n){
        return true;
    }else{
        return false;
    }
}

int HeapMaxOrMin(int *vetor, int tam_vec){
    bool isHeapMax = true;
    bool isHeapMin = true;


    for (int i = 0; i < tam_vec; i++) {
        if(temFilhoEsq(i,tam_vec))
        {
            if(vetor[i] < vetor[2*i+1] ){
                isHeapMax = false;
            }

            if(vetor[i] > vetor[2*i+1] ){
                isHeapMin = false;
            }

        }
        if(temFilhoDir(i,tam_vec)){
            if(vetor[i] < vetor[2*i+2] ){
                isHeapMax = false;
            }

            if(vetor[i] > vetor[2*i+2] ){
                isHeapMin = false;
            }
        }
        if(isHeapMax == false && isHeapMin == false)
        {
            break;
        }

    }

    if(isHeapMax && isHeapMin)
    {
        return -1; //single node
    }
    else if(isHeapMax==false && isHeapMin==false)
    {
        return 0;// no max/min heap
    }
    else if(isHeapMax == true){
        return 1;//max heap
    }else{
        return 2;//min heap
    }

}
int main()
{
    int MAX = 8;
    //int vec[MAX] = {20, 25, 32, 29, 27, 35, 40, 45};
    //int vec[MAX] = {20, 32, 25, 29, 27, 35, 40, 45};
    int vec[MAX] = {50, 45, 48, 29, 15, 35, 40, 27};
    int piso = MAX/2;
    int res = -1;



    res = HeapMaxOrMin(vec, MAX);
    cout <<res << endl;
    return 0;
}
