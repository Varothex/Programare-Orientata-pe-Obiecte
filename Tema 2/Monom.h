#include <bits/stdc++.h>
#ifndef MONOM_H
#define MONOM_H

//template <class T>
class Monom
{

public:
    int grad;
    float coef;

    friend class Polinom;

    friend std::istream &operator >>(std::istream &input, Monom &m1);

    friend std::ostream &operator <<(std::ostream &output, Monom m1);

    Monom &operator = (Monom const &m1) = default;

    Monom(int g=0, float c=0)
    {
        grad = g;
        coef = c;
    }

    Monom(const Monom &mon);

    ~Monom();

    void print();
};

#endif
