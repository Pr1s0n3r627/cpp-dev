#include<iostream>
using namespace std;

struct B {
    int b;
};

void d(B* x, int a) {
    x->b += a;
}

void w(B* x, int a) {
    if (x->b >= a)
        x->b -= a;
    else
        cout << "Insufficient funds. Current balance: " << x->b << endl;
}

int main() {
    int i, j, k;
    cin >> i >> j >> k;
    B x = {i};
    d(&x, j);
    w(&x, k);
    if (x.b >= 0)
        cout << "New balance: " << x.b << endl;
}
