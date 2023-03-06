#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Render{
int randomNumber;
public:
Render(){
randomNumber = 1+rand()%99;
}
void setRandom(int ran){
    randomNumber=ran;
}
int getRandom()const{
    return randomNumber;
}

};

class InputHandler{
    int input;
    string sinput;

    public:
    InputHandler(){}
    InputHandler(string sinput,int input){
        this->sinput=sinput;
        this->input=input;
    }

    void setNumber(int input){this->input=input; }
    void setString(int sinput){this->sinput=sinput; }

    int getNumber() const {return input; }
    string getString() const {return sinput; }

};

class Physics{
    float value;

    public:

    Physics(float value=0){this->value=value;}
    void setValue(float value){this->value=value;}
    float getValue()const {return value;}
};

class GameEngine{
    Render rand;
    InputHandler IH;
    Physics phy;
    string name;

    public:
    GameEngine(Render rand,InputHandler IH,Physics phy,string name){
        this->rand=rand;
        this->IH=IH;
        this->phy=phy;
        this->name=name;
    }
    void printDetails(){
        cout<<"\n***********Information About Game Engine***************\nName : "<<name<<"\nRandom Number : "<<rand.getRandom()<<"\nInputted value : "<<IH.getNumber()<<"\nInputted string : "<<IH.getString()<<"\nWith a physical value of : "<<phy.getValue()<<"\n\nHas been successfully activated\n";
    }

    void setName(string name){this->name=name;}
    string getName() const {return name;}

};
int main(){
Render random;
InputHandler input("The inputted string",10);
Physics ph(23.65);

GameEngine Engine(random,input,ph,"Game.TK");
Engine.printDetails();
cout<<endl;
    return 0;
}