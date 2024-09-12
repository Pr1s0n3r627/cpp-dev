#include <iostream>
using namespace std;

struct Node {
int data;
Node* next;
};

void printList(Node* head) {
if (!head) {
cout << "List is empty";
return;
}
Node* temp = head;
do {
cout << temp->data << " ";
temp = temp->next;
} while (temp != head);
}

Node* deleteFirst(Node* head) {
if (!head) return nullptr;
if (head->next == head) {
delete head;
return nullptr;
}
Node* temp = head;
while (temp->next != head) temp = temp->next;
Node* toDelete = head;
temp->next = head->next;
head = head->next;
delete toDelete;
return head;
}

int main() {
int n;
cin >> n;
if (n < 2) {
cout << "List is empty" << endl << "List is empty";
return 0;
}

Node* head = nullptr;
Node* temp = nullptr;
Node* last = nullptr;

for (int i = 0; i < n; i++) {
int price;
cin >> price;
Node* newNode = new Node();
newNode->data = price;
if (!head) {
head = newNode;
head->next = head;
last = head;
} else {
last->next = newNode;
newNode->next = head;
last = newNode;
}
}

printList(head);
cout << endl;

head = deleteFirst(head);
printList(head);
return 0;
}
