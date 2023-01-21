#include<iostream>
#include<iomanip>

union id{
  int numbers;
  char string[20];  //Here we can use only 1 member of id at a time this is the functionality of union 
};

enum depart {Skin ,Bones ,Heart ,OPD};/*this will assign integer numbers against each value 
                                        for example skin=0 Bones=1 Heart=2 OPD =3*/ 

int Glob=45;
using namespace std;

void swap(int &,int &);

void incr(int & a,int b=1){
     a+=b;
}


inline sum(int a,int b){
    return a+b;
    }

teach_default_arguments_fun(){

    int val;

    cout<<"Here we will increment your given value by 1 and by 2 when you want between 1-5\nGive the value : ";
    cin>>val;
    int ask;
    cout<<"Give the number of iteration you want to define the incremention value : ";
    cin>>ask;

    for(int i=1;i<=5;i++){
        if(i==ask){
            int temp;
            cout<<"Give the incrementarion value : ";
            cin>>temp;
            incr(val,temp);
        }
        else incr(val);

        cout<<"The value apppeared after increment is : "<<val<<endl;
    }
}


int main(){
    cout << "Hello world\nThis is the first C++ program for me\nGive  the value of the first variable : ";
    int var1,var2;
    cin>>var1;
    cout<<"Give the value of the variable 2 : ";
    cin>>var2;
    cout<<"The sum of the variables through INLINE FUNCTION is "<<sum(var1,var2)<<"\nThanks \n";
    int Glob=2;
    cout<<"The value of global variable is : "<<Glob<<endl<<"Noted that is has printed the local variable but we can force it to print the global variable\nThe value of global variable is "<<::Glob<<"\nThis is done by using scope resolution opeartor (::)"<<endl;

    ///*********************Refence Variables With Type casting****************************
    
    int &reffered_var=Glob;
    cout<<"The valeue of Reffered variable is "<<reffered_var<<endl<<"Printing after the type casting "<<endl;
    cout<<"The value of floating reffered variable is "<<float(reffered_var)<<endl;

//**********************Manipulators_______________________
///( endl )is also a manipulator meanwhile setw(value) is also a manipulator found in iomanip these are used to handle the output of the program

    cout<<setw(-10)<<"4"<<endl;
    cout<<setw(-10)<<"40"<<endl;
    cout<<setw(-10)<<"1654"<<endl;
for(int i=1;i<=5;i++)cout<<"The value of i is :"<<i<<endl;

// call by refrence can also be occur with refrence variables 
int a,b;

cout<<"Give the value of a : ";cin>> a;
cout<<"Give the value of b : ";cin>> b;

swap(a,b);

cout<<"The value of a after swapping is "<<a<<" while the value of b is : "<<b<<endl;

teach_default_arguments_fun();
    return 0;
}


void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}