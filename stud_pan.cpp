 nodelay(stud_win, TRUE);

vector<std::tuple<int, int, char>> stud_state;
int ch_input2 = 0;
int start_index = 0;

    while (ch_input2 != 'q' && ch_input2 != 'Q' && ch_input2 != 'r' && ch_input2 != 'R' ) {
  display_students(stud_win, start_index, height, width);
  wrefresh(stud_win);
     save_content_state(stud_win,stud_state,height, width);
    clear_panel(stud_pan);
     draw_objects(stud_pan, stud_win, height,width, stud_state);
    ch_input2=wgetch(stud_win);
switch (ch_input2) {
    // show other students from the list
    case 'M':
case 'm':
    {
        // Increment the start_index to show the next set of students
        start_index += 1;

        // If we've reached the end of the list, wrap around to the beginning
        if (start_index > students_list.size()) {
            start_index = 0;
        }

        // Display the students starting from the new start_index
                break;
    }    // add
    case 'w':
case 'W':
             {top_panel(loading_pan);
    update_panels();
    doupdate();
    // Print title at the top center
    box(loading_win, 0, 0);
    mvwprintw(loading_win, 0, (box_width_loading - strlen("ADD STUDENT")) / 2, "ADD STUDENT");
    wrefresh(loading_win);

    // Call the add_student function
    add_student(students_list, students_file, loading_win);

    // Print "Done!" message
    mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("Done!")) / 2, "Done!");
    wrefresh(loading_win);
    usleep(500000); // Wait for 0.5 seconds

    // Hide the loading panel
    hide_panel(loading_pan);
    clear_panel(loading_pan);
    break;}
    // STUDENT
    case 'L':
    case 'l':
             {top_panel(loading_pan);
    update_panels();
    doupdate();
    // Print title at the top center
    box(loading_win, 0, 0);
    mvwprintw(loading_win, 0, (box_width_loading - strlen("STUDENT INFO")) / 2, "STUDENT INFO");
    wrefresh(loading_win);

    // Get the first name and last name from the user
    mvwprintw(loading_win, 2, 2, "Enter student's first name: ");
    wrefresh(loading_win);
    string first_name = get_input(loading_win, 3, 2);

    mvwprintw(loading_win, 4, 2, "Enter student's last name: ");
    wrefresh(loading_win);
    string last_name = get_input(loading_win, 5, 2);

    string key = first_name + "_" + last_name;

    // Check if the student exists in the map
    auto it = students_list.find(key);
    if (it != students_list.end()) {
        // Print the student's information
        mvwprintw(loading_win, 7, 2, "First Name: %s", it->second.first_name.c_str());
        mvwprintw(loading_win, 8, 2, "Last Name: %s", it->second.last_name.c_str());
        mvwprintw(loading_win, 9, 2, "Email: %s", it->second.email_address.c_str());
        mvwprintw(loading_win, 10, 2, "ID: %s", it->second.id.c_str());

        // Print the student's course marks
        int line = 12;
        mvwprintw(loading_win, line++, 2, "Course Marks:");
        for (const auto& [course_name, course] : it->second.marks) {
            mvwprintw(loading_win, line++, 4, "Course: %s", course_name.c_str());
            mvwprintw(loading_win, line++, 6, "Coefficient: %d", course.coefficient);
            mvwprintw(loading_win, line++, 6, "CC Mark: %.2f", course.cc_mark);
            mvwprintw(loading_win, line++, 6, "Exams:");
            for (const auto& exam : course.exams) {
               mvwprintw(loading_win, line++, 8, "%s %s (Mark: %.2f, Worth: %.2f)", typeid(*exam).name() + 1, exam->name.c_str(), exam->mark, exam->get_worth());            }
            line++;
        }
    } else {
        mvwprintw(loading_win, 7, 2, "Student not found!");
    }

    wrefresh(loading_win);
    usleep(7000000); // Wait for 1 second

    // Hide the loading panel
    hide_panel(loading_pan);
    clear_panel(loading_pan);
    break; } // TEACHER
        // RETURN
    case 'r':
    case 'R': {
              current_panel = 0;
             clear_panel(stud_pan);
                            werase(stud_win);  // Erase the window to clear any characters
                            wrefresh(stud_win);  // Refresh the window to apply changes
                            show_panel(pan1);
                            show_panel(pan3);
                            hide_panel(help_pan);
                            hide_panel(input_pan);
                            hide_panel(stud_pan);
                            hide_panel(tea_pan);
                            hide_panel(stat_pan);
                            hide_panel(proba_pan);
                            update_panels();
                            doupdate();    
      current_panel = 0;
        break;}

    // EXIT
    case 'q':
    case 'Q':
        top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("THANKS FOR USING OUR PROGRAN")) / 2, "THANKS FOR USING OUR PROGRAN");
                 mvwprintw(loading_win, box_height_loading / 2+2, (box_width_loading - strlen("ALL THANKS IS DUE TO ALLAH SWT")) / 2, "ALL THANKS IS DUE TO ALLAH SWT");
                    wrefresh(loading_win); 
                usleep(2000000);
               clear_panel(loading_pan);
                 cleanPW(pan1,pan3,help_pan,input_pan,loading_pan,stud_pan,tea_pan,stat_pan,proba_pan,win1,win3,help_win,input_win,loading_win,stud_win,tea_win,stat_win,proba_win);
                exit(0);
    }
}
