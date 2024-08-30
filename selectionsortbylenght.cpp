#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
int n;
cin >> n;
cin.ignore();

vector<string> books(n);
for (int i = 0; i < n; i++) {
getline(cin, books[i]);
}

for (int i = 0; i < n - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < n; j++) {
if (books[j].length() < books[minIndex].length()) {
minIndex = j;
}
}
if (minIndex != i) {
swap(books[i], books[minIndex]);
}
}

for (const auto& book : books) {
cout << book << endl;
}

return 0;
}
