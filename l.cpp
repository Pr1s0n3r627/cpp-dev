#include<bits/stdc++.h>
using namespace std;
struct Node {
int coff;
int exp;
Node* next;
Node(int c, int e) {
coff = c;
exp = e;
next = NULL;
}
};
void insert(Node*& poly, int c, int e) {
Node* newnode = new Node(c, e);
if (!poly || poly->exp < e) {
newnode->next = poly;
poly = newnode;
return;
}
Node* temp = poly;
while (temp->next != NULL && temp->next->exp > e) {
temp = temp->next;
}
newnode->next = temp->next;
temp->next = newnode;
}
void deletenode(Node*& poly, int x) {
if (!poly) return;
if (poly->exp == x) {
Node* toDelete = poly;
poly = poly->next;
delete toDelete;
return;
}
Node* temp = poly;
while (temp->next && temp->next->exp != x) {
temp = temp->next;
}
if (temp->next && temp->next->exp == x) {
Node* toDelete = temp->next;
temp->next = temp->next->next;
delete toDelete;
}
}
void display(Node* poly) {
Node* temp = poly;
bool first = true;
while (temp) {
if (!first) {
cout << " + ";
}
cout << temp->coff << "x^" << temp->exp;
first = false;
temp = temp->next;
}
cout << endl;
}
int main() {
Node* poly = NULL;
int n;
cin >> n;
for (int i = 0; i < n; i++) {
int c, e;
cin >> c >> e;
insert(poly, c, e);
}
int x;
cin >> x;
deletenode(poly, x);
display(poly);
return 0;
}