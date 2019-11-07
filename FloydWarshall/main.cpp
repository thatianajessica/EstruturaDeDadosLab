#include <iostream>
#include <fstream>
#define inf 9999999

using namespace std;

int main()
{
    int a, b, c, v;
    ifstream infile("floyd.in");

    infile>>v;
    int adjascencia[v][v]={inf};
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i!=j)adjascencia[i][j] = inf;
            else  adjascencia[i][j] = 0;
        }
    }

    while (infile >> a >> b >> c )
    {
       adjascencia[a-1][b-1]=c;
       adjascencia[b-1][a-1]=c;
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjascencia[i][j] == inf)
                cout<<"inf"<<" ";
            else
                cout<<" "<<adjascencia[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j <v; j++)
            {

                if ((adjascencia[i][j] > adjascencia[i][k] + adjascencia[k][j]))
                    adjascencia[i][j] = adjascencia[i][k] + adjascencia[k][j];
            }
        }

    }

     for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjascencia[i][j] == inf)
                cout<<"inf"<<" ";
            else
                cout<<" "<<adjascencia[i][j]<<"  ";
        }
        cout<<endl;
    }



infile.close();
}
