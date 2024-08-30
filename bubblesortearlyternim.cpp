#include <iostream>
#include <vector>
using namespace std;

int main() {
int n;
cin >> n;

vector<int> array(n);
for (int i = 0; i < n; i++) {
cin >> array[i];
}

int passes = 0;
bool swapped;

do {
swapped = false;
passes++;
for (int i = 0; i < n - 1; i++) {
if (array[i] > array[i + 1]) {
swap(array[i], array[i + 1]);
swapped = true;
}
}
} while (swapped);

cout << passes << endl;

for (int i = 0; i < n; i++) {
cout << array[i] << " ";
}
cout << endl;

return 0;
}
