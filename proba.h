#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate regression coefficients (beta0 and beta1)
std::pair<double, double> calculate_regression_coefficients(const std::vector<double>& years, const std::vector<double>& midterm_marks) {
    double mean_years = 0.0, mean_marks = 0.0;
    double sum_xy = 0.0, sum_xx = 0.0;

    // Calculate means
    for (size_t i = 0; i < years.size(); ++i) {
        mean_years += years[i];
        mean_marks += midterm_marks[i];
    }
    mean_years /= years.size();
    mean_marks /= midterm_marks.size();

    // Calculate regression coefficients
    for (size_t i = 0; i < years.size(); ++i) {
        sum_xy += (years[i] - mean_years) * (midterm_marks[i] - mean_marks);
        sum_xx += (years[i] - mean_years) * (years[i] - mean_years);
    }

    double beta1 = sum_xy / sum_xx;
    double beta0 = mean_marks - beta1 * mean_years;

    return {beta0, beta1};
}

// Function to predict future midterm marks based on regression coefficients
std::vector<double> predict_future(const std::vector<double>& years, double beta0, double beta1, int years_ahead) {
    std::vector<double> future_predictions(years_ahead);

    for (int i = 0; i < years_ahead; ++i) {
        double future_year = years.back() + i + 1;
        future_predictions[i] = beta0 + beta1 * future_year;
    }

    return future_predictions;
}

// Function to calculate success percentage based on predicted future values
double calculate_success_percentage(const std::vector<double>& future_predictions, double passing_score) {
    int passing_students = 0;
    int total_students = future_predictions.size();

    for (size_t i = 0; i < total_students; ++i) {
        if (future_predictions[i] >= passing_score) {
            passing_students++;
        }
    }

    double passing_percentage = (static_cast<double>(passing_students) / total_students) * 100.0;
    return passing_percentage;
}

// Example usage (assuming this would be integrated into an existing application)
void print_success_percentage(WINDOW* win, const std::string& module_name, int years_ahead, int start_row, int start_col,
                              const std::map<std::string, Student>& students_list_year1,
                              const std::map<std::string, Student>& students_list_year2,
                              const std::map<std::string, Student>& students_list_year3) {
    std::vector<double> midterm_marks;
    std::vector<double> years;

    // Collect midterm marks and years data
    collect_midterm_data(students_list_year1, module_name, midterm_marks, years,3);
    collect_midterm_data(students_list_year2, module_name, midterm_marks, years,2);
    collect_midterm_data(students_list_year3, module_name, midterm_marks, years,1);
    // Calculate regression coefficients
    auto [beta0, beta1] = calculate_regression_coefficients(years, midterm_marks);

    // Predict future midterm marks
    std::vector<double> future_predictions = predict_future(years, beta0, beta1, years_ahead);

    // Calculate passing score (example: passing score is 10 out of 20)
    double passing_score = 10.0;

    // Calculate success percentage based on predicted future values
    double passing_percentage = calculate_success_percentage(future_predictions, passing_score);

    // Print results using mvwprintw (assuming this integrates with ncurses)
    mvwprintw(win, start_row, start_col, "Predicted percentage is: %.2f%%",  passing_percentage);
        wrefresh(win);
}
void print_success_percentage2(WINDOW* win, const std::string& module_name, int years_ahead, int start_row, int start_col,
                              const std::map<std::string, Student>& students_list_year1,
                              const std::map<std::string, Student>& students_list_year2,
                              const std::map<std::string, Student>& students_list_year3) {
    std::vector<double> midterm_marks;
    std::vector<double> years;

    // Collect midterm marks and years data
    collect_midterm_data(students_list_year1, module_name, midterm_marks, years,3);
    collect_midterm_data(students_list_year2, module_name, midterm_marks, years,2);
    collect_midterm_data(students_list_year3, module_name, midterm_marks, years,1);
    // Calculate regression coefficients
    auto [beta0, beta1] = calculate_regression_coefficients(years, midterm_marks);

    // Predict future midterm marks
    std::vector<double> future_predictions = predict_future(years, beta0, beta1, years_ahead);

    // Calculate passing score (example: passing score is 10 out of 20)
    double passing_score = 10.0;
std::vector<double> midterm_marks2;
collect_midterm_data(students_list_year1, module_name, midterm_marks2, years,3);

    // Calculate success percentage based on predicted future values
    double passing_percentage = calculate_success_percentage(future_predictions, passing_score);
    double passing_percentage2 = calculate_success_percentage(midterm_marks2, passing_score);

    // Print results using mvwprintw (assuming this integrates with ncurses)
    mvwprintw(win, start_row, start_col, "Current percentage is: %.2f%%",  passing_percentage2);
    mvwprintw(win, start_row-1, start_col, "Predicted percentage is: %.2f%%",  passing_percentage);
        wrefresh(win);
}

 void print_success_percentage3(WINDOW* win, const std::string& module_name, int years_ahead, int start_row, int start_col,
                              const std::map<std::string, Student>& students_list_year1,
                              const std::map<std::string, Student>& students_list_year2,
                              const std::map<std::string, Student>& students_list_year3) {
    std::vector<double> midterm_marks;
    std::vector<double> years;

    // Collect midterm marks and years data
    collect_midterm_data(students_list_year1, module_name, midterm_marks, years,3);
    collect_midterm_data(students_list_year2, module_name, midterm_marks, years,2);
    collect_midterm_data(students_list_year3, module_name, midterm_marks, years,1);
    // Calculate regression coefficients
    auto [beta0, beta1] = calculate_regression_coefficients(years, midterm_marks);

    // Predict future midterm marks
    std::vector<double> future_predictions = predict_future(years, beta0, beta1, years_ahead);

    // Calculate passing score (example: passing score is 10 out of 20)
    double passing_score = 10.0;
std::vector<double> midterm_marks2;
collect_midterm_data(students_list_year1, module_name, midterm_marks2, years,3);

    // Calculate success percentage based on predicted future values
    double passing_percentage =100- calculate_success_percentage(future_predictions, passing_score);
    double passing_percentage2 = 100-calculate_success_percentage(midterm_marks2, passing_score);

    // Print results using mvwprintw (assuming this integrates with ncurses)
    mvwprintw(win, start_row, start_col, "Current percentage is: %.2f%%",  passing_percentage2);
    mvwprintw(win, start_row-1, start_col, "Predicted percentage is: %.2f%%",  passing_percentage);
        wrefresh(win);
}
// Function to calculate the predicted highest score next year
double predictHighestScore(const std::vector<double>& marks) {
    if (marks.empty()) {
        std::cerr << "The marks list is empty." << std::endl;
        return -1; // Returning -1 to indicate an error condition
    }

    // Number of top marks to consider for prediction
    const double TOP_COUNT = 3; 
    
    // Make a copy of the marks and sort them in descending order
    std::vector<double> sortedMarks = marks;
    std::sort(sortedMarks.begin(), sortedMarks.end(), std::greater<double>());
    
    // Calculate the average of the top N marks
    double sum = 0;
    int count = std::min(TOP_COUNT, static_cast<double>(sortedMarks.size()));
    for (int i = 0; i < count; ++i) {
        sum += sortedMarks[i];
    }
    
    double averageOfTopMarks = sum / count;
    return averageOfTopMarks;
}

void print_success_percentage4(WINDOW* win, const std::string& module_name, int years_ahead, int start_row, int start_col,
                              const std::map<std::string, Student>& students_list_year1,
                              const std::map<std::string, Student>& students_list_year2,
                              const std::map<std::string, Student>& students_list_year3) {
    std::vector<double> midterm_marks; 
    std::vector<double> years;

    // Collect midterm marks and years data
    collect_midterm_data(students_list_year1, module_name, midterm_marks, years,3);
    collect_midterm_data(students_list_year2, module_name, midterm_marks, years,2);
    collect_midterm_data(students_list_year3, module_name, midterm_marks, years,1);


    double num =predictHighestScore(midterm_marks);
    mvwprintw(win, start_row, start_col, "highestPossibleMark is: %.2f",  num);
        wrefresh(win);
}


double getHighestMark(const std::vector<double>& marks) {
    if (marks.empty()) {
        std::cerr << "The marks vector is empty." << std::endl;
        return -1; // Return -1 to indicate an error condition
    }

    return *std::max_element(marks.begin(), marks.end());
}
double calculateOverallInterestPercentage(const std::vector<double>& interestPercentages) {
    double sum = 0.0;

    for (const auto& percentage : interestPercentages) {
        sum += percentage;
    }

    return sum / interestPercentages.size();
}



double calculateInterestPercentage(double moduleMark, double highestPossibleMark) {
    if (highestPossibleMark <= 0) {
        std::cerr << "Highest possible mark should be greater than zero." << std::endl;
        return -1; // Return -1 to indicate an error condition
    }

    double interestPercentage = (moduleMark / highestPossibleMark) * 100;
    return interestPercentage;   
}

std::vector<double> calculateInterestPercentages(const std::vector<double>& marks, double highestPossibleMark) {
    std::vector<double> interestPercentages;
    interestPercentages.reserve(marks.size());

    for (const auto& mark : marks) {
        double interestPercentage = calculateInterestPercentage(mark, highestPossibleMark);
        interestPercentages.push_back(interestPercentage);
    }

    return interestPercentages;
}



void print_success_percentage5(WINDOW* win, const std::string& module_name, int years_ahead, int start_row, int start_col,
                              const std::map<std::string, Student>& students_list_year1,
                              const std::map<std::string, Student>& students_list_year2,
                              const std::map<std::string, Student>& students_list_year3) {
    std::vector<double> midterm_marks; 
    std::vector<double> years;

    // Collect midterm marks and years data
    collect_midterm_data(students_list_year1, module_name, midterm_marks, years,3);
    collect_midterm_data(students_list_year2, module_name, midterm_marks, years,2);
    collect_midterm_data(students_list_year3, module_name, midterm_marks, years,1);

double highestMark = getHighestMark(midterm_marks);
std::vector<double> interestPercentages = calculateInterestPercentages(midterm_marks, highestMark);

    double overallInterestPercentage = calculateOverallInterestPercentage(interestPercentages);



    mvwprintw(win, start_row, start_col, "interest Percentage is: %.2f%%",  overallInterestPercentage);
        wrefresh(win);
}



std::string module_to_focus_on(const Student& s) {
    double min_mark = 20.0; // initialize min with a high value (assuming max mark is 20)
    std::string less_interested_module ; // default to english for initialization

    // iterate over the map of courses in the student's marks
    for (const auto& it : s.marks) {
        std::string course_name = it.second.to_string(); // get the course name

        // skip courses with empty names
        if (course_name.empty()) {
            continue;
        }

        double midterm_mark = it.second.get_midterm_mark(); // get the midterm mark


        if (midterm_mark <= min_mark) {
            min_mark = midterm_mark;
            less_interested_module = course_name; // set the course name as the least interested module
        }
    }

        return less_interested_module; // Return the name of the course
}  
std::string less_interested_module(const Student& student) {
    auto it = std::min_element(student.marks.begin(), student.marks.end(),
                               [&student](const auto& lhs, const auto& rhs) {
                                   double lhs_midterm = student.get_midterm_mark(lhs.first);
                                   double rhs_midterm = student.get_midterm_mark(rhs.first);
                                   return lhs_midterm < rhs_midterm;
                               });
    
    return it != student.marks.end() ? it->first : "";
}


Cours findCourseWithLowestMidtermMark(const map<string, Cours>& courses) {
    if (courses.empty()) {
        throw runtime_error("No courses available.");
    }

    auto it = courses.begin();
    auto minCourseIt = it;

    for (++it; it != courses.end(); ++it) {  // Start from the second element
        if (it->second.get_midterm_mark() < minCourseIt->second.get_midterm_mark()) {
            minCourseIt = it;
        }
    }

    return minCourseIt->second;
}
Cours findCourseWithLowestFinalMark(const map<string, Cours>& courses) {
    if (courses.empty()) {
        throw runtime_error("No courses available.");
    }

    auto it = courses.begin();
    auto minCourseIt = it;

    for (++it; it != courses.end(); ++it) {  // Start from the second element
        if (it->second.get_final_mark() < minCourseIt->second.get_final_mark()) {
            minCourseIt = it;
        }
    }

    return minCourseIt->second;
}
std::string getLowestScoredModule(const Student& student) {
    auto it = std::min_element(student.marks.begin(), student.marks.end(),
                               [&student](const auto& lhs, const auto& rhs) {
                                   return student.get_final_mark(lhs.first) < student.get_final_mark(rhs.first);
                               });
    return it != student.marks.end() ? it->first : "";
}

std::string findMostNeededHelpModule(const std::vector<Student>& students) {
    std::map<std::string, int> moduleFrequency;

    for (const auto& student : students) {
        std::string lowestScoredModule = getLowestScoredModule(student);
        if (!lowestScoredModule.empty()) {
            moduleFrequency[lowestScoredModule]++;
        }
    }

    auto mostNeededHelpModule = std::max_element(moduleFrequency.begin(), moduleFrequency.end(),
                                                 [](const auto& lhs, const auto& rhs) {
                                                     return lhs.second < rhs.second;
                                                 });

    return mostNeededHelpModule != moduleFrequency.end() ? mostNeededHelpModule->first : "";
}
