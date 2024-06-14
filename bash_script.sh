#!/bin/bash

# Open file explorer and store the file path
selected_file=$(zenity --file-selection --title="Select a file" 2>/dev/null)

# Check if a file was selected
if [ -n "$selected_file" ]; then
    # Print the selected file path
    echo "$selected_file"
   else
    echo "No file selected."
fi


