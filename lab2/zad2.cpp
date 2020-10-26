#include <iostream>
#include <stdlib.h>
using namespace std;

void fun(int &a, int &b)
{
    int c = 0;
    c = a;
    a = b;
    b = c;
}

int main()
{
    int a = 10;
    int b = 20;
    fun(a,b);
    cout << a << ' ';
    cout << b;
    return 0;
}