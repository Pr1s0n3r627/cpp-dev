#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x) {
int low = 0, high = n - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == x) return mid;
else if (arr[mid] < x) low = mid + 1;
else high = mid - 1;
}
return -1;
}

int main() {
int n, x;
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];
cin >> x;

int result = binarySearch(arr, n, x);
if (result != -1) cout << result << endl;
else cout << "Product not found in the inventory" << endl;

return 0;
}
