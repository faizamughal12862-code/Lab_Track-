#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
private:
    string taskNo;
    string title;
    string description;
    string deadline;
    int totalMarks;
    int obtainedMarks;
    bool isSubmitted;
    string submissionText;  // student's answer

public:
    // Constructor
    Task(string taskNo, string title, string description, string deadline, int totalMarks);

    // Getters
    string getTaskNo() const;
    string getTitle() const;
    string getDescription() const;
    string getDeadline() const;
    int getTotalMarks() const;
    int getObtainedMarks() const;
    bool getIsSubmitted() const;

    string getSubmissionText() const;
    void setSubmissionText(string text);

    // Setters
    void setObtainedMarks(int marks);
    void setIsSubmitted(bool status);

    // Display
    void displayTask() const;

    // Destructor
    ~Task();
};

#endif

// #ifndef TASK_H
// #define TASK_H

// #include <string>
// using namespace std;

// class Task {
// private:
//     string taskNo;
//     string title;
//     string description;
//     string deadline;
//     int totalMarks;
//     int obtainedMarks;
//     bool isSubmitted;

// public:
//     // Constructor
//     Task(string taskNo, string title, string description, string deadline, int totalMarks);

//     // Getters
//     string getTaskNo() const;
//     string getTitle() const;
//     string getDescription() const;
//     string getDeadline() const;
//     int getTotalMarks() const;
//     int getObtainedMarks() const;
//     bool getIsSubmitted() const;

//     // Setters
//     void setObtainedMarks(int marks);
//     void setIsSubmitted(bool status);

//     // Display
//     void displayTask() const;

//     // Destructor
//     ~Task();
// };

// #endif