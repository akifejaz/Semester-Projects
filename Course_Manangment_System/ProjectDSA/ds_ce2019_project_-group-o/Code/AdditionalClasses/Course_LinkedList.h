
#ifndef _Course_LinkedList_
#define _Course_LinkedList_
#include <string>

class Course_Node;

#include "Student_LinkedList.h"
#include "Teacher_Node.h"

//----
#include "Student_Node.h"
#include "course_Node.h"

//----


class Course_LinkedList
{
private:
    /* data */
    Course_Node *head;
    Course_Node *tail;
    int count; 
    // Student_LinkedList *obj;

    

public:
    Course_LinkedList(/* args */) ;
    ~Course_LinkedList();
    void CreatNewCourse (std::string , std::string ,Teacher_Node *, Student_Node*, int);  // append newCourse with paramentrs name & ID
    void replaceTeacher(std::string, std::string,std::string, std::string);
    void specifyTeacher(std::string, std::string, std::string);
    void prepend (std::string , std::string);
    void deleteCourse (std::string);
    void addStudents(std::string, Student_Node *ptr, int );
    void removeTeacher(std::string, std::string,std::string);
    void removestudents(std::string, std::string);
    void swap1( Course_Node* ptr, Course_Node* ptr1);
    void sort();
    int CoursesizeCheck(std::string );
    Course_Node * getCourseListHead();
    Student_LinkedList *getStdListPtr();

    Course_Node* getLast ();
    Course_Node* getFirst ();
    void saveData();
    void readData();
    void display();
};

#endif