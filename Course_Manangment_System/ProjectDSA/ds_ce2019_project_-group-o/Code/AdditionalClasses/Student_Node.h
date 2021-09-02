#include <string>
#ifndef _Student_Node_
#define _Student_Node_


class Student_Node
{
private:
    /* data */
    std::string stdName;
    std::string stdID;
    Student_Node * Next;

public:
    Student_Node();
    Student_Node(std::string , std::string) ;
    ~Student_Node() {}

    std::string getStdNmame();
    std::string getStdID();
    void setNext(Student_Node *);
    void setStudents(std::string , std::string);
    
    Student_Node* getNext();
};
#endif