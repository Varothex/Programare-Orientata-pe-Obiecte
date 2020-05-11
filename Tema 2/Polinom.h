#ifndef POLINOM_H
#define POLINOM_H
#include "Monom.h"

class Polinom
{
public:
    int nr_monoame, gradmax;
    float *poli;
    Monom *m;

    friend class Polinom_ireductibil;

    friend istream &operator >>(istream& input, Polinom &p1);

    friend ostream &operator <<(ostream& output, Polinom p1);

    Polinom(int n=1);

    Polinom(const Polinom &p);

    ~Polinom();

    void add(Monom *mo);

    bool ireductibil();

    void print();
};

#endif
