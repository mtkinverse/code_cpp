#include<iostream>
#include<string>
using namespace std;

enum Style{runningshoes ,sneakers,stiletto};
enum demography{infant,toddler,child,teenager,adult};

class user{

 string name;
 int *id,age;
 float height,size;
 char gen;


 public:

 user(){} 
 user(string Name,int *arr,int Age,float val,float valb,char gend){
    name=Name;
    age=Age;
    height=val;
    size=valb;
    gen=gend;
    id=new int[2];
    for(int i=0;i<2;i++)id[i]=arr[i];
 } 

void setID(int *val){id=val;}
void setAge(int age){this->age=age;}
void setHeight(float val){height=val;}
void setSize(float val){size=val;}
void setChar(char val){gen=val;}
void setName(string val){name=val;}

int* const getID(){return id;}
int const getAge(){return age;}
float const getHeight(){return height;}
float const getSize(){return size;}
char const getGen(){return gen;}
string const getName(){return name;}

};

class shoe{
    float size,width;
    string brand,color;
    Style style;
    demography demo;
    public:

    shoe(){}
    shoe(float vala,float valb,string Brand,string Color,Style st,demography de){
        size=vala;
        width=valb;
        brand=Brand;
        color=Color;
        style=st;
        demo=de;
    }

   void setSize(float val){size =val;}
   void setWidth(float val){width =val;}
   void setBrand(string val){brand=val;}
   void setColor(string val){color=val;}
   void setStyle(Style val){style =val;}
   void setDemo(demography val){demo =val;}

   float const  getSize (){return size;}
   float const  getWidth (){return width;}
   string const  getBrand (){return brand;}
   string const  getColor (){return color;}
   Style const  getStyle() {return style;}
   demography const getDemo(){return demo;}

   demography checkAge(int age){
    demography var;
    switch(age){
        case 0 ... 2: var=infant; break;
        case 3 ... 5: var= toddler; break;
        case 10 ... 12:var= child; break;
        case 13 ... 19:var= teenager; break;
        default: var=adult;
    }
    return var;
   }
};

void UpdateInfo(shoe * ptr ,int n){
    system("cls");
 cout<<"Give the shoe number you entered to update the info : ";
 int choiceA,choiceB,tempno;
 string temps;
 float tempf;
 Style tempstyle;
 demography tempdemo;

 cin>>choiceA;
 if(choiceA>0 && choiceA<=n){
    cout<<"What do you want to update\n1- Size\n2- Width\n3- Brand\n4- Color\n5- Style\n6- Demography\nEnter your choice : ";
    cin>>choiceB;

    switch(choiceB){

        case 1:
         cout<<"The current size is : "<<ptr[choiceA-1].getSize()<<"\nEnter the new size : ";
        cin>>tempf;
        ptr[choiceA-1].setSize(tempf);
        cout<<"The value has been updated\n";
        system("pause");
        break;
        
        case 2:

         cout<<"The current width is : "<<ptr[choiceA-1].getWidth()<<"\nEnter the new width : ";
        cin>>tempf;
        ptr[choiceA-1].setWidth(tempf);
        cout<<"The value has been updated\n";
        system("pause");

        break;
        case 3:

         cout<<"The current brand is : "<<ptr[choiceA-1].getBrand()<<"\nEnter the new brand : ";

        fflush(stdin);
        getline(cin,temps);
        fflush(stdin);
        ptr[choiceA-1].setBrand(temps);

        cout<<"The value has been updated\n";
        system("pause");

        break;
        case 4:
         cout<<"The current color is : "<<ptr[choiceA-1].getColor()<<"\nEnter the new color : ";

        fflush(stdin);
        getline(cin,temps);
        fflush(stdin);
        ptr[choiceA-1].setColor(temps);

        cout<<"The value has been updated\n";
        system("pause");
        break;
        case 5:
        cout<<"The current style of the shoes is ";
        switch(ptr[choiceA-1].getStyle()){
            case 0: cout<<"Running Shoes"; break;
            case 1: cout<<"Sneakers"; break;
            case 2: cout<<"Stiletto"; break;
        }
        cout<<"Choose the new style\n1- Runnung shoes\n2- Sneakers\n3- Stiletto\nEnter your choice : ";
        cin>>choiceB;

        switch(choiceB){
         case 1: tempstyle =runningshoes;  break;
         case 2: tempstyle =sneakers;  break;
         case 3: tempstyle =stiletto;  break;
        }
        ptr[choiceA-1].setStyle(tempstyle);
        cout<<"The value has been updated\n";
        system("pause");
        break;

        case 6:
        cout<<"The current demography of the shoes is ";

        switch(ptr[choiceA-1].getDemo()){
             case 0: cout<<"Infant";break;
         case 1:cout<<"Toddler";break;
            case 2:cout<<"Child";break;
            case 3:cout<<"Teenager";break;
            case 4:cout<<"Adult";break;
        }

        cout<<"\nChoose the new demography\n1- Infant \n2- Toddler\n3- Child\n4- Teenager\n5- Adult\nEnter your choice : ";
        cin>>choiceB;

        switch(choiceB){
         case 1:  tempdemo =infant;    break;
         case 2: tempdemo =toddler;    break;
         case 3:  tempdemo =child;    break;
         case 4:  tempdemo =teenager;    break;
         case 5:  tempdemo =adult;    break;
        }

        ptr[choiceA-1].setDemo(tempdemo);
        cout<<"The value has been updated\n";
        system("pause");
        break;
    }
 }
 else cout<<"Wrong Entry !";
}

void DisplayInfo(shoe *ptr,int n){

    int temno,chose,choice;
    
    cout<<"Give the number of shoe you want to view information : ";
    cin>>temno;
    if(!(temno>0&&temno<=n))cout<<"Wrong Entry !\n";
    
    else{
     cout<<"The information of the given shoe is\nSize : "<<ptr[temno-1].getSize()<<"\nWidth : "<<ptr[temno-1].getWidth()<<"\nBrand : "<<ptr[temno-1].getBrand()<<"\nColor : "<<ptr[temno-1].getColor()<<"\nStyle : ";

     switch(ptr[temno-1].getStyle()){
        case 0: cout<<"Running shoes";break;
        case 1: cout<<"Sneakers";break;
        case 2: cout<<"Stiletto";break;
     }
     
     cout<<"\nDemography : ";
     switch(ptr[temno-1].getDemo()){
        case 0: cout<<"Infant";break;
         case 1:cout<<"Toddler";break;
            case 2:cout<<"Child";break;
            case 3:cout<<"Teenager";break;
            case 4:cout<<"Adult";break;
     }
     cout<<endl;
     system("pause");
    }
}


int main(){
    cout<<"22k-4609 Taha Khan\n";

string enterID;
cout<<"Enter your ID : ";
fflush(stdin);
getline(cin,enterID);
fflush(stdin);

int ind1,ind2;

ind1=enterID[0]-'0';
ind1*=10;
ind1+=enterID[1]-'0';

ind2=((enterID[4]-'0')*1000)+((enterID[5]-'0')*100)+((enterID[6]-'0')*10)+(enterID[7]-'0');

int valID[2];
valID[0]=ind1;
valID[1]=ind2;

string temname;
int temage;
 float temheight,temsize;
 char temgen;
 cout<<"Enter your name : ";
fflush(stdin);
getline(cin,temname);
fflush(stdin);
cout<<"Enter your age : ";cin>>temage;
cout<<"Enter your height : ";cin>>temheight;
cout<<"Enter the size of your foot : ";cin>>temsize;
cout<<"Enter your gender : ";cin>>temgen;

user client(temname,valID,temage,temheight,temsize,temgen);

cout<<"How many shoes do you want to prchase : ";
int temno,check;
cin>>temno;
 float size,width;
    string brand,color;
    Style style;
    demography demo;

shoe *ptr = new shoe [temno];

for(int i=0;i<temno;i++){
    cout<<"\n->> Enter the information of the shoe"<<i+1<<"\nSize : ";
    cin>>size;
    ptr[i].setSize(size);
    cout<<"Width : ";
    cin>>width;
    ptr[i].setWidth(width);
    cout<<"Brand : ";
    fflush(stdin);
    getline(cin,brand);
    fflush(stdin);
    ptr[i].setBrand(brand);
    cout<<"Color : ";
    fflush(stdin);
    getline(cin,color);
    fflush(stdin);
    ptr[i].setColor(color);
    cout<<"Please select the style of the shoe\n1- Running Shoes\n2- Sneakers\n3- Stiletto\nEnter your choice : ";
    cin>>check;
    switch(check){
        case 1:style=runningshoes; break;
        case 2:style=sneakers; break;
        case 3:style=stiletto; break;
    }    
    demo=ptr[i].checkAge(temage);
    ptr[i].setDemo(demo);
}
    
int *newptr =new int[2];
newptr=client.getID();

while(1){

    system("cls");
    cout<<"==>> User : "<<client.getName()<<"\n==>> ID : {"<<newptr[0]<<" , "<<newptr[1]<<"}\n";
    cout<<"\nSelect your desired operation precisely\n 1.) Update the information of the given shoe\n 2.) View the given information\n 3.) Exit\nEnter your choice :  ";
    cin>>check;

    switch(check){
        case 1: UpdateInfo(ptr,temno); break;
        case 2: DisplayInfo(ptr,temno); break;
        case 3: exit(0); break;
        default: cout<<"Invalid Entry Kindly be precise !\n";
        system("pause");
    }
}
delete[] newptr;
    return 0;
}
