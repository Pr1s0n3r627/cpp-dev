#include <iostream>
using namespace std;

struct Node {
int data;
Node* next;
};

Node* insertFront(Node* head, int data) {
Node* newNode = new Node{data, head};
return newNode;
}

int findMiddle(Node* head) {
Node *slow = head, *fast = head;
while (fast && fast->next) {
slow = slow->next;
fast = fast->next->next;
}
return slow->data;
}

int main() {
int n, x;
cin >> n;
Node* head = nullptr;
for (int i = 0; i < n; ++i) {
cin >> x;
head = insertFront(head, x);
}
cout << findMiddle(head);
}
