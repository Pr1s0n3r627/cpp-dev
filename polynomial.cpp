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
newNode->next = temp->next;
temp->next = newNode;
}
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
cin >> n;
Node* poly = nullptr;
for (int i = 0; i < n; ++i) {
cin >> c >> p;
insert(poly, c, p);
}
display(poly);
return 0;
}
