#include <iostream>

using namespace std;

typedef struct
{
    int id;
    string imie;
    string nazwisko;
    int wiek;
} tosoba;

void init_tab(tosoba **tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\nPodaj id imie naziwsko i wiek: ";
            cin >> tab[i][j].id >> tab[i][j].imie >> tab[i][j].nazwisko >> tab[i][j].wiek;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << tab[i][j].id << " " << tab[i][j].imie << " " << tab[i][j].nazwisko << " " << tab[i][j].wiek << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    tosoba **tab = nullptr;

    //---------------------
    tab = new tosoba *[n];
    for (int i = 0; i < n; i++)
        tab[i] = new tosoba[n];
    //---------------------

    init_tab(tab, n);

    delete[] tab;

    return 0;
}