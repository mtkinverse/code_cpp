#include<iostream>
using namespace std;

    int cal_runs(int arr[]){
        int value=0;
        for(int i=0;i<6;i++){
             value+=arr[i];
        }
        return value;
    }

class scores{
    int ball[6],runs,six,fours,dots;
    public:

    // friend int cal_runs(int []);
    friend void printData(scores [],int);
    void check_stats( );

     scores(){//We have declared this default constructor so that when we initialize the obj it should automatically set to zero and no error should be thrown
        ball[6]=runs=six=fours=0;
    }
    scores(int arr[]){
  
        for(int i=0;i<6;i++){
            ball[i]=arr[i];
          }

    }

};

    void scores::check_stats(){

        fours=six=dots=0;

     for(int i=0;i<6;i++){
        if(ball[i]==4)fours++;
        else if(ball[i]==6)++six;        
        else if(ball[i]==0)dots++;
    }
         runs=cal_runs(ball);
    }

    void printData(scores overs[],int no_overs){

        for(int i=0;i<no_overs;i++){

            cout<<"--> Over Number "<<i+1<<endl;
            for(int j=0;j<6;j++){
                cout<<"Ball "<<j+1<<" : "<<overs[i].ball[j]<<endl;
            }
            cout<<"Total sixes : "<<overs[i].six<<endl<<"Total fours : "<<overs[i].fours<<endl<<"Dot balls : "<<overs[i].dots<<endl<<"The total runs scored : "<<overs[i].runs<<endl<<endl;

        }
    }





    int main(){

        cout<<"Hi and welcome to the stats checker\nGive the number of overs of the match ";
        int no_overs;
        cin>>no_overs;

        scores overs[no_overs];
        cout<<"\n\n------------------Give the stat-------------------\n\n";


        for(int i=0;i<no_overs;i++){
        int arr[6];
            cout<<"Over Number "<<i+1<<endl;
            for(int j=0;j<6;j++){
                cout<<"Give the runs on ball "<<j+1<<" : ";
                cin>>arr[j];
                if(arr[j]<0||arr[j]>6){
                    printf("\nKindly be prcised and enter accurate information\n");
                    --j;
                } 
            }
            overs[i]=scores(arr);
            overs[i].check_stats();
        }

        cout<<"\n\n********************The Given stats are*********************"<<endl<<endl;
        printData(overs,no_overs);
        
        return 0;
    }