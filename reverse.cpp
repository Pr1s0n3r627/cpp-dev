#include <iostream>
#include <string>
using namespace std;

void reverseString(string s) {
    if (s.empty()) return;
    reverseString(s.substr(1));
    cout << s[0];
}

int main() {
string s;
getline(cin, s);
reverseString(s);
cout << endl;
return 0;
}
