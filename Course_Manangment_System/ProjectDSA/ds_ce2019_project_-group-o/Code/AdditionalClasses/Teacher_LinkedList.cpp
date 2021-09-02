#include <fstream>
#include <cstdio>
#include "Teacher_LinkedList.h"
// #include "Teacher_Node.h"
// #include "Student_Node.h"
// #include "Course_Node.h"
// class Teacher_Node;

// Teacher Node + StdList + stdNode +Course Node Header also Included Here 

Teacher_LinkedList techer_obj ;
#include <iostream>
using namespace std;

Teacher_LinkedList:: Teacher_LinkedList(/* args */) {

    head = nullptr;
    tail = nullptr;
    count = 0;

    // cout<<"\nread Data";
    // techer_obj.readTeacherData();

}
Teacher_LinkedList::   ~Teacher_LinkedList(){

    saveTeacherData();
}

void Teacher_LinkedList::appendTeacherNode(std::string teac_name, std::string teac_ID, int s_h, int s_m, int e_h, int e_m){
// // void Teacher_LinkedList::appendTeacherNode(Teacher_Node *ptr){
//     // cout<<"\n------Teacher Append Called :--------\n";
//     Teacher_Node *temp = new Teacher_Node(teac_name,teac_ID,s_h ,s_m ,e_h, e_m );

//     if(head == nullptr){

//             // head => null
//             // [ empty List ]  So, => "Add Node at end " 
//             // New Start Of NodeList =>we need,  head ? Tail ? 

//             // head => Presernt Input (Node) : Tail => Presernt Input (Node) 
//             //Next Pointer will be Null 
            
//             head = temp; 
//             temp->setNext(nullptr);
//             tail = temp ;
//         }

//         else{

//             // [ 1, 3, 4, 5 ] => Append (at end) 
//             //   head     tail
//             //tail->next = nullptr

//             tail->setNext(temp); // tail updated 
//             //tail->temp-> NUll
//             // [ 1, 3, 4, 5 , temp ] => Append (at end) 
//             //  head          tail
//             temp->setNext(nullptr);

//             //data provide
            
//             tail = temp;
            
  
//         }

//     count += 1;


}

Teacher_Node * Teacher_LinkedList:: getHead(){

    return head;
}
void Teacher_LinkedList::appendTeacher(std::string teac_name, std::string teac_ID){

    // cout<<"\n------Teacher Append Called :--------\n";
    Teacher_Node *temp = new Teacher_Node(teac_name,teac_ID);

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


}

Teacher_Node * Teacher_LinkedList:: getCurrentTeacherNode(){

    Teacher_Node * temp = head ; //Teacher_Node * temp1 = temp;
    
    return tail;

}



void Teacher_LinkedList:: spacifyTime(int s_h, int s_m, int e_h, int e_m){

    Teacher_Node *temp; 
    temp->setTiming(s_h ,s_m ,e_h, e_m );

}

void  Teacher_LinkedList:: SpacifyTime( std::string ID, int s_t_hours , int s_t_minuts , int e_t_hours, int e_t_minuts ){

    Teacher_Node *temp = head;

    if (head==nullptr | count==0){

        cout<<"There is No Teacher Data Yet :";
        return;
    }

    while(temp!=nullptr){

        if(temp->getTeacherID()==ID){

            cout<<"\nTeacher Exists :";
            cout<<"\nTeacher Name : "<<temp->getTeacherName();

            temp->setTiming(s_t_hours ,s_t_minuts ,e_t_hours, e_t_minuts);
            
            return;
        }

        temp = temp->getNext();
    }

    cout<<"\nNo Teacher With this ID Exist :";
    return;
}

void Teacher_LinkedList:: display(){


    Teacher_Node *temp = head;

    if (head==nullptr | count==0){

        cout<<"\nThere is No Teacher Data :";
        return;
    }

    if (temp==nullptr){

        cout<<"No Teacher Data Available at this Moment \n";
    }
    else {

        int i=1;
        cout<<"\nTotal Teachers  :"<<count<<endl;
        while(temp!= nullptr)
        {
    
            cout<<"Name of  Teacher : ["<<temp->getTeacherName()<<"] ";
            cout<<"Teacher  ID      :  [" <<temp->getTeacherID()<<"] ";
            cout<<"Available Time : From ["<<temp->getStartTime() <<"]" <<" To ["<<temp->getEndTime()<<"]";
            cout<<" \n ";
        
            temp = temp->getNext();
        }
            cout <<endl;
    }
}

void Teacher_LinkedList:: addStudents(std::string cour_ID, Student_Node * ptr , int size){

    course_ptr->addStudents(cour_ID, ptr, size);
    
}

int Teacher_LinkedList :: CourseizeCheck(std::string ID){

    return course_ptr->CoursesizeCheck(ID);
}

void Teacher_LinkedList::deleteNode(std:: string ID){

    Course_LinkedList *temp; Course_Node *temp1 = temp->getCourseListHead();
    Student_Node *temp2 = temp1->getHead(); Student_LinkedList *temp3;

    //----------- Delete Node of Student ----------
    

    //--------------------------------------------

}

void Teacher_LinkedList:: removeStudents(std::string c_ID, std::string s_ID){


    Course_LinkedList *temp; 
    temp->removestudents(c_ID, s_ID);
    // Course_Node *temp1 = temp->getCourseListHead();
    // Student_Node *temp2 = temp1->getHead(); 
    // Student_LinkedList *temp3 ;

    // while (temp1!=nullptr)  //Curse Node 
    // {
    //     /* code */
    //     if(temp1->getCourseID()==c_ID){

    //         cout<<"\nCourse With This ID Exsits:";
    //         // temp3 = temp1->getStudentList();

    //         while(temp2!=nullptr){


    //             if(temp2->getStdID()==s_ID){
    //                 cout<<"\nStudent with this ID Exists ";

    //                 temp3->removeStudent(s_ID);
                    
    //                 return;
    //             }

    //             temp2 = temp2->getNext();
                
    //         }


            

    //     }
    //     temp1 = temp1->getNext();
    // }

    // cout<<"\nNo course With this ID exists :";
    // return;
    

}

void Teacher_LinkedList:: saveTeacherData(){

    //Saviing Teacher List in "TeacherData"
    Teacher_Node *temp = head;

    fstream file;

    file.open("TeacherData.txt", ios::out | ios::app);

    if(!file){

        cout<<"\nFile 'TeacherData.txt' Opened Failed ";
        return;
    }

    //Teacher List -- Loop through Every Node of List
    while(temp!=nullptr){


        file.write((char*)&temp, sizeof(temp));

        temp = temp->getNext();
    }

    cout<<"\nData Written Sussesfully ! ";
    
    file.close();

}

void Teacher_LinkedList:: readTeacherData(){

//     // Teacher_LinkedList *temp = this; 
    Teacher_Node *tempNode = new Teacher_Node;

    fstream file;
    file.open("TeacherData.txt", ios::in);
    if(!file){

        cout<<"\nFile Opened Failed ";
    }

    file.seekg(0, ios::beg);

    while(file.read((char*)&tempNode, sizeof(Teacher_Node))){ //
//     //     //End of File Loop 
//     //     //Read for objects 
//         // file.read((char*)&tempNode, sizeof(tempNode));

       appendTeacherNode(tempNode->getTeacherName(),tempNode->getTeacherID(), tempNode->getStartHour(), tempNode->getStartMin(),tempNode->getEndHour(), tempNode->getEndMin());
//         // temp->appendTeacherNode(tempNode);
        

   }

    remove("TeacherData.txt");
    file.close();

}


void Teacher_LinkedList::swap1( Teacher_Node* ptr, Teacher_Node* ptr1){

std::string temp, temp1; 
temp = ptr->getTeacherID();
temp1 = ptr->getTeacherName();

ptr->setTeacher(ptr1->getTeacherName(),ptr1->getTeacherID());
ptr1->setTeacher(temp1,temp);


}

void Teacher_LinkedList:: sort(){

    cout<<"Sort Called ";
    for ( Teacher_Node *temp = head ; temp->getNext()!=nullptr; temp = temp->getNext() )
    {
        for (Teacher_Node *temp1 = temp; temp1 != nullptr; temp1 = temp1->getNext())
        {
            if (temp->getTeacherID() > temp1->getTeacherID())
            {

                swap1(temp, temp1);
                
                
            }
        }
    }
}