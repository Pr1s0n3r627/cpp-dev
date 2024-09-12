#include <iostream>
using namespace std;

struct Node {
int data;
Node* next;
};

Node* insertAtEnd(Node* head, int value) {
Node* newNode = new Node();
newNode->data = value;
newNode->next = nullptr;
if (!head) return newNode;
Node* temp = head;
while (temp->next) temp = temp->next;
temp->next = newNode;
return head;
}

void printList(Node* head) {
while (head) {
cout << head->data << " ";
head = head->next;
}
cout << endl
}

int main() {
Node* head = nullptr;
int value;
while (cin.peek() != '\n') {
cin >> value;
head = insertAtEnd(head, value);
}
cin.clear();
cin.ignore();
cin >> value;
head = insertAtEnd(head, value);
printList(head);
return 0;
}
