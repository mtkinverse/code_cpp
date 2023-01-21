#include<iostream>
#include<string>
using namespace std;

class Emp{
    private: float sal; string pass;
    void check_str(string);

    public:
   string id;float work_hr;

    void getdata(Emp & var);

    void print_it(Emp var){
        cout<<"id : "<<var.id<<endl;
        cout<<"password : "<<var.pass<<endl;
        cout<<"Salary : "<<var.sal<<endl;
        cout<<"Working hours : "<<var.work_hr<<endl<<endl;
    }
    
};

void Emp :: check_str(string s){

    int check[4]={0};

for(int i=0;i<s.length();i++){

   switch(s.at(i)){

    case 48 ... 57:
      ++check[0];  
      break;

    case 65 ... 90: 
      ++check[2];  
      break; 

    case 97 ... 123 : 
      ++check[1];  
      break;

     case 33 ... 47: case 58 ... 64: case 91 ... 96 : case 124 ... 126: 
      ++check[3];    
      break;
    
   }

}

for(int i=0;i<4;i++){
    if(!check[i]){
        cout<<"\nInvalid password please provide strong password\n";
        exit(0);
    }
}
}

    void Emp ::  getdata(Emp & var){

        cout<<"Give the ID of the employee : "; cin>>var.id; 
        cout<<"Give the password of the employee : "; cin>>var.pass; 
        check_str(var.pass);
        cout<<"Give the workung hours of the employee : "; cin>>var.work_hr; 
        cout<<"Give the salary of the employee : "; cin>>var.sal; 

    }

int main(){

    cout<<"Welcome to the Employee Details\n\n";
   Emp taha,aman;
Emp & reffered =taha;
   cout<<"\n\nGive the information about Taha\n\n";
   taha.getdata( reffered);

Emp & reffer2 =aman;
   cout<<"\n\nGive the information about Aman\n\n";
   aman.getdata( reffer2);

   cout<<"\nThe information you give about Taha\n\n";
   taha.print_it( taha);

   cout<<"\n\nThe information you give about Aman\n\n";
   aman.print_it( aman);
    
   return 0;

}