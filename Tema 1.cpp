#include <iostream>

using namespace std;

struct tuplu
{
    int maxim, poz;
};

class Vector
{
private:
    int n, *v;

public:

    friend istream& operator >>(istream& input, Vector& x1);
    friend ostream& operator <<(ostream& output, Vector x1);

    Vector(int n=1, int x=0)                        //constructor de initializare
    {
        this -> n = n;
        v = new int[n];
        for(int i = 0; i < n; i++)
            v[i] = x;
    }

    int getN()
    {
        return n;
    }

    Vector(const Vector& x1)                        //constructor de copiere
    {
        n = x1.n;
        v = new int[n];
        for(int i = 0; i < n; i++)
            v[i] = x1.v[i];
    }

    Vector& operator = (Vector const &x1)           //operator de atribuire
    {
        this -> n =  x1.n;
        for (int i = 0; i < x1.n; i++)
            this -> v[i] = x1.v[i];
        return *this;
    }

    int& operator [] (int i)
    {
        return v[i];
    }

    void reactualizare(int n, int x)
    {
        delete[] v;
        this -> n = n;
        v = new int[n];
        for(int i = 0; i < n; i++)
            v[i] = x;
    }

    int suma()
    {
        int s = 0;
        for(int i = 0; i < getN(); i++)
            s = s + v[i];
        return s;
    }

    tuplu max()
    {
        tuplu rez;
        rez.maxim = v[0];
        rez.poz = 1;
        for(int i = 1; i < getN(); i++)
            if(v[i] > rez.maxim)
            {
                rez.maxim = v[i];
                rez.poz = i+1;
            }
        return rez;
    }

    void sortare()
    {
        int min, aux, poz, j;
        for(int i = 0; i < getN()-1; i++)
        {
            min = v[i];
            poz = i;
            for(j = i+1; j < getN(); j++)
                if(v[j] < min)
                {
                    min = v[j];
                    poz = j;
                }
            if(poz != i)
            {
                aux = v[i];
                v[i] = min;
                v[poz] = aux;
            }
        }
    }

    int operator * (Vector const &x1)
    {
        int p = 0;
        if (x1.n != n)
            return 0;
        else
            for (int i = 0; i < n; i++)
                p += v[i] * x1.v[i];
        return p;
    }

    ~Vector()                                       //destructor
    {
        n = 0;
        delete[] v;
    }
};

istream& operator >> (istream &input, Vector &x1)   //input
{
    delete[] x1.v;
    input >> x1.n;
    x1.v = new int[x1.n];
    for (int i = 0; i < x1.n; i++)
        input >> x1[i];
    return input;
}

ostream& operator << (ostream &output, Vector x1)   //output
{

    int n = x1.n;
    output << "[";
    for (int i = 0; i < x1.n-1; i++)
        output << x1[i] << ", ";
    output << x1[n-1] << "]";
    return output;
}

int main()
{
    Vector v1, v4;
    cin >> v1;
    cout << "\n";

    tuplu rez = v1.max();
    cout << "Maximul este " << rez.maxim << " pe pozitia " << rez.poz << "\n" << "\n";

    cout << "Suma elementelor este: " << v1.suma() << "\n" << "\n";

    v1.sortare();
    cout << "Sortam crescator: " << "\n" << v1 << "\n" << "\n";

    Vector v2 = v1;
    cout << "Copiem v1 in v2: " << "\n" << v2 << "\n" << "\n";

    Vector v3(v1);
    cout << "Initializam v3 cu v1: " << "\n" << v3 << "\n" << "\n";

    v1.reactualizare(6,9);
    cout << "Reactualizam v1: " << "\n" << v1 << "\n" << "\n";

    cout << "Produsul scalar v1*v2: " << v1*v2 << "\n" << "\n";

    cout << "Suprascriem v1 folosind supraincarcarea '=' : " << "\n";
    cin >> v4;
    v1 = v4;
    cout << "\n" << v1 << "\n";

    return 0;
}
