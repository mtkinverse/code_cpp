#include<iostream>
#include<string>
using namespace std;

class Player{
    protected:
  string name;
  int age;
  float amount;
  public:
  Player(string name,int age,float amount){
    this->name=name;
    this->age=age;
    this->amount=amount;
  }
};

class Batsman: virtual public Player{
    protected:
    string role;
    public:
    Batsman(string role,string name,int age,float price):Player(name,age,price){
        this->role=role;
    }
};

class Bowler: virtual public Player{
    protected:
    string bowlingType;
    public:
    Bowler(string bowlingType,string name,int age,float price):Player(name,age,price){
        this->bowlingType=bowlingType;
    }
};

class Allrounder : public Batsman,Bowler{
    public:
    Allrounder(string role,string bowlingType,string name,int age,float price):Batsman(role,name,age,price),Bowler(bowlingType,name,age,price),Player(name,age,price){}
    string getRole( )const {return role;}
    string getBowlingType()const {return bowlingType;}
    string getName()const{return name;}
    int getAge()const{return age;}
    float getPrice()const{return amount;}
};

int main(){
    
    Allrounder maddy("Middle Order","Right arm off spinner","Imad Wasim",35,3500000);

    cout<<"Information About the allrounder\nName : "<<maddy.getName()<<"\nAge : "<<maddy.getAge()<<"\nPrice : "<<maddy.getPrice()<<"\nBatting role : "<<maddy.getRole()<<"\nBowling Type : "<<maddy.getBowlingType()<<endl;
    
    return 0;
    
}