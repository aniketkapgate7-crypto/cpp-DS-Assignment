#include <iostream>

using namespace std;

int main() {
    int book[10];
    int n = 0;
    int choice;
    int searchID;

    for (;;) {
        cout << "\n================ SMART LIBRARY ================";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        // If user typed letters, words, or caused an input failure
        if (cin.fail()) {
            cin.clear();              // Reset the error flag
            cin.ignore(10000, '\n');  // Discard bad input up to the newline
            cout << "Invalid input! Please enter a number.\n";
            continue;                 // Jump to the next iteration
        }

        if (choice == 1) {
            if (n < 10) {
                cout << "Enter book ID: ";
                cin >> book[n];

                // Validate book ID input as well
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid book ID! Book was not added.\n";
                } else {
                    n++;
                    cout << "Book added!\n";
                }
            } else {
                cout << "Storage limit reached!\n";
            }
        } else if (choice == 2) {
            if (n == 0) {
                cout << "\nNo books in library.\n";
            } else {
                cout << "\nBooks in library:\n";
                for (int i = 0; i < n; i++) {
                    cout << book[i] << endl;
                }
            }
        } else if (choice == 3) {
            cout << "Enter book ID to search: ";
            cin >> searchID;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid ID entered!\n";
            } else {
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (book[i] == searchID) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    cout << "Book found!\n";
                } else {
                    cout << "Book not found!\n";
                }
            }
        } else if (choice == 4) {
            cout << "Thank you!\n";
            break;
        } else {
            cout << "Invalid choice! Enter a number between 1 and 4.\n";
        }
    }

    return 0;
}