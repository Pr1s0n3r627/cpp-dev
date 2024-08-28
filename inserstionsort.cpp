#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
vector<float> arr(6);

// Take input for the array
for (int i = 0; i < 6; i++) {
cin >> arr[i];
}

// Sort the array
sort(arr.begin(), arr.end());

// Output the sorted array
for (int i = 0; i < 6; i++) {
cout << arr[i] << " "; // Fixed the output statement
}

cout << endl;

return 0;
}
