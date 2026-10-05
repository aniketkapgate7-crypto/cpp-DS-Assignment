// STACK  - history of recently served customers
#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char name[MAX][20];
    int token[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    void push(int t, char n[]) {
        if (top == MAX - 1) { cout << "Stack is full\n"; return; }
        top++;
        token[top] = t;
        for (int i = 0; i < 20; i++) name[top][i] = n[i];   // copy name
    }

    void pop() {
        if (isEmpty()) { cout << "History is empty\n"; return; }
        cout << "Removed Token " << token[top] << " - " << name[top] << endl;
        top--;
    }

    void display() {
        if (isEmpty()) { cout << "  (no history)\n"; return; }
        for (int i = top; i >= 0; i--)          // latest first
            cout << "  Token " << token[i] << " - " << name[i] << endl;
    }
};

int main() {
    Stack history;
    int choice, token;
    char name[20];

    do {
        cout << "\n1. Add Served Customer\n2. Remove Last\n3. Show History\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Token: "; cin >> token;
            cout << "Name: ";  cin >> name;
            history.push(token, name);
        }
        else if (choice == 2) history.pop();
        else if (choice == 3) {
            cout << "Recently served (latest first):\n";
            history.display();
        }
    } while (choice != 0);

    return 0;
}

