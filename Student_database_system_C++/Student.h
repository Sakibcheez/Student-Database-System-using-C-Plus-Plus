#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    std::string name;
    int roll;  // Changed from 'id' to 'roll' for clarity
    std::string email;
    std::string phoneNumber;
    int age;

    Student();
    Student(std::string name, int roll, std::string email, std::string phoneNumber, int age);
    void displayInfo() const;
};

#endif
