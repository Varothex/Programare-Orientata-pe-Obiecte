#ifndef POLINOM_IREDUCTIBIL_H
#define POLINOM_IREDUCTIBIL_H
#include "Polinom.h"

class Polinom_ireductibil: public Polinom
{
public:

    friend istream &operator >>(istream& input, Polinom &p1);

    friend ostream &operator <<(ostream& output, Polinom p1);

    Polinom_ireductibil(int n=1);

    Polinom_ireductibil(const Polinom &p);

    ~Polinom_ireductibil();

    bool ireductibil();
};

#endif
