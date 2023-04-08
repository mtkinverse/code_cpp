#include<iostream>
#include<string>
using namespace std;
//Note here I have made the checkValues function of Checker friend of class A 
class A;
class Checker{
    public:
    void checkValues(const A&);
};

class A{
    int a,b;
friend void Checker:: checkValues(const A&); 
    public:
    A(int a=0,int b=0):a(a),b(b){};
    int getA()const{return a;}
    int getB()const{return b;}
};

void Checker::checkValues(const A& obj){cout<<"\nA : "<<obj.a<<"\nB : "<<obj.b<<endl;}

int main(){
    A obj(4,5);
    Checker check;
    check.checkValues(obj);
    
    return 0;}