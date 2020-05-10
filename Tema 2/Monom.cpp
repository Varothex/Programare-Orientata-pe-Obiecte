#include <iostream>
#include "Monom.h"
#include "Polinom.h"
#include "Polinom_ireductibil.h"

using namespace std;

/**Cerinta 6: Polinoame reprezentate ca tablouri unidimensionale (prin gradul polinomului si
vectorul coeficientilor)

Se dau urmatoarele clase:
- Clasa Monom(int grad, float coef);
- Clasa Polinom(int nr_monoame, Monom *m);
- Polinom_ireductibil: Polinom.

Dacă vi se pare mai natural, puteți sa aveți clasa Polinom ca clasa de baza pentru
Polinom_Ireductibil și pentru Polinom_reductibil:
- Clasa Polinom(int nr_monoame, Monom *m) – clasa abstracta;
- Polinom_ireductibil: Polinom;
- Polinom_reductibil: Polinom.

Afisarea unui polinom reductibil să fie făcută ca produs de 2 polinoame.

Clasa derivata trebuie sa contina o metoda care sa aplice criteriul lui Eisenstein de verificare
a ireductibilitatii polinoamelor.*/

int main()
{
    Monom x(3, 4.0), y(4, 5.0), z(5, 6.0);
    x.print();
    y.print();
    z.print();

    Polinom xyz(5);
    xyz.add(&x);
    xyz.add(&y);
    xyz.add(&z);
    xyz.print();

    xyz.ireductibil();

    cout << "\n";

    Monom a(1, 3), b(5, 34), c(10, 5);
    a.print();
    b.print();
    c.print();

    Polinom abc(10);
    abc.add(&a);
    abc.add(&b);
    abc.add(&c);
    abc.print();

    abc.ireductibil();

    return 0;
}
