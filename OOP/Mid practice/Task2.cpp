//22k-4609    7.35
#include<iostream>
#include<string>
using namespace std;

class Car{
    string model,make;
    int year;
    float price;
    const float SalesTax;
    public:
    Car():SalesTax(0){}
    Car(string make,string model,int year,float price,float SalesTax):SalesTax(SalesTax){
        this->model=model;
        this->make=make;
        this->year=year;
        this->price=price;
    }
    void setMake(string make){this->make=make;}
    void setModel(string model){this->model=model;}
    void setPrice(float price){this->price=price;}
    void setYear(int year){this->year=year;}

    int getYear()const{return year;}
    int getPrice()const{return price;}
    int getSalesTax()const{return SalesTax;}
    string getModel()const{return model;}
    string getMake()const{return make;}

};

   static float calculateTotalPrice(Car obj){
         return obj.getSalesTax()+obj.getPrice()+(0.1*obj.getPrice());
    }

class Salesperson{
    string* names;
    Car* cars;
    public:
    Salesperson(){}
    
    Salesperson(string* names,Car* cars){
        this->cars=new Car[sizeof(cars)];
        this->names=new string[sizeof(names)];
        this->cars=cars;
        this->names=names;
    }

    void setName(string name,int i){
        this->names[i]=name;
    }
    string getName(int i)const{
        return names[i];
    }

    // void setCar(const Car &obj,int i){
    //     cars[i]=new Car;
    //     cars[i]=obj;
    // }
    Car getCar(int i)const{
        return cars[i];
    }
    float CalculateCom(int n){
        float com=0;
        for(int i=0;i<n;i++){
            com+=(calculateTotalPrice(cars[i])-(cars[i].getPrice()+cars[i].getSalesTax()));
        }
        return com;
    }
}; 

int main(){
Car cars[3]={Car("Honda","Civic",2022,20000,1500),Car("Toyota","Corolla",2022,18000,1500),Car("Ford","Fusion",2022,22000,1500)};
string names[3]={"name1","name2","name3"};
Salesperson Man(names,cars);
float val=0;
for(int i=0;i<3;i++)val+=Man.CalculateCom(i);
cout<<"The total commision earned by the person is "<<val<<endl;
    return 0;
}

//8.40