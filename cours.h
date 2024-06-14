#ifndef COURS_H
#define COURS_H

#include <string>
#include <vector>
#include <stdexcept>
#include "exam.h"

using namespace std;

class Cours {
public:
    string name;
    int coefficient;
    double cc_mark;
    vector<Exam*> exams;

    Cours(string n = "", int c = 0, double m = 0.0);

    void set_coefficient(int c);
    void set_ccmark(double m);
    double calculate_average() const;
    void add_exam(Exam* e);
    friend ostream& operator<<(ostream& os, const Cours& cours);
    ~Cours() = default;
    string to_string() const {
        return name;
    }
     double get_midterm_mark() const;
    double get_final_mark() const;
};

// Implementation

Cours::Cours(string n, int c, double m) : name(n) {
    set_coefficient(c);
    set_ccmark(m);
}

void Cours::set_coefficient(int c) {
    if (c < 0) {
        throw invalid_argument("Coefficient must be positive");
    }
    coefficient = c;
}

void Cours::set_ccmark(double m) {
    if (m < 0) {
        throw invalid_argument("CC mark must be positive");
    }
    cc_mark = m;
}

void Cours::add_exam(Exam* e) {
    exams.push_back(e);
}

double Cours::calculate_average() const {
    if (exams.empty()) {
        return cc_mark * 0.04; // No exams, just the CC mark contribution
    }

    double average = 0;
    for (const auto& e : exams) {
        average += e->get_mark() * e->get_worth();
    }
    average += cc_mark * 0.04;
    return average;
}
ostream& operator<<(ostream& os, const Cours& cours) {
    os << "Course: " << cours.name << ", Coefficient: " << cours.coefficient << ", CC Mark: " << cours.cc_mark;
    if (!cours.exams.empty()) {
        os << ", Exams: ";
        for (const auto& exam : cours.exams) {
            os << exam->get_mark() << " ";
        }
    }
    return os;
}


double Cours::get_midterm_mark() const {
    for (const auto& exam : exams) {
        Midterm* midterm = dynamic_cast<Midterm*>(exam);
        if (midterm) {
            return midterm->get_mark();
        }
    }
    return 0.0; // Return 0 if no midterm exam is found.
}

double Cours::get_final_mark() const {
    for (const auto& exam : exams) {
        FinalExam* finalExam = dynamic_cast<FinalExam*>(exam);
        if (finalExam) {
            return finalExam->get_mark();
        }
    }
    return 0.0; // Return 0 if no final exam is found.
}
#endif // COURS_H

