
#ifndef _Student_LinkedList_
#define _Student_LinkedList_

class Student_Node;
#include <string>

class Student_LinkedList
{
private:
    /* data */
    Student_Node *head;
    Student_Node *tail;
    int count; 
    

public:
    Student_LinkedList(/* args */) ;
    ~Student_LinkedList();
    void CreatNewStudent (std::string , std::string );  // append newCourse with paramentrs name & ID
    
    Student_Node* getLast ();
    Student_Node* getHead ();
    void removeStudent(std::string);
    void saveData();
    Student_LinkedList* readData();
    void sort();
    void swap1( Student_Node* ptr, Student_Node* ptr1);
    void display();
    int getcount();
};

#endif