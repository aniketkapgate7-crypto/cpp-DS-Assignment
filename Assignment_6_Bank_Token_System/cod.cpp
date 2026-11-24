#include <iostream>
using namespace std;

struct Token {
    int tokenNo;
    char name[30];
    int type; // 1 = General, 2 = Priority
};

// 1. General Queue (FIFO)
Token genQueue[10];
int gFront = 0, gRear = 0;

// 2. Priority Queue (Senior / Differently-Abled)
Token prioQueue[10];
int pFront = 0, pRear = 0;

// 3. Served History Stack (LIFO)
Token servedStack[10];
int top = -1;

int nextToken = 101;

void issueToken(int type) {
    Token t;
    t.tokenNo = nextToken++;
    t.type = type;
    cout << "Enter Customer Name (one word): ";
    cin >> t.name;

    if (type == 2) {
        prioQueue[pRear++] = t;
        cout << "Priority Token #" << t.tokenNo << " issued to " << t.name << "\n";
    } else {
        genQueue[gRear++] = t;
        cout << "General Token #" << t.tokenNo << " issued to " << t.name << "\n";
    }
}

void serveCustomer() {
    Token current;
    // Priority Queue always served first
    if (pFront < pRear) {
        current = prioQueue[pFront++];
    } else if (gFront < gRear) {
        current = genQueue[gFront++];
    } else {
        cout << "No customers waiting!\n";
        return;
    }

    cout << "Serving Token #" << current.tokenNo << " (" << current.name << ")\n";
    servedStack[++top] = current; // Push to history stack
}

void showServedHistory() {
    if (top == -1) {
        cout << "No customers served yet.\n";
        return;
    }
    cout << "\n--- Recently Served (Latest First) ---\n";
    for (int i = top; i >= 0; i--) {
        cout << "Token #" << servedStack[i].tokenNo << " - " << servedStack[i].name
             << (servedStack[i].type == 2 ? " [Priority]" : " [General]") << "\n";
    }
}

int main() {
    int ch;
    do {
        cout << "\n1. General Token  2. Priority Token  3. Serve Next  4. Served History  5. Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) issueToken(1);
        else if (ch == 2) issueToken(2);
        else if (ch == 3) serveCustomer();
        else if (ch == 4) showServedHistory();
    } while (ch != 5);
    return 0;
}