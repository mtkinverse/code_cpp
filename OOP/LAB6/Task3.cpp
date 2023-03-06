#include<iostream>
#include<string>
using namespace std;
string dum;
class MenuItems{
    string name;
    float price;

    public:
    Food(string name="",float price=0.00){
        this->name=name;
        this->price=price;
    }
    void setName(string name){
        this->name=name;
    }
    void setPrice(float val){price=val;}

    string getName()const {return name;}
    float getPrice()const {return price;}

};

class Menu{

MenuItems *items;
static int totalItems;

public:

Menu(){}
Menu(MenuItems* items,int number){
    this->items=new MenuItems[number];
    totalItems=number;

    for(int i=0;i<number;i++)this->items[i]=items[i];
    
}

void AddItem(string name,float price){
    MenuItems* temp=new MenuItems[totalItems]
    ;
    for(int i=0;i<totalItems;i++){
        temp[i]=items[i];
    }
    totalItems++;
    items = new MenuItems[totalItems];

    for(int i=0;i<totalItems-1;i++)items[i]=temp[i];
    items[totalItems-1].setName(name);
    items[totalItems-1].setPrice(price);
    delete[] temp;
    
    cout<<"\nItem Has been Updated\n";
    
}

void removeItem(string name){

    for(int i=0;i<totalItems;i++){
        if(name.compare(items[i].getName())==0){
            for(int j=i;j<totalItems-1;j++){
                items[j]=items[j+1];
            }
            MenuItems* temp = new MenuItems[totalItems-1];
            for(int i=0;i<totalItems-1;i++)temp[i]=items[i];
            totalItems--;
            items = new MenuItems[totalItems];
            for(int i=0;i<totalItems;i++)items[i]=temp[i];
            delete[] temp;
            cout<<"\nItem Removed\n";
            system("pause");
            return;
        }
    }
    cout<<"\nItem Not found !\n";system("pause");
}

void displayMenu(){

    for(int i=0;i<totalItems;i++) cout<<"\n-->> Item "<<i+1<<"\nName : "<<items[i].getName()<<"\nPrice : "<<items[i].getPrice()<<endl;
}

void UpdateItemName(string name,string newName){
    for(int i=0;i<totalItems;i++){
        if(name.compare(items[i].getName())==0){
            items[i].setName(newName);
            return;
            }
    }
    cout<<"\nItem Not Found !\n";system("pause");
}

void UpdateItemPrice(string name,float newPrice){

    for(int i=0;i<totalItems;i++){
        if(name.compare(items[i].getName())==0){
            items[i].setPrice(newPrice);
            return;
            }
    }
    cout<<"\nItem Not Found !\n";system("pause");
}

float getPriceItem(int n){
   return items[n].getPrice();
}

string getNameItem(int n){
    return items[n].getName();
}
};

int Menu::totalItems=0;

class Order{
    int Items;
    float price;

    public:

    Order(){
        Items=0;
        price=0;
    }
    void UpdateOrder(float price){
        Items++;
        this->price+=price;
    }

    int getItems()const{return Items;}
    float getPrice()const{return price;}

};

class Payment{
    float cost;
    public:
    Payment(float cost=0){
        this->cost=cost;
    }
    void setCost(float cost){this->cost=cost;}
    float getCost() const {return cost;}

};

class OrderSystem{
    Menu menu;
    Payment pay;
    Order order;
    public:
    OrderSystem(){}
    
    void getMenu() { menu.displayMenu();}
 
    void UpdateItem(){

        system("cls");
        string S,tS;
        float temprice;
        cout<<"Give the name of the Item you want to update : ";
        getline(cin,dum);
        cin.clear();
        getline(cin,S);
        cin.clear();
        int choice;
        cout<<"What do you want to update\n1 ~ Name of an item\n2 ~ price of an item\nEnter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Give the new name : ";
            getline(cin,dum);
            cin.clear();
            getline(cin,tS);
            cin.clear();
            menu.UpdateItemName(S,tS);
             break;
             
             case 2:
              cout<<"Give the new price : ";
              cin>>temprice;
              menu.UpdateItemPrice(S,temprice);
             break;

            default : cout<<"Kindly be precised\n";
            system("pause");
        }
    }

    void ChangeItem(){
        string tempS;
        float tempf;
        int chA,chB;
system("cls");
        cout<<"Kindly select the process you want to udergo\n1- Add an item\n2- Remove an item\nEnter your choice : ";
        cin>>chA;

        switch(chA){
            case 1: 
            cout<<"Give the name of new Item : ";
            getline(cin,dum);
            cin.clear();
            getline(cin,tempS);
            cin.clear();
            cout<<"Give the price of the new item : ";cin>>tempf;
            menu.AddItem(tempS,tempf);
            break;

            case 2: 
             cout<<"Give the name of the item you want to remove : ";
            getline(cin,dum);
            cin.clear();
            getline(cin,tempS);
            cin.clear();
            menu.removeItem(tempS);
            break;
            default : cout<<"invalid Entry Kindly be precised";
            system("pause");
        }
        cout<<"The list has been updated\n";
        system("pause");
    }

    void PlaceOrder(){
system("cls");
        order=Order();
        cout<<"Kindly ensure us what do you want to buy\n";
        menu.displayMenu();
        cout<<"Give the number of items items you want to buy : ";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
        int no;
        cout<<"Give the item number you want to buy : ";
        cin>>no;
        order.UpdateOrder(menu.getPriceItem(--no));
        }
        pay.setCost(order.getPrice());

       system("cls");
        cout<<"\n\n-- You have ordered "<<order.getItems()<<" items \nYour Total bill is : "<<order.getPrice()<<" RS\n";
        system("pause");
    }


};

int main(){

int choiceA,choiceB,choiceC;

OrderSystem OS;

while(1){
system("cls");

cout<<"\n######\tWelcome to the Order Manager\t######\n\nKindly select the desired option precisely\n 1 = View Menu\n 2 = Place an oreder\n 3 = Update List\n 4= Exit\n\nEnter your choice : ";
cin>>choiceA;

switch(choiceA){

    case 1:
    system("cls");
     OS.getMenu();
    system("pause");
    break;

    case 2 :
     OS.PlaceOrder();
    break;

    case 3:
    system("cls");
    cout<<"\nWhat do you want to update\n 1) Update an existing item\n 2) Add or remove an Item\nEnter your choice : ";
   cin>>choiceB;
    switch(choiceB){
        case 1:
        OS.UpdateItem();
         break;
        case 2:
        OS.ChangeItem();
         break;
         
         
    default : cout<<"Be precised ! \n";

    }
    
    break;
    case 4:
    exit(0);
    break;
    default : cout<<"Be precised ! \n";
    system("pause");
}
}
cout<<"\n\n\t\t*****Thanks for visiting*********\n";

    return 0;
}