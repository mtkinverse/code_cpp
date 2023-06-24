// 3.07
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class Reader;
class Writer;

class Student{
    char ID[10],Name[30],Year[10];
    int BatchNO;
    friend class Reader;
    friend class Writer;
    public:
    Student(){
      strcpy(ID,"");        
      strcpy(Name,"");        
      strcpy(Year,"");
      BatchNO=0;        
    }
    Student(char ID[],char Name[],char Year[],int BatchNo){
        this->BatchNO=BatchNo;
        strcpy(this->ID,ID);
        strcpy(this->Name,Name);
        strcpy(this->Year,Year);
    }
};

class Reader{
    public:
    static void ReadIt(){
        fstream file;
        file.open("StudentData.bin",ios::binary|ios::in);
        Student temp;
        while(file.read((char*)&temp,sizeof(temp))){
            cout<<"----------------------------------\nStudent Name : "<<temp.Name<<"\nStudnet ID : "<<temp.ID<<"Student Year : "<<temp.Year<<"\nBatch Number : "<<temp.BatchNO<<endl;
        }
        file.close();
        cout<<"\n\n === Data ended ! ==\n";
        system("pause");
    }
};

class Writer{
public:
static void WriteIt(){
Student temp;
    fstream file;
     char tempID[10],tempName[30],tempYear[10];
    int tempBatchNO;
    system("cls");

    char blank[10];//just to ensure the entry !

    cout<<" -->> Enter the Information of the student\nBatch number : ";
    cin>>tempBatchNO;
    fflush(stdin);
    cout<<"Name : ";
    fgets(blank,30,stdin);//It was skipping tempName so i took this step
    fgets(tempName,30,stdin);
    cout<<"ID : ";
    fgets(tempID,10,stdin);
    cout<<"Year : ";
    fgets(tempYear,10,stdin);
    
    fflush(stdin);
    cin.clear();

    temp = Student (tempID,tempName,tempYear,tempBatchNO);
    
    file.open("StudentData.bin",ios::binary|ios::app);
    file.write((char*)&temp,sizeof(Student));
    file.close();
    cout<<"\n\n == Data Written successfully ==\n";
    system("pause");
    fflush(stdin);
}
};

int main(){

    Reader reader;
    Writer writer;
    while(1){
cout<<" Welcome please select the desired operation precisely !\n 1 - Write Data at StudentData.bin\n 2 - Read all Data from StudentData.bin\n 3 - Exit\n\nEnter Your choice (1,2,3) : ";
int choice;
cin>>choice;

switch (choice)
{
case 1 :
   writer.WriteIt();
break;

case 2:
  reader.ReadIt();
break;

case 3:
  exit(0);
break;

default : cout<<" !!! Be precise !!!\n";
system("pause");

}

} 
return 0;
}
