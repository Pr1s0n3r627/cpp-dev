#include <iostream>
#include <map>
using namespace std;

int main() {
int a, sku;
string name;
map<int, string> inventory;
cin >> a;
while (a--) {
cin >> name >> sku;
inventory[sku] = name;
}
cin >> sku;
if (inventory.erase(sku)) cout << "Item Deleted" << endl;
else cout << "Item does not exist" << endl;
return 0;
}
