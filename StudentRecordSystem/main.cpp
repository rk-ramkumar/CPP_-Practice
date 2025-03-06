#include <iostream>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    int age;
    float grade;
};

std::vector<Student> students;

void addStudent()
{
    Student s;
    std::cout << "Enter ID: ";
    std::cin >> s.id;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, s.name);
    std::cout << "Enter Age: ";
    std::cin >> s.age;
    std:: cout << "Enter grade: ";
    std::cin >> s.grade;

    students.push_back(s);
    std::cout << "Student added successfully!\n";
};

int main()
{
    return 0;
}