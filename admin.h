#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include "Student.h"
#include "Task.h"
#include <vector>
using namespace std;

class Admin : public Person {
public:
    // Constructor
    Admin(string name, string id, string password);

    // Student management
    void addStudent(vector<Student>& students, string name, string id, string password);
    void viewAllStudents(const vector<Student>& students) const;

    // Task management
    void assignTask(vector<Student>& students, string studentId, Task t);
    void evaluateStudent(vector<Student>& students, string studentId, string taskId, int marks);

    // Attendance
    void markAttendance(vector<Student>& students, string studentId, string record);

    // Promote student to admin
    void promoteToAdmin(vector<Student>& students, string studentId);

    // Override displayInfo
    void displayInfo() const override;

    // Destructor
    ~Admin();
};

#endif