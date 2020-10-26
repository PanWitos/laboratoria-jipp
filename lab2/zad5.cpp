#include <iostream>
#include <stdlib.h>
using namespace std;

void fun(void *a, void *b, size_t s)
{
    void *c = malloc(s);
    memcpy(c,a,s);
    memcpy(a,b,s);
    memcpy(b,c,s);
}

int main()
{
    int a = 10;
    int b = 20;
    void *p1 = &a;
    void *p2 = &b;
    fun(p1,p2,sizeof(a));
    cout << a << ' ' << b << '\t';

    float c = 10.12;
    float d = 20.34;
    void *p3 = &c;
    void *p4 = &d;
    fun(p3,p4,sizeof(c));
    cout << c << ' ' << d << '\t';

    char e = 'a';
    char f = 'b';
    void *p5 = &e;
    void *p6 = &f;
    fun(p5,p6,sizeof(e));
    cout << e << ' ' << f;

    
    return 0;
}