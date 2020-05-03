#include <iostream>
#include "Polinom.h"

using namespace std;

Polinom::Polinom(int n)
{
    nr_monoame = n;
    poli = new int[n];
    for(int i = 0; i <= n; i++)
        poli[i] = 0;
}

void Polinom::add(Monom *mo)
{
    m = mo;
    poli[m -> grad] = m -> coef;
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
