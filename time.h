#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <stdexcept> // include the appropriate header for std::invalid_argument

using namespace std;

class Time
{
private:
    int seconds;
    int minutes;
    int hours;
public:
    Time(int h = 0, int m = 0, int s = 0);
    friend ostream& operator<<(ostream& out, const Time& t);
    Time operator-(const Time& other) const;
};

Time::Time(int h, int m, int s)
{
    if (h < 0 || m < 0 || s < 0)
    {
        throw invalid_argument("time must be a positive value");
    }
    else
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
}

Time Time::operator-(const Time& other) const
{
    int total_seconds_1 = hours * 3600 + minutes * 60 + seconds;
    int total_seconds_2 = other.hours * 3600 + other.minutes * 60 + other.seconds;

    if (total_seconds_1 < total_seconds_2)
    {
        cout << other << " has passed" << endl;
        exit(1);
    }

    int diff_seconds = total_seconds_1 - total_seconds_2;
    int h = diff_seconds / 3600;
    int m = (diff_seconds % 3600) / 60;
    int s = diff_seconds % 60;

    return Time(h, m, s);
}

ostream& operator<<(ostream& out, const Time& t)
{
    out << t.hours << ":" << t.minutes << ":" << t.seconds;
    return out;
}

#endif

