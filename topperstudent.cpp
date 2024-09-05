#include<iostream>
using namespace std;

struct S {
    int id, m;
};

int main() {
    int n, mx = -1;
    cin >> n;
    S s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i].id >> s[i].m;
        if (s[i].m > mx)
            mx = s[i].m;
    }
    for (int i = 0; i < n; i++) {
        if (s[i].m == mx)
            cout << "ID: " << s[i].id << ", Marks: " << s[i].m << endl;
    }
}
