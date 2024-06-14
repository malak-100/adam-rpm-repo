#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include "exam.h"
#include "cours.h"
using namespace std;

class Student {
public:
    string first_name;
    string last_name;
    string email_address;
    string id;
    map<string, int> attendances;
    map<string,Cours> marks;
    Student(string fname = "", string lname = "", string email = "", string id = "");

    void set_student_infos(); // Not implemented, keeping as is.
    void add_attendance(string course_name, int attendance);
    double calculate_the_average() const;

    friend std::ostream& operator<<(std::ostream& os, const Student& stu);
double get_midterm_mark(const string& course_name) const;
    double get_final_mark(const string& course_name) const;
    ~Student() = default;
};

// Implementation

Student::Student(string fname, string lname, string email, string id)
    : first_name(fname), last_name(lname), email_address(email), id(id) {}

void Student::set_student_infos() {
    // This function can be used to set student info interactively or from some source.
}

void Student::add_attendance(string course_name, int attendance) {
    if (attendance < 0 || attendance > 100) {
        throw invalid_argument("Attendance must be between 0 and 100");
    }
    attendances[course_name] = attendance;
}

double Student::calculate_the_average() const {
    if (attendances.empty()) {
        return 0.0; // If no attendances are recorded, return 0.
    }
    int total = 0;
    for (const auto& entry : attendances) {
        total += entry.second;
    }
    return static_cast<double>(total) / attendances.size();
}

std::ostream& operator<<(std::ostream& os, const Student& stu) {
    os << "First Name: " << stu.first_name << "\n"
       << "Last Name: " << stu.last_name << "\n"
       << "Email: " << stu.email_address << "\n"
       << "ID: " << stu.id << "\n";
    for (const auto& entry : stu.attendances) {
        os << "Course: " << entry.first << ", Attendance: " << entry.second << "\n";
    }
    return os;
}
double Student::get_midterm_mark(const string& course_name) const {
    auto it = marks.find(course_name);
    if (it != marks.end()) {
        return it->second.get_midterm_mark();
    }
    return 2.0; // Return 0 if the course is not found or there are no midterms.
}

double Student::get_final_mark(const string& course_name) const {
    auto it = marks.find(course_name);
    if (it != marks.end()) {
        return it->second.get_final_mark();
    }
    return 0; // Return 0 if the course is not found or there are no finals.
}
#endif // STUDENT_H

