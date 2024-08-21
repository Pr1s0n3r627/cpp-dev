#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
int n;
cin >> n;

vector<int> arr(n);
for (int i = 0; i < n; i++) {
cin >> arr[i];
}

if (n < 3) {
sort(arr.begin(), arr.end());
cout << arr[n - 1] << endl;
} else {
nth_element(arr.begin(), arr.begin() + n - 3, arr.end());
cout << arr[n - 3] << endl;
}

return 0;
}