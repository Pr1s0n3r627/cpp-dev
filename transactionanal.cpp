#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
int n;
cin >> n;

if (n < 4) {
cout << "Array must have at least 4 elements" << endl;
return 0;
}

vector<int> arr(n);

for (int i = 0; i < n; ++i) {
cin >> arr[i];
}

sort(arr.begin(), arr.end());

for (int i = 0; i < n; ++i) {
cout << arr[i] << " ";
}
cout << endl;

cout << arr[1] << endl;
cout << arr[n - 2] << endl;

return 0;
}
