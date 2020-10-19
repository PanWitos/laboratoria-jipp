#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    int len = strlen(argv[1]);
    for (int i = 0; i < len - 1; i++)
    {
        if(argv[1][0] != argv[1][len - 1 - i])
            cout << "To nie jest palindrom";
            break;
    }
    return 0;
}