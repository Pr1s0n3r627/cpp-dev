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

int sumEven(Node* head) {
int sum = 0;
while (head) {
if (head->data % 2 == 0) sum += head->data;
head = head->next;
}
return sum;
}

int main() {
int n, x;
cin >> n;
Node* head = nullptr;
for (int i = 0; i < n; ++i) {
cin >> x;
head = insertFront(head, x);
}
cout << sumEven(head);
}
