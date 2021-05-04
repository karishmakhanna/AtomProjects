
/*
student.cpp
csci10- section01-hw8

Created by Karishma Khanna on 11/09/18.



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
void mergeStudent(Student s1, Student s2);
void printStudent(Student s);

// for testing
int main() {
    Student s1={"k", 12, "m", {{"a", "b", "c", "d"}, {1, 2, 3, 4}, 4, 2.5}, 10, {2, 2, 2}};
    Student s2={"karishma", 123, "math", {{"b", "e", "c", "d", "j"}, {4, 2, 0, 9, 7}, 5, 4.4}, 12, {2, 2, 2}};

    // added

    Student merge;
    if(s1.dob.day == s2.dob.day && s1.dob.month == s2.dob.month && s1.dob.year == s2.dob.year){
      cout<<"Merging student information."<<endl;
      cout<<endl;
      mergeStudent(s1, s2);
      cout<<endl;
    } else {
      cout<<"The students entered were not the same, so their information could not be merged."<<endl;
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
    // TO do

    for(int i=0; i<s.tran.class_count; i++) {
      cout<<"Course "<<i+1<<": "<<s.tran.classes[i]<<", Grade: "<<s.tran.grades[i]<<"/100"<<endl;
    }
    cout<<"GPA: "<<s.tran.gpa<<"/100"<<endl;
}


// initializing student


// Merging
void mergeStudent(Student s1, Student s2) {
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

    // Fill in stuff for transcript
    // TO DO

    Student ret;
    Student temp;
    ret.dob.month = s1.dob.month;
    ret.dob.day = s1.dob.day;
    ret.dob.year = s1.dob.year;
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
    if(s1.name.length() > s2.name.length()) {
        ret.name = s1.name;
    } else {
        ret.name = s2.name;
      }

    for (int i=0; i<s1.tran.class_count; i++) {
      temp.tran.classes[i]=s1.tran.classes[i];
      temp.tran.grades[i]=s1.tran.grades[i];
    }
    for (int j=s1.tran.class_count; j<s1.tran.class_count+s2.tran.class_count; j++) {
      temp.tran.classes[j]=s2.tran.classes[j-s1.tran.class_count];
      temp.tran.grades[j]=s2.tran.grades[j-s1.tran.class_count];
    }
    cout<<s1.tran.class_count<<endl;
    cout<<s2.tran.class_count<<endl;

    temp.tran.class_count=s1.tran.class_count+s2.tran.class_count;
    cout<<s1.tran.class_count<<endl;
    cout<<s2.tran.class_count<<endl;
    cout<<temp.tran.class_count<<endl;

    for (int k=0; k<temp.tran.class_count; k++) {
      cout<<"k: "<<k<<endl;
      for (int l=k+1; l<temp.tran.class_count; l++) {
        cout<<"l: "<<l<<endl;
        if (temp.tran.classes[l]==temp.tran.classes[k]) {
          temp.tran.classes[l]="Duplicate";
          if (temp.tran.grades[l]>=temp.tran.grades[k]) {
            temp.tran.grades[k]=temp.tran.grades[l];
          }
        }
      }
    }

    for(int v=0; v<temp.tran.class_count; v++) {
      cout<<"Course "<<v+1<<": "<<temp.tran.classes[v]<<", Grade: "<<temp.tran.grades[v]<<"/100"<<endl;
    }

    int count=-1;
    for (int h=0; h<temp.tran.class_count; h++) {
      if (temp.tran.classes[h]!="Duplicate") {
        count=count+1;
        cout<<count;
        ret.tran.classes[count]=temp.tran.classes[h];
        ret.tran.grades[count]=temp.tran.grades[h];
        cout<<count<<endl;
      }
    }
    for(int c=0; c<=count; c++) {
      cout<<"Course "<<c+1<<": "<<ret.tran.classes[c]<<", Grade: "<<ret.tran.grades[c]<<"/100"<<endl;
    }

    double total=0.0;
    for(int g=0; g<=count; g++) {
      total=total+ret.tran.grades[g];
      cout<<total<<endl;
    }
    ret.tran.class_count=count+1;
    cout<<ret.tran.class_count<<endl;
    cout<<total<<endl;
    ret.tran.gpa=total/ret.tran.class_count;
    cout<< ret.tran.gpa<<endl;
}
