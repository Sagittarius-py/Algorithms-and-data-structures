#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    int i, z;
    int tab[10];

    cout << "Losowe liczby" << endl;

    for (i = 0; i < 10; i++)
    {
        tab[i] = rand() % 100 + 1;
        cout << tab[i] << "   ";
    }

    cout << endl;

    int *tablica = new int[10];

    for (int i = 10; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                tab[j + 1] = tab[j];
                tablica[j + 1] = tab[j];
                tab[j] = z;
                tablica[j] = z;
            }
        }
    }
    for (int i = 10; i > 0; i--)
    {
        cout << (int)tablica << "    ";
        tablica++;
    }

    delete[] tablica;
    return 0;
}