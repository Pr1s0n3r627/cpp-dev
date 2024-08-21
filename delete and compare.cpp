#include <iostream>
using namespace std;

int main() {
int arr[5];
int n = 5;
int position;
int comparisons = 0;

for(int i = 0; i < n; i++) {
cin >> arr[i];
}

for(int i = 0; i < n; i++) {
cout << arr[i] << endl;
}

cout << "Enter position of element to delete: ";
cin >> position;

if(position < 1 || position > n) {
cout << "Invalid Position\n";
cout << "Comparsions: 0\n";
} else {
position--;

for(int i = position; i < n - 1; i++) {
arr[i] = arr[i + 1];
comparisons++;
}

n--;

for(int i = 0; i < n; i++) {
cout << arr[i] << endl;
}

cout << "Comparsions: " << comparisons+1 << endl;
}

return 0;
}
