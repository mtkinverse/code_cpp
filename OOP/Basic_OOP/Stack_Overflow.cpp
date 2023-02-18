#include<iostream>
#include<string>
using namespace std;
int val;

class DataScientist{
    string firstName,lastName,highestEdu,country;
    int age,numberOfans,numberOfques,ID;

    public:
    DataScientist(){
        ID=val;
        val++;
        }
    DataScientist(string fname,string lname,string highedu,string con,int tage,int noa,int noq){
        firstName=fname;
        lastName=lname;
        highestEdu=highedu;
        country=con;
        age=tage;
        numberOfans=noa;
        numberOfques=noq;
        ID=val;
        val++;

        cout<<"A new user has been updated\n";
    }

    int getNoa(){return numberOfans;}
    int getNoq(){return numberOfques;}

    void setFname(string val){firstName=val;}
    void setLname(string val){lastName=val;}
    void setCountry(string val){country=val;}
    void setEdu(string val){highestEdu=val;}
    void setAge(int val){age=val;}

    string getFname(){return firstName;}
    string getLname(){return lastName;}
    string getCountry(){return country;}
    int getAge(){return age;}

    void AskQuestion(){numberOfques++;}
    void AnswerProblem(){numberOfans++;}
};

class Admin{
    string name,lastName,country;
    int age,ID;
    int UserCount=0;

    public:
  
    Admin(string Name,string lname,string Country,int tage,int id){
     name=Name;
     lastName=lname;
     country=Country;
     age=tage;
     ID=id;
    }

    void setFname(string Name){name=Name;}
    void setLname(string Name){lastName=Name;}
    void setCountry(string val){country=val;}
    void setAge(int val){age=val;}

    void updateUser(){++UserCount;}

    int getAge(){return age;}
    string getName(){return name;}
    string getLname(){return lastName;}
    string getCountry(){return country;}
  
    void TotalUser(){
      cout<<"The total users are : "<<UserCount<<endl;    
    }
};
int main(){
    cout<<"22k-4609 Taha Khan\n";

    string temps;
        cout<<"Enter your student ID : ";
        fflush(stdin);
        getline(cin,temps);
        fflush(stdin);

        int maxlen=temps.length(),index[2];

    index[0]=temps[maxlen-1]-'0';
    index[1]=temps[1]-'0';

    val=(index[1]*10)+(index[0]);
    // val*=(-1);

    Admin adm("Taha","Khan","Pakistan",18,4609);

    DataScientist sci1("Rao","Abdul","BS(CS)","Pakistan",17,5,5);
    adm.updateUser();
    DataScientist sci2("Hamdan","Vohra","BS(CS)","Pakistan",20,4,5);
    adm.updateUser();

    cout<<"In this platform"<<endl;
    adm.TotalUser();

    cout<<"\n----Information about admin\nName : "<<adm.getName()<<" "<<adm.getLname()<<"\nCountry : "<<adm.getCountry()<<"\nAge : "<<adm.getAge()<<endl<<endl;

    cout<<"\n -->> First User\nName : "<<sci1.getFname()<<" "<<sci1.getLname()<<"\nCountry : "<<sci1.getCountry()<<"\nAge : "<<sci1.getAge()<<"\nNumber of questions asked : "<<sci1.getNoa()<<"\nNumber of answer given : "<<sci1.getNoq()<<endl;
    

    cout<<"\n -->> Second User :\nName : "<<sci2.getFname()<<" "<<sci2.getLname()<<"\nCountry : "<<sci2.getCountry()<<"\nAge : "<<sci2.getAge()<<"\nNumber of questions asked : "<<sci2.getNoa()<<"\nNumber of answer given : "<<sci2.getNoq()<<endl;
 cout<<"User 1 has asked a question\n";
    sci1.AskQuestion();
 cout<<"User 2 gave an answer\n";
    sci2.AnswerProblem();

    cout<<"Updating the information of admin\n";
    adm.setFname("The");adm.setLname("Taha Khan");adm.setCountry("Beloved Pakistan");adm.setAge(20);

    cout<<"Updating the information of first user\n";
    sci1.setFname("Daiyal");sci1.setLname("Ahmed"); 

    cout<<"Updating the information of second user\n";
    sci2.setAge(25);sci2.setEdu("PHD"); 

    cout<<"After the modification\n\n -->> Information of the admin\nName : "<<adm.getName()<<" "<<adm.getLname()<<"\nCountry : "<<adm.getCountry()<<"\nAge : "<<adm.getAge()<<endl<<endl;
    
    adm.TotalUser();
    
    cout<<"\n -->> First User\nName : "<<sci1.getFname()<<" "<<sci1.getLname()<<"\nCountry : "<<sci1.getCountry()<<"\nAge : "<<sci1.getAge()<<"\nNumber of questions asked : "<<sci1.getNoa()<<"\nNumber of answer given : "<<sci1.getNoq()<<endl;
    

    cout<<"\n -->> Second User :\nName : "<<sci2.getFname()<<" "<<sci2.getLname()<<"\nCountry : "<<sci2.getCountry()<<"\nAge : "<<sci2.getAge()<<"\nNumber of questions asked : "<<sci2.getNoa()<<"\nNumber of answer given : "<<sci2.getNoq()<<endl;


    return 0;
    
    }