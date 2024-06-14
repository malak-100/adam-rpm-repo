#ifndef TEACHER_H
#define TEACHER_H

#include "cours.h"
#include "date.h"
#include <string>
#include <map>
#include <iostream>

class Teacher {
public:
    std::string last_name;
    std::string first_name;
    std::string email_address;
    std::map<string, Cours> courses;

    Teacher(std::string first_name = "", std::string last_name = "", std::string email_address = "");

    void add_cours(const Cours& c, const string& d);

    friend std::ostream& operator<<(std::ostream& os, const Teacher& t);
};

// Implementation

Teacher::Teacher(std::string first_name, std::string last_name, std::string email_address)
    : first_name(first_name), last_name(last_name), email_address(email_address) {}

void Teacher::add_cours(const Cours& c, const string& d) {
    courses[d] = c;
}

std::ostream& operator<<(std::ostream& os, const Teacher& t) {
    os << "First Name: " << t.first_name << "\n";
    os << "Last Name: " << t.last_name << "\n";
    os << "Email Address: " << t.email_address << "\n";
    os << "Courses: \n";
    for (const auto& course_entry : t.courses) {
        os << "Date: " << course_entry.first << ", Course: " << course_entry.second << "\n";
    }
    return os;
}

#endif // TEACHER_H

