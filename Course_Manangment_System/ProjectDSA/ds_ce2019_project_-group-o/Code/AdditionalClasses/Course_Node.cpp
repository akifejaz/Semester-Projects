#include "string.h"
#include <iostream>
using namespace std;

#include "Course_Node.h"

Course_Node:: Course_Node(std::string n, std::string id, Teacher_Node * ptr2, Student_Node* ptr, int s) {

courseName = n;
courseID = id;
// teacher = teach;
// teacherID = teachID;
te_ptr = ptr2;
std_list = ptr;
size = s;
Next = nullptr;
//setting initally values of course

// name = '\0';
// courseID = '\0' ;
// count = 0;
// Next = nullptr;

//But we also have to store these data
// there for we will read data from our directories
// first and then move forward with program

}
Course_Node:: ~Course_Node() {


}
void Course_Node:: setData(std::string CName, std::string CID, Student_Node *ptr , Teacher_Node* ptr1, int siz){

    courseName = CName;
    courseID = CID;
    te_ptr  = ptr1;
    std_list = ptr;
    size = siz;
}
int Course_Node:: getSize(){

    return size;
}

Student_Node*  Course_Node:: getHead (){

    return std_list;

}

void  Course_Node:: setSize(int n ){

    size = n;
}

Course_Node * Course_Node:: getNext(){

    return Next;

}

void Course_Node:: setNext(Course_Node *ptr){

    Next = ptr;

}

std::string Course_Node:: getCourseName(){

    return courseName;
}
std:: string Course_Node:: getCourseID(){

    return courseID;

}

Teacher_Node *  Course_Node:: getTeacher(){

    return te_ptr;
}

// std::string  Course_Node:: getTeacherID(){

//     return teacherID;
// }

Student_Node* Course_Node:: getStudentList(){

    return std_list;

}

void Course_Node:: setStudentList(Student_Node* ptr){

    std_list = ptr;
}

void Course_Node:: setTeacher(std::string name , std::string ID){

    te_ptr->setTeacher(name,ID);
}

void Course_Node:: setTeacherNode(Teacher_Node *ptr){

    te_ptr = ptr;
}

// Course_Node *  Course_Node:: getCourseListHead(){

//     return head;
// }
