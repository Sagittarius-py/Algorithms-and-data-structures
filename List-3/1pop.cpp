#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct lista
{
    string imie;
    string nazwisko;
    string PESEL;
    int wiek;
    lista *pop = nullptr;
};

void push(lista *&l)
{
    lista *tmp = new lista;
    cout << "imie: ";
    cin >> tmp->imie;
    cout << "nazwisko: ";
    cin >> tmp->nazwisko;
    cout << "PESEL: ";
    cin >> tmp->PESEL;
    cout << "wiek: ";
    cin >> tmp->wiek;

    tmp->pop = l;
    l = tmp;
}

bool pop(lista *&l)
{
    if (l == nullptr)
        return false;

    lista *tmp = l->pop;
    delete l;
    l = tmp;
    return true;
}

void show(lista *&l)
{
    for (lista *next = l; next != nullptr; next = next->pop)
    {
        cout << next->imie << endl
             << next->nazwisko << endl
             << next->PESEL << endl
             << next->wiek << endl
             << endl;
    }
}

void save(lista *&l)
{
    fstream file;
    file.open("plik.txt", ios::out);
    for (lista *next = l; next != nullptr; next = next->pop)
    {
        file << next->imie << " "
             << next->nazwisko << " "
             << next->PESEL << " "
             << next->wiek << endl;
    }

    file.close();
}

int menu()
{
    int wybor = 0;
    cout << endl
         << "Co chvesz zrobic: " << endl
         << "   1) Dodac element" << endl
         << "   2) Zdjac elemet" << endl
         << "   3) wyswietlic wszystkie elemety" << endl
         << "   4) Zapisac wszystkie elemety do pliku tekstowego" << endl
         << "   5) Wyjsc" << endl;
    cin >> wybor;

    return wybor;
}

int main()
{
    int wybor = 1;
    lista *pocz = nullptr;
    do
    {
        wybor = menu();

        if (wybor == 1)
            push(pocz);
        else if (wybor == 2)
            pop(pocz);
        else if (wybor == 3)
            show(pocz);
        else if (wybor == 4)
            save(pocz);

    } while (wybor > 0 && wybor < 5);

    while (pop(pocz))
        ;
    return 0;
}