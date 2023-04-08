#include<iostream>
#include<string>
using namespace std;

class Animal{
    public:
    Animal(){}
    void Eat(){cout<<"Eating anything coming in front of me"<<endl;}
    void Play(){cout<<"Playing with the things found in nature"<<endl;}
};

class Pet{
    
    public:
    Pet(){}
    void Eat(){cout<<"Eating the food what owner provided"<<endl;}
    void Play(){cout<<"Playing with the toys that owner provided"<<endl;}
};

class PetAnimal:public Animal,public Pet{
public:
    void Eat(){
        Animal:: Eat();
        Pet::Eat();
    }

    void Play(){
        Animal:: Play();
        Pet::Play();
    }
};
//When I call them without overriding it was showing ambiguity

int main(){
    PetAnimal peto;
    peto.Eat();
    peto.Play();
}