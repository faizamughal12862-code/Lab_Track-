#include "Person.h"
#include <iostream>
using namespace std;

// Constructor — runs when you do: Person p("Ali", "101", "pass", "student")
Person::Person(string name, string id, string password, string role) {
    this->name     = name;
    this->id       = id;
    this->password = password;
    this->role     = role;
}

// Getters
string Person::getName() const { return name; }
string Person::getId() const { return id; }
string Person::getPassword() const { return password; }
string Person::getRole() const { return role; }

// Check password
bool Person::checkPassword(string enteredPassword) const {
    return password == enteredPassword;
}

// Setter
void Person::setPassword(string newPassword) {
    password = newPassword;
}

// Display basic info
void Person::displayInfo() const {
    cout << "Name : " << name << endl;
    cout << "ID   : " << id   << endl;
    cout << "Role : " << role << endl;
}

// Destructor
Person::~Person() {
    // nothing to manually clean up right now
    // but needed for safe inheritance
}


// #include "Person.h"
// #include <iostream>
// using namespace std;

// // Constructor
// Person::Person(string name, string id, string password, string role) {
//     this->name     = name;
//     this->id       = id;
//     this->password = password;
//     this->role     = role;
// }

// // Getters
// string Person::getName() const { 
//     return name; 
// }

// string Person::getId() const { 
//     return id; 
// }

// string Person::getPassword() const { 
//     return password; 
// }

// string Person::getRole() const { 
//     return role; 
// }

// // Setter
// void Person::setPassword(string newPassword) {
//     password = newPassword;
// }

// // Display info
// void Person::displayInfo() const {
//     cout << "Name : " << name << endl;
//     cout << "ID   : " << id   << endl;
//     cout << "Role : " << role << endl;
// }

// // Destructor
// Person::~Person() {
//     // nothing to clean up right now
// }