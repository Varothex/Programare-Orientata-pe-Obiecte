#ifndef POLINOM_H
#define POLINOM_H
#include "Monom.h"

class Polinom
{
public:
    int nr_monoame, gradmax;
    float *poli;
    Monom *m;

    void add(Monom *mo);

    void print();
};

#endif
