
const wchar_t *lines2[]={
        L"                             ██████╗   ██████╗   ██████╗    ██████╗    █████╗    ",
        L"                             ██╔══██╗  ██╔══██╗ ██╔═══██╗   ██╔══██╗  ██╔══██╗     ",
        L"                             ██████╔╝  ██████╔╝ ██║   ██║   ██████╔╝  ███████║    ",
        L"                             ██╔═══╝   ██╔══██╗ ██║   ██║   ██╔══██╗  ██╔══██║  ",
        L"                             ██║       ██║  ██║ ╚██████╔╝   ██████╔╝  ██║  ██║     ",
        L"                             ╚═╝       ╚═╝  ╚═╝  ╚═════╝    ╚═════╝   ╚═╝  ╚═╝",
        L"                                                                        ",
        L"                                                                        ",
        L"                                                                        ",
        L"                                                                        ",
        L"                                                                        ",
        L"   1.What is the percentage of seccess of the students in a specefic module next x year                                                                     ",
        L"   2.What is the percentages of performance in each module this year and the next x year                                                                  ",
        L"   3.What is the percentage of the failure of the students in a specefic module next x year                                                                     ",
        L"   4.What is the heightest score that the students will probably get it next year                                                                    ",
        L"   5.What is the percentage of the Interest for a specific module by the students                                                                     ",
        L"   6.What is the module that the x student have to focus on in his free time                                                                     ",
        L"   7.What is the module that the administration need to help in emergency with it                                                                     ",
        L"                                                                        ",
        L"                                                                        ",
        L"                                                                        ",
        L"                                                                        ",
        L"                                                                        ",
        L"                                 Q:quit      R:return     Press_char_before_info_to_display_it                          ",
};  
    const int num_lines2 = sizeof(lines2) / sizeof(lines2[0]);


                show_panel(proba_pan);
                hide_panel(pan1);
                hide_panel(pan3);
                hide_panel(help_pan);
                update_panels();
                doupdate();
                current_panel = 2;
                 draw_falling_objects(proba_pan,height,width );
                werase(proba_win); // Clear the input panel's window
                 box(proba_win, 0, 0); // Draw the box around the input panel's window
    // Add any additional code to draw the text or other contents of the input panel
                wrefresh(proba_win);
          for (int i = 0,j=5; i < num_lines2; ++i,++j) {
            mvwprintw(proba_win, j, 4, "%ls", lines2[i]);
    }        wrefresh(proba_win);
     
        int ch_input = 0;
    while (ch_input != 'q' && ch_input != 'Q' && ch_input != 'r' && ch_input != 'R' ) {
        ch_input = wgetch(proba_win); // Get input from the input panel window
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
                hide_panel(proba_pan);
                hide_panel(help_pan);
                update_panels();
                doupdate();
                current_panel = 0;
                break; // Exit the loop

            case '1':
            
      {
                
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("PROBA")) / 2, "PROBA");
                 wrefresh(loading_win);
        mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);
        mvwprintw(loading_win, 4, 2, "Enter number of years: ");
    wrefresh(loading_win);
    string num = get_input(loading_win, 5, 2);
        clear_panel(loading_pan);
        box(loading_win, 0, 0);
        print_success_percentage(loading_win,module_name, stoi(num), 5, 2,
                               students_list_next_next_year,
                              students_list_next_year,
                              students_list);
        //mvwprintw(loading_win, 4, 2, "Enter this is %.2f ",students_list_next_year["malak_felioune"].get_midterm_mark("English"));
               usleep(5000000); 
    



clear_panel(loading_pan);
    hide_panel(loading_pan);

      } break;

          case '2':
                {
                
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("PROBA")) / 2, "PROBA");
                 wrefresh(loading_win);
        mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);
        mvwprintw(loading_win, 4, 2, "Enter number of years: ");
    wrefresh(loading_win);
    string num = get_input(loading_win, 5, 2);
        clear_panel(loading_pan);
        box(loading_win, 0, 0);
        print_success_percentage2(loading_win,module_name, stoi(num), 5, 2,
                               students_list_next_next_year,
                              students_list_next_year,
                              students_list);
        //mvwprintw(loading_win, 4, 2, "Enter this is %.2f ",students_list_next_year["malak_felioune"].get_midterm_mark("English"));
               usleep(5000000); 
    



    clear_panel(loading_pan);
    hide_panel(loading_pan);

      } break;

           case '3':
                {
                
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("PROBA")) / 2, "PROBA");
                 wrefresh(loading_win);
        mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);
        mvwprintw(loading_win, 4, 2, "Enter number of years: ");
    wrefresh(loading_win);
    string num = get_input(loading_win, 5, 2);
        clear_panel(loading_pan);
        box(loading_win, 0, 0);
        print_success_percentage3(loading_win,module_name, stoi(num), 5, 2,
                               students_list_next_next_year,
                              students_list_next_year,
                              students_list);
        //mvwprintw(loading_win, 4, 2, "Enter this is %.2f ",students_list_next_year["malak_felioune"].get_midterm_mark("English"));
               usleep(5000000); 
    



    clear_panel(loading_pan);
    hide_panel(loading_pan);

      } break;


            case '4':
                {
                
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("PROBA")) / 2, "PROBA");
                 wrefresh(loading_win);
        mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);
        
        clear_panel(loading_pan);
        box(loading_win, 0, 0);
        print_success_percentage4(loading_win,module_name, 0, 5, 2,
                               students_list_next_next_year,
                              students_list_next_year,
                              students_list);
        //mvwprintw(loading_win, 4, 2, "Enter this is %.2f ",students_list_next_year["malak_felioune"].get_midterm_mark("English"));
               usleep(5000000); 
    



    clear_panel(loading_pan);
    hide_panel(loading_pan);

      } break;
       case '5':
                {
                
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("PROBA")) / 2, "PROBA");
                 wrefresh(loading_win);
        mvwprintw(loading_win, 2, 2, "enter module name: ");
    wrefresh(loading_win);
    string module_name = get_input(loading_win, 3, 2);
        
        clear_panel(loading_pan);
        box(loading_win, 0, 0);
        print_success_percentage5(loading_win,module_name, 0, 5, 2,
                               students_list_next_next_year,
                              students_list_next_year,
                              students_list);
        //mvwprintw(loading_win, 4, 2, "Enter this is %.2f ",students_list_next_year["malak_felioune"].get_midterm_mark("English"));
               usleep(5000000); 
    



    clear_panel(loading_pan);
    hide_panel(loading_pan);

      } break;
       case '6':
                {
                
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("PROBA")) / 2, "PROBA");
                 wrefresh(loading_win);
                mvwprintw(loading_win, 4, 2, "Enter Student name (current year)(firstn_lastn): ");
    wrefresh(loading_win);
    string stud = get_input(loading_win, 5, 2);
        clear_panel(loading_pan);
        box(loading_win, 0, 0);
    

    std::string least_interested_module = less_interested_module(students_list[stud]);

// Print the least interested module (assuming within a function or loop)
mvwprintw(loading_win, 4, 2, "The module is: %s", least_interested_module.c_str());


     // mvwprintw(loading_win, 4, 2, "The module is : %s",module_to_focus_on(students_list[stud]).c_str());
     wrefresh(loading_win);   //mvwprintw(loading_win, 4, 2, "Enter this is %.2f ",students_list_next_year["malak_felioune"].get_midterm_mark("English"));
               usleep(5000000); 
    



    clear_panel(loading_pan);
    hide_panel(loading_pan);

      } break;

      case '7':
                {
                
                top_panel(loading_pan); 
                update_panels();
                doupdate();
                 box(loading_win, 0, 0);
                 mvwprintw(loading_win, box_height_loading / 2, (box_width_loading - strlen("PROBA")) / 2, "PROBA");
                                clear_panel(loading_pan);
        box(loading_win, 0, 0);
     vector<Student> vec ;
     for(auto elem : students_list){vec.push_back(elem.second);}

     mvwprintw(loading_win, 4, 2, "The module is: %s",findMostNeededHelpModule(vec).c_str()); 
     wrefresh(loading_win);   //mvwprintw(loading_win, 4, 2, "Enter this is %.2f ",students_list_next_year["malak_felioune"].get_midterm_mark("English"));
               usleep(5000000); 
    



    clear_panel(loading_pan);
    hide_panel(loading_pan);

      } break;




    }
   }


