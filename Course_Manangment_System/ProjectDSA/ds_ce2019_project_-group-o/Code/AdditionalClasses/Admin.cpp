
#include <iostream>
using namespace std;
#include <fstream>
#include "Admin.h"


Admin ::Admin(){


}

Admin ::~Admin(){


}

void Admin :: AddStudentsIncourse(){

      std::string  s_Name, c_ID, std_ID; int n=0;
            
            
            agin_input:
            cout<<"\nHow many students you want to add ?";
            cin>>n;
            cin.ignore();

            //------------Some Exeptions/ Boundry Cases -----------------//
            if(n<0 || n>10){

                cout<<"\n Cannot Add beyond 0 -- 10";
                goto agin_input;
            }
            Student_Node *arr = new Student_Node[n];

            courseIDagain:
            cout<<"\nEnter Course ID : ";
            getline(cin,c_ID);

            int len = CourseSizeCheck(c_ID);
            if (len==-1){

                cout<<"\nCourse doest not exist with your ID";
                goto courseIDagain;
            }
            else {

                if(len+n>10){

                    cout<<"\nStudents should not More than 10 ";
                    cout<<"\nThere are already "<<len<<" Students Present";
                    goto agin_input;
                }
            }
            //------------Some Exeptions/ Boundry Cases -----------------//

            for (int i=0; i<n; i++){

            Student_a:
                cout<<"\nEnter Student ID : ";
                getline(cin,std_ID);

            //----------- Student Check -----------------//
            Student_Node *std_temp = student_obj.getHead();

                while(std_temp!=nullptr){

                    if (std_temp->getStdID()==std_ID){

                        arr[i] = *std_temp;
                        break;
                    }

                    std_temp = std_temp->getNext();
                }
                
                if(std_temp==nullptr){

                    cout<<"\nStudent Entered is not Preset in Student List Data :";
                    goto Student_a;

                }

                cout<<"\nSize :"<<n<<endl;
                addstudents(c_ID,arr,n);

            //-----------check ---------------

            }

}


void Admin ::creatCourse(std::string n, std::string id, Teacher_Node * ptr2, Student_Node* ptr, int size){

    //get course info.
    course_obj->CreatNewCourse (n,id,ptr2 ,ptr, size);

    
}

void Admin :: removeStudents(std::string ID, std::string ID1){

    course_obj->removestudents(ID,ID1);

}

void Admin::display(){

    course_obj->display();

}

// void Admin::saveData(){

//     // course_obj->saveData();

//     //Here We have Course Obj "Basically Has Acces to all the data "
//     Course_LinkedList *ptr = course_obj; 
//     Student_LinkedList *stdPtr ; Student_Node* stdNode;
//     Teacher_Node *tecNode;
//     Course_Node *ptrNode = ptr->getCourseListHead();

//     remove("ProgramData.txt");

//     fstream file;
//     file.open("ProgramData.txt", ios::out | ios::app);

//     if(!file){

//         cout<<"\nFile Opened Failed ";
//         return;
//     }

//     // std::string a,b,c,d;
//     while(ptrNode!=nullptr) {  //course Node -> Null 

    	
//     // a = ptrNode->getCourseID();
//     // b = ptrNode->getCourseName();
//     // c = ptrNode->getTeacher()->getTeacherID();
//     // d = ptrNode->getTeacher()->getTeacherName();

//     // file<<c;
//     // file<<"\n";

//     // file<<b;
//     // file<<"\n";

//         // Itrate for All Courses
//     stdPtr = ptrNode->getStudentList(); //Student List 
//     tecNode = ptrNode->getTeacher();

//     stdNode = stdPtr->getHead();

//     //Writing Student Data 
//     while(stdNode!=nullptr){

//         file.write((char*)(stdNode), sizeof(stdNode));

//         stdNode = stdNode->getNext();
//     }

//     //Writing Teacher Data
//     // file.write((char*)tecNode, sizeof(tecNode));

//     //Writing Course Data
//     file.write((char*)ptrNode, sizeof(ptrNode));


//         ptrNode = ptrNode->getNext() ;

//     }

//     file.close();
// }

// void Admin::readData(){

//     Course_LinkedList *ptr = new Course_LinkedList;
//     Student_LinkedList *stdPtr = new Student_LinkedList ;
//     Student_Node* stdNode = new Student_Node;
//     Teacher_Node *tecNode = new Teacher_Node;
//     Course_Node *ptrNode = new Course_Node;

    
//     fstream file;
//     file.open("ProgramData.txt", ios::in);

//     if(!file){

//         cout<<"\nFile Opened Failed ";
//     }

//     file.seekg(0, ios::beg);



//     while (file.read((char*)ptrNode, sizeof(ptrNode))) //course ->
//     {
        
//         stdPtr = ptrNode->getStudentList(); //Student List 
//         tecNode = ptrNode->getTeacher();

//         stdNode = stdPtr->getHead();

//         while(file.read((char*)stdNode, sizeof(stdNode))){

//             stdPtr->CreatNewStudent(stdNode->getStdNmame(),stdNode->getStdID());
//         }

//         ptrNode->setStudentList(stdPtr);

//         ptrNode->setTeacherNode(tecNode);


//         ptr->CreatNewCourse(ptrNode->getCourseName(),ptrNode->getCourseID(),tecNode,stdPtr);
//     }

//     // ptr->display();
    
//     file.close();


// }

void Admin:: deleteCourse(std::string del_course){

    
    course_obj->deleteCourse(del_course);
}

void Admin:: replaceTeacher(std::string pre_teach, std::string new_teachID, std::string new_teachName, std::string courseName){

    course_obj->replaceTeacher( pre_teach, new_teachID, new_teachName, courseName  );
    
}

void Admin:: removeTeacher(std::string name, std::string ID, std::string courseID){

    course_obj->removeTeacher(name, ID, courseID);
}

 void Admin:: specifyTeacher(std::string name, std::string ID, std::string course_ID){

     course_obj->specifyTeacher(name, ID, course_ID);

}

void Admin:: addstudents(std::string ID, Student_Node* ptr, int size){

    course_obj->addStudents(ID,ptr,size);
}

int Admin:: CourseSizeCheck(std::string ID){

    return course_obj->CoursesizeCheck(ID);

}