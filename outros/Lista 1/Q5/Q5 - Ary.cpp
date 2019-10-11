int main()
{
    int n1, n2, aux;
    cout<<"Digite um numero"<<endl;
    cin>>n1;
    cout<<"Digite um numero"<<endl;
    cin>>n2;
    while(aux != 0){
        if((n2*2)>n1){
            aux = n1 - n2;
            n1 = n2;
            n2 = aux;
        }else{
            aux = n1 - (n2*2);
            n1 = n2;
            n2 = aux;
        }
    }
    cout<<n1;
    return 0;
}
