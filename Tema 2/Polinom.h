#ifndef POLINOM_H
#define POLINOM_H
#include "Monom.h"

class Polinom
{
    public:
        int nr_monoame;
        float *poli;
        Monom *m;

        friend class Polinom_ireductibil;

        Polinom(int n);

        Polinom(const Polinom &p);

        void add(Monom *mo);

        bool ireductibil();

        void print();

        ~Polinom();
};

#endif
