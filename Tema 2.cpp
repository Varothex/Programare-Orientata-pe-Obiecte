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
        
        /*Monom(g=0, c=0)                           //constructor de initializare
        {
            mon = new int[grad];
        
        }
        
        Vector(const Vector& x1)                    //constructor de copiere
        {
            n = x1.n;
            v = new int[n];
            for(int i = 0; i < n; i++)
                v[i] = x1.v[i];
        }
        
        ~Vector()                                   //destructor
        {
            n = 0;
            delete[] v;
        }*/
};

class Polinom
{
    int nr_monoame, Monom *m;
};

istream& operator >> (istream &input, Monom &mon1)
{
    input >> mon1.grad;                             //citim gradul = index
    input >> mon1.coef;                             //citim coef = element
    return input;
}

/*ostream& operator << (ostream &output, Monom mon1)//output
{
    int n = x1.n;
    output << "[";
    for (int i = 0; i < x1.n-1; i++)
        output << x1[i] << ", ";
    output << x1[n-1] << "]";
    return output;
}*/

int main()
{
    
    return 0;
}
