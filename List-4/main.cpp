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
    lista *pop;
    lista *nast;
};

void nowyElemet(lista *&l)
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
    tmp->nast = nullptr;
    if (l != nullptr)
    {
        l->nast = tmp;
    }

    l = tmp;
}

void usunPierwszy(lista *l)
{
    string doZnalezienia;
    cout << "Podaj nazwisko: ";
    cin >> doZnalezienia;
    for (lista *obiekt = l; obiekt != nullptr; obiekt = obiekt->pop)
    {
        if (obiekt->nazwisko == doZnalezienia)
        {
            if (obiekt->pop != 0)
                obiekt->pop->nast = obiekt->nast;
            if (obiekt->nast != 0)
                obiekt->nast->pop = obiekt->pop;
            delete obiekt;
            break;
        }
    }
}

void usunWszystkie(lista *l)
{
    string doZnalezienia;
    cout << "Podaj nazwisko: ";
    cin >> doZnalezienia;
    for (lista *obiekt = l; obiekt != nullptr; obiekt = obiekt->pop)
    {
        if (obiekt->nazwisko == doZnalezienia)
        {
            if (obiekt->pop != 0)
                obiekt->pop->nast = obiekt->nast;
            if (obiekt->nast != 0)
                obiekt->nast->pop = obiekt->pop;
            delete obiekt;
        }
    }
}

void znajdzWgKlucza(lista *l)
{
    string zn_str = "";
    int klucz, zn_wie = 0;
    cout << "Podaj klucz: " << endl
         << "    1) Imie." << endl
         << "    2) Nazwisko" << endl
         << "    3) PESEL" << endl
         << "    4) Wiek" << endl;
    cin >> klucz;

    if (klucz == 1)
    {
        cout << "Podaj imie do znalezienia: ";
        cin >> zn_str;
        for (lista *obiekt = l; obiekt != nullptr; obiekt = obiekt->pop)
        {
            if (obiekt->imie == zn_str)
            {
                cout << obiekt->imie << endl
                     << obiekt->nazwisko << endl
                     << obiekt->PESEL << endl
                     << obiekt->wiek << endl
                     << endl;
            };
        }
    }
    else if (klucz == 2)
    {
        cout << "Podaj nazwisko do znalezienia: ";
        cin >> zn_str;
        for (lista *obiekt = l; obiekt != nullptr; obiekt = obiekt->pop)
        {
            if (obiekt->nazwisko == zn_str)
            {
                cout << obiekt->imie << endl
                     << obiekt->nazwisko << endl
                     << obiekt->PESEL << endl
                     << obiekt->wiek << endl
                     << endl;
            };
        }
    }
    else if (klucz == 3)
    {
        cout << "Podaj PESEL do znalezienia: ";
        cin >> zn_str;
        for (lista *obiekt = l; obiekt != nullptr; obiekt = obiekt->pop)
        {
            if (obiekt->PESEL == zn_str)
            {
                cout << obiekt->imie << endl
                     << obiekt->nazwisko << endl
                     << obiekt->PESEL << endl
                     << obiekt->wiek << endl
                     << endl;
            };
        }
    }
    else if (klucz == 4)
    {
        cout << "Podaj wiek do znalezienia: ";
        cin >> zn_wie;
        for (lista *obiekt = l; obiekt != nullptr; obiekt = obiekt->pop)
        {
            if (obiekt->wiek == zn_wie)
            {
                cout << obiekt->imie << endl
                     << obiekt->nazwisko << endl
                     << obiekt->PESEL << endl
                     << obiekt->wiek << endl
                     << endl;
            };
        }
    }
}

void edytuj(lista *&l)
{
    string cokolwiek;
    cout << "Podaj PESEL edytowanego elemetu: ";
    cin >> cokolwiek;
    for (lista *obiekt = l; obiekt != nullptr; obiekt = obiekt->pop)
    {
        if (obiekt->PESEL == cokolwiek)
        {
            cout << "imie: ";
            cin >> obiekt->imie;
            cout << "nazwisko: ";
            cin >> obiekt->nazwisko;
            cout << "PESEL: ";
            cin >> obiekt->PESEL;
            cout << "wiek: ";
            cin >> obiekt->wiek;
        };
    }
}

void pokaz(lista *&l)
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

void zapisz(lista *&l)
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
         << "   2) Usun 1 elemet wg nazwiska" << endl
         << "   3) Usun wszystkie elemety wg nazwiska" << endl
         << "   4) Znajdz wszystkie elemety wg klucza" << endl
         << "   5) wyswietlic wszystkie elemety" << endl
         << "   6) Zapisac wszystkie elemety do pliku tekstowego" << endl
         << "   7) Wyjsc" << endl;
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
            nowyElemet(pocz);
        else if (wybor == 2)
            usunPierwszy(pocz);
        else if (wybor == 3)
            usunWszystkie(pocz);
        else if (wybor == 4)
            znajdzWgKlucza(pocz);
        else if (wybor == 5)
            pokaz(pocz);

    } while (wybor > 0 && wybor < 7);

    return 0;
}