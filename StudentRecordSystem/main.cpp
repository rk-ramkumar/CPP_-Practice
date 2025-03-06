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

// Helper methods
void printStudentDetail(Student student)
{
    std::cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << "\n";
};

Student getStudentDetails()
{
    Student student;
    std::cout << "Enter ID: ";
    std::cin >> student.id;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, student.name);
    std::cout << "Enter Age: ";
    std::cin >> student.age;
    std:: cout << "Enter Grade: ";
    std::cin >> student.grade;

    return student;
};

// Main methods
void addStudent()
{
    Student student = getStudentDetails();

    students.push_back(student);
    std::cout << "Student added successfully!\n";
};

void displayStudents()
{
    if(students.empty())
    {
        std::cout << "\nNo students available\n";
        return;
    }
    std::cout << "\n--- Student Records ---\n";
    for(const auto student : students)
    {
        std::cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << "\n";
    };
};



void searchStudent()
{
    int studentId;
    std::cout << "Enter Student ID To Search: ";
    std::cin >> studentId;
    
    for(const auto student: students)
    {
        if(student.id == studentId)
        {
            printStudentDetail(student);
            return;
        }
    }

    std::cout << "Student Not Found\n";
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