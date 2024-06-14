    switch (ch) {
    // HELP
    case 'h':
    case 'H':
        if (current_panel != 1) {
            show_panel(help_pan);
            hide_panel(pan1);
            hide_panel(pan3);
            hide_panel(input_pan);
            hide_panel(stud_pan);
            hide_panel(tea_pan);
            hide_panel(stat_pan);
            hide_panel(proba_pan);
            update_panels();
            doupdate();
            current_panel = 1;
            box(help_win, 0, 0);
             mvwprintw(help_win, 10, 2, "visit Readme section on GitHub : https://github.com/malak-100/adam-rpm-repo  because imad did not finish man page");
                 mvwprintw(help_win, 12, 2, "Press R:return Q:quit ");
                   wrefresh(help_win);
        int ch_input = 0;
    while (ch_input != 'q' && ch_input != 'Q' && ch_input != 'r' && ch_input != 'R' ) {
        ch_input = wgetch(help_win); // Get input from the input panel window
        switch (ch_input) {
            case 'Q':
            case 'q':
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

            case 'R':
            case 'r':
                show_panel(pan1);
                show_panel(pan3);
                hide_panel(input_pan);
                hide_panel(help_pan);
                update_panels();
                doupdate();
                current_panel = 0;
                break; // Exit the loop
        
        }}
        }
        
        break;

    // INPUT
    case 'i':
    case 'I':
        if (current_panel == 0) { // Only allow switch to input from home panel
            #include "input_pan.cpp" 
            }
        
        break;

    // STUDENT
    case 'S':
    case 's':
        if (current_panel == 0) {
            show_panel(stud_pan);
            hide_panel(pan1);
            hide_panel(pan3);
            hide_panel(help_pan);
            hide_panel(input_pan);
            hide_panel(tea_pan);
            hide_panel(stat_pan);
            hide_panel(proba_pan);
            update_panels();
            doupdate();
            current_panel = 3;
         #include "stud_pan.cpp"  
            }
        break;

    // TEACHER
    case 'T':
    case 't':
        if (current_panel == 0) {
            show_panel(tea_pan);
            hide_panel(pan1);
            hide_panel(pan3);
            hide_panel(help_pan);
            hide_panel(input_pan);
            hide_panel(stud_pan);
            hide_panel(stat_pan);
            hide_panel(proba_pan);
            update_panels();
            doupdate();
            current_panel = 4;
            #include "tea_pan.cpp"
        }
        break;

    // STATISTICS
    case 'A':
    case 'a':
        if (current_panel == 0) {
            show_panel(stat_pan);
            hide_panel(pan1);
            hide_panel(pan3);
            hide_panel(help_pan);
            hide_panel(input_pan);
            hide_panel(stud_pan);
            hide_panel(tea_pan);
            hide_panel(proba_pan);
            update_panels();
            doupdate();
            current_panel = 5;
            #include "stat_pan.cpp"
        }
        break;

    // PROBABILITY
    case 'p':
    case 'P':
        if (current_panel == 0) {
            show_panel(proba_pan);
            hide_panel(pan1);
            hide_panel(pan3);
            hide_panel(help_pan);
            hide_panel(input_pan);
            hide_panel(stud_pan);
            hide_panel(tea_pan);
            hide_panel(stat_pan);
            update_panels();
            doupdate();
            current_panel = 6;
            #include "proba_pan.cpp"
        }
        break;

    // RETURN
    case 'r':
    case 'R':
        if (current_panel != 0) {
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
        }
        break;

    // EXIT
    case 'q':
    case 'Q':
        current_panel = -1; // Indicate exit condition to main loop
        break;
}
