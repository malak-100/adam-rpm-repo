#ifndef STAT_H
#define STAT_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "student.h"
#include <cmath>
#include <tuple>
#include <algorithm>
#include <ncurses.h>

using namespace std;

// Helper function to draw polygons
void draw_polygon(vector<tuple<int, int, char>> points) {
    for (const auto &it : points) {
        cout << "\033[" << get<1>(it) << ";" << get<0>(it) << "H";
        cout << get<2>(it) << flush;
    }
}

// Function to calculate statistical parameters for midterm marks
map<string, double>* calculate_statistical_parameters(map<string, Student> &students, const string &course_name) {
    map<string, double>* stats = new map<string, double>;
    double mean_midterm = 0;
    double variance_midterm = 0;
    double std_deviation_midterm = 0;
    int count = 0;
    vector<double> midterm_marks;

    // Collect valid midterm marks
    for (const auto& entry : students) {
        double midterm_mark = entry.second.get_midterm_mark(course_name);
        if (!isnan(midterm_mark)) {
            midterm_marks.push_back(midterm_mark);
        }
    }

    // Calculate mean of midterm marks
    count = midterm_marks.size();
    if (count > 0) {
        for (int i = 0; i < count; ++i) {
            mean_midterm += midterm_marks[i];
        }
        mean_midterm /= count;
    }
    stats->insert(make_pair("mean_midterm", mean_midterm));

    // Calculate variance of midterm marks
    if (count > 0) {
        for (int i = 0; i < count; ++i) {
            variance_midterm += pow(midterm_marks[i] - mean_midterm, 2);
        }
        variance_midterm /= count;
    }
    stats->insert(make_pair("variance_midterm", variance_midterm));

    // Calculate standard deviation of midterm marks
    std_deviation_midterm = sqrt(variance_midterm);
    stats->insert(make_pair("std_deviation_midterm", std_deviation_midterm));

    // Calculate coefficient of variation of midterm marks
    double coeff_of_var_midterm = (mean_midterm != 0) ? std_deviation_midterm / mean_midterm : 0;
    stats->insert(make_pair("cvx_midterm", coeff_of_var_midterm * 100)); // store it as a percentage

    return stats;
}// Function to calculate statistical parameters for final marks
map<string, double>* calculate_final_statistical_parameters(map<string, Student> &students, const string &course_name) {
    map<string, double>* stats = new map<string, double>;
    double mean_final = 0;
    double variance_final = 0;
    double std_deviation_final = 0;
    int count = 0;

    // Calculate mean of final exam marks
    for (const auto &entry : students) {
        double final_mark = entry.second.get_final_mark(course_name);
        mean_final += final_mark;
        count++;
    }
    if (count > 0) {
        mean_final /= count;
    }
    stats->insert(make_pair("mean_final", mean_final));

    // Calculate variance of final exam marks
    for (const auto &entry : students) {
        double final_mark = entry.second.get_final_mark(course_name);
        variance_final += pow(final_mark - mean_final, 2);
    }
    if (count > 0) {
        variance_final /= count;
    }
    stats->insert(make_pair("variance_final", variance_final));

    // Calculate standard deviation of final exam marks
    std_deviation_final = sqrt(variance_final);
    stats->insert(make_pair("std_deviation_final", std_deviation_final));

    // Calculate coefficient of variation of final exam marks
    double coeff_of_var_final = (mean_final != 0) ? std_deviation_final / mean_final : 0;
    stats->insert(make_pair("cvx_final", coeff_of_var_final * 100)); // store it as a percentage

    return stats;
}

// Function to calculate midterm statistics
map<string, double> calculate_midterm_statistics(map<string, Student>& students, const string &module_name) {
    map<string, double> stats;

    if (students.empty()) {
        stats["mode_midterm"] = 0;
        stats["median_midterm"] = 0;
        stats["max_midterm"] = 0;
        stats["min_midterm"] = 0;
        return stats;
    }

    vector<double> midterm_marks;

    // Collect midterm marks for the specified module
    for (auto &entry : students) {
        double midterm_mark = entry.second.get_midterm_mark(module_name);
        midterm_marks.push_back(midterm_mark);
    }

    // Calculate mode
    map<double, int> count_map;
    for (double mark : midterm_marks) {
        count_map[mark]++;
    }
    double mode_midterm = 0;
    int max_count = 0;
    for (const auto &pair : count_map) {
        if (pair.second > max_count) {
            max_count = pair.second;
            mode_midterm = pair.first;
        }
    }
    stats["mode_midterm"] = mode_midterm;

    // Calculate median
    sort(midterm_marks.begin(), midterm_marks.end());
    double median_midterm = 0;
    if (midterm_marks.size() % 2 == 0) {
        median_midterm = (midterm_marks[midterm_marks.size() / 2 - 1] + midterm_marks[midterm_marks.size() / 2]) / 2;
    } else {
        median_midterm = midterm_marks[midterm_marks.size() / 2];
    }
    stats["median_midterm"] = median_midterm;

    // Calculate maximum and minimum
    double max_midterm = *max_element(midterm_marks.begin(), midterm_marks.end());
    double min_midterm = *min_element(midterm_marks.begin(), midterm_marks.end());
    stats["max_midterm"] = max_midterm;
    stats["min_midterm"] = min_midterm;

    return stats;
}

// Function to calculate final exam statistics
map<string, double> calculate_final_exam_statistics(map<string, Student>& students, const string &module_name) {
    map<string, double> stats;

    if (students.empty()) {
        stats["mode_final"] = 0;
        stats["median_final"] = 0;
        stats["max_final"] = 0;
        stats["min_final"] = 0;
        return stats;
    }

    vector<double> final_exam_marks;

    // Collect final exam marks for the specified module
    for (auto &entry : students) {
        double final_exam_mark = entry.second.get_final_mark(module_name);
        final_exam_marks.push_back(final_exam_mark);
    }

    // Calculate mode
    map<double, int> count_map;
    for (double mark : final_exam_marks) {
        count_map[mark]++;
    }
    double mode_final_exam = 0;
    int max_count = 0;
    for (const auto &pair : count_map) {
        if (pair.second > max_count) {
            max_count = pair.second;
            mode_final_exam = pair.first;
        }
    }
    stats["mode_final"] = mode_final_exam;

    // Calculate median
    sort(final_exam_marks.begin(), final_exam_marks.end());
    double median_final_exam = 0;
    if (final_exam_marks.size() % 2 == 0) {
        median_final_exam = (final_exam_marks[final_exam_marks.size() / 2 - 1] + final_exam_marks[final_exam_marks.size() / 2]) / 2;
    } else {
        median_final_exam = final_exam_marks[final_exam_marks.size() / 2];
    }
    stats["median_final"] = median_final_exam;

    // Calculate maximum and minimum
    double max_final_exam = *max_element(final_exam_marks.begin(), final_exam_marks.end());
    double min_final_exam = *min_element(final_exam_marks.begin(), final_exam_marks.end());
    stats["max_final"] = max_final_exam;
    stats["min_final"] = min_final_exam;

    return stats;
}

// Helper function to collect midterm marks and years data
void collect_midterm_data(const map<string, Student>& students,
                          const string &module_name,
                          vector<double>& midterm_marks,
                          vector<double>& years,
                          int year_number) {
    for (auto &entry : students) {
        double midterm_mark = entry.second.get_midterm_mark(module_name);
        midterm_marks.push_back(midterm_mark);
        years.push_back(static_cast<double>(year_number));
    }
}

// Helper function to collect final exam marks and years data
void collect_final_exam_data(map<string, Student>& students,
                             const string &module_name,
                             vector<double>& final_exam_marks,
                             vector<double>& years,
                             int year_number) {
    for (auto &entry : students) {
        double final_exam_mark = entry.second.get_final_mark(module_name);
        final_exam_marks.push_back(final_exam_mark);
        years.push_back(static_cast<double>(year_number));
    }
}

// Helper function to calculate mean of a vector of doubles
double calculate_mean(const vector<double>& data) {
    if (data.empty()) return 0.0;
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

// Helper function to calculate covariance between two vectors of doubles
double calculate_covariance(const vector<double>& data1, const vector<double>& data2, double mean1, double mean2) {
    if (data1.size() != data2.size() || data1.empty()) return 0.0;
    double covariance = 0.0;
    for (size_t i = 0; i < data1.size(); ++i) {
        covariance += (data1[i] - mean1) * (data2[i] - mean2);
    }
    return covariance / data1.size();
}

// Function to calculate correlation coefficient for midterm marks and year number
double calculate_correlation_coefficient(map<string, Student>& students1,
                                         map<string, Student>& students2,
                                         map<string, Student>& students3,
                                         const string &module_name) {
    vector<double> midterm_marks;
    vector<double> years;
    collect_midterm_data(students1, module_name, midterm_marks, years, 1);
    collect_midterm_data(students2, module_name, midterm_marks, years, 2);
    collect_midterm_data(students3, module_name, midterm_marks, years, 3);

    double mean_midterm = calculate_mean(midterm_marks);
    double mean_years = calculate_mean(years);

    double covariance = calculate_covariance(midterm_marks, years, mean_midterm, mean_years);

    double variance_midterm = calculate_covariance(midterm_marks, midterm_marks, mean_midterm, mean_midterm);
    double variance_years = calculate_covariance(years, years, mean_years, mean_years);

    double correlation_coefficient = (variance_midterm != 0 && variance_years != 0) ?
                                      covariance / (sqrt(variance_midterm) * sqrt(variance_years)) :
                                      0.0;

    return correlation_coefficient;
}

// Function to calculate correlation coefficient for final exam marks and year number
double calculate_correlation_final_coefficient(map<string, Student>& students1,
                                               map<string, Student>& students2,
                                               map<string, Student>& students3,
                                               const string &module_name) {
    vector<double> final_exam_marks;
    vector<double> years;
    collect_final_exam_data(students1, module_name, final_exam_marks, years, 1);
    collect_final_exam_data(students2, module_name, final_exam_marks, years, 2);
    collect_final_exam_data(students3, module_name, final_exam_marks, years, 3);

    double mean_final_exam = calculate_mean(final_exam_marks);
    double mean_years = calculate_mean(years);

    double covariance = calculate_covariance(final_exam_marks, years, mean_final_exam, mean_years);

    double variance_final_exam = calculate_covariance(final_exam_marks, final_exam_marks, mean_final_exam, mean_final_exam);
    double variance_years = calculate_covariance(years, years, mean_years, mean_years);

    double correlation_coefficient = (variance_final_exam != 0 && variance_years != 0) ?
                                      covariance / (sqrt(variance_final_exam) * sqrt(variance_years)) :
                                      0.0;

    return correlation_coefficient;
}

// Function to calculate the covariance between midterm marks and year number
double calculate_midterm_year_covariance(map<string, Student>& students,
                                         const string &module_name,
                                         int year_number) {
    vector<double> midterm_marks;
    vector<double> years;
    collect_midterm_data(students, module_name, midterm_marks, years, year_number);

    double mean_midterm = calculate_mean(midterm_marks);
    double mean_year = calculate_mean(years);

    double covariance = calculate_covariance(midterm_marks, years, mean_midterm, mean_year);

    return covariance;
}


void draw_midterm_scatter_plot(WINDOW* plot_win,
                               map<string, Student>& students_list,
                               map<string, Student>& students_list_next_year,
                               map<string, Student>& students_list_next_next_year,
                               const string& module_name,
                               int plot_width,
                               int plot_height) {
    // Prepare data
    vector<double> midterm_marks;
    vector<double> years;

    collect_midterm_data(students_list, module_name, midterm_marks, years, 1);
    collect_midterm_data(students_list_next_year, module_name, midterm_marks, years, 2);
    collect_midterm_data(students_list_next_next_year, module_name, midterm_marks, years, 3);

    if (midterm_marks.empty() || years.empty()) {
        mvwprintw(plot_win, plot_height / 2, plot_width / 2 - 10, "No data to display");
        wrefresh(plot_win);
        return;
    }

    // Determine scaling factors
    double max_mark = *max_element(midterm_marks.begin(), midterm_marks.end());
    double min_mark = *min_element(midterm_marks.begin(), midterm_marks.end());
    int max_year = 3; // Assuming we have data for 3 years

    // Clear previous plot
    werase(plot_win);

    // Draw x-axis and y-axis with margins
    for (int x = 1; x < plot_width - 1; ++x) {
        mvwaddch(plot_win, plot_height - 2, x, '-'); // x-axis
    }
    for (int y = 1; y < plot_height - 1; ++y) {
        mvwaddch(plot_win, y, 1, '|'); // y-axis
    }

    // Label axes with margins
    mvwprintw(plot_win, plot_height - 1, plot_width / 2 - 4, "Marks");
    mvwprintw(plot_win, 0, plot_width / 2 - 2, "Years");

    // Plot data points
    for (size_t i = 0; i < midterm_marks.size(); ++i) {
        int x = static_cast<int>((years[i] - 1) * (plot_width - 4) / (max_year * 2)) + 2;
        int y = plot_height - 2 - static_cast<int>((midterm_marks[i] - min_mark) / (max_mark - min_mark) * (plot_height - 3));
        mvwaddch(plot_win, y, x, '+');
    }

    wrefresh(plot_win);
}


void draw_final_exam_scatter_plot(WINDOW* plot_win,
                                  map<string, Student>& students_list,
                                  map<string, Student>& students_list_next_year,
                                  map<string, Student>& students_list_next_next_year,
                                  const string& module_name,
                                  int plot_width,
                                  int plot_height) {
    // Prepare data
    vector<double> final_exam_marks;
    vector<double> years;

    collect_final_exam_data(students_list, module_name, final_exam_marks, years, 1);
    collect_final_exam_data(students_list_next_year, module_name, final_exam_marks, years, 2);
    collect_final_exam_data(students_list_next_next_year, module_name, final_exam_marks, years, 3);

    if (final_exam_marks.empty() || years.empty()) {
        mvwprintw(plot_win, plot_height / 2, plot_width / 2 - 10, "No data to display");
        wrefresh(plot_win);
        return;
    }

    // Determine scaling factors
    double max_mark = *max_element(final_exam_marks.begin(), final_exam_marks.end());
    double min_mark = *min_element(final_exam_marks.begin(), final_exam_marks.end());
    int max_year = 3; // Assuming we have data for 3 years

    // Clear previous plot
    werase(plot_win);

    // Draw x-axis and y-axis with margins
    for (int x = 1; x < plot_width - 1; ++x) {
        mvwaddch(plot_win, plot_height - 2, x, '-'); // x-axis
    }
    for (int y = 1; y < plot_height - 1; ++y) {
        mvwaddch(plot_win, y, 1, '|'); // y-axis
    }

    // Label axes with margins
    mvwprintw(plot_win, plot_height - 1, plot_width / 2 - 4, "Marks");
    mvwprintw(plot_win, 0, plot_width / 2 - 2, "Years");

    // Plot data points
    for (size_t i = 0; i < final_exam_marks.size(); ++i) {
        int x = static_cast<int>((years[i] - 1) * (plot_width - 3) / (max_year * 2)) + 2;
        int y = plot_height - 2 - static_cast<int>((final_exam_marks[i] - min_mark) / (max_mark - min_mark) * (plot_height - 3));
        mvwaddch(plot_win, y, x, '*');
    }

    wrefresh(plot_win);
}

#endif

