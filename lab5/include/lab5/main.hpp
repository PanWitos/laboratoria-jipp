#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <list>

using namespace std;


class macierz
{
    private:
    int ilo_wier;
    int ilo_kol;
    vector<vector<double> > m_macierz;
    public:
    macierz(int x, int y);
    macierz(int x);
    ~macierz();
    void set(int n,int m,int val);
    double get(int n, int m);
    void print();
    int rows();
    int cols();
    macierz operator+(macierz m2);
    macierz operator-(macierz m2);
    macierz operator*(macierz m2);
    void store(string filename, string path);
    macierz(string path);
    void main();
    friend ostream &operator<<(ostream &output, macierz &M);
    bool operator==(macierz m2);
    bool operator!=(macierz m2);
    vector <double> operator[](int x);
    void operator++(int);
    void operator--(int);
};