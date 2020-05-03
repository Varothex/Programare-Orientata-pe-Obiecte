#ifndef MONOM_H
#define MONOM_H


class Monom
{
    int grad;
    float coef;

    public:
        friend class Polinom;

        Monom(int g=0, float c=0);

        Monom(const Monom &mon);

        void print();

        ~Monom();
};

#endif // MONOM_H
