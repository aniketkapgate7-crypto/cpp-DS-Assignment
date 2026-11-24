#include <iostream>
using namespace std;

struct Order {
    int id;
    char name[30];
    int itemCode;
};

// 1. Regular Queue (FIFO)
Order regQueue[10];
int rFront = 0, rRear = 0;

// 2. VIP Priority Queue
Order vipQueue[10];
int vFront = 0, vRear = 0;

// 3. Cancelled Orders Stack (LIFO)
Order cancelStack[10];
int top = -1;

int orderCounter = 1;

// Simple Recursive Menu
int showMenu(int step) {
    int choice;
    if (step == 1) {
        cout << "\n1. Starters  2. Main Course  3. Drinks\nChoose category: ";
        cin >> choice;
        return showMenu(choice + 1); // Recursive call
    }
    if (step == 2) {
        cout << "1. Paneer Tikka  2. Spring Roll (0 to go back): ";
        cin >> choice;
        if (choice == 0) return showMenu(1); // Recursion back
        return 10 + choice;
    }
    if (step == 3) {
        cout << "1. Veg Biryani  2. Dal Rice (0 to go back): ";
        cin >> choice;
        if (choice == 0) return showMenu(1);
        return 20 + choice;
    }
    cout << "1. Cold Coffee  2. Lime Soda (0 to go back): ";
    cin >> choice;
    if (choice == 0) return showMenu(1);
    return 30 + choice;
}

void placeOrder(bool isVIP) {
    Order o;
    o.id = orderCounter++;
    cout << "Enter Customer Name (one word): ";
    cin >> o.name;
    o.itemCode = showMenu(1);

    if (isVIP) {
        vipQueue[vRear++] = o;
        cout << "VIP Order #" << o.id << " placed!\n";
    } else {
        regQueue[rRear++] = o;
        cout << "Regular Order #" << o.id << " placed!\n";
    }
}

void prepareOrder() {
    // VIP Queue always goes first
    if (vFront < vRear) {
        Order o = vipQueue[vFront++];
        cout << "Preparing VIP Order #" << o.id << " for " << o.name << " (Item " << o.itemCode << ")\n";
    } else if (rFront < rRear) {
        Order o = regQueue[rFront++];
        cout << "Preparing Regular Order #" << o.id << " for " << o.name << " (Item " << o.itemCode << ")\n";
    } else {
        cout << "No pending orders!\n";
    }
}

void cancelOrder() {
    if (vFront < vRear) {
        cancelStack[++top] = vipQueue[vFront++];
        cout << "Cancelled VIP Order #" << cancelStack[top].id << "\n";
    } else if (rFront < rRear) {
        cancelStack[++top] = regQueue[rFront++];
        cout << "Cancelled Regular Order #" << cancelStack[top].id << "\n";
    } else {
        cout << "Nothing to cancel!\n";
    }
}

void viewCancelled() {
    if (top == -1) {
        cout << "No cancelled orders.\n";
        return;
    }
    cout << "\n--- Cancelled Orders (Latest First) ---\n";
    for (int i = top; i >= 0; i--) {
        cout << "Order #" << cancelStack[i].id << " - " << cancelStack[i].name << "\n";
    }
}

int main() {
    int ch;
    do {
        cout << "\n1. Regular Order  2. VIP Order  3. Prepare Next  4. Cancel Order  5. Cancelled History  6. Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) placeOrder(false);
        else if (ch == 2) placeOrder(true);
        else if (ch == 3) prepareOrder();
        else if (ch == 4) cancelOrder();
        else if (ch == 5) viewCancelled();
    } while (ch != 6);
    return 0;
}