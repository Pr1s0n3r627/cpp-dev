#include <iostream>
#include <cmath>
using namespace std;
struct Node {
int coefficient;
int exponent;
Node* next;
};
Node* newNode(int coeff, int exp) {
Node* temp = new Node;
temp->coefficient = coeff;
temp->exponent = exp;
temp->next = NULL;
return temp;
}
Node* insertInOrder(Node* head, int coeff, int exp) {
Node* temp = newNode(coeff, exp);
if (!head || head->exponent < exp) {
temp->next = head;
return temp;
}
Node* curr = head;
while (curr->next && curr->next->exponent >= exp) {
curr = curr->next;
}
temp->next = curr->next;
curr->next = temp;
return head;
}
void printPolynomial(Node* head) {
if (!head) {
cout << "0";
return;
}
Node* temp = head;
bool isFirst = true;
bool hasPrinted = false;
while (temp) {
if (temp->coefficient != 0) {
if (!isFirst && temp->coefficient > 0)
cout << " +";
if (temp->coefficient < 0) {
if(isFirst){
cout << "-";
}
else{
cout << " -";
}
cout << abs(temp->coefficient);
} else if (!isFirst) {
cout << "";
cout << abs(temp->coefficient);
} else {
cout << abs(temp->coefficient);
}
if (temp->exponent != 0) {
cout << "x";
if (temp->exponent != 1) {
cout << "^" << temp->exponent;
}
}
hasPrinted = true;
isFirst = false;
}
temp = temp->next;
}
if (!hasPrinted) {
cout << "0";
}
cout << endl;
}
Node* addPolynomials(Node* poly1, Node* poly2) {
Node* result = NULL;
while (poly1 != NULL || poly2 != NULL) {
int coeff = 0, exp = 0;
if (poly1 == NULL) {
coeff = poly2->coefficient;
exp = poly2->exponent;
poly2 = poly2->next;
} else if (poly2 == NULL) {
coeff = poly1->coefficient;
exp = poly1->exponent;
poly1 = poly1->next;
} else if (poly1->exponent == poly2->exponent) {
coeff = poly1->coefficient + poly2->coefficient;
exp = poly1->exponent;
poly1 = poly1->next;
poly2 = poly2->next;
} else if (poly1->exponent > poly2->exponent) {
coeff = poly1->coefficient;
exp = poly1->exponent;
poly1 = poly1->next;
} else {
coeff = poly2->coefficient;
exp = poly2->exponent;
poly2 = poly2->next;
}
result = insertInOrder(result, coeff, exp);
}
return result;
}
int evaluate(Node* head, int x) {
int result = 0;
Node* temp = head;
while (temp) {
result += temp->coefficient * pow(x, temp->exponent);
temp = temp->next;
}
return result;
}
int main() {
int n1, n2, coeff, exp;
cin >> n1;
Node* poly1 = NULL;
for (int i = 0; i < n1; i++) {
cin >> coeff >> exp;
poly1 = insertInOrder(poly1, coeff, exp);
}
cin >> n2;
Node* poly2 = NULL;
for (int i = 0; i < n2; i++) {
cin >> coeff >> exp;
poly2 = insertInOrder(poly2, coeff, exp);
}
int x;
cin >> x;
Node* result = addPolynomials(poly1, poly2);
printPolynomial(poly1);
printPolynomial(poly2);
printPolynomial(result);
int evalResult = evaluate(result, x);
cout << x << ": " << evalResult << endl;
return 0;
}