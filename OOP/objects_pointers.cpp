#include<iostream>
using namespace std;

class student{
    int id;
    float sgpa;
    public : 
student(){}
    student(int a,float b){
        id=a;
        sgpa=b;
    }

    student(int a,int b){
        id=a;
        sgpa=float(b);
    }

    show(){
        cout<<"The id of the student is : "<<id<<endl<<"The SGPA of the student is : "<<sgpa<<endl<<endl;
    }
};

int main(){
    cout<<"Give the number of students you want to generate report : ";
    int n;
    cin>>n;
  student *arr=new student[n];

  cout<<"Enter the information of students\n";

  for(int i=0;i<n;i++){
    int temp;
    float tempf;
    cout<<"Student number "<<i+1<<" :\nID : ";
    cin>>temp;
    cout<<"SGPA : ";
    cin>>tempf;
    while(tempf>4.00||tempf<=0.00){
        cout<<"\nWrong attempt kindly enter the accurate sgpa : ";
        cin>>tempf;
    }
    *(arr+i)= student(temp,tempf);
  }

  cout<<"The given information of "<<n<<" students is\n\n";

  for(int i=0;i<n;i++,++arr){
    cout<<"Student "<<i+1<<endl;
    arr->show();
    cout<<endl;
  }

 return 0;   
}