#include <iostream>
#include <map>
using namespace std;

struct Node {
int coeff;
int exp;
Node* next;
};

Node* createNode(int coeff, int exp) {
Node* newNode = new Node();
newNode->coeff = coeff;
newNode->exp = exp;
newNode->next = nullptr;
return newNode;
}

void printPolynomial(Node* head) {
if (!head) {
cout << "Empty Polynomial";
return;
}
Node* temp = head;
bool first = true;
while (temp) {
if (!first && temp->coeff >= 0) cout << " + ";
if (temp->coeff != 0) cout << temp->coeff << "x^" << temp->exp;
temp = temp->next;
first = false;
}
}

Node* insertNode(Node* head, int coeff, int exp) {
Node* newNode = createNode(coeff, exp);
if (!head) return newNode;

Node* temp = head;
while (temp->next != nullptr) {
temp = temp->next;
}
temp->next = newNode;
return head;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
map<int, int> polyMap;

Node* temp = poly1;
while (temp) {
polyMap[temp->exp] += temp->coeff;
temp = temp->next;
}

temp = poly2;
while (temp) {
polyMap[temp->exp] += temp->coeff;
temp = temp->next;
}

Node* resultHead = nullptr;

for (auto it = polyMap.rbegin(); it != polyMap.rend(); ++it) {
if (it->second != 0) {
resultHead = insertNode(resultHead, it->second, it->first);
}
}

return resultHead;
}

int main() {
int n1, n2;
Node* poly1 = nullptr;
Node* poly2 = nullptr;

cout << "Enter the first polynomial:" << endl;
cout << "Enter the number of terms in the polynomial: ";
cin >> n1;
for (int i = 0; i < n1; i++) {
int coeff, exp;
cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
cin >> coeff >> exp;
poly1 = insertNode(poly1, coeff, exp);
}

cout << "Enter the second polynomial:" << endl;
cout << "Enter the number of terms in the polynomial: ";
cin >> n2;
for (int i = 0; i < n2; i++) {
int coeff, exp;
cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
cin >> coeff >> exp;
poly2 = insertNode(poly2, coeff, exp);
}

if (!poly1 && !poly2) {
cout << "Both polynomials are empty." << endl;
return 0;
}

cout << "Polynomial 1: ";
printPolynomial(poly1);
cout << endl;

cout << "Polynomial 2: ";
printPolynomial(poly2);
cout << endl;

Node* result = addPolynomials(poly1, poly2);

cout << "Addition Result: ";
printPolynomial(result);
cout << endl;

return 0;
}
