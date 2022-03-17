#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int intujaca = rand() % 50 + 1;
    int *adrIntujaca = &intujaca;

    double dublujaca = rand() * (rand() % 100 + 1);
    double *adrDublujaca = &dublujaca;

    float floatujaca = rand() % 10 / 5.0;
    float *adrFloatujaca = &floatujaca;

    int tab[10] = {};
    int *adrTab = tab;
    for (int i = 0; i < 10; i++)
        tab[i] = rand() % 100 + 1;

    cout << intujaca << ", " << dublujaca << ", " << floatujaca << endl;
    for (int i = 0; i < 10; i++)
        cout << tab[i] << ", ";
    return 0;
}
