#include<iostream>
#include<string>
using namespace std;

struct date{
    int day,month,year;
};

class officer;
class emp{
 string name;
 int id_no;
 struct date joined;
 float salary;  
 friend void displayData(officer [],int );


 public:
//  emp(){}
 emp(){
    cout<<endl<<endl;
    cout<<"Give the name of the employee : ";cin>>name;
    fflush(stdin);
    cout<<"Give the id of the employee : ";cin>>id_no;
    cout<<"Give the salary of the employee : ";cin>>salary;
    cout<<"Give the joining date of the employee \nDay : ";cin>>joined.day;
    cout<<"Month : ";cin>>joined.month;
    cout<<"Year : ";cin>>joined.year;
 }

};

//--->> The following class is inherited from class emp
class officer : private emp{
  string depart,post;
  friend void displayData(officer [],int );
  public:
  officer(){
    fflush(stdin);
    cout<<"Give the department of the officer : ";cin>>depart;
    cout<<"Give the post of the officer : ";cin>>post;
    fflush(stdin);
  }
};

void displayData(officer arr[],int no_emp ){

  cout<<"\n****************Printing the Given stats*********************\n\n";

  for(int i=0;i<no_emp;i++){
    cout<<"--->> Officer "<<i+1<<endl<<"Name : "<<arr[i].name<<endl<<"ID : "<<arr[i].id_no<<endl<<"Depart : "<<arr[i].depart<<endl<<"Designation : "<<arr[i].post<<endl<<"Salary : "<<arr[i].salary<<endl<<"Joining Date : "<<arr[i].joined.day<<"-"<<arr[i].joined.month<<"-"<<arr[i].joined.year<<endl<<endl;
  }

}
int main(){
    cout<<"Hi and welcome to the Employee management system\nGive the numbers of officers in your organization : ";
    int no_emp;
    cin>>no_emp;
    officer officers[no_emp];
    displayData(officers,no_emp);
}