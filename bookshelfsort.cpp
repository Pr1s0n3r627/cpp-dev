#include <iostream>
#include <vector>
#include <string>

using namespace std;

void insertionSort(vector<int>& b) {
    int n = b.size();
    
    for (int i = 1; i < n; i++) {
        int key = b[i];
        int j = i - 1;

        while (j >= 0 && b[j] > key) {
            b[j + 1] = b[j];
            j = j - 1;
        }
        b[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    insertionSort(b);
    
    string s;
    for (int i : b) s += to_string(i) + " ";
    cout << s;
    return 0;
}
