#include<iostream>
using namespace std;

class Base{
    protected:
    int varBase;
    public:
    virtual void display(){
        cout<<"The value of base varible is : "<<varBase<<endl;
    }

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
        Base :: display();
        cout<<"The value of derived variable is : "<<varDer<<endl<<endl;
    }
};

int main(){

    // Derived objDer;
    // Base *objBase = &objDer;
    Base *objBase = new Derived;
    objBase->setData(4,2);
    objBase->display();
     // ==>> NOTE BELOW ALL ARE FOR IF WE HAVE NOT DECLARED THE FUNCTION IN THE BASE CLASS "VIRTUAL" Because At this time I have declared virtual
    //-->> Notice that though it is pointing to a derived object, it will run the function setData and display() of Base class
    //-->> We cannot access the members of the derived class with a base class pointer

    Derived *ptrDr = new Derived;
    ptrDr->setData(5,2);
    ptrDr->display();

    /*
    -->> Now lets see what happens if we point a base class object with derived class pointer
    */

//    Derived *newptr = objBase;
/*
-->> It is throwing an error
*/
}