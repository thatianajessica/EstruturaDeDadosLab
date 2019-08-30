 #include <iostream>

using namespace std;

int main(){
    cout<<"N"<<endl;
    int n;
    cin>>n;

    int v[n];
    cout<<"V"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int maior=0,segundomaior=0;

    for(int i=0;i<n;i++){
        if(v[i]>=maior){
            segundomaior=maior;
            maior=v[i];
        }
        else if(v[i]>segundomaior){
            segundomaior=v[i];
        }

    }
    cout<<segundomaior<<endl;

    return 0;
}
