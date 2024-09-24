#include <iostream>
#include <cmath>
using namespace std;

struct Node {
int c, e;
Node* next;
Node(int _c, int _e) : c(_c), e(_e), next(nullptr) {}
};

void printPoly(Node* head) {
Node* t = head;
bool first = true;
while (t) {
if (!first) cout << " + ";
cout << t->c << "x^" << t->e;
t = t->next;
first = false;
}
cout << '\n';
}

int main() {
int n, x, res = 0, sumE = 0, allC0 = 1;
cin >> n;

if (n == 0) {
cout << "Polynomial is empty\n";
return 0;
}

Node* head = nullptr;
Node* tail = nullptr;  // To maintain the correct order
for (int i = 0; i < n; ++i) {
int c, e;
cin >> c >> e;
if (c != 0) allC0 = 0;
sumE += e;
Node* t = new Node(c, e);
if (!head) {
head = tail = t;
} else {
tail->next = t;
tail = t;
}
}

if (allC0) {
cout << "zero, Operation not possible\n";
return 0;
}

printPoly(head);
cin >> x;
cout << "Value of x: " << x << '\n';

Node* t = head;
while (t) {
res += t->c * pow(x, t->e);
t = t->next;
}

if (sumE == 0) {
cout << "Sum of exponents is zero, divisibility check is not applicable\n";
} else if (res % sumE == 0) {
cout << "For x = " << x << ", the evaluated result " << res << " is divisible by the sum of exponents " << sumE << ".\n";
} else {
cout << "For x = " << x << ", the evaluated result " << res << " is not divisible by the sum of exponents " << sumE << ".\n";
}

return 0;
}
