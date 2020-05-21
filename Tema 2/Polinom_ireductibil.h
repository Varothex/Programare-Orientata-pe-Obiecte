#ifndef POLINOM_IREDUCTIBIL_H
#define POLINOM_IREDUCTIBIL_H
#include "Polinom.h"

class Polinom_ireductibil: public Polinom
{
public:

    friend std::istream &operator >>(std::istream &input, Polinom &p1);

    friend std::ostream &operator <<(std::ostream &output, Polinom p1);

    Polinom_ireductibil(int n=1);

    Polinom_ireductibil(const Polinom &p);

    ~Polinom_ireductibil();

    bool ireductibil();
};

#endif
