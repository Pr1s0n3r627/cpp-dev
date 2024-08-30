#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& a, vector<int>& t, int l, int m, int r) {
int i = l;
int j = m + 1;
int k = l;
long long inv = 0;

while ((i <= m) && (j <= r)) {
if (a[i] <= a[j]) {
t[k++] = a[i++];
} else {
t[k++] = a[j++];
inv += (m + 1) - i;
}
}

while (i <= m)
t[k++] = a[i++];

while (j <= r)
t[k++] = a[j++];

for (i = l; i <= r; i++)
a[i] = t[i];

return inv;
}

long long mergeSort(vector<int>& a, vector<int>& t, int l, int r) {
long long inv = 0;

if (l < r) {
int m = (l + r) / 2;

inv += mergeSort(a, t, l, m);
inv += mergeSort(a, t, m + 1, r);
inv += merge(a, t, l, m, r);
}

return inv;
}

int main() {
int n;
cin >> n;

vector<int> a(n);

for (int i = 0; i < n; i++) {
cin >> a[i];
}

vector<int> t(n);
long long invCount = mergeSort(a, t, 0, n - 1);

cout << invCount << endl;

return 0;
}
