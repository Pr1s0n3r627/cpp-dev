#include <iostream>
#include <cmath>

using namespace std;
int main() {

    cout << ">>" << std::endl;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout <<  pow(i, i) << " ";
    }

    return 0;
}