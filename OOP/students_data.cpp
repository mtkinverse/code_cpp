#include<iostream>
using namespace std;

class sec_k{
   unsigned int cell;
   float cgpa;
public:
    static int count;///Keep remember it will automatically initialize to zero

   string id;
   void print_data();

   void get_data(){
    cout<<"\n\nEnter the information of student "<<count+1<<endl;
    fflush(stdin);
    cout<<"\nGive the id of the student "<<count+1<<" : ";cin>>id;
    fflush(stdin);
    cout<<"\nGive the CGPA of the student "<<count+1<<" : ";cin>>cgpa;
    cout<<"\nGive the cell number of the student "<<count+1<<" : ";cin>>cell;
    cout<<endl;
    count++;
   }  
};

int sec_k :: count;  

   void sec_k :: print_data(){
    cout<<"\n the id of the student "<<count+1<<" : ";cout<<id;
    cout<<"\n the cell number of the student "<<count+1<<" : ";cout<<cell;
    cout<<"\n the CGPA of the student "<<count+1<<" : ";cout<<cgpa;
    cout<<endl<<endl;

    }
   
 
 int main(){

    sec_k stu[50];

    cout<<"Hi welcome to the student manager\n--> Kindly give the correct information of the students\n";

    int c;

    while(c!=0){
        stu[sec_k::count].get_data();///Here it was throwing error that count is not declared in this scope therefore I have used  the scope resolution operator (::) to set the scope of the variable with the class sec_k
        cout<<"Enter 'E' to exit and print, and any key to add more"<<endl;
        cin>>c;
    }     

int num = sec_k :: count;

    cout<<"\n\nYou have entered the information of "<<num<<" student(s)\n";

    for(int i=0;i<num;i++)  stu[i].print_data();
        
          
}