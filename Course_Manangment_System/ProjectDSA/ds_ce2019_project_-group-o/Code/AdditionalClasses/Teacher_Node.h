#include <string>
#ifndef _Teacher_Node_
#define _Teacher_Node_

class Teacher_Node
{
private:
    /* data */
    Teacher_Node *Next ; // Next pointer for linkedlist of course class
    int startTimeHour;
    int startTimeMin;
    int endTimeHour;
    int endTimeMin;

    int totalTime;
    std:: string teacherID;
    std:: string teacherName;

    

    //the course could have the following properties
    // Name , ID , Teacher , 

public:
    Teacher_Node(){}
    Teacher_Node(std::string , std::string); //Name + ID
    Teacher_Node(std::string , std::string, int , int , int , int) ;
    ~Teacher_Node() ;

    Teacher_Node *getNext();
    void setNext(Teacher_Node *);

    Teacher_Node * getThisTeacher(); //return teacher Node
    std::string getAvailableTime();

    int getStartHour();
    int getStartMin();
    int getEndHour();
    int getEndMin();

    std::string getTeacherID();
    std::string getTeacherName();
    void setTeacher(std::string, std::string);
    void setTiming(int , int , int , int);
    std::string getStartTime();
    std::string getEndTime();


};


#endif