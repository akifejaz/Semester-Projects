#include <string>

#ifndef _Course_Node_H
#define _Course_Node_H

class Teacher_Node;
class Student_LinkedList;
class Student_Node;

// #include "Student_LinkedList.h"
#include "Course_LinkedList.h"
extern Student_LinkedList *student_array;

class Course_Node
{
private:
    /* data */
    Course_Node *Next ; // Next pointer for linkedlist of course class

    std:: string courseName ; // Name of the course
    std :: string courseID ;  // ID 
    // std:: courseName.reserve(100);
    int size;
    // std:: string teacher;
    // std:: string teacherID;
    Student_Node *std_list;
    // Student_LinkedList * std_ptr;
    Teacher_Node * te_ptr;
    int count;

    //the course could have the following properties
    // Name , ID , Teacher , 

public:
    Course_Node(){}
    Course_Node(std::string , std::string, Teacher_Node *, Student_Node*, int) ;
    ~Course_Node() ;

    void setData(std::string , std::string , Student_Node * , Teacher_Node* , int );
    Course_Node *getNext();
    void setNext(Course_Node *);
    int getSize();
    std::string getCourseName();
    std::string getCourseID();
    Teacher_Node * getTeacher();
    Student_Node* getStudentList();
    
    void setTeacher(std::string , std::string);
    void setTeacherNode(Teacher_Node *);
    void setSize(int );
    void setStudentList(Student_Node* ptr);
    // void setStudents(std::string)

    Student_Node* getHead ();
    // Course_Node * getCourseListHead();
    void display();
};


#endif