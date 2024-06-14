# Adam

Adam is an HR software designed for RHEL-like operating systems. Note that this program works only on Fedora terminal. If you are on Windows, install Fedora WSL from Microsoft.

![Home Page on Adam](https://raw.githubusercontent.com/malak-100/adam-rpm-repo/main/ENSIA.png)




It is for student management. You can input students' files, exam marks, and previous year marks, as well as teachers' files in a specific format:. 

For the students' file, each line should be as follows:  

malak felioune malak@gmail.com 23454  
firstname lastname email id

For the teachers' file, input as follows:  

Omar Abdulrahman omar.abdulrahman@gmail.com Arabic 10/12/2010  
firstname lastname email any_module_name startdate{dd/mm/yyyy}

For exam marks files:  

malak felioune English 14 18  
firstname lastname module midterm finalexam

There are three exams lists for this year, the previous year, and the previous two years. If there is no data, some features will not work correctly. Ensure that you insert all the files in the input tab first, then proceed to the other sections.

- **Students Tab**: Shows the students' list, allows adding another student manually, and provides more info about a student.
- **Teachers Tab**: Similar functionalities for teachers.
- **Stats Tab**: Displays all statistical parameters about the inserted data.
- **Proba Tab**: Shows some interesting values based on regression analysis (note: predictions may not be precise).
- **Input Tab**: Input the files in the format above for each file 

This is the humble effort of one week, but we believe that we can make it more advanced in the future!

## Ensure the terminal is kept in full size

Note: Handling terminal resizing programmatically is not trivial.

To keep the terminal window at a size that makes the letters easier to read, we recommend zooming in to an intermediate level.

### To install via dnf in fedora

$ sudo nano /etc/yum.repos.d/adam.repo

Then write inside the file:

[adam]  
name=Adam RPM Repository  
baseurl=https://malak-100.github.io/adam-rpm-repo/  
enabled=1  
gpgcheck=0

Save the file and then run:

$ sudo dnf install adam
# BE SURE THAT YOU DO NOT INPUT THE SAME FILES OR DATA TWICE 
# If you want to clone the repo and run adam bin directly
YOU MUST PUT THOSE FILES IN THIER PLACE IN THE SYSTEM AND GIVE THEM THE FOLLOWING PERMISSIONS 
```bash

mv bash_script.sh /usr/share/adam/ 
mv bash_script1.sh /usr/share/adam/
mv bash_script2.sh /usr/share/adam/
mv bash_script3.sh /usr/share/adam/
mv bash_script_delete1.sh /usr/share/adam/
mv bash_script_delete2.sh /usr/share/adam/
mv bash_script_delete3.sh /usr/share/adam/
mv selected_file.sh /usr/share/adam/
mv data /usr/share/adam/ 
chmod +wxr setup.sh
./setup.sh
chmod +wxr /usr/share/adam/bash_script.sh 
chmod +wxr /usr/share/adam/bash_script1.sh 
chmod +wxr /usr/share/adam/bash_script2.sh 
chmod +wxr /usr/share/adam/bash_script3.sh 
chmod +wxr /usr/share/adam/bash_script_delete1.sh 
chmod +wxr /usr/share/adam/bash_script_delete2.sh 
chmod +wxr /usr/share/adam/bash_script_delete3.sh 
chmod +wxr /usr/share/adam/selected_file.sh 
chmod +wxr /usr/share/adam/exams_datahovuhovi.txt
chmod +wxr /usr/share/adam/exams_next_datahovuhovi.txt
chmod +wxr /usr/share/adam/exams_next_next_datahovuhovi.txt
chmod +wxr /usr/share/adam/students_datahovuhovi.txt
chmod +wxr /usr/share/adam/teachers_datahovuhovi.txt

cp adam /usr/local/bin/
 # now you can run it in any place in the system  
```
# TO ADD STUDENTS OR FILES OR TEACHERS OR MANIPULATE OR INSERT ANY DATA YOU MUST BE A ROOT USER 

