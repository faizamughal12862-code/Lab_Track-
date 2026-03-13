#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Task.h"
#include <vector>
using namespace std;

class Student : public Person {
private:
    vector<Task> tasks;
    vector<string> attendance;

public:
    // Constructor
    Student(string name, string id, string password);

    // Getters for file saving
    vector<Task> getTasks() const { return tasks; }
    vector<string> getAttendance() const { return attendance; }

    // Task functions
    void addTask(Task t);
    void submitTask(string taskId, string answer);
    void viewTasks() const;
    void viewGrades() const;

    // Task marks
    void setTaskMarks(string taskId, int marks);
    bool isTaskSubmitted(string taskId) const;

    // Attendance functions
    void markAttendance(string record);
    void viewAttendance() const;

    // Override displayInfo from Person
    void displayInfo() const override;

    // Destructor
    ~Student();
};

#endif


// #ifndef STUDENT_H
// #define STUDENT_H

// #include "Person.h"
// #include "Task.h"
// #include <vector>
// using namespace std;

// class Student : public Person {
// private:
//     vector<Task> tasks;
//     vector<string> attendance;

// public:
//     // Constructor
//     Student(string name, string id, string password);

//     // Getters for file saving
//     vector<Task> getTasks() const { return tasks; }
//     vector<string> getAttendance() const { return attendance; }

//     // Task functions
//     void addTask(Task t);
//     void viewTasks() const;
//     void viewGrades() const;

//     // Task marks
//     void setTaskMarks(string taskId, int marks);

//     // Attendance functions
//     void markAttendance(string record);
//     void viewAttendance() const;

//     // Override displayInfo from Person
//     void displayInfo() const override;

//     // Destructor
//     ~Student();
// };

// #endif


// #ifndef STUDENT_H
// #define STUDENT_H

// #include "Person.h"
// #include "Task.h"
// #include <vector>
// using namespace std;

// class Student : public Person {
// private:
//     vector<Task> tasks;
//     vector<string> attendance;

// public:
//     // Constructor
//     Student(string name, string id, string password);

//     // Task functions
//     void addTask(Task t);
//     void viewTasks() const;
//     void viewGrades() const;

//     // Task marks
//     void setTaskMarks(string taskId, int marks);

//     // Attendance functions
//     void markAttendance(string record);
//     void viewAttendance() const;

//     // Override displayInfo from Person
//     void displayInfo() const override;

//     // Destructor
//     ~Student();
// };

// #endif


// #ifndef STUDENT_H
// #define STUDENT_H

// #include "Person.h"
// #include "Task.h"
// #include <vector>
// using namespace std;

// class Student : public Person {
// private:
//     vector<Task> tasks;
//     vector<string> attendance;

// public:
//     // Constructor
//     Student(string name, string id, string password);

//     // Task functions
//     void addTask(Task t);
//     void viewTasks() const;
//     void viewGrades() const;

//     // Attendance functions
//     void markAttendance(string record);
//     void viewAttendance() const;

//     // Override displayInfo from Person
//     void displayInfo() const override;

//     // Destructor
//     ~Student();
// };

// #endif