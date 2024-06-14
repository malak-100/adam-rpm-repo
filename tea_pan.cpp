 nodelay(tea_win, TRUE);

vector<std::tuple<int, int, char>> tea_state;
int ch_input2 = 0;
int start_index = 0;

    while (ch_input2 != 'q' && ch_input2 != 'Q' && ch_input2 != 'r' && ch_input2 != 'R' ) {
  display_teachers(tea_win, height, width, start_index);
     wrefresh(tea_win);
    save_content_state(tea_win,tea_state,height, width);
    clear_panel(stud_pan);
     draw_objects(tea_pan, tea_win, height,width, tea_state);
    ch_input2=wgetch(tea_win);
switch (ch_input2) {
    // show other students from the list
   case 'M':
case 'm':
    {
        start_index += 1; // Assuming we want to show the next 3 teachers

        // If we've reached the end of the list, wrap around to the beginning
        if (start_index > teachers_list.size()) {
            start_index = 0;
        }
        break;
    }   // add 
    case 'w':
case 'W':
             {top_panel(loading_pan);
    update_panels();
    doupdate();
    // Print title at the top center
    box(loading_win, 0, 0);
    mvwprintw(loading_win, 0, (box_width_loading - strlen("ADD TEACHER")) / 2, "ADD TEACHER");
    wrefresh(loading_win);

    // Call the add_student function
    add_teacher(teachers_list, teachers_file, loading_win);

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
    clear_panel(loading_pan);break;} // TEACHER
        // RETURN
    case 'r':
    case 'R': {
              current_panel = 0;
             clear_panel(tea_pan);
                            werase(tea_win);  // Erase the window to clear any characters
                            wrefresh(tea_win);  // Refresh the window to apply changes
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
