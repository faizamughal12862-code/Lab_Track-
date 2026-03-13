#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Admin.h"
#include "Task.h"
#include "FileManager.h"
using namespace std;

// ─────────────────────────────────────────
// FORWARD DECLARATIONS
// ─────────────────────────────────────────
void showMainMenu();
void handleLogin(vector<Student>& students, vector<Admin>& admins);
void handleRegister(vector<Student>& students, vector<Admin>& admins);
void showAdminMenu(Admin& admin, vector<Student>& students, vector<Admin>& admins);
void showStudentMenu(Student& student);

// ─────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────
int main() {
    vector<Student> students;
    vector<Admin>   admins;

    // Load all data from files on startup
    FileManager::loadUsers(students, admins);
    FileManager::loadTasks(students);
    FileManager::loadAttendance(students);

    int choice;
    while (true) {
        cout << "\n================================" << endl;
        cout << "       WELCOME TO LABTRACK      " << endl;
        cout << "================================" << endl;
        cout << "1. Login"                          << endl;
        cout << "2. Register"                       << endl;
        cout << "3. Exit"                           << endl;
        cout << "================================" << endl;
        cout << "Enter choice: ";
        cin  >> choice;

        if      (choice == 1) handleLogin(students, admins);
        else if (choice == 2) handleRegister(students, admins);
        else if (choice == 3) {
            cout << "Goodbye!" << endl;
            break;
        }
        else cout << "Invalid choice. Try again." << endl;
    }

    return 0;
}

// ─────────────────────────────────────────
// LOGIN
// ─────────────────────────────────────────
void handleLogin(vector<Student>& students, vector<Admin>& admins) {
    string id, password;

    cout << "\n=== LOGIN ===" << endl;
    cout << "Enter ID      : "; cin >> id;
    cout << "Enter Password: "; cin >> password;

    // check admins first
    for (int i = 0; i < admins.size(); i++) {
        if (admins[i].getId() == id && admins[i].checkPassword(password)) {
            cout << "\nWelcome, " << admins[i].getName() << "!" << endl;
            showAdminMenu(admins[i], students, admins);
            return;
        }
    }

    // check students
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id && students[i].checkPassword(password)) {
            cout << "\nWelcome, " << students[i].getName() << "!" << endl;
            showStudentMenu(students[i]);
            return;
        }
    }

    cout << "Invalid ID or password." << endl;
}

// ─────────────────────────────────────────
// REGISTER
// ─────────────────────────────────────────
void handleRegister(vector<Student>& students, vector<Admin>& admins) {
    string name, id, password, confirmPassword;

    cout << "\n=== REGISTER ===" << endl;
    cout << "Enter Name    : "; cin >> name;
    cout << "Enter ID      : "; cin >> id;

    // check if ID already exists
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            cout << "ID already taken. Try a different one." << endl;
            return;
        }
    }
    for (int i = 0; i < admins.size(); i++) {
        if (admins[i].getId() == id) {
            cout << "ID already taken. Try a different one." << endl;
            return;
        }
    }

    cout << "Enter Password        : "; cin >> password;
    cout << "Confirm Password      : "; cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Passwords do not match. Try again." << endl;
        return;
    }

    // role is always student on self-registration
    Student newStudent(name, id, password);
    students.push_back(newStudent);

    // save to file immediately
    FileManager::saveUsers(students, admins);

    cout << "Account created! You can now login as a Student." << endl;
}

// ─────────────────────────────────────────
// ADMIN MENU
// ─────────────────────────────────────────
void showAdminMenu(Admin& admin, vector<Student>& students, vector<Admin>& admins) {
    int choice;

    while (true) {
        cout << "\n=== ADMIN MENU ===" << endl;
        cout << "1. View All Students"        << endl;
        cout << "2. View Student Tasks"       << endl;
        cout << "3. Assign Task"              << endl;
        cout << "4. Evaluate Student"         << endl;
        cout << "5. Mark Attendance"          << endl;
        cout << "6. Promote to Admin"         << endl;
        cout << "7. Logout"                   << endl;
        cout << "Enter choice: ";
        cin  >> choice;

        if (choice == 1) {
            admin.viewAllStudents(students);
        }

        else if (choice == 2) {
            string studentId;
            cout << "Enter Student ID: "; cin >> studentId;
            bool found = false;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getId() == studentId) {
                    students[i].viewTasks();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found." << endl;
        }

        else if (choice == 3) {
            string studentId, taskId, title, desc, deadline;
            int totalMarks;

            cout << "Enter Student ID : "; cin >> studentId;
            cout << "Enter Task ID    : "; cin >> taskId;
            cin.ignore();
            cout << "Enter Title      : "; getline(cin, title);
            cout << "Enter Description: "; getline(cin, desc);
            cout << "Enter Deadline   : "; getline(cin, deadline);
            cout << "Enter Total Marks: "; cin >> totalMarks;

            Task t(taskId, title, desc, deadline, totalMarks);
            admin.assignTask(students, studentId, t);
            FileManager::saveTasks(students);
        }

        else if (choice == 4) {
            string studentId, taskId;
            int marks;

            cout << "Enter Student ID : "; cin >> studentId;
            cout << "Enter Task ID    : "; cin >> taskId;

            // find student and check submission status first
            bool studentFound = false;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getId() == studentId) {
                    studentFound = true;
                    if (!students[i].isTaskSubmitted(taskId)) {
                        cout << "Cannot evaluate — student has not submitted this task yet." << endl;
                    } else {
                        cout << "Task is submitted. Enter Marks: "; cin >> marks;
                        admin.evaluateStudent(students, studentId, taskId, marks);
                        FileManager::saveTasks(students);
                    }
                    break;
                }
            }
            if (!studentFound) cout << "Student not found." << endl;
        }

        else if (choice == 5) {
            string studentId, date, status;

            cout << "Enter Student ID : "; cin >> studentId;
            cout << "Enter Date       : "; cin >> date;
            cout << "Present/Absent   : "; cin >> status;

            string record = date + " - " + status;
            admin.markAttendance(students, studentId, record);
            FileManager::saveAttendance(students);
        }

        else if (choice == 6) {
            string studentId;
            cout << "Enter Student ID to promote: "; cin >> studentId;
            admin.promoteToAdmin(students, studentId);
        }

        else if (choice == 7) {
            cout << "Logged out." << endl;
            break;
        }

        else cout << "Invalid choice." << endl;
    }
}

// ─────────────────────────────────────────
// STUDENT MENU
// ─────────────────────────────────────────
void showStudentMenu(Student& student) {
    int choice;

    while (true) {
        cout << "\n=== STUDENT MENU ===" << endl;
        cout << "1. View My Tasks"       << endl;
        cout << "2. Submit a Task"       << endl;
        cout << "3. View My Grades"      << endl;
        cout << "4. View My Attendance"  << endl;
        cout << "5. Logout"              << endl;
        cout << "Enter choice: ";
        cin  >> choice;

        if      (choice == 1) student.viewTasks();
        else if (choice == 2) {
            string taskId, answer;
            cout << "Enter Task ID : "; cin >> taskId;
            cin.ignore();
            cout << "Enter your answer/submission:\n";
            getline(cin, answer);
            student.submitTask(taskId, answer);
        }
        else if (choice == 3) student.viewGrades();
        else if (choice == 4) student.viewAttendance();
        else if (choice == 5) {
            cout << "Logged out." << endl;
            break;
        }
        else cout << "Invalid choice." << endl;
    }
}


// #include <iostream>
// #include <vector>
// #include <string>
// #include "Person.h"
// #include "Student.h"
// #include "Admin.h"
// #include "Task.h"
// #include "FileManager.h"
// using namespace std;

// // ─────────────────────────────────────────
// // FORWARD DECLARATIONS
// // ─────────────────────────────────────────
// void showMainMenu();
// void handleLogin(vector<Student>& students, vector<Admin>& admins);
// void handleRegister(vector<Student>& students, vector<Admin>& admins);
// void showAdminMenu(Admin& admin, vector<Student>& students, vector<Admin>& admins);
// void showStudentMenu(Student& student);

// // ─────────────────────────────────────────
// // MAIN
// // ─────────────────────────────────────────
// int main() {
//     vector<Student> students;
//     vector<Admin>   admins;

//     // Load all data from files on startup
//     FileManager::loadUsers(students, admins);
//     FileManager::loadTasks(students);
//     FileManager::loadAttendance(students);

//     int choice;
//     while (true) {
//         cout << "\n================================" << endl;
//         cout << "       WELCOME TO LABTRACK      " << endl;
//         cout << "================================" << endl;
//         cout << "1. Login"                          << endl;
//         cout << "2. Register"                       << endl;
//         cout << "3. Exit"                           << endl;
//         cout << "================================" << endl;
//         cout << "Enter choice: ";
//         cin  >> choice;

//         if      (choice == 1) handleLogin(students, admins);
//         else if (choice == 2) handleRegister(students, admins);
//         else if (choice == 3) {
//             cout << "Goodbye!" << endl;
//             break;
//         }
//         else cout << "Invalid choice. Try again." << endl;
//     }

//     return 0;
// }

// // ─────────────────────────────────────────
// // LOGIN
// // ─────────────────────────────────────────
// void handleLogin(vector<Student>& students, vector<Admin>& admins) {
//     string id, password;

//     cout << "\n=== LOGIN ===" << endl;
//     cout << "Enter ID      : "; cin >> id;
//     cout << "Enter Password: "; cin >> password;

//     // check admins first
//     for (int i = 0; i < admins.size(); i++) {
//         if (admins[i].getId() == id && admins[i].checkPassword(password)) {
//             cout << "\nWelcome, " << admins[i].getName() << "!" << endl;
//             showAdminMenu(admins[i], students, admins);
//             return;
//         }
//     }

//     // check students
//     for (int i = 0; i < students.size(); i++) {
//         if (students[i].getId() == id && students[i].checkPassword(password)) {
//             cout << "\nWelcome, " << students[i].getName() << "!" << endl;
//             showStudentMenu(students[i]);
//             return;
//         }
//     }

//     cout << "Invalid ID or password." << endl;
// }

// // ─────────────────────────────────────────
// // REGISTER
// // ─────────────────────────────────────────
// void handleRegister(vector<Student>& students, vector<Admin>& admins) {
//     string name, id, password, confirmPassword;

//     cout << "\n=== REGISTER ===" << endl;
//     cout << "Enter Name    : "; cin >> name;
//     cout << "Enter ID      : "; cin >> id;

//     // check if ID already exists
//     for (int i = 0; i < students.size(); i++) {
//         if (students[i].getId() == id) {
//             cout << "ID already taken. Try a different one." << endl;
//             return;
//         }
//     }
//     for (int i = 0; i < admins.size(); i++) {
//         if (admins[i].getId() == id) {
//             cout << "ID already taken. Try a different one." << endl;
//             return;
//         }
//     }

//     cout << "Enter Password        : "; cin >> password;
//     cout << "Confirm Password      : "; cin >> confirmPassword;

//     if (password != confirmPassword) {
//         cout << "Passwords do not match. Try again." << endl;
//         return;
//     }

//     // role is always student on self-registration
//     Student newStudent(name, id, password);
//     students.push_back(newStudent);

//     // save to file immediately
//     FileManager::saveUsers(students, admins);

//     cout << "Account created! You can now login as a Student." << endl;
// }

// // ─────────────────────────────────────────
// // ADMIN MENU
// // ─────────────────────────────────────────
// void showAdminMenu(Admin& admin, vector<Student>& students, vector<Admin>& admins) {
//     int choice;

//     while (true) {
//         cout << "\n=== ADMIN MENU ===" << endl;
//         cout << "1. View All Students"    << endl;
//         cout << "2. Assign Task"          << endl;
//         cout << "3. Evaluate Student"     << endl;
//         cout << "4. Mark Attendance"      << endl;
//         cout << "5. Promote to Admin"     << endl;
//         cout << "6. Logout"               << endl;
//         cout << "Enter choice: ";
//         cin  >> choice;

//         if (choice == 1) {
//             admin.viewAllStudents(students);
//         }

//         else if (choice == 2) {
//             string studentId, taskId, title, desc, deadline;
//             int totalMarks;

//             cout << "Enter Student ID : "; cin >> studentId;
//             cout << "Enter Task ID    : "; cin >> taskId;
//             cin.ignore();
//             cout << "Enter Title      : "; getline(cin, title);
//             cout << "Enter Description: "; getline(cin, desc);
//             cout << "Enter Deadline   : "; getline(cin, deadline);
//             cout << "Enter Total Marks: "; cin >> totalMarks;

//             Task t(taskId, title, desc, deadline, totalMarks);
//             admin.assignTask(students, studentId, t);
//             FileManager::saveTasks(students);
//         }

//         else if (choice == 3) {
//             string studentId, taskId;
//             int marks;

//             cout << "Enter Student ID : "; cin >> studentId;
//             cout << "Enter Task ID    : "; cin >> taskId;
//             cout << "Enter Marks      : "; cin >> marks;

//             admin.evaluateStudent(students, studentId, taskId, marks);
//             FileManager::saveTasks(students);
//         }

//         else if (choice == 4) {
//             string studentId, date, status;

//             cout << "Enter Student ID : "; cin >> studentId;
//             cout << "Enter Date       : "; cin >> date;
//             cout << "Present/Absent   : "; cin >> status;

//             string record = date + " - " + status;
//             admin.markAttendance(students, studentId, record);
//             FileManager::saveAttendance(students);
//         }

//         else if (choice == 5) {
//             string studentId;
//             cout << "Enter Student ID to promote: "; cin >> studentId;
//             admin.promoteToAdmin(students, studentId);
//         }

//         else if (choice == 6) {
//             cout << "Logged out." << endl;
//             break;
//         }

//         else cout << "Invalid choice." << endl;
//     }
// }

// // ─────────────────────────────────────────
// // STUDENT MENU
// // ─────────────────────────────────────────
// void showStudentMenu(Student& student) {
//     int choice;

//     while (true) {
//         cout << "\n=== STUDENT MENU ===" << endl;
//         cout << "1. View My Tasks"       << endl;
//         cout << "2. View My Grades"      << endl;
//         cout << "3. View My Attendance"  << endl;
//         cout << "4. Logout"              << endl;
//         cout << "Enter choice: ";
//         cin  >> choice;

//         if      (choice == 1) student.viewTasks();
//         else if (choice == 2) student.viewGrades();
//         else if (choice == 3) student.viewAttendance();
//         else if (choice == 4) {
//             cout << "Logged out." << endl;
//             break;
//         }
//         else cout << "Invalid choice." << endl;
//     }
// }