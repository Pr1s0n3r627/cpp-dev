#include <bits/stdc++.h>
using namespace std;

struct book {
string title;
string id;
string author;
int year;
};

void addBook(book *i) {
cin.ignore();
getline(cin, i->title);
getline(cin, i->id);
getline(cin, i->author);
cin >> i->year;
}

void findBook(book arr[], int n, string auth) {
bool found = false;
for (int i = 0; i < n; i++) {
if (arr[i].author == auth) {
if (!found) {
cout << "Books by author " << auth << ":" << endl;
found = true;
}
cout << "Title: " << arr[i].title
<< ", Book ID: " << arr[i].id
<< ", Author: " << arr[i].author
<< ", Publication Year: " << arr[i].year << endl;
}
}
if (!found) {
cout << "No books found by author: " << auth << endl;
}
}

int main() {
int n;
cin >> n;
book *arr = new book[n];

for (int i = 0; i < n; i++) {
addBook(&arr[i]);
}

string auth;
cin.ignore();
getline(cin, auth);

findBook(arr, n, auth);

delete[] arr; // Free the dynamically allocated memory
return 0;
}
