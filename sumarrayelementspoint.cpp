#include <iostream>
using namespace std;

int main() {
int n, sum = 0;
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];
for (int *ptr = arr; ptr < arr + n; ptr++) sum += *ptr;
cout << sum;
return 0;
}
