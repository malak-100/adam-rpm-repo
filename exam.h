#ifndef EXAM_H
#define EXAM_H

#include <string>
#include "time.h"
#include "date.h"
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

class Exam {
public:
    string name;
    double mark;
    date Date;
    Time time;

    Exam(string n = "", double m = 5, date d = date(), Time t = Time());
   
    void set_mark(double m);
    virtual void set_worth(double w) = 0;
    double get_mark() const;
    virtual double get_worth() const = 0;
    void set_mark(string s){mark = stod(s);}
    virtual ~Exam() = default;
};

class Midterm : public Exam {
public:
    double worth;

    Midterm(string n = "", double m = 5, double w = 0, date d = date(), Time t = Time());
    Midterm(double m) : Exam("", m, date(), Time()) { set_mark(m); }
        double get_worth() const override;
    
    void set_worth(double w) override;
    ~Midterm() override = default;
};

class FinalExam : public Exam {
public:
    double worth;

    FinalExam(string n = "", double m = 5, double w = 0, date d = date(), Time t = Time());
    FinalExam(double m) : Exam("", m, date(), Time()) { set_mark(m); }
    
    double get_worth() const override;
    void set_worth(double w) override;
    ~FinalExam() override = default;
};

// Implementation

Exam::Exam(string n, double m, date d, Time t) : name(n), Date(d), time(t) {
    set_mark(m);
}

double Exam::get_mark() const {
    return mark;
}

void Exam::set_mark(double m) {
    if (m < 0) {
        throw invalid_argument("mark must be positive");
    }
    mark = m;
}

Midterm::Midterm(string n, double m, double w, date d, Time t) : Exam(n, m, d, t) {
    set_worth(w);
}

double Midterm::get_worth() const {
    return worth;
}

void Midterm::set_worth(double w) {
    if (w < 0 || w > 1) {
        throw invalid_argument("worth must be between 0 and 1");
    }
    worth = w;
}

FinalExam::FinalExam(string n, double m, double w, date d, Time t) : Exam(n, m, d, t) {
    set_worth(w);
}

double FinalExam::get_worth() const {
    return worth;
}

void FinalExam::set_worth(double w) {
    if (w < 0 || w > 1) {
        throw invalid_argument("worth must be between 0 and 1");
    }
    worth = w;
}

#endif // EXAM_H

