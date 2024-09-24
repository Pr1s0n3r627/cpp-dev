#include <iostream>
#include <map>
using namespace std;
struct Node {
int coeff;
int exp;
Node* next;
Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};
void insertTerm(Node*& head, int coeff, int exp) {
Node* newNode = new Node(coeff, exp);
if (!head) {
head = newNode;
return;
}
Node* temp = head;
while (temp->next != nullptr) {
temp = temp->next;
}
temp->next = newNode;
}
void printPolynomial(Node* head) {
if (!head) {
cout << "Empty Polynomial" << endl;
return;
}
Node* temp = head;
while (temp != nullptr) {
if (temp->coeff > 0 && temp != head)
cout << "+";
if (temp->exp == 0)
cout << temp->coeff;
else if (temp->exp == 1)
cout << temp->coeff << "x";
else
cout << temp->coeff << "x^" << temp->exp;
temp = temp->next;
if (temp != nullptr)
cout << " ";
}
cout << endl;
}
Node* simplifyPolynomial(Node* head) {
if (!head) return nullptr;
map<int, int> termMap;
Node* temp = head;
while (temp != nullptr) {
termMap[temp->exp] += temp->coeff;
temp = temp->next;
}
Node* simplifiedHead = nullptr;
for (auto it = termMap.rbegin(); it != termMap.rend(); ++it) {
if (it->second != 0) {
insertTerm(simplifiedHead, it->second, it->first);
}
}
return simplifiedHead;
}
int main() {
Node* poly = nullptr;
int n;
cout << "Enter the number of terms in the polynomial: ";
cin >> n;
if (n == 0) {
cout << "Empty Polynomial" << endl;
return 0;
}
for (int i = 0; i < n; i++) {
int coeff, exp;
cout << "Enter the coefficient and exponent for term " << i + 1 << ": ";
cin >> coeff >> exp;
insertTerm(poly, coeff, exp);
}
cout << "Original Polynomial: ";
printPolynomial(poly);
Node* simplifiedPoly = simplifyPolynomial(poly);
if (!poly && !simplifiedPoly) {
cout << "Empty Polynomial" << endl;
} else {
cout << "Simplified Polynomial: ";
printPolynomial(simplifiedPoly);
}
return 0;
}
