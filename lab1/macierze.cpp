#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cout << "Podaj wartosci pierwszej macierzy ";
    cin >> a >> b >> c >> d >> e >> f;
    int mac1[2][3] = {{a,b,c},{d,e,f}};
    cout << "Podaj wartosci drugiej macierzy ";
    cin >> a >> b >> c >> d >> e >> f;
    int mac2[2][3] = {{a,b,c},{d,e,f}};

    int mac3[2][3] = {{mac1[0][0] + mac2[0][0],mac1[0][1] + mac2[0][1],mac1[0][2] + mac2[0][2]},{mac1[1][0] + mac2[1][0],mac1[1][1] + mac2[1][1],mac1[1][2] + mac2[1][2]}};

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++)
            cout << mac3[i][j] << ' ';
    return 0;
}