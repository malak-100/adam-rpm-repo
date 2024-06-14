
   
// Uncommented code that should display text in win1
const wchar_t *lines2[] = {
        L"██╗  ███╗   ██╗██████╗ ██╗   ██╗████████╗                ",
        L"██║  ████╗  ██║██╔══██╗██║   ██║╚══██╔══╝   Insert file by pressing F ",
        L"██║  ██╔██╗ ██║██████╔╝██║   ██║   ██║      Files should be in the formal ASCII",
        L"██║  ██║╚██╗██║██╔═══╝ ██║   ██║   ██║      Infos in the file have the format",
        L"██║  ██║ ╚████║██║     ╚██████╔╝   ██║      FirstName LastName Email ID ",
        L"╚═╝  ╚═╝  ╚═══╝╚═╝      ╚═════╝    ╚═╝      Note that the delimiter btw Infos can be from thsi chars :",
        L"                                          -|-           ",
        L"Consider checking the manual page or the help page in the home",
        L"Check that you cloned the repository of that program in the user home",
        L"If you are not in fedora WSL you have to go to the Before_running.txt on github",
        L"We recommand installing fedora WSL for the smooth and the ease of use ",
        L"Do not manipulate any files from the txt files that have been installed ",
        L"To add Students,Courses,Exams,Teachers you can do that by pressing the chars",
        L"Do not forget that you can insert everything manually one by one in its tab",
        L"                                       ",
        L"                                       ",
        L"                                       ",
        L"                                       ",
        L"                                       ",
        L"                                       ",
        L"                                       ",
        L"                                       ",
        L"                                       ",
        L"        Q:quit D:delete_data_file  R:return  S:students_txt_file T:teachers_txt_file C:cours_exams_mark      ",
    };

   
    const int num_lines2 = sizeof(lines2) / sizeof(lines2[0]);


                show_panel(input_pan);
                hide_panel(pan1);
                hide_panel(pan3);
                hide_panel(help_pan);
                update_panels();
                doupdate();
                current_panel = 2;
                 draw_falling_objects(input_pan,height,width );
                werase(input_win); // Clear the input panel's window
                 box(input_win, 0, 0); // Draw the box around the input panel's window
    // Add any additional code to draw the text or other contents of the input panel
                wrefresh(input_win);
          for (int i = 0,j=8; i < num_lines2; ++i,++j) {
            mvwprintw(input_win, j, 4, "%ls", lines2[i]);
    }        wrefresh(input_win);
     
        int ch_input = 0;
    while (ch_input != 'q' && ch_input != 'Q' && ch_input != 'r' && ch_input != 'R' ) {
        ch_input = wgetch(input_win); // Get input from the input panel window
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

            case 'S':
            case 's':
                
                if(main_students_files() ==0){ 
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");
                 wrefresh(loading_win);
// Print loading bar
const char* lines33 = "[...............^_^.................]";
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

// Print message below the loading bar
int done_message_y = loading_bar_y + 2;
int done_message_x = (box_width_loading - strlen("Students file loaded successfully!")) / 2;
mvwprintw(loading_win, done_message_y, done_message_x, "Sudents file loaded successfully!");
wrefresh(loading_win);
usleep(600000);

clear_panel(loading_pan);
    hide_panel(loading_pan);

              }
                else {
        top_panel(loading_pan); 
                update_panels();
                doupdate();
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("Something went wrong when loading file")) / 2, "Something went wrong when loading file");
                 mvwprintw(loading_win, box_height_loading / 2+2, (box_width_loading - strlen("check the instructions or try again")) / 2, "check the instructions or try again");
        hide_panel(loading_pan);
      }
                break;

            case 'T':
            case 't':
                if(main_teachers_files() ==0){ 
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("LOADING")) / 2, "LOADING");
                 wrefresh(loading_win);
// Print loading bar
const char* lines33 = "[...............(^-^)...............]";
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

// Print message below the loading bar
int done_message_y = loading_bar_y + 2;
int done_message_x = (box_width_loading - strlen("teachers file loaded successfully!")) / 2;
mvwprintw(loading_win, done_message_y, done_message_x, "teachers file loaded successfully!");
wrefresh(loading_win);
usleep(600000);

clear_panel(loading_pan);
    hide_panel(loading_pan);

              } 
                else {
        top_panel(loading_pan); 
                update_panels();
                doupdate();
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("Something went wrong when loading file")) / 2, "Something went wrong when loading file");
                 mvwprintw(loading_win, box_height_loading / 2+2, (box_width_loading - strlen("check the instructions or try again")) / 2, "check the instructions or try again");
        hide_panel(loading_pan);
      }

                break;

            case 'C':
            case 'c':
   {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("exams_insertion")) / 2, "exams_insertion");
                wrefresh(loading_win);

// Print choices
int choice_y = 2;
mvwprintw(loading_win, choice_y, 2, "1: Insert exams marks of this year");
mvwprintw(loading_win, choice_y + 1, 2, "2: Insert exams marks the previous year");
mvwprintw(loading_win, choice_y + 2, 2, "3: Insert exams marks the previous year");

wrefresh(loading_win);
        // Wait for user input
int choice;
do {
    choice = wgetch(loading_win);
} while (choice < '1' || choice > '3');

if(choice=='1'){if(main_exams_files() ==0){ 
                
              }
                else {
        top_panel(loading_pan); 
                update_panels();
                doupdate();
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("Something went wrong when loading file")) / 2, "Something went wrong when loading file");
                 mvwprintw(loading_win, box_height_loading / 2+2, (box_width_loading - strlen("check the instructions or try again")) / 2, "check the instructions or try again");
        hide_panel(loading_pan);clear_panel(loading_pan);break;
      }
                }
if(choice=='2'){if(main_exams_next_files() ==0){ 
                
              }
                else {
        top_panel(loading_pan); 
                update_panels();
                doupdate();
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("Something went wrong when loading file")) / 2, "Something went wrong when loading file");
                 mvwprintw(loading_win, box_height_loading / 2+2, (box_width_loading - strlen("check the instructions or try again")) / 2, "check the instructions or try again");
        hide_panel(loading_pan);clear_panel(loading_pan);break;
      }
                }
if(choice=='3'){if(main_exams_next_next_files() ==0){ 
                
              }
                else {
        top_panel(loading_pan); 
                update_panels();
                doupdate();
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("Something went wrong when loading file")) / 2, "Something went wrong when loading file");
                 mvwprintw(loading_win, box_height_loading / 2+2, (box_width_loading - strlen("check the instructions or try again")) / 2, "check the instructions or try again");
        hide_panel(loading_pan);clear_panel(loading_pan);break;
      }
                }




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

// Print "Done!" message below the loading bar
int done_message_y = loading_bar_y + 2;
int done_message_x = (box_width_loading - strlen("Done!")) / 2;
mvwprintw(loading_win, done_message_y, done_message_x, "Done!");
wrefresh(loading_win);
usleep(500000);
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              }



                break;
            case 'D':
            case 'd':
              {
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                  // Print title at the top center
                // Print title at the top center
                box(loading_win,0,0);
                mvwprintw(loading_win, 0, (box_width_loading - strlen("DELETION_WINDOW")) / 2, "DELETION_WINDOW");
                wrefresh(loading_win);

// Print choices
int choice_y = 2;
mvwprintw(loading_win, choice_y, 2, "1: Delete all exams data");
mvwprintw(loading_win, choice_y + 1, 2, "2: Delete all students data");
mvwprintw(loading_win, choice_y + 2, 2, "3: Delete all teachers data");
mvwprintw(loading_win, choice_y + 3, 2, "4: Delete all the above");
wrefresh(loading_win);
        // Wait for user input
int choice;
do {
    choice = wgetch(loading_win);
} while (choice < '1' || choice > '4');



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

// Print "Done!" message below the loading bar
int done_message_y = loading_bar_y + 2;
int done_message_x = (box_width_loading - strlen("Done!")) / 2;
mvwprintw(loading_win, done_message_y, done_message_x, "Done!");
wrefresh(loading_win);
usleep(500000);
if(choice=='1'){system("~/exp/tem/panel/bash_script_delete1.sh");}
if(choice=='2'){system("~/exp/tem/panel/bash_script_delete2.sh");}
if(choice=='3'){system("~/exp/tem/panel/bash_script_delete3.sh");}
if(choice=='4'){system("~/exp/tem/panel/bash_script3.sh");}
// Hide the loading panel
hide_panel(loading_pan);
clear_panel(loading_pan);


              }





    }
   }


