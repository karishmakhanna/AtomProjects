
//  Copyright © 2017 csci 10 smanna

#include <iostream>

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

    const int n = 100; //You may wish to make this smaller for testing.
    Student freshmen[n];

    for(int i = 0; i < n; i++) {
        initializeStudent(freshmen[i]);
    }

    cout << freshmen[0].name << endl;
    for(int i = 0; i < n; i++){
        printStudent(freshmen[i]);
    }
    cout << endl;
    return 0;
}

// printing student information
void printStudent(Student s) {
    cout << "Name is: " << s.name << endl;
    cout << "ID is: " << s.id << endl;
    cout << "major is:" << s.major << endl;
    cout << "Birthday is: " << s.dob.month << "/" << s.dob.day << "/" << s.dob.year << endl;
    cout << "Age is: " << s.age;

    //Add stuff for transcript
    // TODO
}


// initializing student
void initializeStudent(Student& st) {
    string dummy;
    cout << "Enter a name" << endl;
    getline(cin, st.name); // getline reads a line
    cout << "Enter an id" << endl;
    cin >> st.id;
    getline(cin, dummy);
    cout << "enter a major" << endl;
    getline(cin, st.major);
    cout << "Enter age: " << endl;
    cin >> st.age;
    cout << "Enter birthday month, day, year as numbers: " << endl;
    cin >> st.dob.month >> st.dob.day >> st.dob.year;

    //Fill in stuff for transcript
    // TODO

}

// Merging
Student mergeStudent(Student s1, Student s2) {
    Student ret = {"no name", 0, ""};
    if(s1.id == s2.id){
        ret.id = s1.id;
        if(s1.age > s2.age) {
            ret.major = s1.major;
        }
        else {
            ret.major = s2.major;
        }
        if(s1.name.length() > s2.name.length())
            ret.name = s1.name;
        else
            ret.name = s2.name;
        //Fill in stuff for transcript
        // TODO
    }
    return ret;
}
