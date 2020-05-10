#include <iostream>
#include "Polinom.h"

using namespace std;

bool p[1000];

int prime(int A, int B)
{
    if(!B)
        return A;
    return prime(B, A%B);
}

bool ciur(int n)
{
    int i, j;

    for(i = 0; i <= n; i++)
        p[i] = 0;
    p[0] = 1;
    p[1] = 1;
    for(i = 4; i <= n; i += 2)
        p[i] = 1;
    for(i = 3; i <= n; i += 2)
        if(p[i] == 0)
            for(j = 2; j <= n/i; j++)
                p[i*j] = 1;
    return p;
}

Polinom::Polinom(int n)
{
    nr_monoame = n;
    poli = new float[n+1];
    for(int i = 0; i <= n; i++)
        poli[i] = 0;
}

Polinom::Polinom(const Polinom &p)
{
  nr_monoame = p.nr_monoame;
  poli = new float[nr_monoame+1];
    for(int i = 0; i <= nr_monoame; i++)
        poli[i] = p.poli[i];
}

void Polinom::add(Monom *mo)
{
    m = mo;
    poli[m -> grad] += m -> coef;
}

bool Polinom::ireductibil()
{
    int i, j, inceput;
    bool ok = 1;

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
        for(j = 3; j <= nr_monoame; j += 2)
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

void Polinom::print()
{
    for(int i = nr_monoame; i >= 0; i--)
        cout << poli[i] << "x^" << i << " ";
    cout << "\n";
}

Polinom::~Polinom()
{
    nr_monoame = 0;
    delete[] poli;
}
