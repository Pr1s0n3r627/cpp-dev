#include <iostream>
#include <string>
using namespace std;

struct Order {
string name;
int id;
Order* next;
Order(string n, int i) : name(n), id(i), next(nullptr) {}
};

class OrderList {
public:
Order* head;
OrderList() : head(nullptr) {}

void addOrder(string name, int id) {
Order* newOrder = new Order(name, id);
if (!head) head = newOrder;
else {
Order* temp = head;
while (temp->next) temp = temp->next;
temp->next = newOrder;
}
}

void removeOrder(int id) {
Order *temp = head, *prev = nullptr;
while (temp) {
if (temp->id == id) {
if (prev) prev->next = temp->next;
else head = temp->next;
delete temp;
cout << "Order has been deleted" << endl;
return;
}
prev = temp;
temp = temp->next;
}
cout << "Order does not exist" << endl;
}
};

int main() {
int n, removeId;
cin >> n;
OrderList list;
for (int i = 0; i < n; ++i) {
string name;
int id;
cin >> name >> id;
list.addOrder(name, id);
}
cin >> removeId;
list.removeOrder(removeId);
return 0;
}
