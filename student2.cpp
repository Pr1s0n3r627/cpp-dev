#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
char name[31];
char regNo[16];
char branch[16];
int semester;

public:
void enterInfo() {
cin.getline(name, 31);
cin.getline(regNo, 16);
cin.getline(branch, 16);
cin >> semester;
cin.ignore();
}

void displayInfo() {
cout << "Name:" << name << endl;
cout << "Registration Number:" << regNo << endl;
cout << "Branch:" << branch << endl;
cout << "Semester:" << semester << endl;
}
};

int main() {
Student s;
s.enterInfo();
s.displayInfo();
return 0;
}