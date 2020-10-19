#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
    int tab[2];
    for (int i = 0; i < argc - 1; i++)
        tab[i] = atoi(argv[i+1]);
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 1; i <= (tab[0]/2); i++)
        if(tab[0]%i == 0)
            sum1 = sum1 + i;
    for(int i = 1; i <= (tab[1]/2); i++)
        if(tab[1]%i == 0)
            sum2 = sum2 + i;
    if(sum1 == tab[1] + 1 && sum2 == tab[0] + 1)
        cout << "Sa to liczby skojarzone";
    else
        cout << "Nie sa to liczby skojarzone";
    return 0;
}