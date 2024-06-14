# Adam

Adam is an HR software designed for RHEL-like operating systems. Note that this program works only on Fedora terminal. If you are on Windows, install Fedora WSL from Microsoft.

![Fedora Logo](https://upload.wikimedia.org/wikipedia/commons/3/3f/Fedora_logo.svg)

It is for student management. You can input students' files, exam marks, and previous year marks, as well as teachers' files in a specific format.

For the students' file, each line should be as follows:  

malak felioune malak@gmail.com 23454  
firstname lastname email id

For the teachers' file, input as follows:  

Omar Abdulrahman omar.abdulrahman@gmail.com Arabic 10/12/2010  
firstname lastname email any_module_name startdate dd/mm/yyyy

For exam marks files:  

malak felioune English 14 18  
firstname lastname module midterm finalexam

There are three exams lists for this year, the previous year, and the previous two years. If there is no data, some features will not work correctly. Ensure that you insert all the files in the input tab first, then proceed to the other sections.

- **Students Tab**: Shows the students' list, allows adding another student manually, and provides more info about a student.
- **Teachers Tab**: Similar functionalities for teachers.
- **Stats Tab**: Displays all statistical parameters about the inserted data.
- **Proba Tab**: Shows some interesting values based on regression analysis (note: predictions may not be precise).

This is the humble effort of one week, but we believe that we can make it more advanced in the future!

## Ensure the terminal is kept in full size

Note: Handling terminal resizing programmatically is not trivial.

To keep the terminal window at a size that makes the letters easier to read, we recommend zooming in to an intermediate level.

### To install via dnf

$ sudo nano /etc/yum.repos.d/adam.repo

Then write inside the file:

[adam]  
name=Adam RPM Repository  
baseurl=https://malak-100.github.io/adam-rpm-repo/  
enabled=1  
gpgcheck=0

Save the file and then run:

$ sudo dnf install adam




