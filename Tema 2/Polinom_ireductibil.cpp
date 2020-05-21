#include <bits/stdc++.h>
#include "Polinom_ireductibil.h"

using namespace std;

istream &operator >> (istream &input, Polinom &p1)
{
    Monom m;
    delete[] p1.poli;
    input >> p1.gradmax;
    input >> p1.nr_monoame;
    p1.poli = new float[p1.gradmax+1];
    for(int i = 0; i <= p1.gradmax; i++)
        p1.poli[i] = 0;
    for (int i = 0; i < p1.nr_monoame; i++)
    {
        input >> m;
        p1.poli[m.grad] += m.coef;
    }
    return input;
}

ostream &operator << (ostream &output, Polinom p1)
{
    for (int i = p1.gradmax; i >= 0; i--)
        output << p1.poli[i] << "x^" << i << " ";
    output << "\n";
    return output;
}

Polinom_ireductibil::Polinom_ireductibil(int n)
{
    nr_monoame = n;
    poli = new float[n+1];
    for(int i = 0; i <= n; i++)
        poli[i] = 0;
}

Polinom_ireductibil::Polinom_ireductibil(const Polinom &p)
{
    nr_monoame = p.nr_monoame;
    poli = new float[nr_monoame+1];
    for(int i = 0; i <= nr_monoame; i++)
        poli[i] = p.poli[i];
}

Polinom_ireductibil::~Polinom_ireductibil()
{
    nr_monoame = 0;
    delete[] poli;
}

int prime(int A, int B)
{
    if(!B)
        return A;
    return prime(B, A%B);
}

bool Polinom_ireductibil::ireductibil()
{
    int i, j, inceput;
    float maxi=-999999;
    bool ok = 1;

    //! maxi = *max_element (poli.begin(), poli.end());

    for (i = 0; i <= nr_monoame; i++)
        if (maxi < poli[i])
            maxi = poli[i];

    vector<bool> p;
    p.assign(maxi, 0);
    p[0] = 1;
    p[1] = 1;
    for(i = 4; i <= maxi; i += 2)
        p[i] = 1;
    for(i = 3; i <= maxi; i += 2)
        if(p[i] == 0)
            for(j = 2; j <= maxi/i; j++)
                p[i*j] = 1;

    for(i = nr_monoame; i > 0; i--)
        if(poli[i])
        {
            if(int(poli[i]) == poli[i])
            {
                if(poli[i] == 1)
                {
                    cout << "Criteriul nu functioneaza pe acest caz: coeficientii nu sunt primi intre ei.\n";
                    return 0;
                }
                else
                {
                    for(j = i-1; j >= 0; j--)
                        if(poli[j])
                            if(prime(int(poli[i]), int(poli[j])) != 1)
                            {
                                cout << "Criteriul nu functioneaza pe acest caz: coeficientii nu sunt primi intre ei.\n";
                                return 0;
                            }
                }
            }
            else
            {
                cout << "Criteriul nu functioneaza pe acest caz: coeficientii nu sunt numere naturale.\n";
                return 0;
            }
        }

    for(i = 0; i <= nr_monoame; i++)
        if(poli[i])
        {
            inceput = poli[i];
            break;
        }

    for(int i = nr_monoame-1; i >= 0; i--)
        if(int(poli[i]) and (int(poli[i]) % 2 != 0))
        {
            ok = 0;
            break;
        }
    if(ok)
    {
        if(int(poli[nr_monoame]) % 2 != 0 and inceput % 4 != 0)
            return 1;
    }
    else
    {
        ok = 1;
        for(j = 3; j <= maxi; j += 2)
            if(p[j] == 0)
            {
                for(i = nr_monoame-1; i >= 0; i--)
                    if(poli[i] and (int(poli[i]) % j != 0))
                    {
                        ok = 0;
                        break;
                    }
                if(ok)
                    if(int(poli[nr_monoame]) % int(j != 0 and inceput % (j*j) != 0))
                    {
                        cout << "Este ireductibil.\n";
                        return 0;
                    }
            }
    }
    cout << "Este reductibil.\n";
    return 0;
}
