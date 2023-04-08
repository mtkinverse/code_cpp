#include<iostream>
#include<string>
using namespace std;

class A{
    protected:
    int a;
    public:
    A(int a){this->a=a;}
    void setA(int val){a=val;}
    int getA()const{return a;}
};

class B:virtual protected A{
  protected:
    int b;
    public:
    B(int a,int b):A(a){this->b=b;}
    int getB()const {return b;}
};

class C : virtual protected A{
    protected:
    int c;
    public:
    C(int a,int c):A(a){
        this->c=c;
    }
    int getC()const {return c;}
};

class D :protected B,protected C{
    public:
    D(int a,int b,int c):B(a,b),C(a,c),A(a){}
    friend ostream& operator << (ostream&,const D& obj){
        cout<<"Value of a : "<<obj.a<<"\nValue of B : "<<obj.b<<"\nValue of C : "<<obj.c<<endl;
    }

};

int main(){
    D obj(1,2,3);
    cout<<obj;
}
