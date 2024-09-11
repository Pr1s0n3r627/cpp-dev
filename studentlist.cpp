#include <iostream>
#include <string>
using namespace std;

struct Student {
string name;
int id;
Student* next;
Student(string n, int i) : name(n), id(i), next(nullptr) {}
};

class StudentList {
public:
Student* head;
StudentList() : head(nullptr) {}

void add(string name, int id) {
Student* newStudent = new Student(name, id);
if (!head) head = newStudent;
else {
Student* temp = head;
while (temp->next) temp = temp->next;
temp->next = newStudent;
}
}

string search(int id) {
Student* temp = head;
while (temp) {
if (temp->id == id) return temp->name;
temp = temp->next;
}
return "Student not found";
}
};

int main() {
int n, searchId;
cin >> n;
StudentList list;
for (int i = 0; i < n; ++i) {
string name;
int id;
cin >> name >> id;
list.add(name, id);
}
cin >> searchId;
cout << list.search(searchId) << endl;
return 0;
}
