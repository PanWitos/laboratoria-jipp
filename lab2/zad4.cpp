#include <iostream>
#include <stdlib.h>
using namespace std;

int fun(int &a, int &b, int &c)
{
    c = a+b;
    return a*b;
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 0;
    int ilocz = fun(a,b,c);
    cout << ilocz << ' ' << c;
    return 0;
}