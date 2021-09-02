#include <fstream>
#include <iomanip>

#include <iostream>
using namespace std;

// class Teacher_LinkedList;
#include "Course_LinkedList.h"
// extern Teacher_LinkedList techer_obj ;


Course_LinkedList :: Course_LinkedList(/* args */) {

    head = nullptr;
    tail = nullptr;
    count = 0 ;

    //Trying to Read From Files 

    cout<<"\nPlease Wait Loading Data ...";
     // Reading Data With this obj

    //We have three  main Classes that need to be stored in file & Read Back Too

    //First Reading Teacher Data 



    //Reading Student Data

    //Reading Course Data 

}
Course_LinkedList:: ~Course_LinkedList(){


}
void Course_LinkedList:: CreatNewCourse (std::string n, std::string  id, Teacher_Node * ptr2, Student_Node* ptr, int size){

    // append newCourse with paramentrs name & ID
    // obj = ptr;
    //We want to append the Node "Add Node at the end of previous NodeList"
    Course_Node *temp = new Course_Node(n, id, ptr2, ptr, size);
        // argumnets are the present values and we are pointing that with "temp" ptr
    
        if(head == nullptr){

            // head => null
            // [ empty List ]  So, => "Add Node at end " 
            // New Start Of NodeList =>we need,  head ? Tail ? 

            // head => Presernt Input (Node) : Tail => Presernt Input (Node) 
            //Next Pointer will be Null 
            
            head = temp; 
            temp->setNext(nullptr);
            tail = temp ;
        }

        else{

            // [ 1, 3, 4, 5 ] => Append (at end) 
            //   head     tail
            //tail->next = nullptr

            tail->setNext(temp); // tail updated 
            //tail->temp-> NUll
            // [ 1, 3, 4, 5 , temp ] => Append (at end) 
            //  head          tail
            temp->setNext(nullptr);

            //data provide
            
            tail = temp;
            
  
        }

    count += 1;

    // int size;
    // cout<<"\n How many student you want to add ? ";
    // cin>>size;
    // std:: string na, na_id;
    // for (int i=0; i<size; i++){

    //     cout<<"\nEnter "<<i<<" Student Details :\n";

    //     cout<<"\nEnter Student Name : ";
    //     cin>>na;

    //     cout<<"\nEnter Student ID : ";
    //     cin>>na_id;

    //     obj.CreatNewStudent (na, na_id);

    // }

}  
void Course_LinkedList:: prepend (std::string , std::string){


}


void Course_LinkedList:: addStudents(std::string ID, Student_Node *ptr, int size){

    Course_Node *temp = head; Student_Node *temp2; 

    // Student_Node *temp1 = ptr->getHead();
    // int len = sizeof(arr)/sizeof(arr[0]);

    if (head==nullptr | count==0){

        cout<<"There is No Course Created Yet :";
        return;
    }

    while (temp!=nullptr)
    {
        /* code */
        if(temp->getCourseID()==ID){

            // cout<<"\nCourse Exists:";
            temp2 = temp->getStudentList();
            
            int n = temp->getSize();

            if(n+size>10){

                cout<<"\nCourse Cannot Have More 10 Students";
                return;
            }

            for(int i=0; i<size; i++){

                temp2[n].setStudents(ptr[i].getStdNmame(), ptr[i].getStdID());
                n = n+1;
            }
            
            temp->setSize(n);
            return;
            
        }

        temp =temp->getNext();
    }

    cout<<"\nNo Course With this ID Exists";
    return;
    
}

int Course_LinkedList:: CoursesizeCheck(std::string ID){

    Course_Node *temp = head;
    if (head==nullptr | count==0){

        cout<<"There is No Course Created Yet :";
        return -1;
        
    }

    while (temp!=nullptr) 
    {
        /* code */
        if(temp->getCourseID()==ID){

            return temp->getSize();
        }

        temp = temp->getNext();

    }

    return -1;
    

}

void Course_LinkedList:: removeTeacher(std::string teach_name, std::string teach_ID, std::string course_ID){

    Course_Node *temp = head;  Teacher_Node *temp1;
    if (head==nullptr | count==0){

        cout<<"There is No Course Created Yet :";
        return;
    }

    while (temp!=nullptr)
    {   
        cout<<"\nCourse ID "<<temp->getCourseID()<<" Teacher ID :" <<temp->getTeacher()->getTeacherID();

        if(temp->getCourseID()==course_ID){
            cout<<"Teacher Exists :";

            if(temp->getTeacher()->getTeacherID()==teach_ID || temp->getTeacher()->getTeacherName()==teach_name){

                cout<<"Course Exist with ["<<temp->getCourseID()<<"] Course ID & Teacher ID ["<<temp->getTeacher()->getTeacherID()<<"] ";
                temp->setTeacher("N/A", "N/A");
                temp1 = temp->getTeacher(); 
                temp1->setTiming(0,0,0,0);
                return;
                                
            }
            else {

                cout<<"\nERROR : The Teacher Exists In Course List But Not Linked With YOur Given Course ID :";
                cout<<"\nTeacher Replace Failed :";
                return;
            }

            return;
        }

        temp = temp->getNext();
    }

    cout<<"Teacher is not linked With any course Yet:";
    return;


}
 

void Course_LinkedList:: replaceTeacher(std::string pre_teac, std::string new_teachID, std::string teachname, std::string coursID){

//First of all let's check if Teacher Exist in our data base or not
    Course_Node *temp = head;
    if (head==nullptr | count==0){

        cout<<"There is No Course Created Yet :";
        return;
    }

    while (temp!=nullptr)
    {
        // cout<<"\nTeacher ID :"<<temp->getTeacher()->getTeacherID();
        if(temp->getTeacher()->getTeacherID()==pre_teac){
            cout<<"Teacher Exists :";

            if(temp->getCourseID()==coursID){

                cout<<"Course Exist with ["<<temp->getCourseID()<<"] Course ID & Teacher ID ["<<temp->getTeacher()->getTeacherID()<<"] ";
                temp->setTeacher(teachname, new_teachID);
                                
            }
            else {

                cout<<"\nERROR : The Teacher Exists In Course List But Not Linked With YOur Given Course ID :";
                cout<<"\nTeacher Replace Failed :";
                return;
            }

            return;
        }

        temp = temp->getNext();
    }

    cout<<"Teacher is not linked With any course Yet:";
    return;
    

}

void Course_LinkedList:: deleteCourse (std::string del_course){

    
    Course_Node *temp = head;
    if (head==nullptr | count==0){

        cout<<"There is No Course Created Yet :";
        return;
    }

    if(temp->getCourseID()==del_course){

    //If true means we have to remove head 
    // shift head to next

        head = head->getNext();
        delete temp;

    }
    else if (tail->getCourseID()==del_course) {
    
    //If true means we have to remove tail
    // remove last update tail
        while(temp->getNext()!=tail) { // temp->getNext()->getNext==nullptr

                temp = temp->getNext();
        }

    //Now When loop will be end "temp" will be having the address of second last Node of NodeList
        tail = nullptr;
        delete tail;
    
        temp->setNext(nullptr);
        tail = temp;

    }

    else {

        //data is in between list Not first or last
    
        while(temp!=tail){

            if(del_course == temp->getNext()->getCourseID()){
            
                cout<<"Matched ";
                // temp = temp->getNext();
                temp->setNext(temp->getNext()->getNext());
                return ;
            
            }
            temp = temp->getNext();
        }

        cout<<"Element is not in list:";
        return ;


    }

    
    count -= 1; // course delted 
}


Course_Node* Course_LinkedList:: getLast (){


}

Course_Node* Course_LinkedList:: getFirst (){


}

void Course_LinkedList:: display(){

    Course_Node *temp = head; 
    // Student_LinkedList * std_ptr;

    
    if (temp==nullptr){

        cout<<"No Course Data Available at this Moment \n"<<endl;
    }
    else {

        size_t fieldWidth = 20; // length of longest text
        
        cout<<"\nTotal No. of Courses : "<<count<<endl;
        cout<<"\nName of Course ";
        cout<<"\tCourse ID ";
        cout<<"\tName of Teacher " ;
        cout<<"\tTeacher ID \n" ;
        while(temp!= nullptr)
        {
            
            
            cout<<setw(fieldWidth) << left <<temp->getCourseName()<<" ";
            cout<<setw(fieldWidth) << left <<temp->getCourseID()<<" ";

            cout<<setw(fieldWidth) << left <<temp->getTeacher()->getTeacherName()<<" ";
            cout<<setw(fieldWidth) << left <<temp->getTeacher()->getTeacherID()<<" ";

            cout<<" \n "<<endl;

            
            Student_Node * temp1 = temp->getStudentList();
            // Student_LinkedList *temp2 = temp->getStudentList();
            //--------Student Display --------
            int len = temp->getSize();
            if (len== 0){

                cout<<"No Student Data Available at this Moment \n\n";
            }
            else {


            cout<<"\nTotal Students For this Course :"<<temp->getSize()<<endl;
            cout<<"\nName Of Student \tStudent ID\n";

            for (int i=0; i<len; i++){

                cout<<temp1[i].getStdNmame()<<"\t\t";
                cout<<temp1[i].getStdID()<<"\t ";
                cout<<" \n ";   
            }
            // while(temp1!= nullptr)
            // {
                
               
            //     cout<<temp1->getStdNmame()<<"\t\t";
            //     cout<<temp1->getStdID()<<"\t ";
            //     cout<<" \n ";
        
            //     temp1 = temp1->getNext();
            // }
                cout <<endl;
            }

            temp = temp->getNext();

        }
    }



    
    
}

void Course_LinkedList:: readData(){

    
}

void Course_LinkedList:: saveData(){



}

void Course_LinkedList:: specifyTeacher(std::string name , std::string ID, std::string course_ID){

    Course_Node *temp = head;
    if (head==nullptr | count==0){

        cout<<"There is No Course Created Yet :";
        return;
    }

    while (temp!=tail)
    {
        if(course_ID==temp->getCourseID()){

            temp->setTeacher(name, ID);
            return;
        }
        
        temp = temp->getNext();
    }

    cout<<"Course is not in list ";
    return ;
    

}

Course_Node * Course_LinkedList::getCourseListHead(){

    return head; 
}

void Course_LinkedList:: removestudents(std::string ID, std::string ID1){

    Course_Node *temp = head;

    while (temp!=nullptr)
    {
        /* code */
        if(temp->getCourseID()==ID){

            Student_Node *temp1 = temp->getStudentList();
            int n = temp->getSize();
            
            for (int i = 0; i < n; i++)
            {
                /* code */
                if(temp1->getStdID()==ID1){

                    temp1->setStudents("N/A","N/A");
                    break;
                }

                temp1 = temp1->getNext();
            }
            
        }

        temp = temp->getNext();
    }
    
}


void Course_LinkedList:: swap1( Course_Node* ptr, Course_Node* ptr1){

std::string temp, temp1;  Student_Node *temp3; Teacher_Node *temp4; int size;

temp = ptr->getCourseID();
temp1 = ptr->getCourseName();
temp3 = ptr->getStudentList();
temp4 = ptr->getTeacher();
size = ptr->getSize();

ptr->setData(ptr1->getCourseName(), ptr1->getCourseID(), ptr1->getStudentList(), ptr1->getTeacher(), ptr1->getSize());
ptr1->setData(temp1, temp,temp3, temp4,size);


}

void Course_LinkedList:: sort(){

    // cout<<"Sort Called ";
    for ( Course_Node *temp = head ; temp->getNext()!=nullptr; temp = temp->getNext() )
    {
        for (Course_Node *temp1 = temp; temp1 != nullptr; temp1 = temp1->getNext())
        {
            if (temp->getCourseID() > temp1->getCourseID())
            {

                swap1(temp, temp1);
                
                
            }
        }
    }
}