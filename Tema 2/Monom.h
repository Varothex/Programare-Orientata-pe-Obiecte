#include <iostream>
#ifndef MONOM_H
#define MONOM_H

using namespace std;

class Monom
{
public:
    int grad;
    float coef;

    friend class Polinom;

    friend istream &operator >>(istream& input, Monom &m1);

    friend ostream &operator <<(ostream& output, Monom m1);

    Monom &operator = (Monom const &m1) = default;

    Monom(int g=0, float c=0);

    Monom(const Monom &mon);

    ~Monom();

    void print();
};

#endif
