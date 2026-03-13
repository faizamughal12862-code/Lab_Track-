#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Student.h"
#include "Admin.h"
#include <vector>
#include <fstream>
using namespace std;

class FileManager {
public:
    // Save all users (students + admins) login info to users.txt
    static void saveUsers(const vector<Student>& students, const vector<Admin>& admins);

    // Load users from users.txt into students and admins vectors
    static void loadUsers(vector<Student>& students, vector<Admin>& admins);

    // Save all tasks to tasks.txt
    static void saveTasks(const vector<Student>& students);

    // Load tasks from tasks.txt into correct students
    static void loadTasks(vector<Student>& students);

    // Save attendance to attendance.txt
    static void saveAttendance(const vector<Student>& students);

    // Load attendance into correct students
    static void loadAttendance(vector<Student>& students);

    // Check if a file exists
    static bool fileExists(string filename);
};

#endif