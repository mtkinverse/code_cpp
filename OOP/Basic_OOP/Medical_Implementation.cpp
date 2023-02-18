#include<iostream>
#include<string>
using namespace std;

struct DOB{
    int day,month,year;
    char ch='-';
};

class HeartRates{
    string Fname;
    int ID;
    struct DOB date;

    public: 

    HeartRates(){}
    HeartRates(string name,int id,struct DOB var){
        Fname=name;
        ID=id;
        date=var;
    }

    void setName(string name){Fname=name;}
    string getName(){return Fname;}

    void setID(int val){ID=val;}
    int getID(){return ID;}

    void setDOB(struct DOB var){date=var;}
    struct DOB getDOB(){return date;}
    
    int getAge(){

        if(date.month>2)
        int tempage=(2023-date.year)-1;
        else 
        int tempage=(2023-date.year);

    }

    int getMaxHeartRate(int val){
        return (220-val);
    }

    double * getTargetHeartRate(int val){
        double *arr=new double[2];
        arr[0]=0.5*val;
        arr[1]=0.85*val;
        return arr;
    }
};

int main(){
    cout<<"22k-4609 Taha Khan\n";

 string temps;
        cout<<"Enter your student ID : ";
        fflush(stdin);
        getline(cin,temps);
        fflush(stdin);

        int maxlen=temps.length(),valID;
        valID=temps[maxlen-2]-'0';

    
    struct DOB val;
    val.day=04;
    val.month=05;
    val.year=2004;

    HeartRates per1("Taha",valID,val);
cout<<"done1";
    val=per1.getDOB();
    int perage=per1.getAge();
    int maxbeet=per1.getMaxHeartRate(perage);
    double *targetbeet;
    targetbeet=per1.getTargetHeartRate(maxbeet);

        cout<<"\nThe person named "<<per1.getName()<<" Has ID "<<per1.getID()<<" and date of birth "<<val.day<<val.ch<<val.month<<val.ch<<val.year<<" ;therefore, his age is "<<perage<<" years and maximum heart rate "<<maxbeet<<" beat/min "<<" Whereas the targated heart rate is ("<<targetbeet[0]
    <<" - "<<targetbeet[1]<<") beat/min\n\n----THANKS\n";

    return 0;
}