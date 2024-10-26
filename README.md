# Student Information Management System

This is a simple C-based application to manage student information and course details. It allows adding, searching, and editing student details, as well as maintaining course records.

## Features

- **Add Student Details:** Register new students by entering their personal information, department, and the list of courses they are following. It calculates the student's GPA based on entered grades and credits.
- **Search Student Details:** Allows searching for a specific student using their index number to view their personal and course details, including their GPA.
- **Edit Student Details:** Provides functionality to update a student's information and course details in case of any changes.
- **Course Management:** Allows predefined and custom course additions, including course ID, name, and credit value.
- **Display Records:**  Displays a detailed list of all students and their associated courses, or a complete list of courses available in the system.

## Usage

To compile and run this code, you need to have a C compiler installed (such as GCC). You can use the following commands:

```bash
gcc -o student_info_system main.c
./student_info_system
