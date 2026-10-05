// MENU DRIVEN - (Bank Token Management System)
#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    char name[MAX][20];
    int token[MAX];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }
    bool isEmpty() { return front > rear; }

    void enqueue(int t, char n[]) {
        if (rear == MAX - 1) { cout << "Queue is full\n"; return; }
        rear++;
        token[rear] = t;
        for (int i = 0; i < 20; i++) name[rear][i] = n[i];
    }

    // gives back token and name of the customer removed
    bool dequeue(int &t, char n[]) {
        if (isEmpty()) return false;
        t = token[front];
        for (int i = 0; i < 20; i++) n[i] = name[front][i];
        front++;
        return true;
    }

    void display() {
        if (isEmpty()) { cout << "  (empty)\n"; return; }
        for (int i = front; i <= rear; i++)
            cout << "  Token " << token[i] << " - " << name[i] << endl;
    }
};

// ---------- Stack ----------
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
        for (int i = 0; i < 20; i++) name[top][i] = n[i];
    }

    void display() {
        if (isEmpty()) { cout << "  (no history)\n"; return; }
        for (int i = top; i >= 0; i--)
            cout << "  Token " << token[i] << " - " << name[i] << endl;
    }
};

// ---------- Main Menu ----------
int main() {
    Queue priorityQ, regularQ;
    Stack history;
    int choice, token = 1, age, t;
    char name[20], n[20], ch;

    do {
        cout << "\n===== BANK TOKEN SYSTEM =====\n";
        cout << "1. Issue Token\n";
        cout << "2. Serve Next Customer\n";
        cout << "3. Show Waiting Customers\n";
        cout << "4. Show Served History\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Name: ";  cin >> name;
            cout << "Age: ";   cin >> age;
            cout << "Differently-abled (y/n): "; cin >> ch;
            if (age >= 60 || ch == 'y' || ch == 'Y') {
                priorityQ.enqueue(token, name);
                cout << "Token " << token << " added to PRIORITY queue\n";
            } else {
                regularQ.enqueue(token, name);
                cout << "Token " << token << " added to REGULAR queue\n";
            }
            token++;
            break;

        case 2:
            if (priorityQ.dequeue(t, n) || regularQ.dequeue(t, n)) {
                cout << "Serving Token " << t << " - " << n << endl;
                history.push(t, n);
            } else {
                cout << "No customers waiting\n";
            }
            break;

        case 3:
            cout << "Priority Queue:\n"; priorityQ.display();
            cout << "Regular Queue:\n";  regularQ.display();
            break;

        case 4:
            cout << "Served History (latest first):\n";
            history.display();
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}