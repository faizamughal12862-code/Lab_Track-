#include "Admin.h"
#include <iostream>
using namespace std;

// Constructor — role is hardcoded as "admin"
Admin::Admin(string name, string id, string password)
    : Person(name, id, password, "admin") {
}

// Add a new student to the system
void Admin::addStudent(vector<Student>& students, string name, string id, string password) {
    // check if id already exists
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            cout << "Student with ID " << id << " already exists." << endl;
            return;
        }
    }
    Student s(name, id, password);
    students.push_back(s);
    cout << "Student " << name << " added successfully." << endl;
}

// View all students
void Admin::viewAllStudents(const vector<Student>& students) const {
    if (students.empty()) {
        cout << "No students in the system yet." << endl;
        return;
    }
    cout << "=== ALL STUDENTS ===" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "--------------------" << endl;
        students[i].displayInfo();
    }
}

// Assign a task to a specific student by ID
void Admin::assignTask(vector<Student>& students, string studentId, Task t) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == studentId) {
            students[i].addTask(t);
            cout << "Task assigned to " << students[i].getName() << " successfully." << endl;
            return;
        }
    }
    cout << "Student with ID " << studentId << " not found." << endl;
}

// Give marks to a student for a specific task
void Admin::evaluateStudent(vector<Student>& students, string studentId, string taskId, int marks) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == studentId) {
            students[i].setTaskMarks(taskId, marks);
            cout << "Marks updated successfully." << endl;
            return;
        }
    }
    cout << "Student with ID " << studentId << " not found." << endl;
}

// Mark attendance for a student
void Admin::markAttendance(vector<Student>& students, string studentId, string record) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == studentId) {
            students[i].markAttendance(record);
            cout << "Attendance marked for " << students[i].getName() << "." << endl;
            return;
        }
    }
    cout << "Student with ID " << studentId << " not found." << endl;
}

// Promote a student to admin
void Admin::promoteToAdmin(vector<Student>& students, string studentId) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == studentId) {
            cout << students[i].getName() << " has been promoted to Admin." << endl;
            cout << "Note: Remove them from students list and create an Admin account." << endl;
            return;
        }
    }
    cout << "Student with ID " << studentId << " not found." << endl;
}

// Override displayInfo
void Admin::displayInfo() const {
    Person::displayInfo();
    cout << "Access : Full Admin Privileges" << endl;
}

// Destructor
Admin::~Admin() {
}