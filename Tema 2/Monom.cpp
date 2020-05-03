#include <iostream>
#include "Monom.h"

using namespace std;

Monom::Monom(int g, float c)
{
    grad = g;
    coef = c;
}

void Monom::print()
{
    cout << coef << "x^" << grad << "\n";
}

Monom::Monom(const Monom &mon) = default;

Monom::~Monom() = default;
