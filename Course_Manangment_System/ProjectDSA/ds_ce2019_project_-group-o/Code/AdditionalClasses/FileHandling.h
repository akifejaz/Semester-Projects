#include <fstream>
#include <iostream>
using namespace std;

// #include "Course_LinkedList.h"

class Course_LinkedList;
class Admin;

extern Course_LinkedList course_list;
extern Admin admin_obj;

#ifndef _FileHanling_H
#define _FileHanling_H

Admin *temp = &admin_obj;




void SaveAdminData( Admin ptr){

    
    ofstream file; 
    file.open("AdminData.txt");

    if(file){

        file.write((char *) &ptr, sizeof(ptr));
    }
    else {

        cout<<"\nFile Open Failed :\n";
    }
    file.close();


    
}

Admin *ReadAdminData(Admin &ptr){

    // Admin *ptr = new Admin() ;

    ifstream file1;
    file1.open("AdminData.txt");

    if(file1){

        file1.read( (char *) & ptr, 50);
    }
    else {

        cout<<"\nFile Open Failed :\n";
    }
    file1.close();

    // cout<<"SavedFile";

    // return ptr;

}

void saveStudentsData(Student_LinkedList ptr){

        ofstream file;
    file.open("StudentsData.txt");

    if(file){

        file.write((char *) &ptr, sizeof(ptr));
    }
    else {

        cout<<"\nFile Open Failed :\n";
    }
    file.close();

}

Student_LinkedList * readStudetnsData(){

    Student_LinkedList *ptr = new Student_LinkedList() ;

    ifstream file1;
    file1.open("StudentsData.txt");

    if(file1){

        file1.read( (char *) & ptr, sizeof(ptr));
    }
    else {

        cout<<"\nFile Open Failed :\n";
    }
    file1.close();

    // cout<<"SavedFile";

    return ptr;

}


#endif