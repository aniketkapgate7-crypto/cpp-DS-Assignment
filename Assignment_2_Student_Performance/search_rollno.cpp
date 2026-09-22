#include <iostream>

using namespace std;

int main() {
    int student[5];
    int searchID;

    cout << "Enter 5 student roll numbers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> student[i];
    }

    cout << "\nEnter searchID: ";
    cin >> searchID;

    for (int i = 0; i < 5; i++) {
        if (student[i] == searchID) {
            cout << "STUDENT FOUND!\n";
            return 0;
        }
    }

    cout << "STUDENT NOT FOUND!\n";
    return 0;
}