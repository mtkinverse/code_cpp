#include<iostream>
using namespace std;

class members{
    int mem1,mem2;
    public:
    members & decalreClass(int mem1,int mem2){
        this->mem1=mem1;

        ///-->> AS you see the members and the receiving arguments are same ;therefore, we are using this operator to define the preference of the member variable and to store the value
        //-->> else if we did not use this operator above it will  not set the value and always return a garbage value

        this->mem2=mem2;
        return *this;
        //this is returnig the pointer to the class
    }
    void showData(){
        cout<<"The value of the member 1 is : "<<mem1<<endl<<"While the value of the member 2 is : "<<mem2 <<endl<<endl;
    }
};

int main(){

    members obj;
    obj.decalreClass(2,3).showData();

    return 0;
}