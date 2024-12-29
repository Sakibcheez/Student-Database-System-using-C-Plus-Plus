#include "Database.h"
#include <fstream>
#include <iostream>

Database::Database(const std::string &fname) : filename(fname) {
    loadFromFile();
}

void Database::loadFromFile() {
    std::ifstream file(filename);
    if (file) {
        std::string name, email, phoneNumber;
        int roll, age;
        while (file >> roll >> name >> email >> phoneNumber >> age) {
            students.emplace_back(name, roll, email, phoneNumber, age);
        }
    }
    file.close();
}

void Database::saveToFile() {
    std::ofstream file(filename);
    for (const auto& student : students) {
        file << student.roll << " " << student.name << " " << student.email << " "
             << student.phoneNumber << " " << student.age << std::endl;
    }
    file.close();
}

void Database::addStudent(const Student &student) {
    students.push_back(student);
    saveToFile();
}

void Database::displayAllStudents() {
    int count = 1;
    for (const auto &student : students) {
        std::cout << "Student-" << count << std::endl;
        student.displayInfo();
        std::cout << std::endl;
        count++;
    }
}

void Database::searchByRoll(int roll) {
    for (const auto &student : students) {
        if (student.roll == roll) {
            student.displayInfo();
            return;
        }
    }
    std::cout << "Student with roll " << roll << " not found.\n";
}

void Database::sortByRoll() {
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.roll < b.roll;
    });
}

void Database::sortByAge() {
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.age < b.age;
    });
}
