int main()
{
    int n, a = 1, b = 2, c = 3;
    cout<<"Digite um numero"<<endl;
    cin>>n;
    while(c < n){
        if((a*b*c)== n){
            cout<<"E TRIANGULAR";
            return 0;
        }
        a++;
        b++;
        c++;
    }
    cout<<"NÃO E TRIANGULAR";
    return 0;
}
