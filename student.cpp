#include "Student.h"
#include <iostream>
using namespace std;

// Constructor — notice role is hardcoded as "student"
Student::Student(string name, string id, string password)
    : Person(name, id, password, "student") {
    // Person constructor handles name, id, password, role
    // nothing extra to initialize here
}

// Submit a task with an answer
void Student::submitTask(string taskId, string answer) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getTaskNo() == taskId) {
            if (tasks[i].getIsSubmitted()) {
                cout << "Task already submitted." << endl;
                return;
            }
            tasks[i].setSubmissionText(answer);
            tasks[i].setIsSubmitted(true);
            cout << "Task submitted successfully!" << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}

// Add a task to this student
void Student::addTask(Task t) {
    tasks.push_back(t);
}

// View all assigned tasks
void Student::viewTasks() const {
    if (tasks.empty()) {
        cout << "No tasks assigned yet." << endl;
        return;
    }
    cout << "=== YOUR TASKS ===" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << "--------------------" << endl;
        tasks[i].displayTask();
    }
}

// View grades only
void Student::viewGrades() const {
    if (tasks.empty()) {
        cout << "No tasks assigned yet." << endl;
        return;
    }
    cout << "=== YOUR GRADES ===" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << tasks[i].getTitle() << " : "
             << tasks[i].getObtainedMarks() << " / "
             << tasks[i].getTotalMarks() << endl;
    }
}

bool Student::isTaskSubmitted(string taskId) const {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getTaskNo() == taskId) {
            return tasks[i].getIsSubmitted();
        }
    }
    return false; // task not found
}

// Set marks for a specific task
void Student::setTaskMarks(string taskId, int marks) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getTaskNo() == taskId) {
            if (!tasks[i].getIsSubmitted()) {
                cout << "Cannot evaluate — task has not been submitted yet." << endl;
                return;
            }
            if (marks < 0 || marks > tasks[i].getTotalMarks()) {
                cout << "Invalid marks. Must be between 0 and " << tasks[i].getTotalMarks() << endl;
                return;
            }
            tasks[i].setObtainedMarks(marks);
            cout << "Marks updated successfully." << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}

// Mark attendance — record is something like "2024-03-13 - Present"
void Student::markAttendance(string record) {
    attendance.push_back(record);
}

// View all attendance records
void Student::viewAttendance() const {
    if (attendance.empty()) {
        cout << "No attendance records yet." << endl;
        return;
    }
    cout << "=== ATTENDANCE ===" << endl;
    for (int i = 0; i < attendance.size(); i++) {
        cout << attendance[i] << endl;
    }
}

// Override Person's displayInfo
void Student::displayInfo() const {
    Person::displayInfo();  // print name, id, role from parent
    cout << "Tasks Assigned : " << tasks.size() << endl;
}

// Destructor
Student::~Student() {
    // vector cleans itself up automatically
}

// #include "Student.h"
// #include <iostream>
// using namespace std;

// // Constructor — notice role is hardcoded as "student"
// Student::Student(string name, string id, string password)
//     : Person(name, id, password, "student") {
//     // Person constructor handles name, id, password, role
//     // nothing extra to initialize here
// }

// // Add a task to this student
// void Student::addTask(Task t) {
//     tasks.push_back(t);
// }

// // View all assigned tasks
// void Student::viewTasks() const {
//     if (tasks.empty()) {
//         cout << "No tasks assigned yet." << endl;
//         return;
//     }
//     cout << "=== YOUR TASKS ===" << endl;
//     for (int i = 0; i < tasks.size(); i++) {
//         cout << "--------------------" << endl;
//         tasks[i].displayTask();
//     }
// }

// // View grades only
// void Student::viewGrades() const {
//     if (tasks.empty()) {
//         cout << "No tasks assigned yet." << endl;
//         return;
//     }
//     cout << "=== YOUR GRADES ===" << endl;
//     for (int i = 0; i < tasks.size(); i++) {
//         cout << tasks[i].getTitle() << " : "
//              << tasks[i].getObtainedMarks() << " / "
//              << tasks[i].getTotalMarks() << endl;
//     }
// }

// // Set marks for a specific task
// void Student::setTaskMarks(string taskId, int marks) {
//     for (int i = 0; i < tasks.size(); i++) {
//         if (tasks[i].getTaskNo() == taskId) {
//             tasks[i].setObtainedMarks(marks);
//             return;
//         }
//     }
//     cout << "Task not found." << endl;
// }

// // Mark attendance — record is something like "2024-03-13 - Present"
// void Student::markAttendance(string record) {
//     attendance.push_back(record);
// }

// // View all attendance records
// void Student::viewAttendance() const {
//     if (attendance.empty()) {
//         cout << "No attendance records yet." << endl;
//         return;
//     }
//     cout << "=== ATTENDANCE ===" << endl;
//     for (int i = 0; i < attendance.size(); i++) {
//         cout << attendance[i] << endl;
//     }
// }

// // Override Person's displayInfo
// void Student::displayInfo() const {
//     Person::displayInfo();  // print name, id, role from parent
//     cout << "Tasks Assigned : " << tasks.size() << endl;
// }

// // Destructor
// Student::~Student() {
//     // vector cleans itself up automatically
// }



// #include "Student.h"
// #include <iostream>
// using namespace std;

// // Constructor — notice role is hardcoded as "student"
// Student::Student(string name, string id, string password)
//     : Person(name, id, password, "student") {
//     // Person constructor handles name, id, password, role
//     // nothing extra to initialize here
// }

// // Add a task to this student
// void Student::addTask(Task t) {
//     tasks.push_back(t);
// }

// // View all assigned tasks
// void Student::viewTasks() const {
//     if (tasks.empty()) {
//         cout << "No tasks assigned yet." << endl;
//         return;
//     }
//     cout << "=== YOUR TASKS ===" << endl;
//     for (int i = 0; i < tasks.size(); i++) {
//         cout << "--------------------" << endl;
//         tasks[i].displayTask();
//     }
// }

// // View grades only
// void Student::viewGrades() const {
//     if (tasks.empty()) {
//         cout << "No tasks assigned yet." << endl;
//         return;
//     }
//     cout << "=== YOUR GRADES ===" << endl;
//     for (int i = 0; i < tasks.size(); i++) {
//         cout << tasks[i].getTitle() << " : "
//              << tasks[i].getObtainedMarks() << " / "
//              << tasks[i].getTotalMarks() << endl;
//     }
// }

// // Mark attendance — record is something like "2024-03-13 - Present"
// void Student::markAttendance(string record) {
//     attendance.push_back(record);
// }

// // View all attendance records
// void Student::viewAttendance() const {
//     if (attendance.empty()) {
//         cout << "No attendance records yet." << endl;
//         return;
//     }
//     cout << "=== ATTENDANCE ===" << endl;
//     for (int i = 0; i < attendance.size(); i++) {
//         cout << attendance[i] << endl;
//     }
// }

// // Override Person's displayInfo
// void Student::displayInfo() const {
//     Person::displayInfo();  // print name, id, role from parent
//     cout << "Tasks Assigned : " << tasks.size() << endl;
// }

// // Destructor
// Student::~Student() {
//     // vector cleans itself up automatically
// }