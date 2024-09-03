#include <iostream>
#include <string>
using namespace std;

struct S {
    string n, r;
    int m;
};

void addS(S*& s, int& c, const string& n, const string& r, int m) {
    S* newS = new S[c + 1];
    for (int i = 0; i < c; ++i)
        newS[i] = s[i];
    newS[c] = {n, r, m};
    delete[] s;
    s = newS;
    ++c;
}

void displaySAboveM(S* s, int c, int t) {
    bool f = false;
    for (int i = 0; i < c; ++i) {
        if (s[i].m > t) {
            cout << "Name: " << s[i].n << ", Roll Number: " << s[i].r << ", Marks: " << s[i].m << endl;
            f = true;
        }
    }
    if (!f) 
        cout << "No students scored above " << t << " marks." << endl;
}

int main() {
    int n, t, c = 0;
    S* s = nullptr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name, roll;
        int marks;
        cin >> name >> roll >> marks;
        addS(s, c, name, roll, marks);
    }
    cin >> t;
    displaySAboveM(s, c, t);
    delete[] s;
    return 0;
}
