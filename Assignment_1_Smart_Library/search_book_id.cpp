#include <iostream>

using namespace std;

int main() {
    int book[5];
    int searchID;

    cout << "Enter 5 book IDs:\n";
    for (int i = 0; i < 5; i++) {
        cin >> book[i];
    }

    cout << "\nEnter searchID: ";
    cin >> searchID;

    for (int i = 0; i < 5; i++) {
        if (book[i] == searchID) {
            cout << "Book found!\n";
            return 0;
        }
    }

    cout << "Book not found!\n";
    return 0;
}