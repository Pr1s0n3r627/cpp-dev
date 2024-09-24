#include <iostream>
using namespace std;

struct Node {
int coeff, power;
Node* next;
Node(int c, int p) : coeff(c), power(p), next(nullptr) {}
};

void insert(Node*& head, int c, int p) {
Node* newNode = new Node(c, p);
if (!head || head->power < p) {
newNode->next = head;
head = newNode;
} else {
Node* temp = head;
while (temp->next && temp->next->power > p)
temp = temp->next;
if (temp->power == p) temp->coeff += c;
else {
newNode->next = temp->next;
temp->next = newNode;
}
}
}

Node* addPolynomials(Node* poly1, Node* poly2) {
Node* result = nullptr;
while (poly1 || poly2) {
if (!poly2 || (poly1 && poly1->power > poly2->power)) {
insert(result, poly1->coeff, poly1->power);
poly1 = poly1->next;
} else if (!poly1 || poly2->power > poly1->power) {
insert(result, poly2->coeff, poly2->power);
poly2 = poly2->next;
} else {
insert(result, poly1->coeff + poly2->coeff, poly1->power);
poly1 = poly1->next;
poly2 = poly2->next;
}
}
return result;
}

void display(Node* head) {
while (head) {
if (head->power == 0) cout << head->coeff;
else cout << head->coeff << "x^" << head->power;
if (head->next) cout << " ·+· ";
head = head->next;
}
cout << endl;
}

int main() {
int n, c, p;
Node* poly1 = nullptr;
Node* poly2 = nullptr;

cin >> n;
for (int i = 0; i < n; ++i) {
cin >> c >> p;
insert(poly1, c, p);
}

int m;
cin >> m;
for (int i = 0; i < m; ++i) {
cin >> c >> p;
insert(poly2, c, p);
}

Node* result = addPolynomials(poly1, poly2);
display(result);
return 0;
}
