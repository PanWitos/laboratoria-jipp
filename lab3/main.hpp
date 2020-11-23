#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>

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
    void get(int n, int m);
    void print();
    int rows();
    int cols();
    macierz add(macierz m2);
    macierz substract(macierz m2);
    macierz multiply(macierz m2);
    void store(string filename, string path);
    macierz(string path);
    int main();
};
