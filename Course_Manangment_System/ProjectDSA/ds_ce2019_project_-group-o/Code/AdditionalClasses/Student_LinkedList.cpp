#include <fstream>
#include <iostream>
using namespace std;

#include "Student_Node.h"
#include "Student_LinkedList.h"




Student_LinkedList :: Student_LinkedList(/* args */) {

     head = nullptr;
     tail = nullptr;
     count = 0;
 }

Student_LinkedList ::~Student_LinkedList(){

}

void Student_LinkedList :: CreatNewStudent (std::string n, std::string id){
  // append newStudent with paramentrs name & ID
    // cout<<"  ewjkhfjk "; 
    //We want to append the Node "Add Node at the end of previous NodeList"
    Student_Node *temp = new Student_Node(n,id);
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



}

Student_Node* Student_LinkedList :: getLast (){


}

Student_Node* Student_LinkedList :: getHead (){

    return head;

}
void Student_LinkedList :: display(){

    Student_Node *temp = head;

    if (temp==nullptr){

        cout<<"No Student Data Available at this Moment \n";
    }
    else {

        int i=1;
        cout<<"\nTotal Students For this Course :"<<count<<endl;
        while(temp!= nullptr)
        {
    
            cout<<"Name of ["<<i<<"] Student : ["<<temp->getStdNmame()<<"] ";
            cout<<"Student ["<<i<<"] ID      :  [" <<temp->getStdID()<<"] ";
            cout<<" \n ";
            i++;
            temp = temp->getNext();
        }
            cout <<endl;
    }

}


Student_LinkedList* Student_LinkedList ::readData(){

    fstream file;
    file.open("StudentData.txt", ios::in);
    file.seekg(0, ios::beg);
    Student_Node* ptr = new Student_Node();
    Student_LinkedList temp ;
    //Course_Node(std::string , std::string, std::string, std:: string, Student_LinkedList*) ;

    while (file.read((char*)ptr, sizeof(Student_Node)))
    {
         
        temp.CreatNewStudent(ptr->getStdNmame(), ptr->getStdID());
    }
    // remove("StudentData.txt");

    return &temp;
}

int Student_LinkedList :: getcount(){

    return count;
}

void Student_LinkedList ::saveData(){

    fstream file;
    remove("StudentData.txt");
    file.open("StudentData.txt", ios::out | ios::app);

    Student_Node* ptr = head;

    while (ptr != nullptr)
    {
        //cout << "\n value at node is  " << temp->getdata() << "\n";
        file.write((char*)ptr, sizeof(Student_Node));
        ptr = ptr->getNext();
    }
    
    file.close();

}

void Student_LinkedList ::removeStudent(std::string ID){

    Student_Node *temp = head;

    if (head==nullptr | count==0){

        cout<<"There is No Student Data Created Yet :";
        return;
    }

    if(temp->getStdID()==ID){

    //If true means we have to remove head 
    // shift head to next

        head = head->getNext();
        delete temp;

    }

    else if (tail->getStdID()==ID) {
    
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

            if(ID == temp->getNext()->getStdID()){
            
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

    
    count -= 1; // Student delted 





}


void Student_LinkedList :: swap1( Student_Node* ptr, Student_Node* ptr1){

std::string temp, temp1;  Student_Node *temp3; Student_Node *temp4; int size;

temp = ptr->getStdNmame();
temp1 = ptr->getStdID();


ptr->setStudents(ptr1->getStdNmame(), ptr1->getStdID());
ptr1->setStudents(temp, temp1);


}

void Student_LinkedList:: sort(){

    // cout<<"Sort Called ";
    for ( Student_Node *temp = head ; temp->getNext()!=nullptr; temp = temp->getNext() )
    {
        for (Student_Node *temp1 = temp; temp1 != nullptr; temp1 = temp1->getNext())
        {
            if (temp->getStdID() > temp1->getStdID())
            {

                swap1(temp, temp1);
                
                
            }
        }
    }
}