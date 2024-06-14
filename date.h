#ifndef date_h
#define date_h

#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept> // include the appropriate header for std::invalid_argument
#include <iomanip>
#include <sstream>

using namespace std;

class date {
private:
    int year;
    int month;
    int day;
public:
    date(string datestr = " ");
    friend ostream& operator<<(ostream& out, const date& d);
    friend bool operator<(const date& lhs, const date& rhs);
    date operator-(const date& other) const;
    ~date() = default;
        string to_string() const {
        stringstream ss;
        ss << setw(4) << setfill('0') << year << '/' << setw(2) << month << '/' << setw(2) << day;
        return ss.str();
    }
};

date::date(string datestr) {
    char str[datestr.length() + 1];
    strcpy(str, datestr.c_str());
    char* token = strtok(str, " ,-:!?=;/\\|");
    int i = 0;
    
    while (token != nullptr) {
        
            switch (i) {
                case 0: day = stoi(string(token)); break;
                case 1: month = stoi(string(token)); break;
                case 2: year = stoi(string(token)); break;
            }
                token = strtok(nullptr, " ,-:!?=;/\\|");
        ++i;
    }
}
date date::operator-(const date& other) const {
    if ((this->year < other.year) ||
        (this->year == other.year && this->month < other.month) ||
        (this->year == other.year && this->month == other.month && this->day < other.day)) {
        cout << "this day has passed" << endl;
        exit(1);
    }

    date remaining;
    remaining.year = this->year - other.year;
    remaining.month = this->month - other.month;
    remaining.day = this->day - other.day;

    // adjust for negative values
    if (remaining.day < 0) {
        remaining.month--;
        remaining.day += 30; // simplified, assuming all months have 30 days
    }
    if (remaining.month < 0) {
        remaining.year--;
        remaining.month += 12;
    }

    return remaining;
}

ostream& operator<<(ostream& out, const date& d) {
    out << d.day << "/" << d.month << "/" << d.year;
    return out;
}

int last_day_of_month(int m) {
    if (m == 2) {
        return 28;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    } else {
        return 31;
    }
}

        bool operator<(const date& lhs, const date& rhs) {
    if (lhs.year != rhs.year) {
        return lhs.year < rhs.year;
    }
    if (lhs.month != rhs.month) {
        return lhs.month < rhs.month;
    }
    return lhs.day < rhs.day;
}

#endif // date_h

