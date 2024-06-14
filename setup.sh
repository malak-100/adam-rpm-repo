#!/bin/bash

# Install ncurses development libraries
sudo dnf install -y ncurses-devel

# Compile your program
g++ main.cpp -o ~/program1/main -lncursesw -lpanel

# Install Zenity and other dependencies for Zenity
sudo dnf install -y zenity dbus-x11

# Set executable permissions for bash scripts
chmod +x ~/program1/bash_script.sh
chmod +x ~/program1/bash_script2.sh
chmod +x ~/program1/bash_script3.sh
chmod +x ~/program1/bash_script_delete1.sh
chmod +x ~/program1/bash_script_delete2.sh
chmod +x ~/program1/bash_script_delete3.sh

# Change permissions of data files
chmod +xwr ~/program1/data/exams_datahovuhovi.txt
chmod +xwr ~/program1/data/exams_next_datahovuhovi.txt
chmod +xwr ~/program1/data/exams_next_next_datahovuhovi.txt
chmod +xwr ~/program1/data/students_datahovuhovi.txt
chmod +xwr ~/program1/data/teachers_datahovuhovi.txt
chmod +xwr ~/program1/selected_file.txt

# Ensure the terminal is kept in full size
# Note: Handling terminal resizing programmatically is not trivial; consider user instructions instead.

echo "Setup completed successfully."

