#include <iostream>
using namespace std;

int countOccurrences(int arr[], int size, int target) {
int count = 0;
for (int i = 0; i < size; ++i) {
if (arr[i] == target) {
++count;
}
}
return count;
}

int main() {
int n, target;

cout << "Enter the number of elements in the array: ";
cin >> n;

int* arr = new int[n];

cout << "Enter the elements of the array: ";
for (int i = 0; i < n; ++i) {
cin >> arr[i];
}

cout << "Enter the target element to count: ";
cin >> target;

int result = countOccurrences(arr, n, target);

cout << result << endl;

delete[] arr;
return 0;
}
