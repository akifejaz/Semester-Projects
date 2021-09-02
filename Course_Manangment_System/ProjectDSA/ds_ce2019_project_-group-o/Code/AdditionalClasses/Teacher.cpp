#include <iostream>
using namespace std;

#include "Teacher.h"
#include <string>
extern Teacher_LinkedList techer_obj ;



void Teacher:: SpacifyTime(std::string ID, int s_t_hours , int s_t_minuts , int e_t_hours, int e_t_minuts){

    obj = &techer_obj;
    obj->SpacifyTime(ID, s_t_hours ,s_t_minuts ,e_t_hours, e_t_minuts);

}

void Teacher::display(){

    
    obj = &techer_obj;
    obj->display();
}

void Teacher:: addStudents(std::string ID , Student_Node* ptr , int size){

    // Course_Node *temp = head;
    // Student_Node * temp1 =temp->getHead();
    obj->addStudents(ID,ptr, size);
    
}

int Teacher:: CoursesizeCheck(std::string courseID){

    return obj->CourseizeCheck(courseID) ;

}
void Teacher:: removeStudents(std::string c_ID, std::string s_ID){

    obj = &techer_obj;
    obj->removeStudents( c_ID,  s_ID );
}

void Teacher:: sortList(){

    obj = &techer_obj;
    obj->sort();


}

