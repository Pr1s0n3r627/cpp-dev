#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
string name;
int id;
};

void addEmployee(vector<Employee>& directory, const string& name, int id) {
Employee newEmployee;
newEmployee.name = name;
newEmployee.id = id;
directory.push_back(newEmployee);
}

int main() {
vector<Employee> directory;
int n;
cin >> n;

for (int i = 0; i < n; i++) {
string name;
int id;
cin >> name >> id;
addEmployee(directory, name, id);
}

if (directory.empty()) {
cout << "No employees in the directory" << endl;
} else {
for (const auto& employee : directory) {
cout << employee.id << endl;
}
}

return 0;
}