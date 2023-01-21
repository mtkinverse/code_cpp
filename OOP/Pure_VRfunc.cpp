#include<iostream>
using namespace std;

class Base{
    protected:
    int varBase;
    public:
    virtual void display()=0;
    /*
    |***********************************************************************************************************|
    |==>> By assigning it 0 , it permits the derived classes to define an implementation of this function       |
    |-> Now if I did not define another display function in derived class it should throw an error              |
    |***********************************************************************************************************|
   */
   virtual void setData(int a){
        cout<<"\nIn the base class\n";
        varBase=a;
    }

   virtual void setData(int a,int b){
        varBase=a;
    }
};

class Derived: public Base{
    int varDer;
    public:

    void setData(int varBase,int varDer){
        cout<<"\nIn the deived class\n";
       this->varBase=varBase;
       this->varDer=varDer;
    }

    void display(){
        
        cout<<"The value of derived variable is : "<<varDer<<endl<<endl;
        cout<<"The value of Base variable is : "<<varBase<<endl<<endl;
    }
};

int main(){

    Base *objBase = new Derived;
    objBase->setData(4,2);
    objBase->display();
   
    Derived *ptrDr = new Derived;
    ptrDr->setData(5,2);
    ptrDr->display();

   
}