#include <iostream>

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
a ireductibilitatii polinoamelor. (Webografie ajutatoare: http://www.profesoronline.ro/teorie-
3140-1.html)*/

class Monom
{
    int grad;
    float coef;

public:

    friend class Polinom;

    Monom(int g, float c)
    {
        grad = g;
        coef = c;
    }

    void print()
    {
        cout << coef << "x^" << grad << "\n";
    }
};

class Polinom
{
    int nr_monoame;
    Monom *m;
    int *poli;

public:

    Polinom(int n)
    {
        nr_monoame = n;
        poli = new int[n];
        for(int i = 1; i <= n; i++)
            poli[i] = 0;
    }

    void add(Monom *mo)
    {
        m = mo;
        poli[m -> grad] = m -> coef;
    }

    void print()
    {
        for(int i = nr_monoame; i > 0; i--)
            cout << poli[i] << "x^" << i << " ";
        cout << "\n";
    }

};

int main()
{
    Monom x(3, 4.0), y(4, 5.0), z(5, 6.0);
    x.print();
    y.print();
    z.print();
    //! Citim Polinom(grad) pentru a face loc in vector. Dupa, in functie de grad, citim
    //! monoamele si le copiem in vector, fiecare pe casuta corespunzatoare gradului lui
    Polinom a(5);
    a.add(&x);
    a.add(&y);
    a.add(&z);
    cout << "\n";
    a.print();
    return 0;
}
