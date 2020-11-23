#include "main.hpp"

macierz::macierz(int x, int y)
{
    ilo_wier = x;
    ilo_kol = y;
    m_macierz.resize(ilo_wier);
    for (int i=0; i < m_macierz.size(); i++)
    {
        m_macierz[i].resize(ilo_kol,0);
    }
}
macierz::macierz(int x)
{
    ilo_wier = x;
    ilo_kol = x;
    m_macierz.resize(ilo_wier);
    for (int i=0; i < m_macierz.size(); i++)
    {
        m_macierz[i].resize(ilo_kol);
    }
}
void macierz::set(int n, int m, int val)
{
    m_macierz[n][m] = val;
}
void macierz::get(int n, int m)
{
    cout << m_macierz[n][m] << endl;
}
void macierz::print()
{
    for (int i = 0; i < ilo_wier; i++)
    {
        for(int j = 0; j < ilo_kol; j++)
            cout << "[" << m_macierz[i][j] << "]";
        cout << endl;
    }
    cout << endl;
}
macierz macierz::add(macierz m2)
{
    if(m2.rows() != ilo_wier || m2.cols() != ilo_kol)
    {
        exit(-1);
    }
    else
    {
        macierz now(ilo_wier,ilo_kol);
        for(int i=0; i<ilo_wier; i++)
            for(int j=0; j<ilo_kol; j++)
                now.m_macierz[i][j] = m_macierz[i][j] + m2.m_macierz[i][j];
        return now;
    }
    
}
macierz macierz::substract(macierz m2)
{
    if(m2.rows() != ilo_wier || m2.cols() != ilo_kol)
    {
        exit(-1);
    }
    else
    {
        macierz now(ilo_wier,ilo_kol);
        for(int i=0; i<ilo_wier; i++)
            for(int j=0; j<ilo_kol; j++)
                now.m_macierz[i][j] = m_macierz[i][j] - m2.m_macierz[i][j];
        return now;
    }
    
}
macierz macierz::multiply(macierz m2)
{
    macierz mnoz(ilo_wier,m2.cols());
    if(m2.cols() != ilo_wier)
    {
        exit(-1);
    }
    else
    {
        double temp = 0.0;
        for(int i=0; i<ilo_wier; i++)
        {
            for(int j=0; j<m2.cols(); j++)   
            { 
                temp = 0.0;
                for(int k=0; k<ilo_kol; k++)
                {
                    temp += m_macierz[i][k] * m2.m_macierz[k][j];
                }
                mnoz.m_macierz[i][j] = temp;
            }
        }
        return mnoz;
    }
}
int macierz::rows()
{
    return ilo_wier;
}
int macierz::cols()
{
    return ilo_kol;
}
void macierz::store(string filename, string path)
{
    ofstream myfile;
    myfile.open(path+filename);
    myfile << ilo_kol << " " << ilo_wier << endl;
    for (int i = 0; i < ilo_wier; i++)
    {
        for(int j = 0; j < ilo_kol; j++)
        {
            myfile << m_macierz[i][j] << " ";
        }
        myfile << endl;
    }
    myfile.close();
}
macierz::macierz(string path)
{
    ifstream myfile(path);
    if(myfile.is_open())
    {
        myfile >> ilo_kol >> ilo_wier;
        m_macierz.resize(ilo_wier);
        for(int i=0; i<m_macierz.size(); i++)
            m_macierz[i].resize(ilo_kol, 0);
        for(int i=0; i<ilo_wier; i++)
            for(int j=0; j<ilo_kol; j++)
                myfile >> m_macierz[i][j];
        myfile.close();
    }
    else
    {
        exit(-1);
    }
    
}
int macierz::main()
{
    macierz przyklad1(4,4);
    macierz przyklad2(4);
    cout << "Ilosc kolumn m. przyklad1: " << przyklad1.cols() << endl;
    cout << "Ilosc wierszy m. przyklad1: " << przyklad1.rows() << endl;
    przyklad1.set(1,1,8);
    przyklad2.set(1,1,7);
    cout << "Elemendt na miejscu 2,2 w m. przyklad1: ";
    przyklad1.get(1,1);
    cout << "Elemendt na miejscu 2,2 w m. przyklad2: ";
    przyklad2.get(1,1);
    przyklad1 = przyklad1.add(przyklad2);
    cout << "M. przyklad1 po dodaniu do niej m. przyklad2" << endl;
    przyklad1.print();
    przyklad1 = przyklad1.substract(przyklad2);
    cout << "M. przyklad1 po dodaniu do niej m. przyklad2 a nastepnie jej odjeciu" << endl;
    przyklad1.print();
    przyklad1 = przyklad1.multiply(przyklad2);
    cout << "M. przyklad1 po przemnozeniu jej przez m. przyklad2" << endl;
    przyklad1.print();
    przyklad1.store("przyklad.txt","");
    macierz przyklad3("przyklad.txt");
    cout << "M. przyklad3 jako odczytana z pliku m. przyklad1" << endl;
    przyklad3.print();

}

int main()
{
    macierz przyklad(1);
    przyklad.main();
}