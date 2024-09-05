#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title, author, isbn;
    int year;
    float price;
};

void inputBooks(Book books[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Details of the book " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "ISBN: ";
        getline(cin, books[i].isbn);
        cout << "Publication Year: ";
        cin >> books[i].year;
        cout << "Price: ";
        cin >> books[i].price;
        cin.ignore();
    }
}

void displayBooks(Book books[], int n) {
    cout << "Library Books:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". Title: " << books[i].title << ", Author: " << books[i].author
            << ", ISBN: " << books[i].isbn << ", Year: " << books[i].year
            << ", Price: Rs. " << books[i].price << endl;
    }
}

void searchBookByISBN(Book books[], int n, const string& search_isbn) {
    for (int i = 0; i < n; i++) {
        if (books[i].isbn == search_isbn) {
            cout << "Book Found:\nTitle: " << books[i].title << "\nAuthor: " << books[i].author
                << "\nISBN: " << books[i].isbn << "\nYear: " << books[i].year
                << "\nPrice: Rs. " << books[i].price << endl;
            return;
        }
    }
    cout << "Book not found" << endl;
}

int main() {
    int n;
    cout << "Number of books: ";
    cin >> n;
    cin.ignore();
    Book* books = new Book[n];
    inputBooks(books, n);
    displayBooks(books, n);
    cout << "Search for a book by ISBN:\nEnter ISBN: ";
    string search_isbn;
    getline(cin, search_isbn);
    searchBookByISBN(books, n, search_isbn);
    delete[] books;
    return 0;
}
