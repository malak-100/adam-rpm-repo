#!/bin/bash

# Install ncurses development libraries
sudo dnf install -y ncurses-devel

# Compile your program
g++ main.cpp -o /usr/share/adam/adam -lncursesw -lpanel

# Install Zenity and other dependencies for Zenity
sudo dnf install -y zenity dbus-x11

# Set executable permissions for bash scripts
chmod +x /usr/share/adam/bash_script.sh
chmod +x /usr/share/adam/bash_script2.sh
chmod +x /usr/share/adam/bash_script3.sh
chmod +x /usr/share/adam/bash_script_delete1.sh
chmod +x /usr/share/adam/bash_script_delete2.sh
chmod +x /usr/share/adam/bash_script_delete3.sh

# Change permissions of data files
chmod +xwr /usr/share/adam/data/exams_datahovuhovi.txt
chmod +xwr /usr/share/adam/data/exams_next_datahovuhovi.txt
chmod +xwr /usr/share/adam/data/exams_next_next_datahovuhovi.txt
chmod +xwr /usr/share/adam/data/students_datahovuhovi.txt
chmod +xwr /usr/share/adam/data/teachers_datahovuhovi.txt
chmod +xwr /usr/share/adam/selected_file.sh



echo "Setup completed successfully! "

