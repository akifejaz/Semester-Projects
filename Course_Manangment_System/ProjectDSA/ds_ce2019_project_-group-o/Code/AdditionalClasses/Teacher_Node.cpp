#include "string.h"
#include "Teacher_Node.h"

Teacher_Node::Teacher_Node(std::string name, std::string ID){

 teacherName = name;
 teacherID = ID;

 startTimeHour = 0;
 startTimeMin = 0;

 endTimeHour = 0;
 endTimeMin = 0;

}

Teacher_Node:: Teacher_Node(std::string n, std::string id, int s_t_H , int s_t_M, int e_t_H , int e_t_M ) {

    teacherName = n;
    teacherID = id;

    startTimeHour = s_t_H;
    startTimeMin = s_t_M;

    endTimeHour = e_t_H;
    endTimeMin = e_t_M;

}
Teacher_Node:: ~Teacher_Node() {


}

Teacher_Node * Teacher_Node:: getNext(){

    return Next;

}

void Teacher_Node:: setNext(Teacher_Node *ptr){

    Next = ptr;

}

void  Teacher_Node::setTiming(int s_t_hours , int s_t_minuts , int e_t_hours, int e_t_minuts){

    startTimeHour = s_t_hours;
    startTimeMin = s_t_minuts;

    endTimeHour = e_t_hours;
    endTimeMin = e_t_minuts;


}

int Teacher_Node:: getStartHour(){

    return startTimeHour;
}
int Teacher_Node:: getStartMin(){

    return startTimeMin;
}
int Teacher_Node:: getEndHour(){
    
    return endTimeHour;
}
int Teacher_Node:: getEndMin(){

    return endTimeMin;

}

std::string Teacher_Node::getTeacherID(){

    return teacherID;
}

std::string Teacher_Node:: getTeacherName(){

    return teacherName;

}

void  Teacher_Node::setTeacher(std::string name, std::string id){

    teacherName = name;
    teacherID = id;
}

std::string Teacher_Node:: getStartTime(){

    std::string sTimeH,sTimeM;

    sTimeH = std::to_string(startTimeHour);
    sTimeM = std::to_string(startTimeMin);

    return (sTimeH + " : " + sTimeM);
}

std::string Teacher_Node:: getEndTime(){

    std::string eTimeH,eTimeM;

    eTimeH = std::to_string(endTimeHour);
    eTimeM = std::to_string(endTimeMin);

    return (eTimeH + " : " + eTimeM);

}



