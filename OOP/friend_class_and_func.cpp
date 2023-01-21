#include<iostream>
#include<string>
using namespace std;

class shop;

class calc{
    public:
    float netprice(float);
    inline float cal_tex (float);
    // friend void shop :: getdata();
};

class shop{
    float price,tex,net_price;
    int count;
    friend class calc;
    public:
    void getdata();
    friend void printdata(shop []);
    string name;
};

void shop :: getdata(){
    calc calc_obj;
    fflush(stdin);
    cout<<"Give the name of the product : ";cin>>name;
    fflush(stdin);
    cout<<"Give the price of the product : ";cin>>price;
    cout<<"Give the quantity of the product : ";cin>>count;
    tex=calc_obj.cal_tex(price);
    net_price=calc_obj.netprice(price);
}

float calc :: netprice(float var){
    float value;
    value+=var+(0.05*var);
    value+=(var*0.1);
    return value;
}
float calc :: cal_tex(float var){
    return (0.1*var);
}

void printdata(shop obj []){

    for(int i=0;i<10;i++){

        cout<<"MATERIAL "<<i+1<<endl;
        cout<<"Name : "<<obj[i].name<<endl;
        cout<<"Quantity : "<<obj[i].count<<endl;
        cout<<"price : "<<obj[i].price <<endl;
        cout<<"Tex : "<<obj[i].tex <<endl;
        cout<<"Retail price : "<<obj[i].net_price<<endl;

    }
}

int main(){
    shop obj[10];
    cout<<"Welcome to the hardware sales kindly give prceised information\n";
    for(int i=0;i<10;i++)obj[i].getdata();
    cout<<"\n\nYou have give the following information"<<endl<<endl;
    printdata(obj);
    cout<<"\n\n--------------------THANKS----------------------------\n\n";
    return 0;
}