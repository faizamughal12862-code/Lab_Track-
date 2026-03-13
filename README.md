# Lab_Track 🧪

A console-based Lab Tracking System built in **C++** using core **OOP concepts**.

Admins can manage students, assign tasks, evaluate submissions and mark attendance — all through a simple terminal interface. Data is saved to files so nothing is lost between sessions.

---

## Features

- Role-based login — Admin and Student
- Self-registration (always as Student)
- Admin can assign tasks to specific students
- Students can submit tasks with their answer
- Admin can only evaluate after task is submitted
- Marks validation (can't exceed total marks)
- Attendance tracking per student
- Admin can promote a student to Admin
- File-based data persistence (no database needed)

---

## How to Run

**Compile:**
```
g++ *.cpp -o main
```

**Run:**
```
./main        # Linux/Mac
.\main.exe    # Windows
```

---

## Default Admin Credentials

```
Username : admin
Password : admin123
```

> Login with these on first run. Then add students from the Admin menu.

---

## Project Structure

```
Lab_Track/
├── Person.h / Person.cpp        → Base class
├── Student.h / Student.cpp      → Inherits Person
├── Admin.h / Admin.cpp          → Inherits Person
├── Task.h / Task.cpp            → Task model
├── FileManager.h / FileManager.cpp → File I/O
└── main.cpp                     → Menus and program flow
```

---

## OOP Concepts Used

| Concept | Where |
|---|---|
| Classes & Objects | Every entity (Student, Admin, Task) |
| Inheritance | Student and Admin extend Person |
| Encapsulation | Private data with getters/setters |
| Polymorphism | virtual displayInfo() overridden in Student and Admin |
| Constructors | Every class initializes its own data |
| Destructors | Defined for safe memory handling |

---

## Built By

Faiza Batool — 2nd Semester CS Student
