#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

#include <iostream>
#include <time.h>

void init_tab(int tab[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        cout << (tab[i] = rand() % 100 + 1) << endl;
    }
}

int main()
{
    int tab[10];
    int *w_tab[10];

    int min;
    int *min_w;
    init_tab(tab, 10);

    cout << "zaczynam ====================================" << endl;

    // iteruj po całej tablicy
    //     zapisz najmniesza wartosc
    //         zapisz jej wskaźnik

    for (int i = 0; i < 9; i++)
    {

        for (int j = 0; j < 9; j++)
        {

            if (tab[j] < tab[j + 1] && tab[j] < min)
            {
                cout << "--------" << endl;
                cout << tab[j] << " < " << tab[j + 1] << endl;
                min = tab[j];
                cout << "--------" << endl;
            }
            else if (tab[j] > tab[j + 1] && tab[j + 1] < min)
            {
                cout << "--------" << endl;
                cout << tab[j] << " > " << tab[j + 1] << endl;
                min = tab[j + 1];
                cout << "--------" << endl;
            }
            cout << min << endl;
        }
        cout << " iteracja ====================================" << endl;
    }
    cout << "skonczylem ====================================" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ". " << *w_tab[i] << endl;
    }

    return 0;
}
