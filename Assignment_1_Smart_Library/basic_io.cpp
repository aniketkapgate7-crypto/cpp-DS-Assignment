#include <iostream>
#include <string>

using namespace std;

int main() {
    int id1, id2, id3;
    string title1, title2, title3;

    // Book 1
    cout << "Enter the ID of Book 1: ";
    cin >> id1;
    cin.ignore();
    cout << "Enter the Title of Book 1: ";
    getline(cin, title1);

    // Book 2
    cout << "Enter the ID of Book 2: ";
    cin >> id2;
    cin.ignore();
    cout << "Enter the Title of Book 2: ";
    getline(cin, title2);

    // Book 3
    cout << "Enter the ID of Book 3: ";
    cin >> id3;
    cin.ignore();
    cout << "Enter the Title of Book 3: ";
    getline(cin, title3);

    // Display Books
    cout << "\n==== LIBRARY BOOKS ====\n";
    cout << "Book ID: " << id1 << "\nTitle: " << title1 << "\n\n";
    cout << "Book ID: " << id2 << "\nTitle: " << title2 << "\n\n";
    cout << "Book ID: " << id3 << "\nTitle: " << title3 << "\n";

    return 0;
}