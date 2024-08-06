#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    string course;
    float cgpa;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Course: ";
    getline(cin, s.course);
    cout << "Enter CGPA: ";
    cin >> s.cgpa;
    students.push_back(s);
    cout << "Student added successfully!" << endl;
}

void displayStudents() {
    for (const auto& s : students) {
        cout << "Roll Number: " << s.rollNo << endl;
        cout << "Name: " << s.name << endl;
        cout << "Course: " << s.course << endl;
        cout << "CGPA: " << s.cgpa << endl;
        cout << "------------------------" << endl;
    }
}

void searchStudent() {
    int rollNo;
    cout << "Enter Roll Number to search: ";
    cin >> rollNo;
    for (const auto& s : students) {
        if (s.rollNo == rollNo) {
            cout << "Roll Number: " << s.rollNo << endl;
            cout << "Name: " << s.name << endl;
            cout << "Course: " << s.course << endl;
            cout << "CGPA: " << s.cgpa << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void deleteStudent() {
    int rollNo;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNo;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNo == rollNo) {
            students.erase(it);
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
