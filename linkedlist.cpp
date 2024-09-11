#include <iostream>
using namespace std;

struct Node {
int data;
Node* next;

Node(int val) {
data = val;
next = nullptr;
}
};

class LinkedList {
public:
Node* head;

LinkedList() {
head = nullptr;
}

void insertAtBeginning(int data) {
Node* newNode = new Node(data);
newNode->next = head;
head = newNode;
}

int findNthFromEnd(int n) {
Node* first = head;
Node* second = head;

for (int i = 0; i < n; ++i) {
if (first == nullptr) return -1;
first = first->next;
}

while (first != nullptr) {
first = first->next;
second = second->next;
}

return second ? second->data : -1;
}
};

int main() {
LinkedList list;
int size, n;

cout << "Enter the size of the linked list: ";
cin >> size;

cout << "Enter the elements of the linked list: ";
for (int i = 0; i < size; ++i) {
int value;
cin >> value;
list.insertAtBeginning(value);
}

cout << "Enter the position from the end: ";
cin >> n;

int result = list.findNthFromEnd(n);
cout << result << endl;

return 0;
}
