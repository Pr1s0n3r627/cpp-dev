#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
int n;
cout << "Enter number of students" << endl;
cin >> n;
vector<int> enrollments(n);
cout << "Enter enroll no. of " << n << " students" << endl;

for (int i = 0; i < n; i++) {
cin >> enrollments[i];
}

set<int> seen;
vector<int> filtered;

for (int i = 0; i < n; i++) {
if (seen.find(enrollments[i]) == seen.end()) {
seen.insert(enrollments[i]);
filtered.push_back(enrollments[i]);
}
}

cout << "Updated list of students after removing duplicate entries" << endl;
for (int i = 0; i < filtered.size(); i++) {
cout << filtered[i] << endl;
}

return 0;
}