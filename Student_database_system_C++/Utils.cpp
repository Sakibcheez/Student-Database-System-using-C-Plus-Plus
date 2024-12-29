#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>

void registerUser() {
    std::string username, password;
    std::cout << "Enter new username: ";
    std::cin >> username;
    std::cout << "Enter new password: ";
    std::cin >> password;

    std::ofstream file("users.txt", std::ios::app); // Open in append mode to add new users
    if (!file) {
        std::cerr << "Failed to open or create users.txt for writing.\n";
        return;
    }
    file << username << " " << password << std::endl;
    file.close();
    std::cout << "User registered successfully!\n";
}

void login() {
    std::string username, password, un, pw;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream file("users.txt");
    if (!file) {
        std::cerr << "Error opening users.txt. Please check if the file exists and is readable." << std::endl;
        return;
    }
    bool isLoggedIn = false;
    while (file >> un >> pw) {
        if (un == username && pw == password) {
            isLoggedIn = true;
            break;
        }
    }
    file.close();
    if (isLoggedIn) {
        std::cout << "Login successful!\n";
    } else {
        std::cout << "Invalid username or password.\n";
    }
}

void showMenu(Database& db) {
    int choice;
    do {
        std::cout << "\n1. Add Student\n2. Display All Students\n3. Search By Roll\n4. Sort By Roll\n5. Sort By Age\n0. Exit\nEnter choice: ";
        std::cin >> choice;
        std::string name, email, phoneNumber;
        int roll, age;

        switch (choice) {
            case 1:  // Add student
                std::cout << "Enter name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter roll number: ";
                std::cin >> roll;
                std::cout << "Enter email: ";
                std::cin >> email;
                std::cout << "Enter phone number: ";
                std::cin >> phoneNumber;
                std::cout << "Enter age: ";
                std::cin >> age;
                db.addStudent(Student(name, roll, email, phoneNumber, age));
                break;
            case 2:  // Display all students
                db.displayAllStudents();
                break;
            case 3:  // Search by roll
                std::cout << "Enter roll number to search: ";
                std::cin >> roll;
                db.searchByRoll(roll);
                break;
            case 4:  // Sort by roll
                db.sortByRoll();
                db.displayAllStudents();
                break;
            case 5:  // Sort by age
                db.sortByAge();
                db.displayAllStudents();
                break;
            case 0:  // Exit
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);
}
