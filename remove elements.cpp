#include <iostream>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int* arr = new int[n];
    int sum = 0, oddCount = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (sum % 2 != 0) {
        cout << "0\n";
    }
    else {
        if (oddCount > 0) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }

    return 0;
}
