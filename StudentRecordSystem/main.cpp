#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
struct Student {
    int id;
    std::string name;
    int age;
    float grade;
};

std::string FileName = "temp/student.txt";
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
    std::cout << "Student Added Successfully!\n";
};

void displayStudents()
{
    if(students.empty())
    {
        std::cout << "\nNo Students Available\n";
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
    
    for(auto student: students)
    {
        if(student.id == studentId)
        {
            printStudentDetail(student);
            return;
        }
    }

    std::cout << "Student Not Found\n";
};

void updateStudent()
{
    int updateId;
    std::cout << "Enter Student ID To Search: ";
    std::cin >> updateId;

    for(auto& student: students)
    {
        if(updateId == student.id)
        {
            student = getStudentDetails();
            std::cout << "Student Updated Successfully!\n";
            return;
        }
    }
    std::cout << "Student not found!\n";
}

void deleteStudent()
{
    int deleteId;
    std::cout << "Enter Student ID To Search: ";
    std::cin >> deleteId;

    for(size_t i = 0; i < students.size(); i++)
    {
        if(students[i].id == deleteId)
        {
            students.erase(students.begin() + i);
            std::cout << "Student deleted successfully!\n";
            return;
        }
    }
    std::cout << "Student not found!\n";
};

void saveToFile()
{
    std::ofstream outFile(FileName);

    if(!outFile)
    {
        std::cout << "Error Opening file for writing!\n";
        return;
    }
    for(const auto student: students)
    {
        outFile << student.id << " " << student.name << " " << student.age << " " << student.grade << "\n"; 
    }
    outFile.close();
    std::cout << "Data Saved Successfully!\n";
};

void loadFromFile()
{
    std::ifstream inFile(FileName);
    if(!inFile)
    {
        std::cout << "No previous data found.\n";
        return;
    }
    Student student;
    while (inFile >> student.id) {
        inFile.ignore();
        inFile >> student.name >> student.age >> student.grade;
        students.push_back(student);
    }

    inFile.close();
};

int main()
{
    loadFromFile();
    int choice;

    do
    {
        std::cout << "\n1. Add Student\n2. Display Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Save & Exit\nChoose: ";
        std::cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: saveToFile(); std::cout << "Exiting... \n"; break;
            default: std::cout << "Invalid Choice! Try Again.\n";
        }
    }while(choice != 6);

    return 0;
}