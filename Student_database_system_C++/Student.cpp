#include "Student.h"
#include <iostream>

Student::Student() : name(""), roll(0), email(""), phoneNumber(""), age(0) {}

Student::Student(std::string n, int r, std::string e, std::string p, int a)
    : name(n), roll(r), email(e), phoneNumber(p), age(a) {}

void Student::displayInfo() const {
    std::cout << "Name: " << name << "\nRoll: " << roll << "\nEmail: " << email
              << "\nPhone: " << phoneNumber << "\nAge: " << age << std::endl;
}
