/*
student.cpp
csci10- section01-hw8

Created by Karishma Khanna on 11/09/18.

In initializeStudent, I added code to read in the students’ courses and
grades and computed the student’s gpa from the grades entered.

In printStudent, I added code to print out the students’ courses and grades,
and their gpa.

In mergeStudent, I added code to include all courses from both students
(but with no duplicates) and compute the new gpa, and stored these values into the
returned Student. For repeated classes, I averaged the grades.

I made some more modifications that seemed to make sense to the original code as well.

I used two students for convenience sake, so I hardcoded some parts that wouldn't work with more than one student,
but I checked to make sure this okay okay because of the wording of the problem and for saving the user time.

*/


//  Copyright © 2017 csci 10 smanna

#include <iostream>
#include <string>
using namespace std;

// Date
struct Date {
    int month;
    int day;
    int year;
};

// Transcript
struct Transcript {
    string classes[100];
    double grades[100];
    int class_count;
    double gpa;
};

// student
struct Student {
    string name;
    int id;
    string major;
    Transcript tran;
    int age;
    Date dob;
};

// function declarations
Student mergeStudent(Student s1, Student s2);
void printStudent(Student s);
void initializeStudent(Student& st);

// for testing
int main() {

    const int n=2; //You may wish to make this smaller for testing, I made this 2 for testing.
    Student freshmen[n];
    // added: prompts for program
    cout<<endl;
    cout<<"The first function in this program will INITIALIZE user inputs for information about two students, the second function will PRINT out the info on the two students, and the third function will MERGE their information into a new data set if the two students are the same. For repeated classes, the average grade will be taken. We are only using two students for the sake of convenience."<<endl;
    cout<<endl;
    // added: first, testing the initializa student function
    cout<<"Initializing students..."<<endl;
    cout<<endl;
    // added: label for which student is being initialized
    for(int b = 0; b < n; b++) {
      cout<<"Student "<<b+1<<endl;
      initializeStudent(freshmen[b]);
      cout<<endl;
    }
    // added: second, testing the print student function
    cout<<"Printing student information..."<<endl;
    cout<<endl;
    // cout << freshman[0].name << endl;
    // commented out because it should be added inside the for loop instead
    // instead of printing the name, I printed the student number since the name is displayed anyway
    for(int z = 0; z < n; z++){
      cout<<"Student "<<z+1<<endl;
      printStudent(freshmen[z]);
      cout<<endl;
    }
    // added: third, testing the merge function
    // if the two students entered have the same birthday, their information will be merged, otherwise, it will not
    if(freshmen[0].dob.day == freshmen[1].dob.day && freshmen[0].dob.month == freshmen[1].dob.month && freshmen[0].dob.year == freshmen[1].dob.year) {
      cout<<"Merging information on Student 1 and Student 2..."<<endl;
      cout<<endl;
      // student variable to hold the result of the merge function
      Student merged=mergeStudent(freshmen[0], freshmen[1]);
      // print the information stored in the new student variable
      printStudent(merged);
      cout<<endl;
    } else {
        cout<<"No two students entered were the same, so their information was not merged."<<endl; // if the DOB was not the same
        cout<<endl;
      }
    return 0;
}

// printing student information
void printStudent(Student s) {
    cout << "Name: " << s.name << endl;
    cout << "Student ID: " << s.id << endl;
    cout << "Major: " << s.major << endl;
    cout << "Birthday: " << s.dob.month << "/" << s.dob.day << "/" << s.dob.year << endl;
    cout << "Age: " << s.age <<endl;

    // Add stuff for transcript
    // TO DO

    // used a for loop to print out all the courses along with their grades at each intex in the classes and grades arrays
    // printed GPA, caculated in the initialize function
    for(int i=0; i<s.tran.class_count; i++) {
      cout<<"Course "<<i+1<<": "<<s.tran.classes[i]<<", Grade: "<<s.tran.grades[i]<<"/100"<<endl;
    }
    cout<<"GPA: "<<s.tran.gpa<<"/100"<<endl;
}


// initializing student
void initializeStudent(Student& st) {
    // string dummy;
    // commented out because the dummy string was not needed
    cout << "Enter the student's name: ";
    getline(cin, st.name); // getline reads a line
    cout << "Enter their student ID number: ";
    cin >> st.id;
    //  getline(cin, dummy);
    // commented out because I used cin.ignore() to get rid of the /n instead of a dummy variable
    cin.ignore();
    cout << "Enter their major: ";
    getline(cin, st.major);
    cout << "Enter their age: ";
    cin >> st.age;
    cout << "Enter their birthday month, day, and year as numbers: " << endl;
    // changed the formatting on how birthday was entered
    cout<<"MM: ";
    cin >> st.dob.month;
    cout<<"DD: ";
    cin >> st.dob.day;
    cout<<"YYYY: ";
    cin >> st.dob.year;

    // Fill in stuff for transcript
    // TO DO

    // enter the number of enrolled courses first, will be used as the bound for the for loop
    cout<<"Enter their number of enrolled courses: ";
    cin>>st.tran.class_count;
    // declare a total variable that will count the total grades for the GPA calculation
    double total=0.0;
    // for loop to enter the courses with getline and grades with cin
    // cin.ignore() is used to get rid of the /n chracter with each cycle of the loop
    // keep adding the values entered for the grades to total in the loop
    for(int i=0; i<st.tran.class_count; i++) {
        cin.ignore();
        cout<<"Enter the name of Course "<<i+1<<": ";
        getline(cin, st.tran.classes[i]);
        cout<<"Grade for Course "<<i+1<<" (out of 100): ";
        cin>>st.tran.grades[i];
        total=total+st.tran.grades[i];
    }
    // cin.ignore() is used to get rid of any /n character
    cin.ignore();
    // the GPA is calulated by dividing the total by the class count, enter the GPA
    st.tran.gpa=total/st.tran.class_count;
}

// Merging
Student mergeStudent(Student s1, Student s2) {
    // Student ret = {"no name", 0, ""};
    // if(s1.id == s2.id){
    //     ret.id = s1.id;
    //     if(s1.age > s2.age) {
    //         ret.major = s1.major;
    //     }
    //     else {
    //         ret.major = s2.major;
    //     }
    //     if(s1.name.length() > s2.name.length())
    //         ret.name = s1.name;
    //     else
    //         ret.name = s2.name;

    // commented out because instead of checking with the student ID, I checked to merge based on the DOB being the same,
    // since although anything else may change, the DOB will never change if the two people are the same

    // Fill in stuff for transcript
    // TO DO

    // declare a return variable ret to hold the merged information
    // declare a variable temp to store and count all the classes and grades
    // only transfer certain finalized class and grade information from temp to ret at the end
    Student ret;
    Student temp;
    // assign the DOB to the ret variable (can be from either student since the DOB is the same)
    ret.dob.month = s1.dob.month;
    ret.dob.day = s1.dob.day;
    ret.dob.year = s1.dob.year;
    // store the other information on age, major, ID, and name from the most current data set, so the one where the age is greater
    // if student 1 is older, take their info, otherwise take the info from student 2
    // name is assigned here in case the names are of equal length
    if(s1.age > s2.age) {
        ret.age = s1.age;
        ret.major = s1.major;
        ret.id = s1.id;
        ret.name = s1.name;
    } else {
      ret.age = s2.age;
      ret.major = s2.major;
      ret.id = s2.id;
      ret.name = s2.name;
    }
    // if the length of one name is greater between student 1 and student 2, take the longer name for the return variable
    // this is useful if the last name in one data set is just an initial instead of the full name
    // this is not useful for cases where someone may have misspelled their name with an extra character or changed their legal name to be shorter
    if(s1.name.length() > s2.name.length()) {
        ret.name = s1.name;
    } else {
        ret.name = s2.name;
      }

    // long process below for merging the classes and grades!

    // first, use a for loop to add all the classes and grades from s1 to the classes and grades arrays in the temp variable
    // for loop from 0 to less than s1 class count
    for (int i=0; i<s1.tran.class_count; i++) {
      temp.tran.classes[i]=s1.tran.classes[i];
      temp.tran.grades[i]=s1.tran.grades[i];
    }
    // second, do the same for student 2, use a for loop to add all the classes and grades from s2 to the classes and grades arrays in temp, following the info from s1
    // for loop from s1 class count to less than the combined s1 and s2 class counts
    for (int j=s1.tran.class_count; j<s1.tran.class_count+s2.tran.class_count; j++) {
      temp.tran.classes[j]=s2.tran.classes[j-s1.tran.class_count]; // j-s1.tran.class_count is used so that the classes from s2 are assigned starting from the first class at index 0, and not from the index of s1's class count
      temp.tran.grades[j]=s2.tran.grades[j-s1.tran.class_count]; // j-s1.tran.class_count is used so that the grades from s2 are assigned starting from the first grade at index 0, and not from the index of s1's class count
    }
    // the new class count for temp is equal to s1's count plus s2's count
    temp.tran.class_count=s1.tran.class_count+s2.tran.class_count;
    // declare a gradecount variable and a total grade variable for the new average grade calculations for each class if there are repeats
    double gradecount;
    double totalgrade;
    // these loops below will be used to identify all the duplicate classes, and average the grades from those duplicates
    // write an outer for loop from 0 to less than temp class count
    for (int k=0; k<temp.tran.class_count; k++) {
      // the loop skips over "Duplicate" classes
      if (temp.tran.classes[k]!="Duplicate") {
        // initialize the total grade to the grade of the class the outer loop is on (will be unique, first appearance of that class), and the gradecount to 1
        totalgrade=temp.tran.grades[k];
        gradecount=1;
        // write an inner loop from one greater than the outer loop index until less than the temp class count
        // the inner loop only runs through all the courses AFTER the outer index not already labeled "Duplicate"
        // the classes before k+1 are guaranteed to be either unique or already labeleed "Duplicate"
        for (int l=k+1; l<temp.tran.class_count; l++) {
          // if any classes in the inner loop have the same name as the class the outer loop is on, and are not already "Duplicate", then the class name in the inner loop will be labeled "Duplicate"
          // the gradecount will incrememnt since a repeat class was found, and the grades from the duplicate will be added to total grade
          if (temp.tran.classes[l]==temp.tran.classes[k] && temp.tran.classes[l]!="Duplicate") {
            temp.tran.classes[l]="Duplicate";
            gradecount++;
            totalgrade=totalgrade+temp.tran.grades[l];
          }
        }
        // the grade returned for that class will be the the total grade for that course from all the repeats, divided by the number of times that course occurred (so the average grade)
        // if there were no repeats, then the grade for this class will be grade in the first time it appeared in the outer array divided by 1
        temp.tran.grades[k]=totalgrade/gradecount;
      }
    }
    // set an integer count variable, which will act as an index to count unique classes, to -1 since the first time it gets incremented, we want it to be index 0, and because if anything goes wrong we will know since the GPA later on will be negative
    int count=-1;
    // use a for loop from 0 to the temp class count to enter all the non duplicate courses and grades from temp into ret
    // if the class name from temp is not "Duplicate", first increment count, then assign the class and grade the loop is currently on from temp to ret at the index count
    // the index count will make it so unique classes are being added to ret adjacently, even though in temp there may be "Duplicate" classes between the unique ones
    for (int h=0; h<temp.tran.class_count; h++) {
      if (temp.tran.classes[h]!="Duplicate") {
        count++;
        ret.tran.classes[count]=temp.tran.classes[h];
        ret.tran.grades[count]=temp.tran.grades[h];
      }
    }
    // declare a total variable to store the overall GPA of the return variable
    double total=0.0;
    // the return variable class count is one greater than count, since count was used as an array index, so there are count+1 unique classes
    ret.tran.class_count=count+1;
    // use a for loop from 0 to less than the return class count
    // keep adding the grades at each index to the total
    for(int g=0; g<ret.tran.class_count; g++) {
      total=total+ret.tran.grades[g];
    }
    // the GPA will be the total divide dby the class count
    ret.tran.gpa=total/ret.tran.class_count;
    // return the ret variable
    return ret;
}
