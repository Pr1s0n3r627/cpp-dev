#include <iostream>
#include <climits>

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

int findMax() {
if (head == nullptr) {
return INT_MIN;
}

int max_value = head->data;
Node* current = head->next;

while (current != nullptr) {
if (current->data > max_value) {
max_value = current->data;
}
current = current->next;
}

return max_value;
}
};

int main() {
LinkedList list;
int size;

cout << "Enter the size of the linked list: ";
cin >> size;

cout << "Enter the elements of the linked list: ";
for (int i = 0; i < size; ++i) {
int value;
cin >> value;
list.insertAtBeginning(value);
}

int max_value = list.findMax();
cout << "The maximum value in the linked list is: " << max_value << endl;

return 0;
}
