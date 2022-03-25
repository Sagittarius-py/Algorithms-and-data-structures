#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct struktura
{
    string imie;
    string nazwisko;
    string PESEL;
    int wiek;
    struktura *pop = nullptr;
};

struktura *stos = new struktura;

void dodaj(struktura stos[], struktura pocz, int iterator)
{
    if (iterator == 0)
    {
        cout << "Imie: ";
        cin >> stos[iterator].imie;

        cout << "Nazwisko: ";
        cin >> stos[iterator].nazwisko;

        cout << "PESEL: ";
        cin >> stos[iterator].PESEL;

        cout << "Wiek: ";
        cin >> stos[iterator].wiek;
    }
    else
    {
        cout << "Imie: ";
        cin >> stos[iterator].imie;

        cout << "Nazwisko: ";
        cin >> stos[iterator].nazwisko;

        cout << "PESEL: ";
        cin >> stos[iterator].PESEL;

        cout << "Wiek: ";
        cin >> stos[iterator].wiek;

        // stos[iterator].pop = &pocz;
    }

    // for (int i = 0; i <= iterator; i++)
    // {
    //     cout << endl
    //          << stos[i].imie << endl
    //          << stos[i].nazwisko << endl
    //          << stos[i].PESEL << endl
    //          << stos[i].wiek << endl;
    // }
}

int main()
{
    int iterator = 0, wybor = 0;
    struktura pocz = stos[iterator - 1];

    do
    {
        cout << endl
             << "Co chvesz zrobic: " << endl
             << "   1) Dodac element" << endl
             << "   2) Zdjac elemet" << endl
             << "   3) wyswietlic wszystkie elemety" << endl
             << "   4) Zapisac wszystkie elemety do pliku tekstowego" << endl
             << "   5) Wyjsc" << endl;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
        {

            dodaj(stos, pocz, iterator);
            iterator++;
            break;
        }
        }

    } while (wybor > 0 && wybor < 5);

    return 0;
}
