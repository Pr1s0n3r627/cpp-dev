#include<iostream>
#include<vector>
using namespace std;

int main()
{
int n;
cout << "Enter number if students" << endl;
cin >> n;
vector<int> marks(n);
cout << "Enter marks of " << n << " students" << endl;

for (int i = 0; i < n; i++)
{
cin >> marks[i];
}

int minrange, maxrange;
cout << "Enter minimum range" << endl;
cin >> minrange;
cout << "Enter maximum range" << endl;
cin >> maxrange;

int count = 0;
for (int i = 0; i < n; i++)
{
if (marks[i] >= minrange && marks[i] <= maxrange)
{
count++;
}
}
cout << "Number of students in the given range are " << count << endl;
return 0;
}