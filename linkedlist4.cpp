#include <iostream>
using namespace std;

struct Node {
int data;
Node* next;
};

Node* deleteMiddle(Node* head) {
if (!head || !head->next) {
cout << "No node left" << endl;
return nullptr;
}

Node *slow = head, *fast = head, *prev = nullptr;

while (fast && fast->next) {
prev = slow;
slow = slow->next;
fast = fast->next->next;
}

prev->next = slow->next;
delete slow;
return head;
}

void printList(Node* head) {
if (!head) return;
while (head) {
cout << head->data << " ";
head = head->next;
}
cout << endl;
}

int main() {
Node* head = nullptr;
Node* temp = nullptr;
int x;

while (cin >> x) {
Node* newNode = new Node();
newNode->data = x;
newNode->next = nullptr;
if (!head) {
head = newNode;
} else {
temp->next = newNode;
}
temp = newNode;

if (cin.peek() == '\n') break;
}

head = deleteMiddle(head);
if (head) {
printList(head);
}

return 0;
}
