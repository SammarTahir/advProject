
$$\   $$\ $$\     $$\ $$$$$$$$\        $$$$$$\  $$\                                          $$\     
$$ |  $$ |\$$\   $$  |\____$$  |      $$  __$$\ \__|                                         $$ |    
\$$\ $$  | \$$\ $$  /     $$  /       $$ /  $$ |$$\  $$$$$$\   $$$$$$\   $$$$$$\   $$$$$$\ $$$$$$\   
 \$$$$  /   \$$$$  /     $$  /        $$$$$$$$ |$$ |$$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\\_$$  _|  
 $$  $$<     \$$  /     $$  /         $$  __$$ |$$ |$$ |  \__|$$ /  $$ |$$ /  $$ |$$ |  \__| $$ |    
$$  /\$$\     $$ |     $$  /          $$ |  $$ |$$ |$$ |      $$ |  $$ |$$ |  $$ |$$ |       $$ |$$\ 
$$ /  $$ |    $$ |    $$$$$$$$\       $$ |  $$ |$$ |$$ |      $$$$$$$  |\$$$$$$  |$$ |       \$$$$  |
\__|  \__|    \__|    \________|      \__|  \__|\__|\__|      $$  ____/  \______/ \__|        \____/ 
                                                              $$ |                                   
                                                              $$ |                                   
                                                              \__|                                   

Advanced Procedural Programming Assignment
Project Value: 40%
Due Date: Thursday 22nd April 2018
XYZ Airport are currently recording passenger travel statistics into Ireland and has requested
you to develop a new passenger statistic application for them.
This program will create a database which will store the details of all the passengers travel
statistics. In addition to storing all the passenger data the application should allow overall
travel statistics to be generated.
Your program should create the database (which for your purpose MUST be implemented
as a linked list) and be able to save, restore, retrieve, add, delete and update passenger
details.
For each passenger, you will store the following details:
 Passport Number (Assume an integer – must be unique)
 First Name
 Second Name
 Year Born
 Email Address (must contain an @, a full stop and a .com)
 Which of the following areas did you travel from:
 UK
 Rest of Europe
 Asia
 Americas
 Australasia
 What travel class did you use to travel to Ireland?
 Economy
 Premium Economy
 Business Class
 First Class
 How many trips to Ireland do you make per year?
 Less than three times per year
 Less than five times per year
 More than five times per year
 On average how long is your duration:
 One day
 Less than 3 days
 Less than 7 day
 More than 7 day
The system is password protected and only the correct username and password details will
allow the user to gain access to the system.
The username and password (6 characters in length) will be stored in a login structure which
is read in from a login file which holds three login records. Ensure that when the user enters
in the password that it cannot be seen on the screen. (It only shows an * for each character.
E.g. ******)
Your program should initialise the linked list based on the passengers’ profiles stored in the
passenger.txt file. This file should be updated when the user terminates the program.
Your program should provide a menu as follows:
1) Add passenger (Note: Passport Number must be unique).
2) Display all passenger to screen
3) Display passenger Details
4) Update a passenger statistic
5) Delete passenger
6) Generate statistics (a – i) based on the user selecting one of the criteria listed in I - II
A. % of players who travel from the UK
B. % of players who travel from the Rest of Europe
C. % of players who travel from the Asia
D. % of players who travel from the Americas
E. % of players who travel from the Australasia
F. % of players who spent on average one day in Ireland
G. % of players who spent on average less than 3 days in Ireland
H. % of players who spent on average less than 7 days in Ireland
I. % of players who spent on average more than 7 days in Ireland
I. Travel Class
II. Born Before 1980
7) Print all passenger details into a report file.
8) List all the passenger of the following the UK in order of year born.
Add passenger: This will add a new passenger at the correct position in your sorted linked
list based on their Passport Number. The passport number must be unique. If it is not a
unique passport number then the user show be given the opportunity to update the
passenger stats.
Display all passenger to screen: Display all passenger details to screen
Display passenger Details: Allow the admin to input either a Passport ID or a Name of the
passenger and display the details for that passenger.
Update Passenger: Allows the admin to update passenger details based on either a name or
Passport number being entered.
Delete Passenger: Allows the user to delete a passenger from the list by passenger number.
Print all Passenger into a report file: Display a passenger report which outputs the following
information of the passenger’s to file:
 All passenger Details
 Passenger Travel Statistics (based upon item 6 of the menu)
Validation:
Your program should perform validation on all menu inputs.
Project Submission
Each student must submit the code developed to support the application. In addition to the
code each student must submit a document explaining the various design decisions that
were made during the project and how their code works.
Submission Deadline
Project Submissions to be submitted to martin.hynes@gmit.ie by 9pm on the 20th April
2018.
NOTES:
 You must implement the passenger’s database as a linked list.
 Comments expected.
 The reuse of code through functions is expected. Each section of the assignment should
be structured within its own function, passing parameters as necessary.
 You should create and populate a login file with sample data to allow successful
validation of user credentials which you will then read in to your login linked list.
 Ensure that any files that are needed to run the program are included in your
submission.
 Use of onscreen messages to inform the user is expected.
 Your code has to run. Serious deduction of marks will occur for code that is not running
correctly.
 Plagiarism is not acceptable. You will be asked to explain your code.
 Late Submissions will be deducted by 5% per day. This will be accumulative – e.g. A
student who submits their work three days late will be given a deduction of 15%.