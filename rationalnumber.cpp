#include <iostream>
using namespace std;

class Rational {
public:
int n, d;

Rational(int n = 0, int d = 1) {
this->n = n;
this->d = d;
}

Rational operator+(const Rational& r) const {
int new_n = n * r.d + r.n * d;
int new_d = d * r.d;
return Rational(new_n, new_d);
}

Rational operator-(const Rational& r) const {
int new_n = n * r.d - r.n * d;
int new_d = d * r.d;
return Rational(new_n, new_d);
}

void print() const {
cout << n << "/" << d << endl;
}
};

int main() {
int n1, d1;
cin >> n1 >> d1;
Rational r1(n1, d1);

int n2, d2;
cin >> n2 >> d2;
Rational r2(n2, d2);

Rational sum = r1 + r2;
sum.print();

Rational diff = r1 - r2;
diff.print();

return 0;
}
