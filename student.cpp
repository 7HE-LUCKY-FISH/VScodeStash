#include "student.h"
using namespace std;
#include <iostream>

void Student::displayDetails() const
{
    cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
}
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

    if(newStudent.gpa >4.0 || newStudent.gpa<0){
        cerr<<"Inivald GPA"<<endl;   
    }else{
            students[0].gpa = newStudent.gpa;
            students[0].age = newStudent.age;
            students[0].name= newStudent.name;
            ++size;
    }
}
void insertAtEnd(Student students[], int &size, const Student &newStudent)
{
    if(newStudent.gpa >4.0 || newStudent.gpa<0){
    cerr<<"Inivald GPA"<<endl;   
    }else{
            students[size].gpa = newStudent.gpa;
            students[size].age = newStudent.age;
            students[size].name= newStudent.name;
            size++;
    }
    //if(newStudent.gpa<4.0|| newStudent.gpa>0){
    //    students[size] = newStudent;
    //    ++size;
    //}else{
    //    cerr<<"Invalid GPA"<<endl;
    //}

}
void changeInfo(Student students[], int size, int index, const Student &newStudent)
{
    if (index >= 0 && index < size)
    {
        if(newStudent.gpa >4.0 || newStudent.gpa<0){
            cerr<<"Inivald GPA"<<endl;
        
        }else{
            students[index].gpa = newStudent.gpa;
            students[index].age = newStudent.age;
            students[index].name= newStudent.name;
        }
        //students[index] = newStudent;
    }
    else
    {
        cout << "Invalid index." << endl;
    }
}
