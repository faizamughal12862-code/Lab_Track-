#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string password;
    string role;   // "admin" or "student"

public:
    // Constructor
    Person(string name, string id, string password, string role);

    // Getters
    string getName() const;
    string getId() const;
    string getPassword() const;
    string getRole() const;

    // Check password — returns true if matches
    bool checkPassword(string enteredPassword) const;

    // Setters
    void setPassword(string newPassword);

    // Display info (virtual so Student/Admin can override it)
    virtual void displayInfo() const;

    // Virtual destructor (important when using inheritance)
    virtual ~Person();
};

#endif



// #ifndef PERSON_H
// #define PERSON_H

// #include <string>
// using namespace std;

// class Person {
// protected:
//     string name;
//     string id;
//     string password;
//     string role;   // "admin" or "student"

// public:
//     // Constructor
//     Person(string name, string id, string password, string role);

//     // Getters
//     string getName() const;
//     string getId() const;
//     string getPassword() const;
//     string getRole() const;

//     // Setters
//     void setPassword(string newPassword);

//     // Display info (virtual so Student/Admin can override it)
//     virtual void displayInfo() const;

//     // Virtual destructor (important when using inheritance)
//     virtual ~Person();
// };

// #endif