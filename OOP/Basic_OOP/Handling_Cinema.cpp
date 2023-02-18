#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
int ticketID;
struct time{
    int hour,min;
    char ch=':';
};

class Ticket{
    int rowNum,seatNum,ticketID;
    bool stat=false;

    public:

    Ticket(){}
    Ticket(int Rnum,int Snum,int Tnum,bool st){
        rowNum=Rnum;
        seatNum=Snum;
        ticketID=Tnum;
        stat=st;
    }

    void setRnum(int val){rowNum=val;}
    void setSnum(int val){seatNum=val;}
    void setTid(int val){ticketID=val;}
    void setStat(bool val){stat=val;}

    int getRnum(){return rowNum;}
    int getSnum(){return seatNum;}
    int getTid(){return ticketID;}
    bool getStat(){return stat;}

    bool changeStat(){
        if(stat)return false;
        else {
            stat=true;
            return true;
        }
    }

    void displaySold(){
        if(stat){
            cout<<"\n-->> Ticket ID : "<<ticketID<<"\nRow number : "<<rowNum<<"\nSeat number : "<<seatNum;
        }
    }

    void displayRem(){
        if(!stat){
            cout<<"\n-->>Ticket ID : "<<ticketID<<"\nRow number : "<<rowNum<<"\nSeat number : "<<seatNum<<endl;
        }
    }
};

class Movie{

    string name;
    struct time movietime;
    Ticket *tickets;
    int seats;

    public:

    Movie(){}
    Movie(int Totaltickets,string Name,struct time time){
        int Rnum,Snum;
        bool stat;
        name=Name;
        movietime=time;
        seats=Totaltickets;
        tickets=new Ticket[Totaltickets];

        cout<<"Give the info about tickets";
     for(int i=0;i<Totaltickets;i++){
        cout<<"\n-->> Ticket "<<i+1<<"\nRow number : ";cin>>Rnum;
        tickets[i].setRnum(Rnum);
        cout<<"Seat number : ";cin>>Snum;
        tickets[i].setSnum(Snum);
        tickets[i].setTid(ticketID++);
        cout<<endl;
        }
    }

    void setName(string val){name=val;}
    void setTime(struct time val){movietime=val;}

    string getName(){return name;}
    struct time getTime(){return movietime;}
    int getSeats(){return seats;}

  void displayrem(){
   for(int i=0;i<seats;i++){
        cout<<"\nTicket "<<i+1<<" : \n";
       tickets[i].displayRem();
   }
    system("pause");
   }

   void displaysold(){
    for(int i=0;i<seats;i++) {
        cout<<"\nTicket "<<i+1<<" : \n";
        tickets[i].displaySold();
    }
    system("pause");
    }


void saleIT(){
    system("cls");
   
   displayrem();

   cout<<"Enter the ticket number you want buy : ";
   int tempnum;
   cin>>tempnum;

   if(tickets[tempnum-1].changeStat())
   cout<<"\nThe tickets has been sold\n";
   else cout<<"The ticket has been sold already\n"; 
   system("pause");
   }
};

void displaymovies(Movie *mov,int val){
    for(int i=0;i<val;i++) cout<<"- Movie "<<i+1<<" : "<<mov[i].getName()<<endl;

}


int main(){
    
    cout<<"22k-4609 Taha Khan\n";
string temps;
        cout<<"Enter your student ID : ";
        fflush(stdin);
        getline(cin,temps);
        fflush(stdin);

        int maxlen=temps.length(),valID[2];
        valID[0]=temps[maxlen-4]-'0';
        valID[1]=temps[maxlen-3]-'0';
    ticketID=(valID[0]*10)+(valID[1]);
    

struct time var;
var.hour=14;
var.min=30;

    Movie *movie;
    int tempno,tempticket,choice;

    cout<<"Of how many movies you want to handle the data : ";
    cin>>tempno;
    movie=new Movie[tempno];
        cout<<"Give information about the movies ";

    for(int i=0;i<tempno;i++){
        cout<<" ==>> Movie "<<i+1<<"\nName : ";
        fflush(stdin);
        getline(cin,temps);
        fflush(stdin);
        cout<<" --Time in 24 Hour format\nHour : "; cin>>var.hour;
        cout<<"Minutes : "; cin>>var.min;
        cout<<"Total Number of tickets : "; cin>>tempticket;
        movie[i]=Movie(tempticket,temps,var);
        cout<<endl;
    }
 
 while(1){
    system("cls");
    cout<<"Choose according to your desired operation precisely\n 1-  buy a ticket\n 2- display sold tickets\n 3- dispalay the remaining tickets\n 4- Exit\nEnter your choice : ";
    cin>>choice;

    switch(choice){
        case 1: 
        cout<<"For which movie you want to buy the tickets\n";
        displaymovies(movie,tempno);
        cout<<"\nEnter the movie number : ";
        int num;
        cin>>num;
        movie[num-1].saleIT(); 
        break;
        case 2: 
        displaymovies(movie,tempno);
        cout<<"Enter the movie number : ";cin>>choice;
        movie[choice-1].displaysold();
         break;
        case 3: 
        displaymovies(movie,tempno);
        cout<<"Enter the movie number : ";cin>>choice;
        movie[choice-1].displayrem();
         break;
        case 4: exit(0); break;
        default : cout<<"Invalid Entry !\n";
    }
 }

    return 0;
}