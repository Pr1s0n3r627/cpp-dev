#include <iostream>
using namespace std;

int fab(int n) {
    if (n == 1 || n == 0) {
        return n;
    } else {
        return fab(n - 1) + fab(n - 2);
    }
}

int main() {
    int k;
    cin >> k;
    int t = fab(k - 1);
    cout << t << endl;
    return 0;
}
