#include <iostream>
#include <stdlib.h>
using namespace std;

void fun(int &a, int *b)
{
    int c = 0;
    c = a;
    a = *b;
    *b = c;

}

int main()
{
    int a = 10;
    int b = 20;
    int *p = &b;
    fun(a,p);
    cout << a << ' ';
    cout << b;
    return 0;
}