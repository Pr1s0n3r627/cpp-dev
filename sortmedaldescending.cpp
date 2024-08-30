#include <iostream>
#include <vector>
using namespace std;

int main() {
int n;
cin >> n;

vector<int> medals(n);
for (int i = 0; i < n; i++) {
cin >> medals[i];
}

for (int i = 1; i < n; i++) {
int key = medals[i];
int j = i - 1;

while (j >= 0 && medals[j] < key) {
medals[j + 1] = medals[j];
j = j - 1;
}
medals[j + 1] = key;
}

for (int i = 0; i < n; i++) {
cout << medals[i] << " ";
}

return 0;
}
