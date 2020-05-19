#include <iostream>
#include "Polinom.h"

using namespace std;

void Polinom::add(Monom *mo)
{
    m = mo;
    poli[m -> grad] += m -> coef;
}

void Polinom::print()
{
    for(int i = nr_monoame; i >= 0; i--)
        cout << poli[i] << "x^" << i << " ";
    cout << "\n";
}
