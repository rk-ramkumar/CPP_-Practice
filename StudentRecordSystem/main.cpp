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

void displayStudents()
{
    std::cout << "\n--- Student Records ---\n";
    for(const auto student : students)
    {
        std::cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << "\n";
    };
};

int main()
{
    int choice;

    do
    {
        std::cout << "\n1. Add Student\n2. Display Students\n3. Exit\nChoose: ";
        std::cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: std::cout << "Exiting... \n"; break;
            default: std::cout << "Invalid choice! Try again.\n";
        
        }
    }while(choice != 3);

    return 0;
}