#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct lista
{
    string imie;
    string nazwisko;
    string PESEL;
    int wiek;
    lista *nast = nullptr;
};

class List
{
public:
    ~List()
    {
        clear();
    }

    void push_back()
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

        if (pocz == nullptr)
            pocz = tmp;

        if (kon != nullptr)
            kon->nast = tmp;

        kon = tmp;
        size++;
    }

    bool pop_front()
    {
        if (pocz == nullptr)
            return false;

        lista *tmp = pocz->nast;
        if (pocz == kon)
            kon = nullptr;
        delete pocz;
        pocz = tmp;
        size--;
        return true;
    }

    void show()
    {
        for (lista *next = pocz; next != nullptr; next = next->nast)
            cout << next->imie << endl
                 << next->nazwisko << endl
                 << next->PESEL << endl
                 << next->wiek << endl
                 << endl;
    }

    void clear()
    {
        while (pop_front())
            ;
    }

    void save()
    {
        fstream file;
        file.open("plik.txt", ios::out);

        lista **tab = new lista *[size];
        size_t n = 0;
        for (lista *next = pocz; next != nullptr; next = next->nast, n++)
            tab[n] = next;

        sort(tab, tab + size, [](lista *a, lista *b)
             { return a->wiek < b->wiek; });

        for (n = 0; n < size; n++)
            file << tab[n]->imie << " "
                 << tab[n]->nazwisko << " "
                 << tab[n]->PESEL << " "
                 << tab[n]->wiek << endl;

        file.close();
    }

private:
    lista *pocz = nullptr, *kon = nullptr;
    size_t size = 0;
};

int menu()
{
    int wybor = 0;

    cout << "Co chcesz zrobic: " << endl
         << "   1) Dodaj elemet na koncu" << endl
         << "   2) Usun elemet z poczatku" << endl
         << "   3) Pokaz elemety" << endl
         << "   4) Wyczysc wszystkie elemety" << endl
         << "   5) Zapisz kolejke" << endl
         << "   6) exit" << endl;
    cin >> wybor;
    return wybor;
}

int main()
{
    List lista;
    int wybor = 1;
    do
    {
        wybor = menu();

        if (wybor == 1)
            lista.push_back();
        else if (wybor == 2)
            lista.pop_front();
        else if (wybor == 3)
            lista.show();
        else if (wybor == 4)
            lista.clear();
        else if (wybor == 5)
            lista.save();
        else if (wybor != 6)
            menu();
    } while (wybor != 6);

    return 0;
}