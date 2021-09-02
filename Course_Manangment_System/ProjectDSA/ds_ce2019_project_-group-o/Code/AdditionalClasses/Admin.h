#include <string>

#include "Course_LinkedList.h"
class Student_LinkedList;
class Teacher_Node;
class Teacher_Node;

#ifndef _ADMIN_H
#define _ADMIN_H


extern Student_LinkedList student_obj;
extern Course_LinkedList course_list;

class Admin
{
private:
    /* data */
    Course_LinkedList *course_obj = &course_list;

public:
    Admin(/* args */);  // Constructor 
    ~Admin();          // Distructor

    void creatCourse(std::string , std::string, Teacher_Node * , Student_Node*, int );       // For New Course Creation
    void specifyTeacher(std::string, std::string, std::string);    // For Spacify Teacher for a course/subject
    void addstudents(std::string, Student_Node*, int);       // add students in pre-created course
    void removeStudents(std::string, std::string);    // remove studetns from particlar course and have particluar ID
    void deleteCourse(std::string);      // delete pre-created Course
    void removeTeacher(std::string, std::string, std::string);     // remove pre-defined teacher
    void replaceTeacher(std::string, std::string, std::string, std::string);    // replace teacher in place of other teacher
    int CourseSizeCheck(std::string);
    void AddStudentsIncourse();
    void SortList();          // Sort list of sstudents , teachers , courses 
    void display();

    void saveData();
    void readData();

    

    // For creation of course, Let's say use Linkedlist
    // for students, teachers, courses there would be linkedlsit for each
    // In order to make linkedlist we need ->  Type + Linking 

    // In general we have used, Node+List => where node has data + list is like 
    // several copies of that type
};



#endif