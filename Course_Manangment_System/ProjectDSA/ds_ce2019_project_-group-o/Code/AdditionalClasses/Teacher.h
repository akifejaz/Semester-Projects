#ifndef _teacher_h
#define _teacher_h

#include "Teacher_LinkedList.h" // course Node ,LIst + std Ndoe ,List + teacher Node

// class Student_Node ;
// class Course_Node;

#include <string>

class Teacher
{
private:

    Teacher_LinkedList *obj;
    Student_Node *ptr;
    Course_Node *ptr2;


public:
    Teacher(/* args */) {}
    ~Teacher() {}
    void SpacifyTime( std::string ,int , int , int, int  ); //start Time + End Time 
    void CancelReservation();
    void addStudents(std::string, Student_Node *,int);
    // void addStudents(std::string , Student_LinkedList*);
    int CoursesizeCheck(std::string);
    void removeStudents(std::string, std::string);
    void msgIngroup();
    void deleteMsg();
    void sortList();
    void saveData();
    void readData();
    void display();

};

#endif