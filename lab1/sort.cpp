#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
    int tab[argc-1];
    for (int i = 0; i < argc - 1; i++)
        tab[i] = atoi(argv[i+1]);
    
    for(int i = 0; i < argc - 1; i++)
        for(int j = 1; j < argc - 1 - i;j++)
            if(tab[j-1]>tab[j])
            swap(tab[j-1],tab[j]);

    for(int i = 0; i < argc-1;i++)
        cout << tab[i] << ' ';
    return 0;
}