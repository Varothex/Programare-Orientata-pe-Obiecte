#include <bits/stdc++.h>
#include "Monom.h"
#include "Polinom.h"
#include "Polinom_ireductibil.h"

using namespace std;

int main()
{
    /*Monom x, y, z;
    cin >> x >> y >> z;
    cout << x << y << z;

    Monom copiex = x;
    cout << copiex;*/

    Monom x(3, 4.0), y(4, 5.0), z(5, 6.0);
    x.print();
    y.print();
    z.print();

    Polinom_ireductibil xyz(5);
    xyz.add(&x);
    xyz.add(&y);
    xyz.add(&z);
    xyz.print();

    xyz.ireductibil();

    cout << "\n";

    /*Monom a, b, c;
    cin >> a >> b >> c;
    cout << a << b << c;

    Polinom abc;
    cin >> abc;
    cout << abc;*/

    Monom a(1, 3), b(5, 34), c(10, 5);
    a.print();
    b.print();
    c.print();

    Polinom_ireductibil abc(10);
    abc.add(&a);
    abc.add(&b);
    abc.add(&c);
    abc.print();

    abc.ireductibil();

    /*Polinom_ireductibil qwerty;
    cout << qwerty.nr_monoame;

    qwerty.print();*/

    return 0;
}
