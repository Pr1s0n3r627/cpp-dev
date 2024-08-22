#include <iostream>
using namespace std;

void toBinary(int n) {
if (n == 0) return;
toBinary(n / 2);
cout << n % 2;
}

void toOctal(int n) {
if (n == 0) return;
toOctal(n / 8);
cout << n % 8;
}

void toHexadecimal(int n) {
if (n == 0) return;
toHexadecimal(n / 16);
int rem = n % 16;
if (rem < 10) cout << rem;
else cout << char(rem - 10 + 'A');
}

int main() {
int decimalNumber, choice;
cout << "Enter a non-negative decimal number: ";
cin >> decimalNumber;
cout << "Enter your choice (1 for Binary, 2 for Octal, 3 for Hexadecimal): ";
cin >> choice;

switch(choice) {
case 1:
if (decimalNumber == 0) cout << 0;
else toBinary(decimalNumber);
cout << endl;
break;
case 2:
if (decimalNumber == 0) cout << 0;
else toOctal(decimalNumber);
cout << endl;
break;
case 3:
if (decimalNumber == 0) cout << 0;
else toHexadecimal(decimalNumber);
cout << endl;
break;
default:
cout << "Invalid choice. Please select 1, 2, or 3" << endl;
}

return 0;
}
