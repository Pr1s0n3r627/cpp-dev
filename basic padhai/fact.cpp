#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long f = 1;
    if (!n) cout << f << "\n";
    else {
        for (int i = 1; i <= n; i++)
        {
            f *= i;
        }
        cout << f << "\n";
    }
}