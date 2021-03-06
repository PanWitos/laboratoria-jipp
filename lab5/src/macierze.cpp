#include <lab5/main.hpp>

macierz::macierz(int x, int y)
{
    try
    {
        if(x<1)
            throw 1;
        if(y<1)
            throw 2;
        ilo_wier = x;
        ilo_kol = y;
        m_macierz.resize(ilo_wier);
        for (int i=0; i < m_macierz.size(); i++)
        {
            m_macierz[i].resize(ilo_kol,0);
        }
    }
    catch(int z)
    {
        if (z == 1)
        {
            cout << "Liczba wierszy musi byc wieksza od 0\n";
        }
        if (z == 2)
        {
            cout << "Liczba wierszy musi byc wieksza od 0\n";
        }
    }
}
macierz::macierz(int x)
{
    try
    {
        if(x<0)
            throw 1;
        ilo_wier = x;
        ilo_kol = x;
        m_macierz.resize(ilo_wier);
        for (int i=0; i < m_macierz.size(); i++)
        {
            m_macierz[i].resize(ilo_kol);
        }
    }
    catch(int z)
    {
        if(z==1)
            cout << "Liczba wierszy i kolumn musi być wieksza od 0\n";
    }
}
void macierz::set(int n, int m, int val)
{
    try 
    {
        if(n < 0 || m < 0)
        {
            throw 1;
        }
        if(n > ilo_wier || m > ilo_kol)
        {
            throw 1;
        }
        m_macierz[n][m] = val;
    }
    catch (int z)
    {
        if(z==1)
            cout << "Komorka poza przedzialem \n";
    }
}
double macierz::get(int n, int m)
{
    try
    {
        if(n < 0 || m < 0)
        {
            throw 1;
        }
        if(n > ilo_wier || m > ilo_kol)
        {
            throw 1;
        }
        return m_macierz[n][m];
    }
    catch(int z)
    {
        if(z==1)
            cout << "Komorka poza przedzialem\n";
    }
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
macierz macierz::operator+(macierz m2)
{
    try
    {
        if(m2.rows() != ilo_wier || m2.cols() != ilo_kol)
        {
            throw 1;
        }
        macierz now(ilo_wier,ilo_kol);
        for(int i=0; i<ilo_wier; i++)
            for(int j=0; j<ilo_kol; j++)
                now.m_macierz[i][j] = m_macierz[i][j] + m2.m_macierz[i][j];
        return now;
    }
    catch(int z)
    {
        if(z==1)
            cout << "Niepoprawne wymiary macierzy\n";
    }
    
}
macierz macierz::operator-(macierz m2)
{
    try
    {
        if(m2.rows() != ilo_wier || m2.cols() != ilo_kol)
        {
            throw 1;
        }
        macierz now(ilo_wier,ilo_kol);
        for(int i=0; i<ilo_wier; i++)
            for(int j=0; j<ilo_kol; j++)
                now.m_macierz[i][j] = m_macierz[i][j] - m2.m_macierz[i][j];
        return now;
    }
    catch (int z)
    {
        if(z==1)
            cout << "Niepoprawne wymiary macierzy\n";
    }   
}
macierz macierz::operator*(macierz m2)
{
    macierz mnoz(ilo_wier,m2.cols());
    try
    {
        if(m2.cols() != ilo_wier)
        {
            throw 1;
        }
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
    catch(int z)
    {
        if(z==1)
            cout << "Niepoprawne wymiary macierzy\n";
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
    try
    {
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
            throw 1;
        }
    }
    catch (int z)
    {
        if(z==1)
            cout << "Blad odczytu pliku\n";
    }
    
}

ostream &operator<<(ostream &output, macierz &M)
{
    for (int i = 0; i < M.ilo_wier; i++)
    {
        for(int j = 0; j < M.ilo_kol; j++)
        {
            output << M.m_macierz[i][j] << " ";
        }
        output << endl;
    }
}

bool macierz::operator==(macierz m2)
{
    try
    {
        if(m2.cols() != ilo_kol)
        {
            throw 1;
        }
        if(m2.rows() != ilo_wier)
        {
            throw 1;
        }
        for (int i = 0; i < m2.ilo_wier; i++)
        {
            for(int j = 0; j < m2.ilo_kol; j++)
            {
                if(m_macierz[i][j] != m2.get(i,j))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    catch(int z)
    {
        if(z==1)
            cout << "Niepoprawne wymiary macierzy\n";
    }
}

bool macierz::operator!=(macierz m2)
{
    try
    {
        if(m2.cols() != ilo_kol)
        {
            throw 1;
        }
        if(m2.rows() != ilo_wier)
        {
            throw 1;
        }
        for (int i = 0; i < m2.ilo_wier; i++)
        {
            for(int j = 0; j < m2.ilo_kol; j++)
            {
                if(m_macierz[i][j] != m2.get(i,j))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    catch(int z)
    {
        if(z==1)
            return 1;
    }
}

vector <double> macierz::operator[](int x)
{
    return m_macierz[x];
}

void macierz::operator++(int x)
{
    for (int i = 0; i < ilo_wier; i++)
    {
        for(int j = 0; j < ilo_kol; j++)
        {
            m_macierz[i][j]++;
        }
    }
}

void macierz::operator--(int x)
{
    for (int i = 0; i < ilo_wier; i++)
    {
        for(int j = 0; j < ilo_kol; j++)
        {
            m_macierz[i][j]--;
        }
    }
}

void macierz::main()
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
    przyklad1 = przyklad1+przyklad2;
    cout << "M. przyklad1 po dodaniu do niej m. przyklad2" << endl;
    przyklad1.print();
    przyklad1 = przyklad1-przyklad2;
    cout << "M. przyklad1 po dodaniu do niej m. przyklad2 a nastepnie jej odjeciu" << endl;
    przyklad1.print();
    przyklad1 = przyklad1*przyklad2;
    cout << "M. przyklad1 po przemnozeniu jej przez m. przyklad2" << endl;
    przyklad1.print();
    przyklad1.store("przyklad.txt","");
    macierz przyklad3("przyklad.txt");
    cout << "M. przyklad3 jako odczytana z pliku m. przyklad1" << endl;
    przyklad3.print();
    cout << przyklad1;
    if(przyklad1==przyklad2)
    {
        cout << "Macierze sa takie same" << endl;
    }
    else
    {
        cout << "Macierze nie sa takie same" << endl;
    }
    
    vector <double> przyklad;
    przyklad = przyklad1[1];
    for(int i = 0; i<przyklad1.ilo_kol; i++)
    {
        cout << przyklad[i] << ' ';
    }
    cout << endl;
    przyklad1--;
    cout << przyklad1;
    przyklad1++;
    cout << przyklad1;

    if(przyklad1!=przyklad2)
    {
        cout << "Macierze nie sa takie same" << endl;
    }
    else
    {
        cout << "Macierze sa takie same" << endl;
    }
}
macierz::~macierz()
{
    
}