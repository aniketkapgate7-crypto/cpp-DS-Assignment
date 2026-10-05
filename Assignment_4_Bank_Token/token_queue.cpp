// QUEUE - token queue with priority
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
        for (int i = 0; i < 20; i++) name[rear][i] = n[i];   // copy name
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Serving Token " << token[front] << " - " << name[front] << endl;
        front++;
    }

    void display() {
        if (isEmpty()) { cout << "  (empty)\n"; return; }
        for (int i = front; i <= rear; i++)
            cout << "  Token " << token[i] << " - " << name[i] << endl;
    }
};

int main() {
    Queue priorityQ, regularQ;
    int choice, token = 1, age;
    char name[20], ch;

    do {
        cout << "\n1. Issue Token\n2. Serve Next\n3. Show Queues\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
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
        }
        else if (choice == 2) {
            if (!priorityQ.isEmpty()) priorityQ.dequeue();
            else regularQ.dequeue();
        }
        else if (choice == 3) {
            cout << "Priority Queue:\n"; priorityQ.display();
            cout << "Regular Queue:\n";  regularQ.display();
        }
    } while (choice != 0);

    return 0;
}
