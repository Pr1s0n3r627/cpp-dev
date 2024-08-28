#include <iostream>
using namespace std;

void find_nth(int n, int a = 0, int b = 1) {
    if (n == 0) {
        cout << a << endl;
        return;
    }
    if (n == 1) {
        cout << b << endl;
        return;
    }
    find_nth(n - 1, b, a + b);
}

int main() {
    int n;
    cin >> n;
    find_nth(n);
    return 0;
}
