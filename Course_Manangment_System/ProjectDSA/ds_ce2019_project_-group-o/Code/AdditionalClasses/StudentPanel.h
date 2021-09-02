#ifndef _studentPanel_h
#define _studentPanel_h


Student_LinkedList student_obj;
Student_Node std_Node;


void studetPanel(){

    StudentPanel:
        int Student_choise;

        cout<<"\nYou are Logged in as teacher, Select the Action";
        cout<<"\n\t1-Reserve available time slot \n\t2-Message in the Course Group \n\t3-Delete Msgs \n\t4-Cancel Resrvation \n\t5-Sort Student List \n\t6-Display Students Data \n\t7-Return To main Menue \n\t8-Exit \n";
        cin>>Student_choise;
        cin.ignore();

        switch (Student_choise)
        {
        case 1:
        {
            cout<<"\nReserve available time slot ";
            /* code */


            goto StudentPanel;
            break;
        }

        case 2:
        {
            cout<<"\nMessage in the Course Group ";
            /* code */

            goto StudentPanel;
            break;
        }
        
        case 3:
        {
            cout<<"\nDelete Msgs ";
            /* code */

            goto StudentPanel;
            break;
        }

        case 4:
        {
            cout<<"\nCancel Resrvation ";
            /* code */

            goto StudentPanel;
            break;
        }

        case 5:
        {
            cout<<"\nSort Student List ";
            /* code */
            student_obj.sort();

            goto StudentPanel;
            break;
        }

        case 6:
        {
            cout<<"\nDisplay Students Data\n";
            /* code */
            student_obj.display();

            goto StudentPanel;
            break;
        }

        case 7:
        {
            cout<<"\nReturn To main Menue ";
            /* code */

            z=1;
            break;
        }

        case 8:
        {
            cout<<"\nExit";
            /* code */

            break;
        }
        
        default:

            cout<<"\nInvalid Choice !";
            goto StudentPanel;
            break;
        }
}

#endif