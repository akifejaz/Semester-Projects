#include <iostream>
#include <fstream>
using namespace std;


#include "AdditionalClasses/AdminPanel.h"
#include "AdditionalClasses/TeacherPanel.h"
#include "AdditionalClasses/StudentPanel.h"

Course_LinkedList course_list;
extern Admin admin_obj;

int main() {
// Write your driving code here

//Dashbord --> User Interface 


int choise ;

    cout<<"\n\t\t\t=================================\n";
    cout<<"\t\t\t||        W E L L C O M E       ||\n";
    cout<<"\t\t\t||   COURSE MANAGEMENT SYSTEM   ||\n";
    cout<<"\t\t\t==================================\n\n";

// admin_obj.readData();
MainMenue:
cout<<"\nSelect Your Roll , Enter 1 , 2 or 3  \n\n";
cout<<"\n\t1- Admin \n\t2- Teacher \n\t3- Student \n\t4- Exit\n";

cin>>choise;
    
    switch (choise)  {
    case 1:
        // code to be executed if 
        //Admin Roll
        cout << "\t\t\t================================\n";
        cout << "\t\t\t||    A D M I N  P A N E L    ||\n";
        cout << "\t\t\t================================\n";

        adminPanel();
        if(x==1){

            x=0;
            goto MainMenue;
        }

        break;

    case 2:
        // code to be executed if
        //Teacher ROl
        cout << "\t\t\t================================\n";
        cout << "\t\t\t||  T E A C H E R  P A N E L || \n";
        cout << "\t\t\t================================\n";
        teacherPanel();

        if(y==1){

            y=0;
            goto MainMenue;
        }

        break;
    case 3:
        {
        // code to be executed if
        //Student Roll
        cout << "\t\t\t================================\n";
        cout << "\t\t\t||  S T U D E N T  P A N E L || \n";
        cout << "\t\t\t================================\n";
        studetPanel();

        if(z==1){

            z=0;
            goto MainMenue;
        }

        break;        
        }

    case 4: 
    {
        

        cout<<"Exit";
        break;
    }
    default:
        // code to be executed if

        cout<<"\nInvalid Choice ";
        goto MainMenue;
    }

    cout<<"\nSaving File:";
    return 0;
}
