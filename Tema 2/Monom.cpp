#include "Monom.h"

using namespace std;

istream &operator >> (istream &input, Monom &m1)
{
    input >> m1.grad;
    input >> m1.coef;
    return input;
}

ostream &operator << (ostream &output, Monom m1)
{
    output << m1.coef << "x^" << m1.grad << "\n";
    return output;
}

Monom::Monom(int g, float c)
{
    grad = g;
    coef = c;
}

Monom::Monom(const Monom &mon) = default;

Monom::~Monom() = default;

void Monom::print()
{
    cout << coef << "x^" << grad << "\n";
}
