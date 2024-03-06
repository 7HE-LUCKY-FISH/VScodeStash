#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
    string name;
    int age;
    double gpa;
    Student(const string &n, int a, double g) : name(n), age(a), gpa(g) {}
    Student() : name(""), age(0), gpa(0.0) {}
    void displayDetails() const;
};

#endif