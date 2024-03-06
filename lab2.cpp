#include <iostream>
#include <string>
using namespace std;
#include "student.h"
#include "student.cpp"
/*
class Student
{
public:
    string name;
    int age;
    double gpa;
    Student(const string &n, int a, double g) : name(n), age(a), gpa(g) {}
    Student() : name(""), age(0), gpa(0.0) {}
    void displayDetails() const
    {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};
void displayStudents(const Student students[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        students[i].displayDetails();
    }
}

void insertAtBeginning(Student students[], int &size, const Student &newStudent)
{
    for (int i = size; i > 0; --i)
    {
        students[i] = students[i - 1];
    }
    students[0] = newStudent;
    ++size;
}
void insertAtEnd(Student students[], int &size, const Student &newStudent)
{
    students[size] = newStudent;
    ++size;
}
void changeInfo(Student students[], int size, int index, const Student &newStudent)
{
    if (index >= 0 && index < size)
    {
        students[index] = newStudent;
        students[index].gpa = max(0.0, min(newStudent.gpa, 4.0));
    }
    else
    {
        cout << "Invalid index." << endl;
    }
}
*/
int main()
{

    int maxSize = 10;
    Student students[maxSize] = {
        {"Alice", 20, 3.5},
        {"Bob", 22, 3.8},
        {"Charlie", 21, 3.2},
    };

    int currentSize = 3;

    cout << "Initial Array:" << endl;
    displayStudents(students, currentSize);

    insertAtBeginning(students, currentSize, {"David", 19, 3.9});
    cout << "\nAfter Inserting at the Beginning:" << endl;
    //displayStudents(students, currentSize);

    insertAtEnd(students, currentSize, {"Eva", 23, 3.7});
    cout << "\nAfter Inserting at the End:" << endl;
    //displayStudents(students, currentSize);


    changeInfo(students, currentSize, 3, {"Charlie", 21, 4.1});
    //changeInfo(students, currentSize, 2, {"Charlie", 21, 3.5});
    cout << "\nAfter Changing Information at Index 2:" << endl;
    displayStudents(students, currentSize);


    cout<<"\n";
    string student_name;
    int student_age;
    double student_gpa;
    cout<<"Enter new student name: ";
    cin>>student_name;
    cout<<"Enter new student age: ";
    cin>>student_age;
    cout<<"Enter new sudent gpa: ";
    cin>>student_gpa;
    //while(student_gpa >4.0 || student_gpa <0){
    //    cout<<"Enter valid gpa: ";
    //    cin>> student_gpa;
    //}
    insertAtEnd(students,currentSize,{student_name, student_age,student_gpa});
    cout<<"\n"<<endl;
    displayStudents(students,currentSize);
    

    return 0;
}