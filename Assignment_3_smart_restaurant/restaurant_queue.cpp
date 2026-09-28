#include<iostream>
#include<string>
using namespace std;

int main()
{
    int order[5];
    int front = 0;
    int rear = 0;

    cout << "ENTER 5 CUSTOMER ORDER ID :" << endl;

    for (int i = 0 ; i < 5 ;i++)
    {
        cin >> order[rear];
        rear++;

    }

    cout << "THE ORDER NUMBER ARE : " <<endl;

    while(front < rear)
    {
        cout << "ORDER IS PROCESSING : " << order[front] << endl;
        front++;
    }

    return 0;
}