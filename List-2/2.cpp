#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

int cokolwiek()
{
    srand(time(NULL));

    const int n = 10;

    int *intujaca = new int;
    *intujaca = rand() * 10;

    double *dublujaca = new double;
    *dublujaca = rand() * (rand() % 10 + 1);

    float *floatujaca = new float;
    *floatujaca = rand() % 10 / 5.0;

    int *tab = new int(n);
    for (int i = 0; i < 10; i++)
        tab[i] = rand() % 100 + 1;

    cout << *intujaca << ", " << *dublujaca << ", " << *floatujaca << endl;
    for (int i = 0; i < 10; i++)
        cout << *(tab + i) << ", ";

    delete[] intujaca, dublujaca, floatujaca, tab;

    return 0;
}

int main()
{
    cokolwiek();

    return 0;
}
