#include <iostream>
#include <map>
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
while (head != nullptr) {
if (head->coefficient != 0) {
cout << head->coefficient << "x^" << head->exponent;
if (head->next != nullptr) {
cout << " + ";
}
}
head = head->next;
}
cout << endl;
}

Node* multiplyPolynomials(Node* poly1, Node* poly2) {
map<int, int> resultMap;  

while (poly1 != NULL) {
Node* current = poly2;
while (current != NULL) {
int coeff = poly1->coefficient * current->coefficient;
int exp = poly1->exponent + current->exponent;

resultMap[exp] += coeff;
current = current->next;
}
poly1 = poly1->next;
}

Node* result = NULL;
for (auto it = resultMap.rbegin(); it != resultMap.rend(); ++it) { 
if (it->second != 0) {
result = insertInOrder(result, it->second, it->first);
}
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
if (n1 == 0 && n2 == 0) {
cout << "Both polynomials are empty." << endl;
return 0;
}

Node* poly2 = NULL;
for (int i = 0; i < n2; i++) {
cin >> coeff >> exp;
poly2 = insertInOrder(poly2, coeff, exp);
}

Node* result = multiplyPolynomials(poly1, poly2);

printPolynomial(poly1);
printPolynomial(poly2);
printPolynomial(result);

return 0;
}