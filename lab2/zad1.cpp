#include <iostream>
#include <stdlib.h>
using namespace std;

void fun(int *a, int *b)
{
    int c = 0;
    if (*a<*b)
    {
        c = *a;
        *a = *b;
        *b = c;
    }
}

int main()
{
    int a = 10;
    int b = 20;
    int *p1 = &a;
    int *p2 = &b;
    fun(p1,p2);
    cout << a << ' ';
    cout << b;
    return 0;
}