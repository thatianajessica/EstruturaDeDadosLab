#include <iostream>

using namespace std;

void printarArestasArvore(int pruffer[], int m)
{
    int n_vertices = m + 2;
    int conjunto_vertices[n_vertices];

    for (int i = 0; i < n_vertices; i++)
        conjunto_vertices[i] = 0;

    for (int i = 0; i < n_vertices - 2; i++)
        conjunto_vertices[pruffer[i] - 1] += 1;

    cout << "Conjunto de arestas : " << endl;

    int j = 0;
    for (int i = 0; i < n_vertices - 2; i++) {
        for (j = 0; j < n_vertices; j++) {
            if (conjunto_vertices[j] == 0) {
                conjunto_vertices[j] = -1;
                cout << "(" << (j + 1) << ", "
                     << pruffer[i] << ")  ";

                conjunto_vertices[pruffer[i] - 1]--;

                break;
            }
        }
    }

    j = 0;

    for (int i = 0; i < n_vertices; i++) {
        if (conjunto_vertices[i] == 0 && j == 0) {
            cout << "(" << (i+1) << ", ";
            j++;
        }
        else if (conjunto_vertices[i] == 0 && j == 1)
            cout << (i+1) << ")\n";
    }
}

int main()
{
    int pruffer[] = { 3, 3, 3, 6, 6, 6, 9, 9 };
    int n = 8;
    printarArestasArvore(pruffer, n);
    return 0;
}
