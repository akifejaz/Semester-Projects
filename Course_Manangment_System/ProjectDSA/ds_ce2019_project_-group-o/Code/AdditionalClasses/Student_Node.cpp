
#include "Student_Node.h"


Student_Node:: Student_Node(){

    // stdName = '\0';
    // stdID = '\0';
    // Next = nullptr;

}
Student_Node:: Student_Node(std::string n , std::string id) {

    
    stdName = n;
    stdID = id;
    Next = nullptr;

}

std::string Student_Node:: getStdNmame(){

    return stdName;

}

std::string Student_Node:: getStdID(){

    return stdID;

}

void Student_Node:: setStudents(std::string name, std::string ID){

    stdName = name;
    stdID = ID;

}

void Student_Node::setNext(Student_Node *ptr){

    Next = ptr;
}

Student_Node* Student_Node:: getNext(){

    return Next;
}
