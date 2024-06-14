#include <panel.h>
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h> // for usleep()
#include <ncursesw/ncurses.h>
#include <ncursesw/panel.h>
#include <locale.h>
#include <cstring>
#include "input.h"
#include <ctime>
#include <cstdlib>
#include <tuple>
#include "date.h"
#include "time.h"
#include <typeinfo>
#include <iomanip>
#include <sstream>
#include <cmath>
#include "stat.h"
#include "proba.h"
#include <iterator>
using namespace std;


 void cleanPW(PANEL*pan1,PANEL*pan3,PANEL*help_pan,PANEL*input_pan,PANEL*loading_pan,PANEL*stud_pan,PANEL*tea_pan,PANEL*stat_pan,PANEL*proba_pan,WINDOW * win1,WINDOW * win3,WINDOW * help_win,WINDOW * input_win,WINDOW * loading_win,WINDOW * stud_win,WINDOW * tea_win,WINDOW * stat_win,WINDOW * proba_win){
 // Clean up
    del_panel(pan3);
    del_panel(pan1);
    del_panel(input_pan);
    del_panel(help_pan);
    del_panel(stud_pan);
    del_panel(tea_pan);
    del_panel(stat_pan);
    del_panel(proba_pan);
    delwin(win3);
    delwin(win1);
    delwin(input_win);
    delwin(help_win);
    delwin(stud_win);
    delwin(tea_win);
    delwin(stat_win);
    delwin(proba_win);
    endwin();
}


void clear_panel(PANEL *panel) {
    werase(panel_window(panel));  // Clear the panel window
    wrefresh(panel_window(panel));  // Refresh to show the changes
}

/*void  display_teacher_info(WINDOW* win,WINDOW* loading_win.PANEL* loading_pan, int height, int width) {
    top_panel(loading_pan);
    update_panels();
    doupdate();

    // Print title at the top center
    box(loading_win, 0, 0);
    int box_width_loading = width - 2;
    mvwprintw(loading_win, 0, (box_width_loading - strlen("TEACHER INFO")) / 2, "TEACHER INFO");
    wrefresh(loading_win);

    // Get the first name and last name from the user
    mvwprintw(loading_win, 2, 2, "Enter teacher's first name: ");
    wrefresh(loading_win);
    string first_name = get_input(loading_win, 3, 2);
    mvwprintw(loading_win, 4, 2, "Enter teacher's last name: ");
    wrefresh(loading_win);
    string last_name = get_input(loading_win, 5, 2);

    // Check if the teacher exists in the map
    auto it = teachers_list.find(first_name + "_" + last_name);
    if (it != teachers_list.end()) {
        const Teacher& teacher = it->second;

        // Print the teacher's information
        mvwprintw(loading_win, 7, 2, "First Name: %s", teacher.first_name.c_str());
        mvwprintw(loading_win, 8, 2, "Last Name: %s", teacher.last_name.c_str());
        mvwprintw(loading_win, 9, 2, "Email: %s", teacher.email_address.c_str());

        // Print the teacher's courses
        int line = 11;
        mvwprintw(loading_win, line++, 2, "Courses:");
        for (const auto& [date, course] : teacher.courses) {
            mvwprintw(loading_win, line++, 4, "Date: %s", date.c_str());
            mvwprintw(loading_win, line++, 4, "%s", course.to_string().c_str());
            line++;
        }
    } else {
        mvwprintw(loading_win, 7, 2, "Teacher not found!");
    }

    wrefresh(loading_win);
    usleep(7000000); // Wait for 1 second

    // Hide the loading panel
    hide_panel(loading_pan);
    clear_panel(loading_pan);
}*/

void draw_input_box(WINDOW *win, int height, int width) {

    int input_box_height = 3;
    int input_box_width = width - 2;
    int input_box_start_y = height - input_box_height - 1;
    int input_box_start_x = 1;

    mvwhline(win, input_box_start_y - 1, input_box_start_x, '-', input_box_width);
    mvwvline(win, input_box_start_y, input_box_start_x - 1, '|', input_box_height);
    mvwvline(win, input_box_start_y, input_box_start_x + input_box_width, '|', input_box_height);
    mvwhline(win, input_box_start_y + input_box_height, input_box_start_x, '-', input_box_width);
    mvwprintw(win, input_box_start_y, input_box_start_x + 1, "Choices:  ");
    mvwprintw(win, input_box_start_y+2, input_box_start_x + 28, "     W:add_student  R:return Q:quit  L:display_x_student_info M:show_more_students ");
    wrefresh(win);
}

void draw_input_box_tea(WINDOW *win, int height, int width) {

    int input_box_height = 3;
    int input_box_width = width - 2;
    int input_box_start_y = height - input_box_height - 1;
    int input_box_start_x = 1;

    mvwhline(win, input_box_start_y - 1, input_box_start_x, '-', input_box_width);
    mvwvline(win, input_box_start_y, input_box_start_x - 1, '|', input_box_height);
    mvwvline(win, input_box_start_y, input_box_start_x + input_box_width, '|', input_box_height);
    mvwhline(win, input_box_start_y + input_box_height, input_box_start_x, '-', input_box_width);
    mvwprintw(win, input_box_start_y, input_box_start_x + 1, "Choices:  ");
    mvwprintw(win, input_box_start_y+2, input_box_start_x + 28, "   W:add_teacher  R:return Q:quit  L:display_x_teacher_info M:show_more  ");
    wrefresh(win);
}





void display_teachers(WINDOW* win, int height, int width, int& start_index) {
    // Clear the window
    werase(win);
    // Print title
    mvwprintw(win, 1, (width - 14) / 2, "TEACHER LIST");
    int start_row = 3; // Starting row for displaying teachers
    int col1 = 2; // Starting column for the first list
    int col2 = width / 3 + 2; // Starting column for the second list
    int col3 = (width * 2) / 3 + 2; // Starting column for the third list
    int row1 = start_row, row2 = start_row, row3 = start_row;
    int max_row = height - 4; // Maximum row for displaying teachers (accounting for the input box)
    int max_teachers_displayed = (height - 4) * 3; // Maximum number of teachers that can be displayed

    // Iterate through the teachers_list map starting from the start_index
    int teacher_count = 1;
    auto it = teachers_list.begin();
    std::advance(it, start_index);
    for (; it != teachers_list.end(); ++it) {
        if (row1 >= max_row && row2 >= max_row && row3 >= max_row) {
            // Stop outputting if the maximum row is reached
            break;
        }

        int col = (teacher_count % 3 == 1) ? col1 : (teacher_count % 3 == 2) ? col2 : col3;
        int& row = (teacher_count % 3 == 1) ? row1 : (teacher_count % 3 == 2) ? row2 : row3;

        // Print teacher's information
        if (row < max_row) {
            mvwprintw(win, row++, col, "Name: %s %s", it->second.first_name.c_str(), it->second.last_name.c_str());
        } else {
            row++;
        }

        if (row < max_row) {
            mvwprintw(win, row++, col, "Email: %s", it->second.email_address.c_str());
        } else {
            row++;
        }

        // Print courses and dates
        if (it->second.courses.empty()) {
            if (row < max_row) {
                mvwprintw(win, row++, col, "No courses registered yet.");
            } else {
                row++;
            }
        } else {
            if (row < max_row) {
                mvwprintw(win, row++, col, "Courses:");
            } else {
                row++;
            }

            for (const auto& course_pair : it->second.courses) {
                if (row < max_row) {
                    mvwprintw(win, row++, col + 2, "Date: %s", course_pair.first.c_str()); // to_string() method
                } else {
                    row++;
                }

                if (row < max_row) {
                    mvwprintw(win, row++, col + 2, "%s", course_pair.second.to_string().c_str()); // to_string() method
                } else {
                    row++;
                }

                if (row < max_row) {
                    row++; // Space between courses
                }
            }
        }

        if (row < max_row) {
            row++; // Space between teachers
        }

        teacher_count++;

        // Check if we have displayed the maximum number of teachers
        if (teacher_count > max_teachers_displayed) {
            break;
        }
    }

   
    // Draw the input box
    draw_input_box_tea(win, height, width);

    // Refresh the window
    wrefresh(win);
}


void display_students(WINDOW *win, int& start_index, int height, int width) {
    int num_students = students_list.size();
    if (num_students == 0) {
        mvwprintw(win, 1, 1, "No students registered yet.");
        return;
    }

    int max_rows = height - 5; // Maximum number of rows to display students (accounting for the input box)
    int num_cols = 3; // Number of columns to display students
    int col_width = width / num_cols; // Width of each column
    auto it = students_list.begin();
    std::advance(it, start_index); // Move the iterator to the start_index position

    int row = 1;
    int student_index = start_index;

    // Calculate the starting x-position to center the columns
    int start_x = (width - (col_width * num_cols)) / 2;

    // Print the title
    mvwprintw(win, 0, (width - 8) / 2, "STUDENTS");

    for (int i = 0; i < max_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            int x_pos = start_x + j * col_width;
            if (it != students_list.end()) {
                // Print the student's name
                mvwprintw(win, row, x_pos + 1, "  %2d  (^-^)  %s %s", student_index + 1, it->second.first_name.c_str(), it->second.last_name.c_str());
                // Print the vertical lines
                mvwvline(win, row, x_pos, '|', 1);
                mvwvline(win, row, x_pos + col_width - 1, '|', 1);
                ++it;
                ++student_index;
            } else {
                // No more students to display, leave the remaining space blank
                mvwhline(win, row, x_pos, ' ', col_width);
            }
        }
        row++;
    }

    // Draw the bottom border for each row
    for (int j = 0; j < num_cols; ++j) {
        int x_pos = start_x + j * col_width;
        mvwhline(win, row, x_pos, '-', col_width);
    }

    // Draw the input box
    draw_input_box(win, height, width);

    // Update the start_index
        // Refresh the window
    wrefresh(win);
}
string get_input(WINDOW* win, int y, int x) {
    string input;
    int ch;
    int cursor_x = x;

    curs_set(1); // Show the cursor
    noecho(); // Don't print the typed characters

    while ((ch = wgetch(win)) != '\n') {
        if (ch == KEY_BACKSPACE || ch == 127 || ch == 8) { // Handle backspace
            if (!input.empty()) {
                input.pop_back();
                mvwdelch(win, y, --cursor_x); // Move the cursor and delete character
            }
        } else if (isprint(ch)) { // Handle printable characters
            input.push_back(ch);
            mvwaddch(win, y, cursor_x++, ch); // Add character and move cursor
        }
    }

    curs_set(0); // Hide the cursor
    echo(); // Enable echo mode

    return input;
}

void add_teacher(map<string, Teacher>& teachers_list, string teachers_file, WINDOW* loading_win) {
    // Variables to store teacher data
    string first_name, last_name, email_address;
    string course_name, course_date;
    map<string, string> courses;
     teachers_file=expand_tilde(teachers_file);
    // Enter teacher's first name
    mvwprintw(loading_win, 2, 2, "Enter teacher's first name: ");
    wrefresh(loading_win);
    first_name = get_input(loading_win, 3, 2);

    // Enter teacher's last name
    mvwprintw(loading_win, 4, 2, "Enter teacher's last name: ");
    wrefresh(loading_win);
    last_name = get_input(loading_win, 5, 2);

    // Enter teacher's email address
    mvwprintw(loading_win, 6, 2, "Enter teacher's email address: ");
    wrefresh(loading_win);
    email_address = get_input(loading_win, 7, 2);

    // Construct the key for the map
    string key = first_name + "_" + last_name;

    // Check if the teacher already exists
    if (teachers_list.find(key) != teachers_list.end()) {
        mvwprintw(loading_win, 9, 2, "Teacher %s %s already exists!", first_name.c_str(), last_name.c_str());
        wrefresh(loading_win);
        return;
    }

    // Create a new teacher object
    Teacher new_teacher(first_name, last_name, email_address);

    // Prompt to add courses with dates
    mvwprintw(loading_win, 10, 2, "Enter courses and dates (Enter 'end' to finish):\n");
    wrefresh(loading_win);
    
    while (true) {
        // Enter course name
        mvwprintw(loading_win, 12, 2, "Enter course name (or 'end' to finish): ");
        wrefresh(loading_win);
        course_name = get_input(loading_win, 13, 2);

        // Check if user wants to end adding courses
        if (course_name == "end") {
            break;
        }

        // Enter course date
        mvwprintw(loading_win, 14, 2, "Enter course date (MM/DD/YYYY): ");
        wrefresh(loading_win);
        course_date = get_input(loading_win, 15, 2);

        // Add course and date to map
        courses[course_name] = course_date;
    }

    
    // Add the new teacher to the map
    teachers_list[key] = new_teacher;

    // Open the output file in append mode
    ofstream output_file(teachers_file, ios::app);
    if (output_file.is_open()) {
        // Write the teacher data to the output file
        output_file << key << " " << first_name << " " << last_name << " " << email_address << " ";
        for (const auto& pair : courses) {
            output_file << pair.first << " " << pair.second ;
        }
         output_file <<endl;
        output_file.close();

        // Print success message
        mvwprintw(loading_win, 16, 2, "Teacher %s %s added successfully!", first_name.c_str(), last_name.c_str());
    } else {
        mvwprintw(loading_win, 16, 2, "Error: Unable to open file for writing: %s", teachers_file.c_str());
    }

    wrefresh(loading_win);
}

void add_student(map<string, Student>& students_list, string students_file, WINDOW* win) {
    string first_name, last_name, email, id;

    mvwprintw(win, 2, 2, "Enter student's first name: ");
    wrefresh(win);
    first_name = get_input(win, 3, 2);

    mvwprintw(win, 4, 2, "Enter student's last name: ");
    wrefresh(win);
    last_name = get_input(win, 5, 2);

    mvwprintw(win, 6, 2, "Enter student's email address: ");
    wrefresh(win);
    email = get_input(win, 7, 2);

    mvwprintw(win, 8, 2, "Enter student's ID: ");
    wrefresh(win);
    id = get_input(win, 9, 2);

    string key = first_name + "_" + last_name;
    Student student(first_name, last_name, email, id);
    students_list[key] = student;
    students_file=expand_tilde(students_file);
    // Save the student's information to the file
    ofstream file(students_file, ios::app); // Open the file in append mode
    if (file.is_open()) {
        file << key << " " << first_name << " " << last_name << " " << email << " " << id << endl;
        file.close();
        mvwprintw(win, 11, 2, "Student added successfully.");
        wrefresh(win);
    } else {
        mvwprintw(win, 11, 2, "Error: Unable to open file for writing: %s", students_file.c_str());
        wrefresh(win);
    }
}

void save_content_state(WINDOW* win, std::vector<std::tuple<int, int, char>>& content_state, int panel_height, int panel_width) {
    content_state.clear();
    for (int y = 1; y < panel_height - 1; ++y) {
        for (int x = 1; x < panel_width - 1; ++x) {
            char ch = mvwinch(win, y, x) & A_CHARTEXT;  // Get character at position
            content_state.push_back(std::make_tuple(x, y, ch));
        }
    }
}
void draw_objects(PANEL* panel, WINDOW* win, int panel_height, int panel_width, const std::vector<std::tuple<int, int, char>>& content_state) {
    const char characters[] = "01";
    srand(time(nullptr));
    int delay = 5000;  // Delay between updates (in microseconds)
    std::vector<std::tuple<int, int, char>> border_coordinates;

    // Initialize border_coordinates with characters for the window border
    for (int y = 0; y < panel_height; ++y) {
        char ch = characters[rand() % strlen(characters)];  // Random character
        border_coordinates.push_back(std::make_tuple(0, y, ch));  // Left border
        border_coordinates.push_back(std::make_tuple(panel_width - 1, y, ch));  // Right border
    }
    for (int x = 1; x < panel_width - 1; ++x) {
        char ch = characters[rand() % strlen(characters)];  // Random character
        border_coordinates.push_back(std::make_tuple(x, 0, ch));  // Top border
        border_coordinates.push_back(std::make_tuple(x, panel_height - 1, ch));  // Bottom border
    }

   
            // Clear the window to erase old characters
        clear_panel(panel);

        // Restore the saved content state
        for (const auto& coord : content_state) {
            int x = std::get<0>(coord);
            int y = std::get<1>(coord);
            char ch = std::get<2>(coord);
            mvwaddch(win, y, x, ch);
        }

        // Refresh to show the restored content
        wrefresh(win);
keypad(win, TRUE);
    nodelay(win, TRUE);
        // Draw the border characters with delay
        for (const auto& coord : border_coordinates) {
                        int x = std::get<0>(coord);
            int y = std::get<1>(coord);
            char ch = std::get<2>(coord);
            mvwaddch(win, y, x, ch);
            wrefresh(win);  // Refresh to show the character
            usleep(delay);  // Delay before drawing the next character
                    }   
  

      }













void draw_falling_objects(PANEL *falling_panel, int panel_height, int panel_width) {
    const char characters[] = "01";
    srand(time(nullptr));
    int num_columns = panel_width-1 ;  // Number of columns to display characters in
    int delay = 60000;  // Delay between updates (in microseconds)
    std::vector<std::tuple<int, int, char>> all_coordinates;

    // Initialize all_coordinates with characters for each column
    for (int x = 1; x < num_columns; ++x) {
        for (int y = 0; y < panel_height-1 ; ++y) {
            char ch = characters[rand() % strlen(characters)];  // Random character
            all_coordinates.push_back(std::make_tuple(x, y, ch));
        }
    }

    // Loop to update characters in each column simultaneously
    while (!all_coordinates.empty()) {
        std::vector<std::tuple<int, int, char>> new_coordinates;

        for (const auto &coord : all_coordinates) {
            int x = std::get<0>(coord);
            int y = std::get<1>(coord);
            char ch = std::get<2>(coord);

            // Move the character down one row
            int new_y = y + 1;

            // If the character reached the bottom, skip it
            if (new_y >= panel_height - 1) {
                continue;
            }

            // Add the new coordinate to the new_coordinates vector
            new_coordinates.push_back(std::make_tuple(x, new_y, ch));

            // Draw the character at the new position
            mvwaddch(panel_window(falling_panel), new_y, x, ch);
             // Delay to control falling speed

        }
 wrefresh(panel_window(falling_panel));  // Refresh to show the characters
        usleep(delay); 
       
        // Replace all_coordinates with new_coordinates for the next iteration
        all_coordinates = std::move(new_coordinates);
    }

    clear_panel(falling_panel);  // Clear the panel after falling objects are displayed
}


int main() {
    main_load(students_list,teachers_list); //global vars
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
   
    noecho();
    curs_set(0);  // Hide the cursor
    start_color(); // Initialize color support
    init_pair(1, COLOR_WHITE, COLOR_BLACK); 
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5,  COLOR_BLUE, COLOR_BLACK);
    init_pair(6,  COLOR_RED, COLOR_BLACK);
       int height, width;
    getmaxyx(stdscr, height, width);  // Get the size of the terminal

    // Create the main window
    WINDOW *win1 = newwin(height, width * (1 - 0.1), 0, width * 0.1);
    box(win1, 0, 0);
    double width_win1=  width * (1 - 0.1);
    double height_win1=height;
    WINDOW *win3 = newwin(height, width * 0.1, 0, 0);
    box(win3, 0, 0);
    int win3_height = height;

    // Calculate vertical spacing between tabs
    int num_tabs = 5;
    int tab_height = height / num_tabs;

    // Print tabs
    std::vector<std::string> tab_labels = {"STUDENTS", "TEACHERS", "PREDICTIONS", "STATISTICS","INPUTS"};
    for (int i = 0; i < num_tabs; ++i) {
        mvwprintw(win3, i * tab_height + tab_height / 2, 1, "%s", tab_labels[i].c_str());
    }

    // Create panels for the windows
    PANEL *pan1 = new_panel(win1);
    PANEL *pan3 = new_panel(win3);
    update_panels();

    // Refresh the screen to show initial setup
    doupdate();

    const wchar_t *lines[] = {
        L"             ███████╗    ███╗   ██╗   ███████╗   ██╗      █████╗",
        L"             ██╔════╝    ████╗  ██║   ██╔════╝   ██║     ██╔══██╗",
        L"             █████╗      ██╔██╗ ██║   ███████╗   ██║     ███████║",
        L"             ██╔══╝      ██║╚██╗██║   ╚════██║   ██║     ██╔══██║",
        L"             ███████╗    ██║ ╚████║   ███████║   ██║     ██║  ██║",
        L"             ╚══════╝    ╚═╝  ╚═══╝   ╚══════╝   ╚═╝     ╚═╝  ╚═╝",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                                                 ",
        L"                                version 0.0.0.1                     ",
        L"       H:help  I:insert_file  Q:quit  S:students  T:teachers  A:stat  P:proba     ",
    };
 int num_lines = sizeof(lines) / sizeof(lines[0]);
for (int i = 0,j=12; i < num_lines; ++i,++j) {
        mvwprintw(win1, j, 18, "%ls", lines[i]);
    }    wrefresh(win1);
    // Example of printing and updating text in win1
  /*  std::string text = "Allah is the greatest and he will remain so ";
    for (int y = 3; y <= 4; ++y) {
        int x = 1;
        // Start position for the text
        for (char c : text) {
            mvwaddch(win1, y, x, c);
            wrefresh(win1);
            x++;
            usleep(60000); // Delay for 60 milliseconds (adjust as needed)
        }
        text = "Oh Allah forgive me";
        wrefresh(win1);
    }
*/

    //help window
    // Wait for user input
    WINDOW *help_win = newwin(height, width , 0, 0);
    box(help_win,0,0);
    PANEL * help_pan=new_panel(help_win);

    WINDOW *input_win = newwin(height, width , 0, 0);
    box(input_win,0,0);
    PANEL * input_pan=new_panel(input_win);
    wbkgd(input_win, COLOR_PAIR(2));
    wattron(input_win, COLOR_PAIR(2));
     
    //loading window

    int box_height_loading = 30;  
    int box_width_loading = 60;
    int win_y_load = (height - box_height_loading) / 2;
    int win_x_load = (width - box_width_loading) / 2;
    WINDOW *loading_win = newwin(box_height_loading, box_width_loading, win_y_load, win_x_load);
    PANEL * loading_pan=new_panel(loading_win);

    box(loading_win,0,0);
    wbkgd(loading_win, COLOR_PAIR(3));
    wattron(loading_win, COLOR_PAIR(3));
 
    //students window
    WINDOW *stud_win = newwin(height, width , 0, 0);
        PANEL * stud_pan=new_panel(stud_win);
    wbkgd(stud_win, COLOR_PAIR(4));
    wattron(stud_win, COLOR_PAIR(4));
    
    //teachers window
     WINDOW *tea_win = newwin(height, width , 0, 0);
    box(tea_win,0,0);
    PANEL * tea_pan=new_panel(tea_win);
    wbkgd(tea_win, COLOR_PAIR(3));
    wattron(tea_win, COLOR_PAIR(3));
    
    // stat window
    WINDOW *stat_win = newwin(height, width , 0, 0);
    box(stat_win,0,0);
    PANEL * stat_pan=new_panel(stat_win);
    wbkgd(stat_win, COLOR_PAIR(5));
    wattron(stat_win, COLOR_PAIR(5));

    //proba window
    WINDOW *proba_win = newwin(height, width , 0, 0);
    wbkgd(proba_win, COLOR_PAIR(6));
    wattron(proba_win, COLOR_PAIR(6));

    box(proba_win,0,0);
    PANEL * proba_pan=new_panel(proba_win);
    



/*
    int ch;
    while ((ch = getch()) != 'q') { // Wait until user inputs 'q' to quit
        if (ch == 'h'  || ch== 'H') {
             top_panel(help_pan); // Switch to panel 2 if 'H' is pressed
            update_panels();
            doupdate();
            while ((ch = getch()) != 'q'  || ch== 'Q'){
            //#include "help_pan.hpp"
             if (ch == 'r' || ch== 'R') {
            top_panel(pan1); // Switch to panel 1
            top_panel(pan3);
            update_panels();
            doupdate();
           // #include "help_pan.hpp"
        }}
        }
         if ((ch= getch()) == 'I' || ch== 'i') { 
         if (ch == 'f' || ch== 'F'){
         top_panel(input_pan); // Switch to panel 2 if 'H' is pressed
            update_panels();
            doupdate();

          main_to_get_file_path();


         if (ch ==  'r'  || ch== 'R') {
            top_panel(pan1); // Switch to panel 1
            top_panel(pan3);
            update_panels();
            doupdate();
           // #include "help_pan.hpp"
        }
      }

    } 
    } */
    int current_panel=0;  // 0 for pan1, 1 for help_pan, 2 for input_pan
     int ch;
    while ((ch = wgetch(win1)) != 'q' && ch != 'Q') {
        #include "handle_input.cpp"// handle_input( ch, current_panel , help_pan, input_pan,input_win,lines2,num_lines2,height,width, pan1,pan3);
    }




top_panel(loading_pan); 
                update_panels();
                doupdate();
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("THANKS FOR USING OUR PROGRAN")) / 2, "THANKS FOR USING OUR PROGRAN");
                 mvwprintw(loading_win, box_height_loading / 2+2, (box_width_loading - strlen("ALL THANKS IS DUE TO ALLAH SWT")) / 2, "ALL THANKS IS DUE TO ALLAH SWT");
                    wrefresh(loading_win); 
                usleep(2000000);
               clear_panel(loading_pan);

   // Clean up
    del_panel(pan3);
    del_panel(pan1);
    del_panel(input_pan);
    del_panel(help_pan);
    del_panel(stud_pan);
    del_panel(tea_pan);
    del_panel(stat_pan);
    del_panel(proba_pan);
    delwin(win3);
    delwin(win1);
    delwin(input_win);
    delwin(help_win);
    delwin(stud_win);
    delwin(tea_win);
    delwin(stat_win);
    delwin(proba_win);
    endwin();

    return 0;
}
