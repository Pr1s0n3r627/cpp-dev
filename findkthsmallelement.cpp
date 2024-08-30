#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
int n, K;
cin >> n;

vector<int> treasures(n);
for (int i = 0; i < n; i++) {
cin >> treasures[i];
}

cin >> K;

if (K < 1 || K > n) {
cout << "Invalid value of K. It should be between 1 and " << n << "." << endl;
return 0;
}

sort(treasures.begin(), treasures.end());

cout << treasures[K - 1] << endl;

return 0;
}
