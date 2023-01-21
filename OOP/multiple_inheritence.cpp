#include<iostream>
using namespace std;

class base1{
    protected: 
    int base1_val1,base1_val2;
    public:
 base1(){}
    base1(int a,int b){
        base1_val1=a;
        base1_val2=b;
    }
    void showbase1(){
        cout<<"The value of base1_val1 : "<<base1_val1<<endl;
        cout<<"The value of base1_val2 : "<<base1_val2<<endl;
    }
};

class base2{
    protected:     
    int base2_val1,base2_val2;
 public:
 base2(){}
    base2(int a,int b){
        base2_val1=a;
        base2_val2=b;
    }
    void showbase2(){
        cout<<"The value of base2_val1 : "<<base2_val1<<endl;
        cout<<"The value of base2_val2 : "<<base2_val2<<endl;
    }
};

class derived : base1,base2{
public:
derived(){}
derived(int a,int b,int c,int d):base1(a,b),base2(c,d){

}
void showder(){
    showbase1();
    showbase2();
}
};

int main(){
    // derived obj;
    int a,b,c,d;
    cout<<"Give the first value : ";cin>>a;
    cout<<"Give the second value : ";cin>>b;
    cout<<"Give the third value : ";cin>>c;
    cout<<"Give the fourth value : ";cin>>d;
    derived obj(a,b,c,d);
    obj.showder();
    return 0;
}