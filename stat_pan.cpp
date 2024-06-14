

const wchar_t *lines2[]={
        L"                                   ██████╗ ████████╗ █████╗  ███████╗ ",
        L"                                  ██╔════╝ ╚══██╔══╝██╔══██╗ ╚══██╔═╝ ",
        L"                                  ███████╗    ██║   ███████║    ██║ ",
        L"                                  ╚════██║    ██║   ██╔══██║    ██║ ",
        L"                                  ███████║    ██║   ██║  ██║    ██║ ",
        L"                                  ╚══════╝    ╚═╝   ╚═╝  ╚═╝    ╚═╝ ",
        L"                                    ",
        L"                                    ",
        L"                                    ",
        L"                                    ",
        L"     Statistical Parameters of the marks of a specefic module :                  ",
        L"  1.Mean of midterm                                             9.Mean of final exams ",
        L"  2.variance of midterm                                         a.variance of final exams ",
        L"  3.standart deviation of midterm                               b.standart deviation of final exams",
        L"  4.coeficient of variance of midterm                           c.coeficient of variance of final exams ",
        L"  5.Mode (most frequent mark) of midterm                        d.Mode (most frequent mark) of final exams ",
        L"  6.Heightest mark and lowest one of midterm                    e.Heightest mark and lowest one of final exams",
        L"  7.coeficient of correlation (marks,years)  of midterm         f.coeficient of correlation (marks,years)  of final exams ",
        L"  8.scatter plot of students marks in term of years of midterm  0.scatter plot of students marks in term of years of final exams",
        L"                             ",
        L"  NOTE:For probability Statistical parameters go to probability tab in the home                                  ",
                L"                                    ",
        L"                                    ",
        L"                                 Q:quit      R:return     Press_char_before_info_to_display_it                          ",

 
};

   
    const int num_lines2 = sizeof(lines2) / sizeof(lines2[0]);


                
                 draw_falling_objects(stat_pan,height,width );
                werase(stat_win); // Clear the input panel's window
                 box(stat_win, 0, 0); // Draw the box around the input panel's window
    // Add any additional code to draw the text or other contents of the input panel
                wrefresh(stat_win);
          for (int i = 0,j=4; i < num_lines2; ++i,++j) {
            mvwprintw(stat_win, j, 4, "%ls", lines2[i]);
    }        wrefresh(stat_win);
     
        int ch_input = 0;
    while (ch_input != 'q' && ch_input != 'Q' && ch_input != 'r' && ch_input != 'R' ) {
        ch_input = wgetch(stat_win); // Get input from the input panel window
        switch (ch_input) {
            case 'Q':
            case 'q':{
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
                exit(0);}

            case 'R':
            case 'r':{
                show_panel(pan1);
                show_panel(pan3);
                hide_panel(stat_pan);
                hide_panel(help_pan);
                update_panels();
                doupdate();
                current_panel = 0;}
                break; // Exit the loop

            case '1':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);


// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}

map<string, double>*stats= calculate_statistical_parameters(students_list,"English") ;

double mean=(*stats)["mean_midterm"];
//double mean=students_list["malak_felioune"].marks["English"].exams[0]->mark;

    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("mean is :")) / 2;
    //mvwprintw(loading_win, done_message_y, done_message_x, "mean is : %.2f", mean);
    mvwprintw(loading_win, done_message_y, done_message_x, "mean is : %.3f", mean);
    wrefresh(loading_win); 
usleep(1000000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            } break;

       case '2':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}
map<string, double>*stats= calculate_statistical_parameters(students_list,  module_name) ;
double var=(*stats)["variance_midterm"];
    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("variance is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "variance is : %.2f", var);
    wrefresh(loading_win);
usleep(1000000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;
      case '3':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}
map<string, double>*stats= calculate_statistical_parameters(students_list,  module_name) ;
double d=(*stats)["std_deviation_midterm"];
 // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("standart deviation is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "standard deviation is : %.2f", d);
    wrefresh(loading_win);
usleep(1000000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;

    case '4':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}
map<string, double>*stats= calculate_statistical_parameters(students_list,  module_name) ;
double c=(*stats)["cvx_midterm"];
   // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("coef of variance is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "coef of variance is : %.2f", c);
    wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;

    case '9':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}
map<string, double>* stats =calculate_final_statistical_parameters(students_list,  module_name);

double m=(*stats)["mean_final"];
 // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("mean is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "mean is : %.2f", m);
    wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;
     

    case 'a':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}
map<string, double>* stats= calculate_final_statistical_parameters(students_list,  module_name);

double v=(*stats)["variance_final"];
    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("variance is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "variance is : %.2f", v);
    wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;
      


    case 'b':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}
map<string, double>* stats =calculate_final_statistical_parameters(students_list,  module_name);

double d=(*stats)["std_deviation_final"];
    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("standard deviation is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "standard deviation : %.2f", d);
    wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;

     case 'c':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}
map<string, double>* stats =calculate_final_statistical_parameters(students_list,  module_name);

double c=(*stats)["cvx_final"];
    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("coef of variance is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "coef of variance : %.2f", c);
    wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;

    case '5':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}

map<string, double> stats =calculate_midterm_statistics(students_list, module_name);
double m=stats["mode_midterm"];
    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("mode is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "mode : %.2f", m);
    wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;

      case 'd':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}

map<string, double> stats =calculate_final_exam_statistics(students_list, module_name);
double m=stats["mode_final"];
  // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("mode is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "mode : %.2f", m);
    wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;
    case 'e':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}

map<string, double> stats =calculate_final_exam_statistics(students_list, module_name);
double min=stats["min_final"];
double max=stats["max_final"];

    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("min is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "min is : %.2f", min);
     mvwprintw(loading_win, done_message_y+1, done_message_x, "max is : %.2f", max);
    wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;

    case '6':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}

map<string, double> stats =calculate_midterm_statistics(students_list, module_name);
double min=stats["min_midterm"];
double max=stats["max_midterm"];
    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("min is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "min is : %.2f", min);
     mvwprintw(loading_win, done_message_y+1, done_message_x, "max is : %.2f", max);
    wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;


    case '7':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}
                    
double c=calculate_correlation_coefficient(students_list,
                                        students_list_next_year,
                                         students_list_next_next_year,
                                         module_name);


    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("coef of correlation is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "coef of correlation is : %.2f", c);
       wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;


     case 'f':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);

            
// Print "LOADING" text in the center
mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");

// Print loading bar
const char* lines33 = "[====================================]";
int loading_bar_y = box_height_loading / 2 + 2;
int loading_bar_x = (box_width_loading - strlen(lines33)) / 2;
for (int y = loading_bar_y; y < loading_bar_y + 1; ++y) {
    int x = loading_bar_x;
    for (const char* c = lines33; *c != '\0'; ++c) {
        mvwaddch(loading_win, y, x, *c);
        wrefresh(loading_win);
        x++;
        usleep(60000); // Delay for 60 milliseconds 
    }
}
                    
double c=calculate_correlation_final_coefficient(students_list,
                                        students_list_next_year,
                                         students_list_next_next_year,
                                         module_name);


    // Display mean value
    int done_message_y = loading_bar_y + 2;
    int done_message_x = (box_width_loading - strlen("coef of correlation is :")) / 2;
    mvwprintw(loading_win, done_message_y, done_message_x, "coef of correlation is : %.2f", c);
       wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;


     case '0':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);
clear_panel(loading_pan);
            box(loading_win,0,0);
draw_final_exam_scatter_plot(loading_win,
                                  students_list,
                                   students_list_next_year,
                                  students_list_next_next_year,
                                  module_name,
                                  box_width_loading,
                                  box_height_loading);
                usleep(5000000);

// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;

     case '8':
                
                {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("STAT_WINDOW")) / 2, "STAT_WINDOW");
                wrefresh(loading_win);


mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);
clear_panel(loading_pan);
box(loading_win,0,0);
draw_midterm_scatter_plot(loading_win,
                               students_list,
                               students_list_next_year,
                               students_list_next_next_year,
                               module_name,
                               box_width_loading,
                               box_height_loading);
                usleep(5000000);
              /*  vector<double> final_exam_marks;
    vector<double> years;

    collect_final_exam_data(students_list, module_name, final_exam_marks, years, 1);
    collect_final_exam_data(students_list_next_year, module_name, final_exam_marks, years, 2);
    collect_final_exam_data(students_list_next_next_year, module_name, final_exam_marks, years, 3);

    if (final_exam_marks.empty() || years.empty()) {
        mvwprintw(loading_win, box_height_loading / 2, box_width_loading / 2 - 10, "No data to display");
        wrefresh(plot_win);
        return;
    }

    // Determine scaling factors
    double max_mark = *max_element(final_exam_marks.begin(), final_exam_marks.end());
    double min_mark = *min_element(final_exam_marks.begin(), final_exam_marks.end());
    int max_year = 3; // Assuming we have data for 3 years

    // Draw x-axis and y-axis
    for (int x = 1; x < box_width_loading - 1; ++x) {
        mvwaddch(loading_win, box_height_loading - 3, x, '-'); // x-axis
    }
    for (int y = 1; y < box_height_loading - 2; ++y) {
        mvwaddch(loading_win, y, 0, '|'); // y-axis
    }

    // Label axes
    mvwprintw(loading_win, box_height_loading - 2, box_width_loading / 2 - 4, "Marks");
    mvwprintw(loading_win, 0, box_width_loading / 2 - 3, "Years");

    // Plot data points
    for (size_t i = 0; i < final_exam_marks.size(); ++i) {
        int x = static_cast<int>((years[i] - 1) / static_cast<double>(max_year - 1) * (plot_width - 2)) + 1;
        int y = plot_height - 3 - static_cast<int>((final_exam_marks[i] - min_mark) / (max_mark - min_mark) * (plot_height - 4));
        mvwaddch(plot_win, y, x, '*');
    }

    wrefresh(loading_win);*/

// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              

            }break;




    }
   }


