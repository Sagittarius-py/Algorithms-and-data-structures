#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

struct tosoba
{
    int id;
    char imie[20];
    char nazwisko[20];
    int wiek;
};

tosoba create(int iterator)
{
    tosoba *struktura = new tosoba;
    srand(time(NULL));

    struktura[iterator].id = iterator;
    cout << "Podaj imie: ";
    cin >> struktura[iterator].imie;
    cout << "Podaj nazwisko: ";
    cin >> struktura[iterator].nazwisko;

    struktura[iterator].wiek = rand() % 100 + 1;

    return *struktura;
}

int display(tosoba tab[], int iterator)
{
    for (int i = 0; i < iterator; i++)
    {
        cout << "ID: " << tab[i].id << endl
             << "Imie: " << tab[i].imie << endl
             << "Nazwisko: " << tab[i].nazwisko << endl
             << "Wiek: " << tab[i].wiek << endl;
    }
    return 0;
}

int main()
{
    tosoba tab[10];

    int iterator = 0;
    create(iterator);
    iterator++;

    display(tab, iterator);

    return 0;
}
