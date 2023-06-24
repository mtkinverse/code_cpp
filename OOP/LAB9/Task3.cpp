#include<iostream>
#include<string>
using namespace std;

class Car{
    friend class Dealer;
    string manufacturer,model;
    int year;
    public:
    Car(){}
    Car(string val1,string val2,int val3){
        manufacturer=val1;
        model=val2;
        year=val3;
    }
    int getYear()const{return year;}
    string getModel()const{return model;}
    string getManufacturer()const{return manufacturer;}

    void printDetails(){
        cout<<" Manufacturer : "<<manufacturer<<"\n Model : "<<model<<"\n Year : "<<year<<endl;
    }
};

class Dealer{
    string name,id;
    public:
    Dealer(string val1,string val2){
        name=val1;
        id=val2;
    }
    void modifyCarDetails(Car& obj){
        string temp1,temp2;
        int tempno;
        cout<<"Hi Dealer "<<name<<" here\nGive the modified model of the car : ";
        cin.clear();
        cin>>temp2;
        cin.clear();
        cout<<"Give the modified name of the manufacturer : ";
        cin.clear();
        fflush(stdin);
        getline(cin,temp1);
        cin.clear();
        cout<<"Give the model of the car : ";
        cin>>tempno;
        obj=Car(temp1,temp2,tempno);
        cout<<"Object Modified !\n";
    }
};

int main(){
    Car Toyota("Toyota","SS-180ZZA",2020);
    cout<<"\n\n* The current details of the car *\n\n";
    Toyota.printDetails();
    Dealer me("Taha Khan","22K-4609");

    me.modifyCarDetails(Toyota);
    cout<<"* After the modification *\n";
    Toyota.printDetails();
}