#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include "student.h"
#include "teacher.h"
#include "date.h"
#include "time.h"
#include "cours.h"
#include <sstream>

using namespace std;
 // File paths
    const string students_file = "~/program1/data/students_datahovuhovi.txt";
    const string teachers_file = "~/program1/data/teachers_datahovuhovi.txt";
    const string exams_file = "~/program1/data/exams_datahovuhovi.txt";
   const string exams_next_file = "~/program1/data/exams_next_datahovuhovi.txt";
const string exams_next_next_file = "~/program1/data/exams_next_next_datahovuhovi.txt";
map<string, Student> students_list_next_year;
map<string, Student> students_list_next_next_year;
map<string, Student> students_list;
map<string, Teacher> teachers_list;
// This function expands the '~' in the file path to the home directory
string expand_tilde(const string& path) {
    if (path[0] == '~') {
        const char* home = getenv("HOME");
        if (home) {
            return string(home) + path.substr(1);
        }
    }
    return path;
}

// Function to trim whitespace from both ends of a string
string trim(const string& str) {
    auto start = str.begin();
    while (start != str.end() && isspace(*start)) {
        start++;
    }

    auto end = str.end();
    do {
        end--;
    } while (distance(start, end) > 0 && isspace(*end));

    return string(start, end + 1);
}

// Function to read student data from a line and add it to the map
void read_line_from_file_students(map<string, Student>& student_list, const string& seg,  string filename) {
    filename =expand_tilde(filename);
    int i = 0;
    char* infos[4];
    char* str = new char[seg.length() + 1];
    strcpy(str, seg.c_str());

    char* token = strtok(str, " ,-:!?=;/\\|");
    while (token != nullptr && i < 4) {
        infos[i] = token;
        token = strtok(nullptr, " ,-:!?=;/\\|");
        ++i;
    }

    string firstname = infos[0];
    string lastname = infos[1];
    string email_address = infos[2];
    string id = infos[3];

    string firstname_lastname = firstname + "_" + lastname;
    Student student(firstname, lastname, email_address, id);
    student_list[firstname_lastname] = student;

    // Open the output file in append mode
    ofstream output_file(filename, ios::app);
    if (output_file.is_open()) {
        // Write the student data to the output file in the same format as save_students_to_file
        output_file << firstname_lastname << " " << firstname << " " << lastname << " " << email_address << " " << id << endl;
        output_file.close();
    } else {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
    }

    delete[] str;
}
// Function to read teacher data from a line and add it to the map
void read_line_from_file_teachers(map<string, Teacher>& teacher_list, const string& seg,  string filename) {
    filename = expand_tilde(filename);
    char* infos[20]; // increased size for more courses and dates
    char* str = new char[seg.length() + 1];
    strcpy(str, seg.c_str());

    int i = 0;
    char* token = strtok(str, " ,-:!?=;|");
    while (token != nullptr && i < 20) {
        infos[i++] = token;
        token = strtok(nullptr, " ,-:!?=;|");
    }
    infos[i] = nullptr;  // Null-terminate the array correctly

    // Make sure we have at least firstname, lastname, and email
    if (i < 3) {
        cerr << "Error: Invalid line format, missing basic information: " << seg << endl;
        delete[] str;
        return;
    }

    string firstname = infos[0];
    string lastname = infos[1];
    string email = infos[2];

    string firstname_lastname = firstname + "_" + lastname;
    Teacher teacher(firstname, lastname, email);
    teacher_list[firstname_lastname] = teacher;

    // Open the output file in append mode
    ofstream teacher_file(filename, ios::app);

    if (teacher_file.is_open()) {
        // Write the teacher data to the teacher file
        teacher_file << firstname_lastname << " " << firstname << " " << lastname << " " << email <<" ";

        int j = 3; // Start from the fourth token
        while (infos[j] != nullptr && infos[j+1] != nullptr) {
            string coursename = infos[j];
            string date_str = infos[j+1];
            date_str =trim(date_str);
            Cours c(coursename);
            
            teacher.add_cours(c, date_str);

            // Write the course data to the teacher file
            teacher_file << coursename << " " << date_str << " ";
            j += 2;
        }
        teacher_file << endl;

        teacher_file.close();
    } else {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
    }

    delete[] str;
}
// Main function for processing student files
int main_students_files() {
    string script_path = "~/program1/bash_script.sh";
    string command = script_path + " > ~/program1/selected_file.txt";
    system(command.c_str());

    ifstream file1(expand_tilde("~/program1/selected_file.txt"));
    if (!file1.is_open()) {
        cerr << "Error: Could not open file for reading selected file path." << endl;
        return 1;
    }

    string selected_file;
    getline(file1, selected_file);
    file1.close();

        ifstream file2(expand_tilde(selected_file));
    if (!file2.is_open()) {
        cerr << "Error: Could not open file: " << selected_file << endl;
        return 1;
    }

    string line;
    while (getline(file2, line)) {
        string trimmed_line = trim(line);
        if (trimmed_line.empty()) {
            continue;
        }
        read_line_from_file_students(students_list, trimmed_line,students_file);
    }
    file2.close();

   
    system("~/program1/bash_script2.sh");

    return 0;
}

// Main function for processing teacher files
int main_teachers_files() {
    string script_path = "~/program1/bash_script.sh";
    string command = script_path + " > ~/program1/selected_file.txt";
    system(command.c_str());

    ifstream file1(expand_tilde("~/program1/selected_file.txt"));
    if (!file1.is_open()) {
        cerr << "Error: Could not open file for reading selected file path." << endl;
        return 1;
    }

    string selected_file;
    getline(file1, selected_file);
    file1.close(); 

        ifstream file2(expand_tilde(selected_file));
    if (!file2.is_open()) {
        cerr << "Error: Could not open file: " << selected_file << endl;
        return 1;
    }

    string line;
    while (getline(file2, line)) {
        string trimmed_line = trim(line);
        if (trimmed_line.empty()) {
            continue;
        }
        read_line_from_file_teachers(teachers_list, trimmed_line, teachers_file) ;    }
    file2.close();

   
    system("~/program1/bash_script2.sh");

    return 0;
}



// Function to save student data to a file
/*void save_students_to_file(const map<string, Student>& students_list, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : students_list) {
            file << entry.first << " " << entry.second.first_name << " " << entry.second.last_name << " " << entry.second.email_address << " " << entry.second.id << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
    }
}*/

// Function to load student data from a file
void load_students_from_file(map<string, Student>& students_list, string filename) {
    filename = expand_tilde(filename);
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            line = trim(line);
        if (line.empty()) {
            continue; // Skip empty lines
        }
            istringstream iss(line);
            string key, firstname, lastname, address, id;
            if (iss >> key >> firstname >> lastname >> address >> id) {
                students_list[key] = Student(firstname, lastname, address, id);
            } else {
                cerr << "Error: Failed to parse student data from line: " << line << endl;
            }
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading: " << filename << endl;
    }
}

// Function to save teacher data to a file
/*void save_teachers_to_file(const map<string, Teacher>& teachers_list, const string& filename, const string& filename2) {
    ofstream file(filename);
    ofstream file2(filename2);
    if (file.is_open()) {
        for (const auto& entry : teachers_list) {
            file << entry.first << " " << entry.second.first_name << " " << entry.second.last_name << " " << entry.second.email_address << endl;
            for (const auto& course_entry : entry.second.courses {
                file << course_entry.first << " " << course_entry.second.name << " " << course_entry.second.coefficient << " " << course_entry.second.cc_mark << endl;
                 if (file2.is_open()) {
                 for (const auto& entry : course_entry.second.exams) {
                file2 << entry->name << " " << entry->get_worth() << " " << entry->Date <<" "<< entry->time<< endl;
               }
            file2 << endl;
        }
        file2.close();
    } else {
        cerr << "Error: Unable to open file for writing: " << filename2 << endl;
    }

                   
            }
            file << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
    }
         
} */

// Function to load teacher data from a file
void load_teachers_from_file(map<string, Teacher>& teachers_list, string filename) {
    filename = expand_tilde(filename);
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            line = trim(line);
            if (line.empty()) {
                continue; // Skip empty lines
            }

            char* str = new char[line.length() + 1];
            strcpy(str, line.c_str());
            char* token = strtok(str, " ,-:!?=;|");
            if (token != nullptr) {
                string key = trim(token);
                token = strtok(nullptr, " ,-:!?=;|");
                if (token != nullptr) {
                    string firstname = trim(token);
                    token = strtok(nullptr, " ,-:!?=;|");
                    if (token != nullptr) {
                        string lastname = trim(token);
                        token = strtok(nullptr, " ,-:!?=;|");
                        if (token != nullptr) {
                            string email = trim(token);
                            string firstname_lastname = trim(key);
                            Teacher teacher(firstname, lastname, email);
                            teachers_list[firstname_lastname] = teacher;
                            token = strtok(nullptr, " ,-:!?=;|");
                            while (token != nullptr) {
                                string coursename = trim(token);
                                token = strtok(nullptr, " ,-:!?=;|");
                                if (token != nullptr) {
                                    string date_str = trim(token);
                                    if (!date_str.empty()) {
                                        Cours c(coursename);
                                        
                                        teachers_list[firstname_lastname].add_cours(c, date_str);
                                        token = strtok(nullptr, " ,-:!?=;|");
                                    } else {
                                        cerr << "Error: Empty date string encountered for course: " << coursename << endl;
                                        token = strtok(nullptr, " ,-:!?=;|");
                                    }
                                } else {
                                    cerr << "Error: Failed to parse course data from line: " << line << endl;
                                    break;
                                }
                            }
                        } else {
                            cerr << "Error: Failed to parse teacher data from line: " << line << endl;
                        }
                    } else {
                        cerr << "Error: Failed to parse teacher data from line: " << line << endl;
                    }
                } else {
                    cerr << "Error: Failed to parse teacher data from line: " << line << endl;
                }
            } else {
                cerr << "Error: Failed to parse teacher data from line: " << line << endl;
            }
            delete[] str;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading: " << filename << endl;
    }
}

 void read_line_from_file_exams(map<string, Student>& students_list, const string& seg, string exams_file) {
    exams_file = expand_tilde(exams_file);
    int i = 0;
    char* infos[5]; 
    char* str = new char[seg.length() + 1];
    strcpy(str, seg.c_str());

    char* token = strtok(str, " ,-:!?=;/\\|");
    while (token != nullptr && i < 5) {
        infos[i] = token;
        token = strtok(nullptr, " ,-:!?=;/\\|");
        ++i;
    }

    // Ensure we have all expected tokens
    if (i < 5) {
        cerr << "Error: Invalid line format, missing some information: " << seg << endl;
        delete[] str;
        return;
    }

    string firstname = infos[0];
    string lastname = infos[1];
    string cours_name = infos[2];
    string exam_mark_mid = infos[3];
    string exam_mark_final = infos[4];

    string firstname_lastname = firstname + "_" + lastname;
    Midterm* mi = new Midterm(exam_mark_mid);
    FinalExam* fi = new FinalExam(exam_mark_final);

    students_list[firstname_lastname].marks[cours_name].exams.push_back(mi);
    students_list[firstname_lastname].marks[cours_name].exams.push_back(fi);

    // Open the output file in append mode
    ofstream output_file(exams_file, ios::app);
    if (output_file.is_open()) {
        // Write the exams data to the output file with proper spacing
        output_file << firstname_lastname << " " << firstname << " " << lastname << " " << cours_name << " " << exam_mark_mid << " " << exam_mark_final<<endl ;
        output_file.close();
    } else {
        cerr << "Error: Unable to open file for writing: " << exams_file << endl;
    }

    delete[] str;
}
// Main function for processing cours-exams files
int main_exams_files() {
     string script_path = "~/program1/bash_script.sh";
    string command = script_path + " > ~/program1/selected_file.txt";
    system(command.c_str());

    ifstream file1(expand_tilde("~/program1/selected_file.txt"));
    if (!file1.is_open()) {
        cerr << "Error: Could not open file for reading selected file path." << endl;
        return 1;
    }

    string selected_file;
    getline(file1, selected_file);
    file1.close();

        ifstream file2(expand_tilde(selected_file));
    if (!file2.is_open()) {
        cerr << "Error: Could not open file: " << selected_file << endl;
        return 1;
    }

    string line;
    while (getline(file2, line)) {
        string trimmed_line = trim(line);
        if (trimmed_line.empty()) {
            continue;
        }
        read_line_from_file_exams(students_list, trimmed_line,exams_file)  ;
    }
    file2.close();

   
    system("~/program1/bash_script2.sh");

    return 0;
}


int main_exams_next_files() {
     string script_path = "~/program1/bash_script.sh";
    string command = script_path + " > ~/program1/selected_file.txt";
    system(command.c_str());

    ifstream file1(expand_tilde("~/program1/selected_file.txt"));
    if (!file1.is_open()) {
        cerr << "Error: Could not open file for reading selected file path." << endl;
        return 1;
    }

    string selected_file;
    getline(file1, selected_file);
    file1.close();

        ifstream file2(expand_tilde(selected_file));
    if (!file2.is_open()) {
        cerr << "Error: Could not open file: " << selected_file << endl;
        return 1;
    }

    string line;
    while (getline(file2, line)) {
        string trimmed_line = trim(line);
        if (trimmed_line.empty()) {
            continue;
        }
        read_line_from_file_exams(students_list_next_year, trimmed_line,exams_next_file)  ;
    }
    file2.close();

   
    system("~/program1/bash_script2.sh");

    return 0;
}

int main_exams_next_next_files() {
     string script_path = "~/program1/bash_script.sh";
    string command = script_path + " > ~/program1/selected_file.txt";
    system(command.c_str());

    ifstream file1(expand_tilde("~/program1/selected_file.txt"));
    if (!file1.is_open()) {
        cerr << "Error: Could not open file for reading selected file path." << endl;
        return 1;
    }

    string selected_file;
    getline(file1, selected_file);
    file1.close();

        ifstream file2(expand_tilde(selected_file));
    if (!file2.is_open()) {
        cerr << "Error: Could not open file: " << selected_file << endl;
        return 1;
    }

    string line;
    while (getline(file2, line)) {
        string trimmed_line = trim(line);
        if (trimmed_line.empty()) {
            continue;
        }
        read_line_from_file_exams(students_list_next_next_year, trimmed_line,exams_next_next_file)  ;
    }
    file2.close();

   
    system("~/program1/bash_script2.sh");

    return 0;
}


//Function to load exam data from a file 
void load_exams_from_file(map<string, Student>& students_list, string exams_file) { 
    exams_file = expand_tilde(exams_file);
    ifstream file(exams_file);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            line = trim(line);
        if (line.empty()) {
            continue; // Skip empty lines 
        } 

            
            istringstream iss(line);
            string firstname_lastname, firstname, lastname, cours_name, exam_mark_mid, exam_mark_final;
            if (iss >> firstname_lastname >> firstname >> lastname >> cours_name >> exam_mark_mid >> exam_mark_final) 
            {  


                string student_key = firstname + "_" + lastname; 
                // Create Midterm and FinalExam objects
                Midterm* mi = new Midterm();  
                FinalExam* fi = new FinalExam();
                mi->set_mark(exam_mark_mid);
                fi->set_mark(exam_mark_final);
                 
                // Add exams to the student's course
                students_list[student_key].marks[cours_name].exams.push_back(mi);   
                students_list[student_key].marks[cours_name].exams.push_back(fi);   
            } else    
            {
              cerr << "Error: Failed to parse exam data from line: " << line << endl;
            }
        }
        file.close();
    } else 

    {
        cerr << "Error: Unable to open file for reading: " << exams_file << endl;
    }
}






int main_load(map<string, Student>&  students_list, map<string, Teacher> & teachers_list) {
   
    // Load students and teachers from files
        load_students_from_file(students_list, expand_tilde(students_file));
        load_exams_from_file(students_list,  expand_tilde(exams_file));
        load_exams_from_file(students_list_next_year,  expand_tilde(exams_next_file));
        load_exams_from_file(students_list_next_next_year,  expand_tilde(exams_next_next_file));
        load_teachers_from_file(teachers_list, expand_tilde(teachers_file));


   
    return 0;
}
/*int main_store(map<string, Student>& students_list, map<string, Teacher> & teachers_list){

   // Save students and teachers back to files before exiting
    save_students_to_file(students_list, students_file);
    save_teachers_to_file(teachers_list, teachers_file);
 //very cool storing //microsoft would never

    return 0;
}*/


