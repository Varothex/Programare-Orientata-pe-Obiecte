#ifndef POLINOM_H
#define POLINOM_H
#include "Monom.h"

class Polinom
{
    int nr_monoame, *poli;
    Monom *m;

    public:
        Polinom(int n);

        void add(Monom *mo);

        void print();

        ~Polinom();
};

#endif // POLINOM_H
