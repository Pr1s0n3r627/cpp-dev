#include <iostream>
using namespace std;

void shift(int *x, int *y, int *z, int n) {
while (n--) {
int temp = *x;
*x = *z;
*z = *y;
*y = temp;
}
}

int main() {
int x, y, z, n;
cin >> x >> y >> z >> n;
shift(&x, &y, &z, n);
cout << x << " " << y << " " << z;
return 0;
}
