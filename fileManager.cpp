#include "FileManager.h"
#include <iostream>
#include <sstream>
using namespace std;

// Check if a file exists
bool FileManager::fileExists(string filename) {
    ifstream f(filename);
    return f.good();
}

// Save all users to users.txt
// Format: name,id,password,role
void FileManager::saveUsers(const vector<Student>& students, const vector<Admin>& admins) {
    ofstream file("users.txt");
    if (!file) {
        cout << "Error saving users." << endl;
        return;
    }

    // save all admins first
    for (int i = 0; i < admins.size(); i++) {
        file << admins[i].getName()     << ","
             << admins[i].getId()       << ","
             << admins[i].getPassword() << ","
             << admins[i].getRole()     << "\n";
    }

    // save all students
    for (int i = 0; i < students.size(); i++) {
        file << students[i].getName()     << ","
             << students[i].getId()       << ","
             << students[i].getPassword() << ","
             << students[i].getRole()     << "\n";
    }

    file.close();
}

// Load users from users.txt
// Each line: name,id,password,role
void FileManager::loadUsers(vector<Student>& students, vector<Admin>& admins) {
    ifstream file("users.txt");
    if (!file) {
        // file doesn't exist yet — create default admin
        Admin defaultAdmin("Admin", "admin", "admin123");
        admins.push_back(defaultAdmin);
        saveUsers(students, admins);
        cout << "First run detected. Default admin created." << endl;
        cout << "Username: admin | Password: admin123" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        // split line by comma
        stringstream ss(line);
        string name, id, password, role;
        getline(ss, name,     ',');
        getline(ss, id,       ',');
        getline(ss, password, ',');
        getline(ss, role,     ',');

        if (role == "admin") {
            admins.push_back(Admin(name, id, password));
        } else {
            students.push_back(Student(name, id, password));
        }
    }

    file.close();
}

// Save all tasks to tasks.txt
// Format: taskId,studentId,title,description,deadline,totalMarks,obtainedMarks,isSubmitted
void FileManager::saveTasks(const vector<Student>& students) {
    ofstream file("tasks.txt");
    if (!file) {
        cout << "Error saving tasks." << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        vector<Task> tasks = students[i].getTasks();
        for (int j = 0; j < tasks.size(); j++) {
            file << tasks[j].getTaskNo()       << ","
                 << students[i].getId()        << ","
                 << tasks[j].getTitle()        << ","
                 << tasks[j].getDescription()  << ","
                 << tasks[j].getDeadline()     << ","
                 << tasks[j].getTotalMarks()   << ","
                 << tasks[j].getObtainedMarks()<< ","
                 << tasks[j].getIsSubmitted()  << "\n";
        }
    }

    file.close();
}

// Load tasks from tasks.txt into correct students
void FileManager::loadTasks(vector<Student>& students) {
    ifstream file("tasks.txt");
    if (!file) return;  // no tasks yet, that's fine

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string taskId, studentId, title, description, deadline;
        string totalMarksStr, obtainedMarksStr, isSubmittedStr;

        getline(ss, taskId,         ',');
        getline(ss, studentId,      ',');
        getline(ss, title,          ',');
        getline(ss, description,    ',');
        getline(ss, deadline,       ',');
        getline(ss, totalMarksStr,  ',');
        getline(ss, obtainedMarksStr,',');
        getline(ss, isSubmittedStr, ',');

        int totalMarks    = stoi(totalMarksStr);
        int obtainedMarks = stoi(obtainedMarksStr);
        bool isSubmitted  = (isSubmittedStr == "1");

        // find the student and add task to them
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == studentId) {
                Task t(taskId, title, description, deadline, totalMarks);
                t.setObtainedMarks(obtainedMarks);
                t.setIsSubmitted(isSubmitted);
                students[i].addTask(t);
                break;
            }
        }
    }

    file.close();
}

// Save attendance to attendance.txt
// Format: studentId,record
void FileManager::saveAttendance(const vector<Student>& students) {
    ofstream file("attendance.txt");
    if (!file) {
        cout << "Error saving attendance." << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        vector<string> records = students[i].getAttendance();
        for (int j = 0; j < records.size(); j++) {
            file << students[i].getId() << "," << records[j] << "\n";
        }
    }

    file.close();
}

// Load attendance into correct students
void FileManager::loadAttendance(vector<Student>& students) {
    ifstream file("attendance.txt");
    if (!file) return;  // no attendance yet, that's fine

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        // split only on first comma — record itself may have spaces/dashes
        int commaPos = line.find(',');
        string studentId = line.substr(0, commaPos);
        string record    = line.substr(commaPos + 1);

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == studentId) {
                students[i].markAttendance(record);
                break;
            }
        }
    }

    file.close();
}