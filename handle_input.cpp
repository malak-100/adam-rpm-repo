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
        
        break;}

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
