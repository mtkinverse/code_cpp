#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

struct cal{
    int op1,op2;
    char ope;
}cal_var;

class simpleCal{
    public:
    int sumFun(int a,int b){
        return a+b;
    }
    int subFun(int a,int b){
        return a-b;
    }
    float divFun(int a,int b){
        if(b==0){
            cout<<"Math Error"<<endl;
            exit(0);
        }else
        return (float) a/b;
    }
    int prodFun(int a,int b){
        return a*b;
    }

    public:
    simplCal(){}
};

class scientificCal{
    public:
    void trigFun(){
        system("cls");
        cout<<"Choose your desired operation\n1- Sin\n2- Cos\n3-Tan\nEnter your choice (1,2,3) : ";
        int check,a;
        cin>>check;
        cout<<"Enter the number : ";
        cin>>a;
        cout<<"The value of desired operation is ";
        switch(check){

            case 1:
           cout<<sin(a);    
            break;

            case 2:
           cout<<cos(a);    
           break;

            case 3:
           cout<<tan(a);    
           break;

           default:
           system("cls");
           cout<<"\n\n\t\tNot correct information provided"<<endl;

        }
        cout<<endl<<endl;
    }
    public:
    scientificCal(){}
};

class hybridCal :public simpleCal ,public scientificCal{

    public:

    hybridCal(){
       
    }

};

int main(){

    hybridCal hyb;
     system("cls");
        cout<<"*********Welcome to hybrid calculator***********\nWhat do you want to use\n1- Simple Calculator\n2- Scientific Calculator"<<endl;
        int check;
        cin>>check;
        switch(check){
            case 1:
            cout<<"Give the numbers and the operator : ";cin>>cal_var.op1>>cal_var.op2>>cal_var.ope;
            switch(cal_var.ope){
                case '+':cout<<"The sum of the two values is "<<hyb.sumFun(cal_var.op1,cal_var.op2)<<endl;break;
                case '-':cout<<"The subractrion of the two values is "<<hyb.subFun(cal_var.op1,cal_var.op2)<<endl;break;
                case '/':cout<<"The division of the two values is "<<hyb.divFun(cal_var.op1,cal_var.op2)<<endl;break;
                case '*':cout<<"The product of the two values is "<<hyb.prodFun(cal_var.op1,cal_var.op2)<<endl;break;
                default : 
                system("cls");
                cout<<"\n\n\t\tKindly be precised !\n";
            }
            break;
            
            case 2:
            hyb.trigFun();
            break;

            default: 
            system("cls");
            cout<<"\n\n\t\tKindly be precised !\n";
        }

            cout<<endl<<endl;
    return 0;
}

