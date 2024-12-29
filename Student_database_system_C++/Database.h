#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include <vector>
#include <string>
#include <algorithm> // For sorting

class Database {
private:
    std::vector<Student> students;
    std::string filename;

public:
    Database(const std::string &filename);
    void loadFromFile();
    void saveToFile();
    void addStudent(const Student &student);
    void displayAllStudents();
    void searchByRoll(int roll);
    void sortByRoll();
    void sortByAge();
};

#endif
