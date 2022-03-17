#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

int *wypelnij()
{
    static int a[10];

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 100 + 1;
    }

    return a;
}

int odczytaj(int a[])
{

    for (int i = 0; i < 10; i++)
    {
        cout << *(a + i) << " ";
    }
    return 0;
}

int main()
{

    int *a = wypelnij();

    odczytaj(a);

    return 0;
}
