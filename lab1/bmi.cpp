#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
    float tab[2];
    for (int i = 0; i < argc - 1; i++)
        tab[i] = atof(argv[i+1]);
    float bmi = tab[0]/(tab[1]*tab[1]);
    cout << "Towje BMI wynosi: " << bmi << ' ';
    if (bmi < 16)
        cout << "wyglodzenie";
    else if (  bmi > 16 && bmi < 16.99)
        cout << "wychudzenie";
    else if (  bmi > 17 && bmi < 18.49)
        cout << "niedowaga";
    else if ( bmi > 18.5 && bmi < 24.99)
        cout << "wartosc prawidlowa";
    else if ( bmi > 25 && bmi < 29.99)
        cout << "nadwaga";
    else if ( bmi > 30 && bmi < 34.99)
        cout << "I stopien otylosci";
    else if ( bmi > 35 && bmi < 39.99)
        cout << "II stopien otylosci";
    else if ( bmi > 40)
        cout << "otylosc skrajna";
    return 0;
}