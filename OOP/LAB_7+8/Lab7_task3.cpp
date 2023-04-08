#include<iostream>
#include<string>
using namespace std;

class Animal{
    protected:
    string name;
    int age;
    public:
    Animal(string name,int age){
        this->name=name;
        this->age=age;
    }
};
class Lion : virtual public Animal{
    protected:
    int teeth;
    public:
    Lion(int teeth,string name,int age):Animal(name,age){
        this->teeth=teeth;
    }
    void getData(){
        cout<<"Give informatino of the lion\nName : ";
        cin.clear();
        fflush(stdin);
        getline(cin,name);
        cin.clear();
        fflush(stdin);
        cout<<"Age : ";
        cin>>age;
        cout<<"Number of teeths : ";
        cin>>teeth;
    }
    void putData(){
        cout<<"Name : "<<name<<"\nAge : "<<age<<"\nTeeths : "<<teeth<<endl;
        }
};

class Eagle:virtual public Animal{
    protected:
    int wings,heads;
    public:
    Eagle(int wings,int heads,string name,int age):Animal(name,age){
        this->wings=wings;
        this->heads=heads;
    }
    void getData(){
        cout<<"Give the information of the Eagle\nName : ";
        fflush(stdin);
        getline(cin,name);
        fflush(stdin);
        cout<<"Age : ";
        cin>>age;
        cout<<"Wings : ";
        cin>>wings;
        cout<<"Heads : ";
        cin>>heads;
    }
    void putData(){
        cout<<"Name : "<<name<<"\nAge : "<<age<<"\nWings : "<<wings<<"\nHeads  : "<<heads<<endl;
    }
};

class Griffin:public Lion,public Eagle{
    public:
    Griffin(int teeth,string name,int age,int wings,int heads):Lion(teeth,name,age),Eagle(wings,heads,name,age),Animal(name,age){}
    void getData(){
        cout<<"Give the information about the griffin\nName : ";
        cin.clear();
        fflush(stdin);
        getline(cin,name);
        cin.clear();
        fflush(stdin);
        cout<<"Age : ";
        cin>>age;
        cout<<"Number of teeths : ";
        cin>>teeth;
        cout<<"Wings : ";
        cin>>wings;
        cout<<"Heads : ";
        cin>>heads;
        (*this)=Griffin(teeth,name,age,wings,heads);
    }
    void putData(){
        cout<<"Information about the Griffin\nName : "<<name<<"\nAge : "<<age<<"\nTeeths : "<<teeth<<"\nWings : "<<wings<<"\nHeads  : "<<heads<<endl;
    }

};

int main(){
    Lion obj1(32,"Lion",15);
    Eagle obj2(2,1,"Eagle",12);
    Griffin obj(32,"Griffin",20,2,1);
    obj1.putData();
    obj2.putData();
    obj.putData();
    return 0;
}

