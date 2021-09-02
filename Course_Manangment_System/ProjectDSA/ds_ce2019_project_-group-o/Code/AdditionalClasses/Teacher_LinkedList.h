
#ifndef _Teacher_LinkedList_H
#define _Teacher_LinkedList_H

// class Teacher_Node;
// class Course_LinkedList;

#include "Course_LinkedList.h"  // Teacher Node + StdList + stdNode +Course Node Header also Included Here 
extern Course_LinkedList course_list;


#include <string>
class Teacher_LinkedList
{
private:
    /* data */
    Teacher_Node *head;
    Teacher_Node *tail;
    int count; 
    
    Course_LinkedList *course_ptr = &course_list;

public:
    Teacher_LinkedList(/* args */) ;
    ~Teacher_LinkedList();

    void appendTeacher(std::string, std::string);
    void appendTeacherNode(std::string, std::string, int , int , int , int );
    void SpacifyTime( std::string , int , int , int, int  ); //start Time + End Time 
    void spacifyTime(int , int , int, int);
    void addStudents(std::string, Student_Node * , int );
    void removeStudents(std::string, std::string);
    int CourseizeCheck(std::string);
    
    void deleteNode(std::string);
    Teacher_Node * getHead();
    void sort();
    void swap1(Teacher_Node *ptr, Teacher_Node* ptr1);
    Teacher_Node * getCurrentTeacherNode();
    void display();
    void saveTeacherData();
    void readTeacherData();
};



#endif