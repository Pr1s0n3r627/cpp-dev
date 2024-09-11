#include <iostream>
#include <vector>
using namespace std;

int main() {
int n, x;
vector<int> v;
cin >> n;
for (int i = 0; i < n; i++) {
cin >> x;
v.push_back(x);
}
for (int i = 0; i < n; i++) cout << v[i] << " ";
bool is_palindrome = true;
for (int i = 0; i < n / 2; i++) {
if (v[i] != v[n - i - 1]) {
is_palindrome = false;
break;
}
}
cout << "\n" << (is_palindrome ? "Palindrome" : "Not Palindrome");
return 0;
}
