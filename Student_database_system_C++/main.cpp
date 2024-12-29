#include <iostream>
#include "Utils.h"
#include "Database.h"

using namespace std;

int main() {
    Database db("students.txt");
    int choice;
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            registerUser();
            // Fall through to login
        case 2:
            login();
            break;
        default:
            cout << "Invalid choice.\n";
            return 1;
    }

    showMenu(db);  // Pass database object to the menu
    return 0;
}
