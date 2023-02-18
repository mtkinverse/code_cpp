#include<iostream>
#include<string>
using namespace std;
static int count=0;
static int val=0;


class Radiator{
    int RadiatorID;
    bool stat=true;

    public:
    
    Radiator(){
      RadiatorID=val+(15*count);
        count++;
    }


    int  const getradID(){
        return RadiatorID;
    }  

    bool getStat(){return stat;}
    void changeStat(){stat!=stat;}

};

class Room{
    string roomName;
    int seatingCapacity,numRadiators=0,radID[2];


    public:

    Room(){}
    Room(string name){
        roomName=name;
        seatingCapacity=12;
    }
    string isHeatedBY(Radiator rad){
        for(int i=0;i<2;i++)if(radID[i]==rad.getradID()) return "Radiator already added to the room\n";
        if(numRadiators==0){
            radID[0]=rad.getradID();
            rad.changeStat();
            numRadiators++;

            return "Radiator successfully added to the room\n";
            }
        else if(numRadiators==1){
            radID[1]=rad.getradID();
            rad.changeStat();
            numRadiators++;

            return "Radiator succesfully added to the room\n";
        }
        else return "Cannot add radiator . Room has a maximum of radiators\n";
    }
};

int main(){
    cout<<"22k-4609 Taha Khan\n";

        string temps;
        cout<<"Enter your student ID : ";
        fflush(stdin);
        getline(cin,temps);
        fflush(stdin);

        int maxlen=temps.length(),index[3];

    index[0]=temps[maxlen-1]-'0';
    index[1]=temps[maxlen-2]-'0';
    index[2]=temps[maxlen-3]-'0';

    val=(index[2]*100)+(index[1]*10)+(index[0]);
    // val*=(-1);

    Radiator rad1,rad2,rad3;
    Room room("The Room");
    cout<<room.isHeatedBY(rad1);
    cout<<room.isHeatedBY(rad2);
    cout<<room.isHeatedBY(rad3);
    cout<<room.isHeatedBY(rad2);
    return 0;
}

