
#include <string>
#ifndef _teacherPanel_h
#define _teacherPanel_h

#include "Teacher.h" // Teacher List , course Node ,LIst + std Ndoe ,List + teacher Node

Teacher t_obj;
// // extern int x,y,z;
extern Teacher t_obj;
extern Teacher_LinkedList techer_obj ;
extern Admin admin_obj ;
extern Student_LinkedList student_obj;

// extern Teacher * teac_ptr;

void teacherPanel(){

        
    TeacherPanel:
        int teacher_choise; Teacher * teac_ptr = &t_obj;
        Teacher_LinkedList *temp = &techer_obj;
        Admin *adminPtr = &admin_obj;
        Student_LinkedList *std_ptr1 = &student_obj;
        

        cout<<"\nYou are Logged in as teacher, Select the Action";
        cout<<"\n\t1-Add Availabe Time \n\t2-Cancel Reservation \n\t3-Add Students in Course \n\t4-Remove Studetns \n\t5-Msg In Group \n\t6-Delete Msg \n\t7-Sort List \n\t8-Return To main Menue \n\t9-Display Teachers Data \n\t10-Exit \n";
        cin>>teacher_choise;
        cin.ignore();


        switch (teacher_choise)
        {
        case 1:
            /* code */
            {
                int sTimeHour, sTimeMin, eTimeHour, eTimeMin; std::string teach_ID;
            cout<<"\nAdd Available Time :";
            cout<<"\nFor adding Available time You Must need to provide Start Time & End Time also Your Teacher ID";
            cout<<"\nEnter Teacher ID :";
            getline(cin,teach_ID);
            

            again1:
            cout<<"\nEnter Start Time Hour :";
            cin>>sTimeHour;
            if(sTimeHour>12 /*|| sTimeHour<=0*/){

                cout<<"\nStart Hours Must be Less than or equal 12 :";
                goto again1;
            }

            again2:
            cout<<"\nEnter Start Time Minuts :";
            cin>>sTimeMin;
            if(sTimeMin>59 /*|| sTimeMin<=0*/){

                cout<<"\nStart Hours Must be Less than or equal 59 :";
                goto again2;
            }

            again3:
            cout<<"\nEnter End Time Hours :";
            cin>>eTimeHour;
            if(eTimeHour>12 /*|| eTimeHour<=0*/){

                cout<<"\nEnd Hours Must be Less than or equal 12 :";
                goto again3;
            }

            again4:
            cout<<"\nEnter End Time Minuts :";
            cin>>eTimeMin;
            if(eTimeMin>59 /*|| eTimeMin<=0*/){

                cout<<"\nEnd Hours Must be Less than or equal 59 :";
                goto again4;
            }

            
            t_obj.SpacifyTime(teach_ID,sTimeHour,sTimeMin,eTimeHour,eTimeMin);
            // teac_ptr->SpacifyTime("teach_ID",3,3,3,3);
            temp->display();

            goto TeacherPanel;
            break;

            }
        case 2:
            {
            cout<<"\nCancel Reservation";

            
            goto TeacherPanel;
            break;
            }

        case 3:
            {
            cout<<"\nAdd Students in Course";
            admin_obj.AddStudentsIncourse();

            cout<<"\n";
            goto TeacherPanel;

            break;

        }
        case 4:
            {
            cout<<"\nRemove Studetn";
            cout<<"\nTo Remove student Enter class ID & ID of studenst :";
            std::string std_ID, course_ID; 
            cout<<"\nEnter course ID :";
            getline(cin,course_ID);
            cout<<"\nEnter Student ID :";
            getline(cin,std_ID);

            t_obj.removeStudents(course_ID,std_ID);

            goto TeacherPanel;
            break;
            }
        case 5:
            {
            cout<<"\nMsg In Group ";

            goto TeacherPanel;
            break;

            }

        case 6:
            {
            cout<<"\nDelete Msg ";

           goto TeacherPanel; 
           break;

           }

        case 7:
            {
            cout<<"\nSort List ";
            t_obj.sortList();

            goto TeacherPanel;
            break;

            }

        case 8:
            {
            cout<<"\nReturn To main Menue\n";

            
            y = 1;
            break;

            }
        case 9:
            {
            cout<<"\nDisplay Teachers Data";
            temp->display();

            
            goto TeacherPanel;
            break;
            }

        case 10:
            {
            cout<<"\nExit";


            break;
            }
        default:

            cout<<"\nInvalid Choice :";

            goto TeacherPanel;
            break;
        }
}

#endif

