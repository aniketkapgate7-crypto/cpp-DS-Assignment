#include<iostream>
using namespace std;

void restaurantmenu()
{
    int choice;

    cout << "*...............RESTAURANT MENU.................*" << endl;
    cout << "1. Pizza " << endl;
    cout << "2. Burger " << endl;
    cout << "3. Pasta" << endl;
    cout << "4. Exit " << endl;

    cout << "ENTER YOUR CHOICE :" << endl;
    cin>>choice;

if (choice == 1)
{
    cout << "YOU SELECTED PIZZA " << endl;
    restaurantmenu();

}

else if (choice==2)
{
    cout << "YOU SELECTED BURGER " << endl;
    restaurantmenu();

}

else if (choice==3)
{
    cout << "YOU SELECTED PASTA " << endl;
    restaurantmenu();


}

else if (choice==4)
{
    cout << "THANK YOU FOR EXITING... " << endl;
    return;

}

else
{
    cout << "INVALID CHOICE ! PLEASE TRY AGAIN..." << endl;
    restaurantmenu();


}
}
int main()
{
    restaurantmenu();

    return 0;


}