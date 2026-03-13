#include "Task.h"
#include <iostream>
using namespace std;

// Constructor
Task::Task(string taskNo, string title, string description, string deadline, int totalMarks) {
    this->taskNo      = taskNo;
    this->title       = title;
    this->description = description;
    this->deadline    = deadline;
    this->totalMarks  = totalMarks;
    this->obtainedMarks  = 0;
    this->isSubmitted    = false;
    this->submissionText = "";  // empty until student submits
}

// Getters
string Task::getTaskNo() const { return taskNo; }
string Task::getTitle() const { return title; }
string Task::getDescription() const { return description; }
string Task::getDeadline() const { return deadline; }
int Task::getTotalMarks() const { return totalMarks; }
int Task::getObtainedMarks() const { return obtainedMarks; }
bool Task::getIsSubmitted() const { return isSubmitted; }

string Task::getSubmissionText() const { return submissionText; }

void Task::setSubmissionText(string text) {
    submissionText = text;
}

// Setters
void Task::setObtainedMarks(int marks) {
    obtainedMarks = marks;
}

void Task::setIsSubmitted(bool status) {
    isSubmitted = status;
}

// Display
void Task::displayTask() const {
    cout << "Task NO     : " << taskNo      << endl;
    cout << "Title       : " << title       << endl;
    cout << "Description : " << description << endl;
    cout << "Deadline    : " << deadline    << endl;
    cout << "Total Marks : " << totalMarks  << endl;
    cout << "Obtained    : " << obtainedMarks << endl;
    cout << "Submitted   : " << (isSubmitted ? "Yes" : "No") << endl;
    if (isSubmitted)
        cout << "Answer      : " << submissionText << endl;
}

// Destructor
Task::~Task() {
    // nothing to clean up
}




// #include "Task.h"
// #include <iostream>
// using namespace std;

// // Constructor
// Task::Task(string taskNo, string title, string description, string deadline, int totalMarks) {
//     this->taskNo      = taskNo;
//     this->title       = title;
//     this->description = description;
//     this->deadline    = deadline;
//     this->totalMarks  = totalMarks;
//     this->obtainedMarks = 0;       // no marks given yet
//     this->isSubmitted   = false;   // not submitted yet
// }

// // Getters
// string Task::getTaskNo() const { return taskNo; }
// string Task::getTitle() const { return title; }
// string Task::getDescription() const { return description; }
// string Task::getDeadline() const { return deadline; }
// int Task::getTotalMarks() const { return totalMarks; }
// int Task::getObtainedMarks() const { return obtainedMarks; }
// bool Task::getIsSubmitted() const { return isSubmitted; }

// // Setters
// void Task::setObtainedMarks(int marks) {
//     obtainedMarks = marks;
// }

// void Task::setIsSubmitted(bool status) {
//     isSubmitted = status;
// }

// // Display
// void Task::displayTask() const {
//     cout << "Task No     : " << taskNo      << endl;
//     cout << "Title       : " << title       << endl;
//     cout << "Description : " << description << endl;
//     cout << "Deadline    : " << deadline    << endl;
//     cout << "Total Marks : " << totalMarks  << endl;
//     cout << "Obtained    : " << obtainedMarks << endl;
//     cout << "Submitted   : " << (isSubmitted ? "Yes" : "No") << endl;
// }

// // Destructor
// Task::~Task() {
//     // nothing to clean up
// }