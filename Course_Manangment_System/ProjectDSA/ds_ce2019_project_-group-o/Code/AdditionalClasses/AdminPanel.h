#include <iostream>
using namespace std;

#include "Admin.h"
#include "Teacher_LinkedList.h"

// Student_LinkedList std_obj;
Admin admin_obj;
// Student_LinkedList *std_ptr1 = new Student_LinkedList();
extern Student_LinkedList student_obj;
extern Student_Node std_Node;
int x,y,z;

extern Admin *ptr;
extern Admin admin_obj;


extern Teacher_Node *techer_ptr ;
extern Teacher_LinkedList techer_obj ;
// extern Student_Node *student_array;


#ifndef _AdminPanel_h
#define _AdminPanel_h

 


void adminPanel(){


        Admin* ptr = &admin_obj;
        Student_LinkedList *std_ptr1 = &student_obj;
        Teacher_Node *techer_ptr = techer_obj.getCurrentTeacherNode();

        int size;
        
    AdminPanel:
        int admin_choise;
        cout<<"\nYou are Logged in as Admin, Select the Action";
        cout<<"\n\t1-Add New Course \n\t2-Remove Course \n\t3-Add Teachers \n\t4-Replace Teacher \n\t5-Remove Teacher \n\t6-Specify Teacher \n\t7-Add Students \n\t8-Add Students in Course \n\t9-Remove Students Data \n\t10-Display Data \n\t11-Return to Main Menue \n\t12-Exit \n";
        cin>>admin_choise;

    
    switch (admin_choise)
    {
        case 1: {
            /* code */
            cin.ignore();
            std:: string std_name, std_ID, teac_name, teac_ID, cours_name,cours_ID;

            cout<<"\n\tCourse Add Menue \n\t";
            cout<<"\nFor creation of Course, You must add Course Info, Teacher info. and No. of students info you wanna add \n";
            
            //Taking Course Info. From Admin 
            cout<<"Enter Name of Course :";
            getline(cin,cours_name);
            cout<<"Enter Course ID :";
            getline(cin,cours_ID);

            //Taking Teacher Info. From Admin 

            teacher_again:
            cout<<"\nEnter Teacher ID :";
            getline(cin,teac_ID);
            
            //techer_obj 
            Teacher_Node *temp = techer_obj.getHead();

            while(temp!=nullptr){

                if (temp->getTeacherID()==teac_ID){

                techer_ptr = temp;
                break;
                }

                temp =temp->getNext();
            }
                
            if(temp==nullptr){

                cout<<"\nTeacher Entered is not preset in Teacher List Data :";
                goto teacher_again;

            }

            Student_Node *student_array = new Student_Node[10];
            //Taking Students Info. for particular course
            std_size:
            cout<<"\nHow many student you want to add ? ";
            cin>>size;
            
            if(size>10 || size <0){

                cout<<"\nOne Course can have 0 - 10 students only Max .";
                goto std_size;
            }

            cin.ignore();

            for (int i=0; i<size; i++){

            Student_again:
                cout<<"\nEnter Student ID : ";
                getline(cin,std_ID);

            //----------- Student Check -----------------//
            Student_Node *std_temp = std_ptr1->getHead();

            while(std_temp!=nullptr){

                if (std_temp->getStdID()==std_ID){

                    student_array[i] = *std_temp;
                    break;
                }

                std_temp = std_temp->getNext();
            }
                
            if(std_temp==nullptr){

                cout<<"\nStudent Entered is not Present in Student List Data :";
                goto Student_again;

            }
            //-------------------------------------------//

            } 

            
            admin_obj.creatCourse(cours_name,cours_ID, techer_ptr,student_array, size) ;

            

            // obj.display();

            cout<<"\n";
            goto AdminPanel;
            break;
            }
        case 2:
            {
            //Remove Course 
            std::string del_course;
            cout<<"\nRemove Course:";
            cin.ignore();
            cout<<"\nIn order to delete Course You Must need to provide Course ID :";
            getline(cin,del_course);

            admin_obj.deleteCourse(del_course);
            
            cout<<"\n";
            goto AdminPanel;
            break;
            }
        
        case 3:
            {
            cout<<"\nAdd Teachers : ";
            std::string teac_name,teac_ID;
            cin.ignore();
            //Taking Teacher Info. From Admin 
            cout<<"\nEnter Teacher Name :";
            getline(cin,teac_name);

            cout<<"\nEnter Teacher ID :";
            getline(cin,teac_ID);
            
            // techer_ptr = new Teacher_Node(teac_name,teac_ID);

            techer_obj.appendTeacher(teac_name,teac_ID);

            
            goto AdminPanel;
            break;

            }
        case 4:
          {
            std::string t_name, t_ID, cour_ID,pre_techID;
            cout<<"\nReplace Teacher:";
            cout<<"\nIn order to Replace Teacher, You Must need to provide Previous Teacher ID ";
            cout<<"\nand the New Teacher ID Also The Course ID (For you want to replace for) :";
            cout<<"\nEnter Previous Teacher ID :";
            cin.ignore();
            getline(cin,pre_techID);
            
            cout<<"\nEnter New Teacher Name :";
            getline(cin,t_name);
            cout<<"\nEnter New Teacher ID :";
            getline(cin,t_ID);
            cout<<"\nEnter Course ID :";
            getline(cin,cour_ID);

            admin_obj.replaceTeacher(pre_techID,t_ID,t_name,cour_ID);

            cout<<"\n";
            goto AdminPanel;
            break;
            }
        case 5: 
            {
            std::string x, y, z;
            cout<<"\nRemove Teacher:";
            cout<<"\nIn order to Remove Teacher, You Must need to provide Teacher ID ";
            cout<<"\nand the Course ID (For you want to remove for) :";
            cout<<"\nEnter Teacher ID  :";
            cin.ignore();
            getline(cin,x);
            cout<<"\nEnter Teacher Name :";
            getline(cin,y);
            cout<<"\nEnter Course ID :";
            getline(cin,z);

            admin_obj.removeTeacher(y,x,z);
            

            cout<<"\n";
            goto AdminPanel;

            break;

            }
        case 6:
            {
            std::string a, b,c;
            cout<<"\nSpecify Teacher:";
            cout<<"\nIn order to Specify Teacher, You Must need to provide Teacher ID ";
            cout<<"\nand the Course ID (For you want to Specify for) :";
            cout<<"\nEnter Teacher ID :";
            cin.ignore();
            getline(cin,a);
            cout<<"\nEnter Teacher Name :";
            getline(cin,b);
            cout<<"\nEnter Course ID :";
            getline(cin,c);

            admin_obj.specifyTeacher(b,a,c);

            cout<<"\n";
            goto AdminPanel;
            break;
            }
        case 7:
            {
            cout<<"\nAdd Students";

            size_again:
            cout<<"\nHow many student you want to add ? ";
            cin>>size; 
            if(size<0 || size >40){
                
                cout<<"\nOnly 0 - 40 students allowed Total ";
                goto size_again;
            }
            else if(size==0){

                break;
            }
            cin.ignore();

            std::string name , ID;// Student_LinkedList *temp = new Student_LinkedList;
            for (int i=0; i<size; i++){

                cout<<"\nEnter "<<i+1<<" Student Details :\n";

                cout<<"\nEnter Student Name : ";
                getline(cin,name);

                cout<<"\nEnter Student ID : ";
                getline(cin,ID);
                std_ptr1->CreatNewStudent(name, ID);

            } 

            cout<<"\n";
            goto AdminPanel;

            break;
            }

        case 8:
        {

            cout<<"\nAdd Students in Course";
            // AddStudents();
            admin_obj.AddStudentsIncourse();

            cout<<"\n";
            goto AdminPanel;

            break;

        }

        case 9:
        {   
            cout<<"\nRemove Students Data: \n";
            std::string stdID, cID;
            cin.ignore();

            cout<<"\nEnter Std ID : ";
            getline(cin,stdID);

            cout<<"\nEnter Course ID :";
            getline(cin,cID);

            admin_obj.removeStudents(cID,stdID);
            


            cout<<"\n";
            goto AdminPanel;

            break;
        }
        case 10:
            {
            cout<<"\nDisplay Data: \n";
            admin_obj.display();

            cout<<"\n";
            goto AdminPanel;

            break;
            }
        case 11:
            {
            cout<<"\nReturn To Main Menue: \n";
            
            x=1;
            break;
            }

        case 12:
            {
            cout<<"\nExit: \n";
            
            break;
            }

        default:
            {
            cout<<"\nInvalid Choice : ";
            cout<<"\n";
            goto AdminPanel;
            break;
            }
        }    



    }


 
#endif 